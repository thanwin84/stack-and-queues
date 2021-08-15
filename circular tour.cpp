class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int extra = 0;
        int start = 0;
        int distance_lacking = 0;
        for (int i = 0; i < gas.size(); i++){
            extra += gas[i] - cost[i];
            if (extra < 0){
                start = i + 1;
                distance_lacking += extra;
                extra = 0;
            }
        }
        if (extra + distance_lacking >= 0){
            return start;
        }
        return -1;
    }
};
