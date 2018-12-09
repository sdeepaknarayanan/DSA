// The longest contiguous subarray problem 

#include<iostream> 
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    vector <int> v;
    cout<<" Enter the number of elements in the array ";
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=0; i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    vector <int> dp(n);
    dp[0] = v[0];
    for (int i=1; i<n; i++){
        if(dp[i-1]<0){
            dp[i] = v[i];
        }
        else{
            dp[i] = dp[i-1] + v[i];
        }
    }
    int max1 = dp[0];
    for(int i=1; i<n;i++){
        max1 = max(dp[i],max1);
    }
    cout<<" The maximum sum is "<<max1;
    return 0;
}
