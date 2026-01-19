
               // Optimal Approach
    //    Time Complexity: O(n)
    //      Space Complexity: O(1)
     class Solution {
public:
   
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size();
        int time = 0; // Total time taken
        
        // Loop through each person
        for (int i = 0; i < n; i++) {
            if (i <= k) {
                // People before or at k can buy up to tickets[k] tickets
                time += min(tickets[k], tickets[i]);
            } else {
                // People after k can buy at most tickets[k] - 1 tickets
                time += min(tickets[k] - 1, tickets[i]);
            }
        }
        
        return time;
    }
};


//--------------------BETTER APPROACH---------------------------------------------------
//T.C = 0(n*n)
 //S.C = 0(n)  

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