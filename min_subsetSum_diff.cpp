#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<cstring>
using namespace std;
vector<vector<bool>> subsetsum(vector<int> a, int n, int sum)
{
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    // for(int i=0;i<n+1;i++)
    //     for(int j=0;j<sum+1;j++)
    //         dp[i][j] = false;
    dp[0][0] = true;

    //for(int i=0;i<n+1;i++)
    //   dp[i][0] = true;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(a[i-1] <= j)
                dp[i][j] = dp[i-1][j - a[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp;
}
int main()
{
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin >> a[i];

    int sum =0; 
    for(int i=0;i<n;i++)
        sum += a[i];

    vector<vector<bool>> dp;
    dp = subsetsum(a, n, sum);

    //viewing the dp ans
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
            cout << dp[i][j] <<" ";

        cout << endl;
    }


    vector<int> v;
    for(int j=0;j<sum/2;j++)
        if(dp[n][j])v.push_back(j);

    int min_diff = INT_MAX;
    for(auto i:v)
        min_diff = min(min_diff, sum - 2*i);

    cout << "Minimum subset sum difference is: " << min_diff;
    return 0;    
}
