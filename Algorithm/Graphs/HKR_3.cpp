/*
*
*
floyd warshal
*
*/

#include<iostream>

using namespace std;
/*
4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4
*/

int main()
{
int V,E;

cin>>V>>E;

int **MyGraphFloyd=new int*[V];
for(int i=0;i<V;i++)
    MyGraphFloyd[i]=new int[V];
for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
        if(i!=j) MyGraphFloyd[i][j]=INF;
            else MyGraphFloyd[i][j]=0;

int u,v,w;
for(int i=0;i<E;i++)
    {
    cin>>u>>v>>w;
    MyGraphFloyd[u-1][v-1]=w;
    }

for(int k=0; k<V;k++)
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(MyGraphFloyd[i][j]>MyGraphFloyd[i][k]+MyGraphFloyd[k][j])
                MyGraphFloyd[i][j]=MyGraphFloyd[i][k]+MyGraphFloyd[k][j];

int Q;
cin>>Q;

for(int i=0;i<Q;i++)
{
    cin>>u>>v;
    cout<<(MyGraphFloyd[u-1][v-1]!=INF? MyGraphFloyd[u-1][v-1]:-1)<<endl;

}
return 0;
}
