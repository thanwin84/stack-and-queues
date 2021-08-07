class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3){
            return 0;
        }
        int trapped_water = 0;
        vector<int> from_left;
        vector<int> from_right(height.size(), 0);
        int maxL = height[0];
        int maxR = height[height.size() - 1];
        for (int i = 0; i < height.size(); i++) {
            maxL = max(maxL, height[i]);
            from_left.push_back(maxL);
            
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            maxR = max(maxR, height[i]);
            from_right[i] = maxR;
        }
        for (int i = 0; i < height.size(); i++) {
            trapped_water += (min(from_left[i], from_right[i]) - height[i]);
        }
        return trapped_water;
    } 
};
