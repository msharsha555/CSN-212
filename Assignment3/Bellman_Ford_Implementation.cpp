#include <iostream>
#include <limits.h>
#include <time.h>
using namespace std;
//Code is not written for creating a graph.
//Graph is treated abstract since we know the edges and their association from the input.
struct edge
{
	int src,des,wt;
};
void Bellman(int v,int e,edge* ed)
{
	int dis[v];dis[0]=0;
	for(int i=1;i<v;i++) dis[i]=INT_MAX;int k=v-1;
	while(k--)
	{
		
		for(int j=0;j<e;j++)
			{
				if(dis[ed[j].src]!=INT_MAX) 
					{
							if(ed[j].wt+dis[ed[j].src]<dis[ed[j].des])
							  		dis[ed[j].des]=ed[j].wt+dis[ed[j].src];
					}
			}
	}
	
	int flag=0;
	//Check if the graph has a negative cycle.
	for(int i=0;i<e;i++)
		if(dis[ed[i].src]+ed[i].wt<dis[ed[i].des] && dis[ed[i].src]!= INT_MAX)	
			{flag=1;break;}
	
	if(flag)	
		
		cout<<"Graph contains negative cycles"<<endl;
	else 
		{	
			cout<<"Optimal Answer is ";
			
			for(int i=0;i<v;i++) 
				cout<<dis[i]<<" ";
			
			cout<<endl;
		}

}
int main() 
{clock_t tStart = clock();
int v,e;cin>>v>>e;
edge* ed= new edge[e];
for(int i=0;i<e;i++) 
	cin>>ed[i].src>>ed[i].des>>ed[i].wt;
Bellman(v,e,ed);
cout<<"Exec_Time : "<<(double)(clock() - tStart)/CLOCKS_PER_SEC;
// your code goes here
	return 0;
}
