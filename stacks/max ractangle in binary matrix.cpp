class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        int n = matrix[0].size();
        vector<int> arr;
        
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == '0') arr.push_back(0);
            else arr.push_back(1);
        }
        int max_area = largestRectangleArea(arr);
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    arr[j] = 0;
                }
                else {
                    arr[j] = arr[j] + 1;
                }
            }
            int temp = largestRectangleArea(arr);
            max_area = max(max_area, temp);
        }
        return max_area;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> width;
        int max_area = INT_MIN;
        vector<int> right = NSER(heights, heights.size());
        vector<int> left = NSEL(heights, heights.size());
        for (int i = 0; i < heights.size(); i++) {
            width.push_back(abs(right[i] - left[i] - 1));
        }
        for (int i = 0; i < heights.size(); i++) {
            max_area = max(max_area, width[i] * heights[i]);
        }
        return max_area;
    }
    vector<int> NSER(vector<int> arr, int n) {
        // Your code here
        vector<pair<int, int>> stack;
        vector<int> result;
        for (auto i = n - 1; i >= 0; i--) {
            if (stack.size() == 0) {
                result.push_back(n);
            }
            else if (stack.size() > 0 and stack.back().second < arr[i]) {
                result.push_back(stack.back().first);
            }
            else if (stack.size() > 0 and stack.back().second >= arr[i]) {
                while (stack.size() > 0 and stack.back().second >= arr[i]) {
                    stack.pop_back();
                }
                if (stack.size() == 0) {
                    result.push_back(n);
                }
                else {
                    result.push_back(stack.back().first);
                }
            }
            stack.push_back({ i, arr[i] });
        }
        reverse(result.begin(), result.end());
        return result;
    }
    vector<int> NSEL(vector<int> arr, int n) {
        // Your code here
        vector<pair<int, int>> stack;
        vector<int> result;
        for (auto i = 0; i < n; i++) {
            if (stack.size() == 0) {
                result.push_back(-1);
            }
            else if (stack.size() > 0 and stack.back().second < arr[i]) {
                result.push_back(stack.back().first);
            }
            else if (stack.size() > 0 and stack.back().second >= arr[i]) {
                while (stack.size() > 0 and stack.back().second >= arr[i]) {
                    stack.pop_back();
                }
                if (stack.size() == 0) {
                    result.push_back(-1);
                }
                else {
                    result.push_back(stack.back().first);
                }
            }
            stack.push_back({ i, arr[i] });
        }
        return result;
    }
};
