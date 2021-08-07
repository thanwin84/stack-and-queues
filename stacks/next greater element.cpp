class Solution
{
    public:
        //Function to find the next greater element for each element of the array.
        vector<long long> nextLargerElement(vector<long long> arr, int n) {
            // Your code here
            vector<long long int> stack;
            vector<long long int> result;
            for (auto i = n -1; i >= 0; i--) {
                // if stack is empty, there is no greater element in front of last element
                if (stack.size() == 0) {
                    result.push_back(-1);
                }
                //if stack top is greater than arr[i], push back stack top to the result 
                else if (stack.size() > 0 and stack.back() > arr[i]) {
                    result.push_back(stack.back());
                }
                // if not, pop until we get stack top is greater than arr[i]
                else if (stack.size() > 0 and stack.back() <= arr[i]) {
                    while (stack.size() > 0 and stack.back() <= arr[i]) {
                        stack.pop_back();
                    }
                    if (stack.size() == 0) {
                        result.push_back(-1);
                    }
                    else {
                        result.push_back(stack.back());
                }
                    }
                //push back arr[i] to the stack so that we can find next greater element
                stack.push_back(arr[i]);
            }
            reverse(result.begin(), result.end());
            return result;
        }
};
