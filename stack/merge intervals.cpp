class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        if (intervals.size() == 0){
            return result;
        }
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            vector<int> first = result.back();
            if (intervals[i][0] <= first[1]){
                result.pop_back();
                result.push_back({first[0], max(first[1], intervals[i][1])});
                
            }
            else result.push_back(intervals[i]);
        }
        return result;
    }
};
