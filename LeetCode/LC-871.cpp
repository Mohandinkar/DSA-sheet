//871 --> Minimum Number of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int fuel = startFuel;
        int dist = 0;
        int i = 0;

        //max heap
        priority_queue<pair<int, int>>pq;

        while(true){

            while(i < stations.size()){
                //push stations within reach with current fuel
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }
                else
                    break;
                
                i++;
            }

            //travel with full fuel
            dist = dist + fuel;
            fuel = 0;

            //reached
            if(dist >= target) break;

            //no fuel station within reach
            if(pq.empty()){
                stops = -1;
                break;
            }

            //refuel with max station fuel within reach
            auto&top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop(); 

            stops++;
        }

        return stops;
    }
};



/*
Approach:
- We need to reach `target` starting with `startFuel` and using fuel stations optimally.  
- Greedy strategy: always refuel at the station with the maximum fuel among the stations we can currently reach.  

Steps:
1. Maintain a max heap (priority queue) to store fuels of reachable stations.  
2. Track two variables:  
   - `dist` → how far we have actually traveled.  
   - `fuel` → fuel available at that moment.  
3. While traveling:  
   - Push all stations into the max heap whose position <= (dist + fuel).  
   - Move as far as possible by consuming current fuel → `dist += fuel, fuel = 0`.  
   - If `dist >= target`, we are done → return number of stops.  
   - If heap is empty (no station within reach), it means we are stuck → return -1.  
   - Otherwise, pick the station with the maximum fuel from heap, refuel there:  
        - New `fuel = (dist - station_position) + station_fuel`  
        - Reset `dist = station_position`  
        - Increment `stops`.  
4. Repeat until `dist >= target`.  

Why this works:  
- Greedy choice ensures we always pick the maximum fuel available at the farthest point we can reach, minimizing the number of stops.  

Time Complexity: O(N log N) (each station can be pushed/popped once).  
Space Complexity: O(N) for the heap.  
*/
