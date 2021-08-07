class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        //this function search for greater value from the left
        vector<pair<int, int>> stack;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (stack.size() == 0) {
                result.push_back(-1);
            }
            else if (stack.size() > 0 and stack.back().second > price[i]) {
                result.push_back(stack.back().first);
            }
            else if (stack.size() > 0 and stack.back().second <= price[i]) {
                while (stack.size() > 0 and stack.back().second <= price[i]) {
                    stack.pop_back();
                }
                if (stack.size() == 0) {
                    result.push_back(-1);
                }
                else {
                    result.push_back(stack.back().first);
                }
            } 
            //first is index, second is price in pair
            stack.push_back({ i, price[i] });
        }
        for (int i = 0; i < n; i++) {
            result[i] = i - result[i];
        }
        return result;
    }
};
