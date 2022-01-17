#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool dp[1001][1001];
bool equal_sum_partition(int nums[], int n, int sum)
{   
    //intialization            
    dp[0][0] = true;

    //finding optimal solution
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];

            else
                dp[i][j] = dp[i-1][j];

        }
    }
    
    return dp[n][sum];
}

int main()
{
    int n, sum=0;
    cout << "Enter number of items and sum: ";
    cin >> n;
    int nums[n];
    cout << "Enter the numbers: ";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    
    memset(dp, false, sizeof(dp));
    
    cout << "Is equal sum partition possible: " << (sum%2!=0 ? 0 : equal_sum_partition(nums, n, sum/2));

}