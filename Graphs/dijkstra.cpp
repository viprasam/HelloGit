/*
Dijkstra Implementation*/


#include <iostream>

#define MAX 2147483647
#define INF 999999
using namespace std;

int Minimum(int *Dist, int *Visited,int len)
    {
    int min=MAX,index;
    for(int i =0;i<len;i++)
        {
        if(!Visited[i] && Dist[i]<min)
            min=Dist[i],index=i;
        }
    return index;
}

void MyDijkstra(int **MyFirstGraph, int S, int V)
    {

    int *Visited=new int[V];
    //memset(Visited,0,sizeof(int)*V);

    int *Dist=new int[V];
    for(int i=0;i<V;i++) Dist[i]=INF,Visited[i]=0;
    //memset(Dist,INF,sizeof(int)*V);

    Dist[S]=0;


    for(int v=0;v<V;v++)
        {
         int u= Minimum(Dist,Visited,V);

        Visited[u]=1;
        for(int i=0;i<V;i++)
        if(!Visited[i] && MyFirstGraph[u][i]!=INF && MyFirstGraph[u][i] && Dist[i]>Dist[u]+MyFirstGraph[u][i])
            Dist[i]=Dist[u]+MyFirstGraph[u][i];
     }

    for(int s=0;s<V;s++)
        {
        if(s==S) continue;
        if(Dist[s]!=INF)
            cout<<Dist[s]<<" ";
        else cout<<"-1 ";
    }
    cout<<endl;

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
        {
        int V,E;
        cin>>V>>E;
        int **MyFirstGraph=new int*[V];

        for(int i=0;i<V;i++)
            MyFirstGraph[i]=new int[V];

        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                MyFirstGraph[i][j]=0;

        int u,v,w;
        for(int i=0; i<E; i++)
            {
                cin>>u>>v>>w;
                MyFirstGraph[u-1][v-1]=MyFirstGraph[u-1][v-1] && (MyFirstGraph[u-1][v-1]<w) ? MyFirstGraph[u-1][v-1]:w;
                MyFirstGraph[v-1][u-1]=MyFirstGraph[v-1][u-1] && (MyFirstGraph[v-1][u-1]<w )? MyFirstGraph[v-1][u-1]:w;

        }

        int S;
        cin>>S;
        MyDijkstra(MyFirstGraph,S-1,V);

    }

    return 0;
}
