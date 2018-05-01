#include<bits/stdc++.h>
using namespace std;
class dijkstra
{
	int adj[20][20],dis[20],no_of_visited_nodes,n,m;
	bool visit[20];
public:
	dijkstra()
	{
		no_of_visited_nodes=0;
		for(int i=1;i<20;i++)
		{
			visit[i]=false;
			dis[i]=10000009;
			for(int j=1;j<20;j++)
				adj[i][j]=100000009;
		}

	}
	void insert()
	{
		int a,b,c;
		cout<<"\nEnter No. Of Nodes";
		cin>>n;
		cout<<"\nEnter No. Of Edges ";
		cin>>m;
		cout<<"\nEnter Edges ";
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			adj[a][b]=c;
			adj[b][a]=c;
		}
	}

	void calculate()
	{
		int s,p;
		cout<<"\nEnter Source Node ";
		cin>>s;
		dis[s]=0;

		while(no_of_visited_nodes!=n)
		{
			int mi=10000009;
			visit[s]=true;
			no_of_visited_nodes++;
			for(int i=1;i<=n;i++)
			{
				if(visit[i]==false)
				{
					dis[i]=min(dis[i],dis[s]+adj[s][i]);
					//cout<<adj[s][i]<<" "<<dis[i]<<" ";
					if(mi>dis[i])
					{
						p=i;
						mi=dis[i];
						//cout<<"a";
					}
				}
			}
			s=p;
			//cout<<" "<<s;
			//cout<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			cout<<dis[i]<<" ";
		}
	}
};

int main()
{
	dijkstra ob;
	ob.insert();
	ob.calculate();
	return 0;
}
