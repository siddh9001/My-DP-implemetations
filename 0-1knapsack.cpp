#include<iostream>
#include<algorithm>
using namespace std;

int knapsack(int we[], int p[], int n, int w)
{
    if(n == 0 || w == 0)
        return 0;
        
    if(we[n-1] <= w)
        return max(p[n-1] + knapsack(we, p, n-1, w-we[n-1]), knapsack(we, p, n-1, w));

    else
        return knapsack(we, p, n-1, w);
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

    cout << "Maximum profit you can gain: " << knapsack(weight, price, n, w);

}