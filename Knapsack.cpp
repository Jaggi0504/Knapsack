#include<bits/stdc++.h>
using namespace std;

int knapsack(int *wt, int *val, int n, int W) {
	if(n == 0 || W == 0) {
		return 0;
	}
	if(wt[0] > W) {
		return knapsack(wt+1, val+1, n-1, W);
	} else {
		int a = knapsack(wt+1, val+1, n-1, W-wt[0]) + val[0];
		int b = knapsack(wt+1, val+1, n-1, W);
		return max(a, b);
	}
}

int knapsack_mem(int *wt, int *val, int n, int W) {
	int dp[n+1][W+1];
	memset(dp, -1, sizeof(dp));
	if(n == 0 || W == 0) {
		return 0;
	}
	if(dp[n][W] != -1) {
		return dp[n][W];
	}
	if(wt[0] > W) {
		return dp[n][W] =  knapsack_mem(wt+1, val+1, n-1, W);
	} else {
		int a = knapsack_mem(wt+1, val+1, n-1, W-wt[0]) + val[0];
		int b = knapsack_mem(wt+1, val+1, n-1, W);
		return dp[n][W] = max(a, b);
	}
}

int knapsackDP(int *wt, int *val, int n, int W) {
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int j=0;j<=W;j++) {
		dp[0][j] = 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=W;j++) {
			if(wt[i-1] <= j) {
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main() {
	int n, wt[1000], val[1000], W;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>wt[i];
	}
	for(int i=0;i<n;i++) {
		cin>>val[i];
	}
	cin>>W;
	int ans = knapsack(wt, val, n, W);
	cout<<ans;
	cout<<endl;
	int ans1 = knapsackDP(wt, val, n, W);
	cout<<"DP:"<<ans1<<endl;
	int ans2 = knapsack_mem(wt, val, n, W);
	cout<<"Memoization:"<<ans2<<endl;
	return 0;
}
