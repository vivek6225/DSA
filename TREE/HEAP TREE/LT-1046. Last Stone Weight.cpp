
// T.C = O(N log N)
// S.C = O(N)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // Max-heap to always get the two heaviest stones
        priority_queue<int> p;

        // Insert all stones into the heap
        for(int stone : stones)
            p.push(stone);

        // Continue until one or no stone remains
        while(p.size() > 1) {

            // Extract the heaviest stone
            int stone1 = p.top();
            p.pop();

            // Extract the second heaviest stone
            int stone2 = p.top();
            p.pop();

            // If weights are different, push the remaining stone
            // If equal, both stones are destroyed (nothing pushed)
            if(stone1 != stone2)
                p.push(stone1 - stone2);
        }

        // If heap is empty, no stone left → return 0
        // Otherwise, return the last remaining stone
        return p.empty() ? 0 : p.top();
    }
};
