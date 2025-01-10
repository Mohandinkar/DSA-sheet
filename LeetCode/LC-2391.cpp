//2391. --> Minimum Amount of Time to Collect Garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       //M truck
       int pickM = 0;
       int travelM = 0;
       int lastHouseM = 0;
       //P truck
       int pickP = 0;
       int travelP = 0;
       int lastHouseP = 0;
       //G truck 
       int pickG = 0;
       int travelG = 0;
       int lastHouseG = 0;

       for(int i=0;i<garbage.size();i++){
         string currHouse = garbage[i];

         for(int j=0;j<currHouse.size();j++){
            char garbageType = currHouse[j];
            //check the grabage type and increase the pickUp time for each truck
            if(garbageType == 'P'){
                pickP++;
                lastHouseP = i;
            }
            if(garbageType == 'M'){
                pickM++;
                lastHouseM = i;
            }
            if(garbageType == 'G'){
                pickG++;
                lastHouseG = i;
            }
         }
       }

       //to calculate the travel time for each truck
       for(int i=0;i<lastHouseP;i++){
        travelP = travelP + travel[i];

       }
        for(int i=0;i<lastHouseM;i++){
        travelM = travelM + travel[i];

       }
        for(int i=0;i<lastHouseG;i++){
        travelG = travelG + travel[i];

       }

       int totalTravelTime = travelP + travelM + travelG;
       int totalPickUptime = pickP + pickM + pickG;

       int totalTime = totalTravelTime + totalPickUptime;

       return totalTime;




    }
};