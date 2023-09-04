class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a),len(b))
        a = a.zfill(n)
        b = b.zfill(n)

        carry = '0'
        answer = ['']*n
        for i in range(n-1, -1, -1):
            if a[i] == b[i]:
                answer[i] = carry
                carry = '0' if a[i] == '0' else '1'
            else:
                answer[i] = '0' if carry == '1' else '1'
        
        return (carry if carry == '1' else '') + ''.join(answer)
