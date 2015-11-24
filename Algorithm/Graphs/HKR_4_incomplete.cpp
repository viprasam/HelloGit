///Kruskhal

#include<iostream>

using namespace std;

/*
4 6
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5
1
*/
struct EdgeArray{
    int src;
    int dest;
    int w;
};

int main()
{

int V,E;
cin>>V>>E;
int **MyGraphKruskal= new int*[V];
for(int i=0;i<V;i++)
    MyGraphKruskal[i]=new int[V];
for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
        MyGraphKruskal[i][j]=0;

EdgeArray *Edge=new EdgeArray[E];
for(int i=0;i<E;i++)
    Edge.dest[i]=0,Edge.src[i]=0,Edge.w[i]=0;




return 0;
}
