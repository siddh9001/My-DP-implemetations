#include<stdio.h>//coin change using DP
int c(int v[],int n,int p)
{
    int dp[p+1];
    dp[0]=0;
    for(int i=1;i<=p;i++)
    {
        int min=p;
        for(int j=0;j<n && v[j]<=i ;j++)
        {
            int x=1+dp[i-v[j]];
            if(x<min)min=x;
        }
        dp[i]=min;
    }
    return dp[p];
}
int main()
{
    int v[3]={1,2,5};
    int p=5;
    printf("%d",c(v,3,p));
}