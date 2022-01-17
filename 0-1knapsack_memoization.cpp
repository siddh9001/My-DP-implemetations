#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[1001][1001];

int knapsack(int we[], int p[], int n, int w)
{
    if(n == 0 || w == 0)
        return 0;

    if(dp[n][w] != -1)
        return dp[n][w];

    if(we[n-1] <= w)
    {
        dp[n][w] = max(p[n-1] + knapsack(we, p, n-1, w-we[n-1]), knapsack(we, p, n-1, w));
        return dp[n][w];
    }
    else
    {
        dp[n][w] = knapsack(we, p, n-1, w);
        return dp[n][w];
    }

    return dp[n][w];
}

int main()
{
    int n, w;
    cout << "Enter number of items and capacity of bag: ";
    cin >> n >> w;
    int weight[n], price[n];
    cout << "Enter weight of item and corresponding price: ";
    for(int i=0;i<n;i++)
        cin >> weight[i] >> price[i];

    memset(dp, -1, sizeof(dp));
    cout << "Maximum profit you can gain: " << knapsack(weight, price, n, w);

}