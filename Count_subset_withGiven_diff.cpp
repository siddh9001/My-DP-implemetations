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
    int n,diff,sum=0;
    cout << "Enter the numbers of elements in array and difference: ";
    cin >> n >> diff;
    int a[n];
    cout << "Enter the elemets of array: ";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s1 = (diff+sum)/2;
    cout << "The number of subsets that can formed whose difference is given is:";
    cout << countOfSubsetSum(a, n, s1);

    return 0;

}