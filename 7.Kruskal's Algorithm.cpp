#include <bits/stdc++.h>
using namespace std;
 class edge
 { public: 
   int s,e,w;
   void in(){
   cout<<"u v weight\n";
   cin>>s>>e>>w;
  }};
edge db[100];
int h[100];
 
int find(int i){
 	 if(h[i]==i)return i;
 	 find(h[i]);}

void merge(int a,int b){
 	h[find(a)]=find(b);}

int krus(int e,int n){
    int i=0,c=0,t=0;
    cout<<"u v cost\n";
	while(c<n-1){
		if(find(db[i].s)!=find(db[i].e)){merge(db[i].s,db[i].e);
		cout<<db[i].s<<" "<<db[i].e<<" "<<db[i].w<<endl;c++;t=t+db[i].w;}
	 	i++;}
     cout<<"total minimum cost - "<<t<<"\n";
           }
bool comp(edge lhs, edge rhs) { return lhs.w < rhs.w; }

int main(){
    	 
	int e=1,i=0,a,d,n;   
	while(e){cout<<"press \n1.to create graph\n2.to add edges in graph\n3.to find min cost\n";
	cin>>e;
	switch(e){
	case 1:i=0;
	       cout<<"write no of cities\n";cin>>n;while(i<=n){h[i]=i;i++;}i=0;
	       cout<<"new graph created\n"; break;		
	case 2:cout<<"write no of edges(link between cities) to add\n";cin>>a;
          if(a<n-1)cout<<"MST not possible\n";
	      else{
	       d=0;
	       while(d<a){
	       db[i].in();
		   d++;i++;
		   }}
	       break;		
	case 3:sort(db,db+i,comp);krus(i,n);break;
	}}return 0;
}


