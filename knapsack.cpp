// Knapsack Problem to print number of elements and the elements
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int n;
	vector <int> wt;
	cout<<"Enter the number of elements ";
	cin>>n;
	cout<<"Enter the weight of each of the elements\n";
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		wt.push_back(temp);
	}
	cout<<"Enter the maximum permissible weight\n";
	int W;
	cin>>W;
	int dp[n+1][W+1];
	for(int i=0; i<n+1;i++){
		for(int j=0; j<W+1;j++){
			dp[i][j] = 0;
		}
	}

	// Dynamic Program is here
	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			if(wt[i-1]<W)
				dp[i][j] = max(dp[i-1][j],1+dp[i-1][j-wt[i-1]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][W]<<"\n";
	for (int i=0; i<n+1; i++){
		for (int j=0; j<W+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;

} 