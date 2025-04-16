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

    
    Graph G= Graph(5);
    G.add(1,2,1);
    G.add(1,3,1);
    G.add(2,3,8);
    G.add(3,4,5);
    G.add(2,4,1);
    Graph c=DFS(G,G.getNodeAtIndex(1));
    cout<<"this is dfs on A:"<<endl;
    c.printGraph();

    cout<<"this is kruskal on b:"<<endl;

    Graph f= Graph(5);
    f.add(0,1,8);
    f.add(0,2,1);
    f.add(1,2,1);
    f.add(1,3,2);
    f.add(2,3,1);

    Graph D=KRUSKAL(f);
    
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



    

    cout<<"this is DIKSTRA on E:"<<endl;

    Graph K= DIKSTRA(E,E.getNodeAtIndex(1));
    for(int i=0;i<K.getNumOfNode();i++){
        cout<<K.getNodeAtIndex(i)->getName()<<": "<<K.getNodeAtIndex(i)->getValue()<<endl;
    }
    



    

   
    return 0;
}