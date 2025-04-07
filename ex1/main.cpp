//elyasafdnana@gmail.com

#include "graph.h"
#include "ququ.h"
#include "algo.h"

int main() {
  
     
    using namespace graph;
    using namespace ququ;
    using namespace Algorithms;
    

    Graph A= Graph(5);
    A.add(1,2,1);
    A.add(1,3,1);
    A.add(2,3,8);
    A.add(3,4,5);
    A.add(2,4,1);
    cout<<"this is gragh a:"<<endl;
    A.printGraph();
    Graph B=bfs(A,A.getNodeAtIndex(1));
    cout<<"this is bfs on a:"<<endl;
    B.printGraph();

    

    Graph c=DFS(A,A.getNodeAtIndex(1));
    cout<<"this is dfs on A:"<<endl;
    c.printGraph();

    cout<<"this is kruskal on b:"<<endl;

    Graph D=KRUSKAL(B);
    D.printGraph();

   
    

    Graph E= Graph(5);
    E.add(1,4,8);
    E.add(1,2,5);
    E.add(2,3,2);
    E.add(2,4,1);
    E.add(4,3,1);
    cout<<"this is grapgh E:"<<endl;
    E.printGraph();
    cout<<"this is prime on E:"<<endl;
    Graph F=PRIME(E);
    F.printGraph();
    

   
    return 0;
}