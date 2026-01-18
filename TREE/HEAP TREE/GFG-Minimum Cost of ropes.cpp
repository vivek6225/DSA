

//T.C = O(n log n)
//T.C = O(n)

class Solution {
  public:
    int minCost(vector<int>& arr) {

        // Min-heap to always get smallest ropes
        priority_queue<int, vector<int>, greater<int>> p;

        // Push all rope lengths into heap
        for(int i = 0; i < arr.size(); i++)
            p.push(arr[i]);

        int cost = 0;

        // Keep combining until one rope remains
        while(p.size() > 1) {

            // Take two smallest ropes
            int rope1 = p.top(); p.pop();
            int rope2 = p.top(); p.pop();

            int newRope = rope1 + rope2;
            cost += newRope;

            // Push combined rope back
            p.push(newRope);
        }

        return cost;
    }
};
