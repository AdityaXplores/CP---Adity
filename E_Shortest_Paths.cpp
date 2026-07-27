#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long d[105][105];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=(i==j?0:INF);
	int m;
	cin>>m;
	while(m--)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
		d[v][u]=min(d[v][u],w);
	}
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=2;i<=n;i++)
		if(d[1][i]==INF)
			cout<<"-1\n";
		else
			cout<<d[1][i]<<'\n';
    return 0;
}