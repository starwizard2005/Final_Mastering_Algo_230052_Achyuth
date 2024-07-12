#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector <long long int> arr(n);
    for (int i = 0;i<n;i++){
        cin >> arr[i];
    }
    vector <long long int> dp(x+1,0);
    dp[0] = 1;
    for (int i = 0;i<n;i++){
        for (int j = arr[i];j<x+1;j++){
            dp[j] = dp[j] + dp[j-arr[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[x];
    return 0;
}
