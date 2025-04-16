
#include "ququ.h"
#include "graph.h"
#include "algo.h"

namespace Algorithms{
    using namespace graph;
    using namespace ququ;
    using namespace std;

    Graph bfs(Graph g,Node* n){
        Graph rg= Graph(g.getNumOfNode());
        Ququ q= Ququ();
        for (int  i = 0; i <g.getNumOfNode() ; i++)
        {

            g.getNodeAtIndex(i)->setColor(true);
        }
        g.getNodeAtIndex(n->getName())->setColor(false);
        q.add(g.getNodeAtIndex(n->getName()));

        while (!q.isEmpty())
        {
          
            Node* n= q.getFirst();
           
            Node** sons=n->getSons();
            for (int i = 0; i < n->getNumOfSons(); i++)
            {
                if (sons[i]->isWhite())
                {
                    rg.add(n->getName(),sons[i]->getName());
                    sons[i]->setColor(false);
                    q.add(sons[i]);
                }
            }
            
        }
        
        return rg;
    }

    void dfsVISIT(Node* n,Graph* rg){

        n->setColor(false);

        Node** sons=n->getSons();
        for (int i = 0; i < n->getNumOfSons(); i++)
        {
            if (sons[i]->isWhite())
            {
                rg->add(n->getName(),sons[i]->getName());
                dfsVISIT(sons[i],rg);
            }
            sons[i]->setColor(false);
        }
        
    } 
    Graph DFS(Graph g,Node* n){
        
        for (int  i = 0; i <g.getNumOfNode() ; i++)
        {
            g.getNodeAtIndex(i)->setColor(true);
        }
        Graph rg=Graph(g.getNumOfNode());
        Node** sons=n->getSons();
        

        bool isFirst=true;
        for (int i = n->getName(); i < g.getNumOfNode(); i++)
        {
            if (g.getNodeAtIndex(n->getName())->isWhite())
            {
               

                dfsVISIT(g.getNodeAtIndex(i),&rg);
                
            }
            
        }
        
        return rg;


    }

    Graph DIKSTRA(Graph& g,Node* n){
        Ququ q=  Ququ();
        for(int i=0;i<g.getNumOfNode();i++){
            g.getNodeAtIndex(i)->setValue(__INT_MAX__);
        }
        g.getNodeAtIndex(n->getName())->setValue(0);
        for(int i=0;i<g.getNumOfNode();i++){
        q.add(g.getNodeAtIndex(i));
        }
        

        while(!q.isEmpty()){
            Node * temp=q.getMin();
            Node** sons=temp->getSons();
            int * w=temp->getWeight();
            for(int i=0;i<temp->getNumOfSons();i++){
                if(w[i]+temp->getValue()<sons[i]->getValue()){
                    sons[i]->setValue(w[i]+temp->getValue());
                }
            }
        }
        
        
        return g;
        }


        Graph PRIME(Graph g){
            Graph rg= Graph(g.getNumOfNode());
            Ququ q= Ququ();
            for (int i = 0; i < g.getNumOfNode(); i++)
            {
                q.add(g.getNodeAtIndex(i));
            }
            g.getNodeAtIndex(1)->setValue(0);

            while (!q.isEmpty())
            {
                Node* n=q.getMin();
                Node** sons=n->getSons();
                int* w=n->getWeight();

                for (int i = 0; i < n->getNumOfSons(); i++)
                {
                    if(q.isInside(sons[i]) &&w[i]<sons[i]->getValue()){
                        if(rg.getNodeAtIndex(sons[i]->getName())->getNumOfSons() ==1){
                            Node** granson=rg.getNodeAtIndex(sons[i]->getName())->getSons();
                            rg.del(sons[i]->getName(),granson[0]->getName());
                        }
                        rg.add(sons[i]->getName(),n->getName());
                        sons[i]->setValue(w[i]);
                    }
                }
             
                
            }
            

            return rg;
            
            

        }

        bool canReach(Graph g,int from, int to){
            
           
            Ququ q= Ququ();
        for (int  i = 0; i <g.getNumOfNode() ; i++)
        {

            g.getNodeAtIndex(i)->setColor(true);

        }
        
        g.getNodeAtIndex(from)->setColor(false);
        q.add(g.getNodeAtIndex(from));

        while (!q.isEmpty())
        {
            
            Node* n= q.getFirst();
        
            Node** sons=n->getSons();
            for (int i = 0; i < n->getNumOfSons(); i++)
            {
                

                if (sons[i]->isWhite())
                {
                    
                    if (sons[i]->getName()==to)
                    {
                        return true;
                    }
                    
                    
                    sons[i]->setColor(false);
                    q.add(sons[i]);
                }
            }
            
        }
        return false;

        }

        Graph KRUSKAL(Graph g){

            WList q=WList();
            for (int i = 0; i <g.getNumOfNode(); i++)
            {
                Node * n=g.getNodeAtIndex(i);
                Node** sons=n->getSons();
                int* w=n->getWeight();
                for (int j = 0; j < n->getNumOfSons(); j++)
                {
                    q.add(n,sons[j],w[j]);
                }
            }

            q.sort();
             Graph rg= Graph(g.getNumOfNode());
            
             for (int i = 0; i < q.getSize(); i++)
             {
                WeightNode* n=q.get(i);
                for (int  i = 0; i <g.getNumOfNode() ; i++)
        {

            rg.getNodeAtIndex(i)->setColor(true);

        }
                if (! canReach(rg,n->getFrom()->getName(),n->getTo()->getName()))
             {
                
                rg.add(n->getFrom()->getName(),n->getTo()->getName(),n->getW());
                
             }
             
                
                
             }

             return rg;
        }



    

    

};