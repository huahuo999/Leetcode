#include <iostream>
#include <vector>
using namespace std;
vector<int> getSchemes(){
    vector<int> dp(1000001, 0);
    dp[0] = 1;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= i; j = 2 * j){
            dp[i] += dp[i-j];
        }
    }
    return dp;
}
int main() {
    vector<int> res = getSchemes();
    for(auto & re : res){
        cout<<re<<endl;
    }
    int testNumber;
    cin>>testNumber;
    for(int k = 0; k < testNumber; k++){
        int n;
        cin>>n;
        cout<<"case #"<<k<<":"<<endl;
        cout<<res[n]<<endl;
    }
}
