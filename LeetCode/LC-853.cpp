//853 --> Car Fleet

class Solution {
    class Car{
        public:
        int pos, speed;

        Car(int p, int s):pos(p), speed(s) {};
    };

    static bool cusComp(Car&a, Car&b){
        return a.pos < b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        //custom class created for to merge pos and speed as one car 
        //can be sort and maintain the order

        for(int i=0;i<position.size();i++){
            Car car(position[i], speed[i]);

            cars.push_back(car);
        }

        sort(cars.begin(), cars.end(), cusComp);

        stack<float>st;
        for(auto car : cars){

            //speed = distance / time formula

            float time = (target - car.pos) / ((float)car.speed);

            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};

//TC => O(nlogn)
//SC => O(n)