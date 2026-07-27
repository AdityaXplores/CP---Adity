#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2,v3,v6;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,a;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a%6==0)v6.push_back(a);
			else if(a%2==0)v2.push_back(a);
			else if(a%3==0)v3.push_back(a);
			else v1.push_back(a);
		}
		for(i=0;i<v6.size();i++)cout<<v6[i]<<' ';
		for(i=0;i<v3.size();i++)cout<<v3[i]<<' ';
		for(i=0;i<v1.size();i++)cout<<v1[i]<<' ';
		for(i=0;i<v2.size();i++)cout<<v2[i]<<' ';
		cout<<'\n';
		v1.clear();
		v2.clear();
		v3.clear();
		v6.clear();
	}
	return 0;
}