class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<int> q;
        int n = tickets.size();
        
        // Store all people in queue
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        
        int time = 0;
        
        while (tickets[k] > 0) {
            tickets[q.front()]--; // Decrease ticket count of the person at front. 

            // Push back if tickets left.
            if (tickets[q.front()]) {
                q.push(q.front());
            }

            q.pop();  // Remove from front
            time++;   // 1 second for each ticket sold.
        }
        
        return time;
    }
};
