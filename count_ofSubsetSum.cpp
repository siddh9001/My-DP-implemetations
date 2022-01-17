#include<iostream>
#include<cstring>
using namespace std;

int countOfSubsetSum(int a[], int n, int sum)
{
    int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][0] = 1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(a[i-1] <= sum)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}
int main()
{
    int n,sum;
    cout << "Enter the numbers of elements in array and sum: ";
    cin >> n >> sum;
    int a[n];
    cout << "Enter the elemets of array: ";
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << "The number of subset has sum equal to given sum is: ";
    cout << countOfSubsetSum(a, n, sum);

    return 0;

}