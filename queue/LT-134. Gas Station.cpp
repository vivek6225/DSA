 
 // T.c = 0(n)
 // S.c = 0(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;
        int start = 0;   // candidate starting station
        int curGas = 0;  // current fuel in tank

        // Traverse all stations once
        for(int i = 0; i < gas.size(); i++) {
            totGas += gas[i];   // total gas available
            totCost += cost[i]; // total cost required

            curGas += (gas[i] - cost[i]); // update current gas balance

            // If current gas becomes negative, can't reach next station
            if(curGas < 0) {
                start = i + 1;  // next station is new candidate start
                curGas = 0;     // reset current gas
            }
        }

        // If total gas < total cost, no solution exists
        return (totGas < totCost) ? -1 : start;
    }
};
