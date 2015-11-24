///Prims Algorithm


#include<iostream>
#define INF 9999999
using namespace std;

int MinimumQueue(int *Dist,int* Visited,int len)
{
    int minm=INF, in;
    for(int i=0;i<len;i++)
         if(!Visited[i] && Dist[i]<minm)
         minm=Dist[i],in=i;

    return in;
}

bool AllVisited(int *Visited,int V)
{
    for(int i=0;i<V;i++)
        if(!Visited[i])
            return false;
    return true;
}/*
-1 3 4 -1 -1
3 -1 5 6 2
4 5 -1 -1 7
-1 6 -1 -1 -1
-1 2 7 -1 -1
*/
int MyPrimsAlgo(int **MyGraphForPrims,int S,int V)
{
    int *Visited=new int[V];
    int *Dist=new int[V];
    for(int i=0;i<V;i++) Dist[i]=INF, Visited[i]=0;
    Dist[S]=0;
    int sum=0,minm;

    while(!AllVisited(Visited,V))
    {
    minm=MinimumQueue(Dist,Visited,V);

    Visited[minm]=1;
    for(int v=0;v<V;v++)
        if(!Visited[v] && MyGraphForPrims[minm][v]!=-1  && Dist[v]>MyGraphForPrims[minm][v])
            Dist[v]=MyGraphForPrims[minm][v];
    /*cout<<"min= "<<minm<<endl;
    for(int i=0;i<V;i++)
       cout<<Visited[i]<<" "; cout<<endl;
    for(int i=0;i<V;i++)
       cout<<Dist[i]<<" "; cout<<endl;*/

    }

    for(int i=0;i<V;i++)
        sum+=Dist[i];

    return sum;
}

int main()
{

int V,E;

cin>>V>>E;

int **MyGraphForPrims= new int*[V];
for (int i=0; i<V;i++)
    MyGraphForPrims[i]=new int[V];
for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
        MyGraphForPrims[i][j]=-1;

int u,v,w;
for(int i=0;i<E;i++)
    {
    cin>>u>>v>>w;
    MyGraphForPrims[u-1][v-1]=MyGraphForPrims[u-1][v-1]<w && MyGraphForPrims[u-1][v-1]!=-1? MyGraphForPrims[u-1][v-1]:w;
    MyGraphForPrims[v-1][u-1]=MyGraphForPrims[v-1][u-1]<w && MyGraphForPrims[v-1][u-1]!=-1? MyGraphForPrims[v-1][u-1]:w;
    }

/*
for(int i=0;i<V;i++)
{for(int j=0;j<V;j++)
    cout<<MyGraphForPrims[i][j]<<" "; cout<<endl;}*/
int S;
cin>>S;

cout<<MyPrimsAlgo(MyGraphForPrims,S-1,V)<<endl;

return 0;
}





