class Node:
    def __init__(self,val, nxt=None, prev = None):
        self.val = val
        self.next = nxt
        self.prev = prev

class DLL:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def add_to_head(self, node: Node):
        node.prev = None
        node.next = self.head

        if not self.head:
            self.tail = node
        else:
            self.head.prev = node
        self.head = node
    
    def remove_node(self, node: Node):
        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev

        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next

        node.next = None
        node.prev = None
    
    def move_to_head(self, node: Node):
        self.remove_node(node)
        self.add_to_head(node)
    
    def evict_tail_node(self):
        tail = self.tail
        self.remove_node(tail)
        return tail.val


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dll = DLL()
        self.items = {}
        

    def get(self, key: int) -> int:
        if key not in self.items:
            return -1
        val, node = self.items.get(key)
        self.dll.move_to_head(node)
        return val
        

    def put(self, key: int, value: int) -> None:
        if key in self.items:
            val, node = self.items.get(key)
            self.dll.move_to_head(node)
            
        else:
            if self.capacity == len(self.items):
                evicted_key = self.dll.evict_tail_node()
                # self.items.pop(evicted_key)
                del self.items[evicted_key]
            node = Node(key)
            self.dll.add_to_head(node)
        self.items[key] = (value, node)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)