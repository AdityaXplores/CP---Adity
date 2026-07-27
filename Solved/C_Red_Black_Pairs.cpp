#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[200001],inf=1000000000;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,c;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>s>>t;
		for(i=0;i<=n;i++)dp[i]=inf;
		dp[0]=0;
		for(i=0;i<n;i++)
		{
			c=0;
			if(s[i]!=t[i])c++;
			dp[i+1]=min(dp[i+1],dp[i]+c);
			if(i<n-1)
			{
				c=0;
				if(s[i]!=s[i+1])c++;
				if(t[i]!=t[i+1])c++;
				dp[i+2]=min(dp[i+2],dp[i]+c);
			}
		}
		cout<<dp[n]<<'\n';
	}
	return 0;
}