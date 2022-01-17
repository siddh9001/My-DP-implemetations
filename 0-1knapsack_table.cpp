#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1001][1001];
int knapsack(int we[], int p[], int n, int w)
{   
    //intialization            
    for(int i=0;i<n+1;i++)
        for(int j=0;j<w+1;j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;

    
    //finding optimal solution
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(we[i-1] <= j)
                dp[i][j] = max(p[i-1] + dp[i-1][j - we[i-1]], dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j];

        }
    }
    
    return dp[n][w];
}

int main()
{
    int n, w;
    cout << "Enter number of items and capacity of bag: ";
    cin >> n >> w;
    int weight[n], price[n];
    cout << "Enter weight of item and corresponding weight: ";
    for(int i=0;i<n;i++)
        cin >> weight[i] >> price[i];
    
    memset(dp, -1, sizeof(dp));

    cout << "Maximum profit you can gain: " << knapsack(weight, price, n, w);

}