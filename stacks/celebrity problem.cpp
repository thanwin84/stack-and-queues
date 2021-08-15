class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    bool AknowsB(vector<vector<int>>& mat, int a, int b) {
        if (mat[a][b] == 1) return true;
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here 
        vector<int> stack;
        for (int i = 0; i < n; i++) {
            stack.push_back(i);
        }
        while (stack.size() > 1) {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            if (AknowsB(M, a, b)) {
                stack.push_back(b); // since a knows b, a can't be celebrity
            }
            else {
                stack.push_back(a); // since a doesn't know b, a can be potential celebrity
            }
        }
        int potential_celebrity;
        if (stack.size() == 1) {
            potential_celebrity = stack.back();
            stack.pop_back();
        }
      //we need to make sure if potential celebrity is the celebrity we are looking for
        for (int i = 0; i < n; i++) {
            if (i != potential_celebrity and (AknowsB(M, potential_celebrity, i) or !AknowsB(M, i, potential_celebrity))) {
                return -1;
            }
        }
        return potential_celebrity;
    }
    };
