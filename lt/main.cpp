#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> dp(numRows+1, 1);
        for(int i = 1; i <= numRows; i++){

        }
    }
};
int main() {
    int numRows = 5;
    Solution solu;
    vector<vector<int>> res = solu.generate(numRows);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
