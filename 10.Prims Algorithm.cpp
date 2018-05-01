#include<bits/stdc++.h>
#define max 9999
#define deep 20

using namespace std;
class graph
{
    int n,e,w,i,j,k;
	public :
	    graph()
	    {
	        n=0;
	    }

	int G[10][10] = {{0}};
	void read()
	{
		cout<<"Enter No. of nodes";
		cin>>n;

		cout<<"Enter no. of edges";
		cin>>e;
		cout<<"Enter edges and weight";
		for(k=0;k<e;k++)
		{
		    cin>>i>>j>>w;
		    G[j-1][i-1]=w;
            G[i-1][j-1]=w;
		}
	}

	void print()
	{
	    
		for(int i=0;i<n;i++)
		{

			for(int j=0;j<n;j++)
			{
				cout<<G[i][j]<<"   ";
			}
			cout<<endl;
		}
	}
	int prims(graph &spanning)
	{
	   
		int visited[deep],from[deep],distance[deep];
		int cost[deep][deep];
		int mini;
		int i,j,u,v,min_cost=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(G[i][j]==0)
				{
					cost[i][j]=max;
				}
				else
				{
					cost[i][j]=G[i][j];
				}
				spanning.G[i][j]=0;
				
			}
			
		}
		visited[0]=1;
		distance[0]=0;
		for(i=1;i<n;i++)
		{
			distance[i]=cost[0][i];
			from[i]=0;
			visited[i]=0;
		}
		
		
		int ne=n-1;
		while(ne>0)
		{
			mini=max;
			for(i=1;i<n;i++)
			{
				if(visited[i]==0&&distance[i]<mini)
				{
					v=i;
					mini=distance[i];
				}
			}
			u=from[v];
			spanning.G[u][v]=distance[v];
			spanning.G[v][u]=distance[v];
			ne--;
			visited[v]=1;
			for(i=1;i<n;i++)
			{
				if(visited[i]==0&&distance[i]>cost[v][i])
				{
					distance[i]=cost[v][i];
					from[i]=v;
				}
			}
			min_cost=min_cost+cost[v][u];
		}
		spanning.n=n;
		return(min_cost);

	}
};

int main()
{
	graph g,spanning;

	g.read();
	cout<<"\nADJACENCY MATRIX FOR GRAPH\n";
	g.print();
	int min=g.prims(spanning);
	cout<<"\nadjacency for spanning\n";

	spanning.print();
	cout<<"\n"<<min;
}
/*
example:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0*/
