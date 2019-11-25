// 973. K Closest Points to Origin
// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

// (Here, the distance between two points on a plane is the Euclidean distance.)

// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

// Example 1:

// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation: 
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)
 

// Note:

// 1 <= K <= points.length <= 10000
// -10000 < points[i][0] < 10000
// -10000 < points[i][1] < 10000

class Plane{
public:
    vector<int> point;
    long distance;
    
    Plane(vector<int> point){
        this->point=point;
        this->distance=((point[0]*point[0])+(point[1]*point[1]));
    }
    
};
class Solution {
    long distance(vector<int> point){
        return ((point[0]*point[0])+(point[1]*point[1]));
    }
    struct Comparator{
        bool operator()(const Plane& p1,const Plane& p2){
            return p2.distance>p1.distance;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k==points.size())    
            return points;
        
        priority_queue<Plane,vector<Plane>,Comparator> pq;
        
        for(int i=0;i<k;i++){
            pq.push(Plane(points[i]));
        }
        for(int i=k;i<points.size();i++){
            if(distance(points[i])<pq.top().distance){
                pq.pop();
                pq.push(Plane(points[i]));
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().point);
            pq.pop();
        }
        return ans;
        
    }
};