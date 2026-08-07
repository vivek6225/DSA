//-------------Optimal Approach----------------------
// Time Complexity = O(n × log(minTime × totalTrips))
// Space Complexity = O(1)
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        int n = time.size();

        // Minimum possible time
        long long start = 1;

        // Fastest bus time
        long long minTime = *min_element(time.begin(), time.end());

        // Maximum possible time:
        // Assume the fastest bus completes all trips alone
        long long end = minTime * 1LL * totalTrips;

        // Apply Binary Search on time
        while (start <= end) {

            long long mid = start + (end - start) / 2;

            long long trips = 0;

            // Count total trips completed by all buses in 'mid' time
            for (int i = 0; i < n; i++) {
                trips += mid / time[i];
            }

            // If enough trips are completed,
            // try to find a smaller possible time
            if (trips >= totalTrips) {
                end = mid - 1;
            }
            // Not enough trips,
            // increase the available time
            else {
                start = mid + 1;
            }
        }

        // 'start' stores the minimum time required
        return start;
    }
};
        
//----------Brute Force Approach----------------------
// Time Complexity = O(maxTime × n)
// Space Complexity = O(1)
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long currentTime = 1;

        while (true) {

            long long trips = 0;

            // Count trips completed by all buses
            for (int i = 0; i < time.size(); i++) {
                trips += currentTime / time[i];
            }

            // If enough trips are completed
            if (trips >= totalTrips) {
                return currentTime;
            }

            // Increase current time
            currentTime++;
        }

        return -1;
    }
};