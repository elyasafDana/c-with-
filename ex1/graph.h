//elyasafdnana@gmail.com


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

namespace graph {

class Node {
private:
    int name;
    bool white;
    int index;
    int* weight;
    Node** son;
    int value;

public:
Node() {
    weight = NULL;
    son = NULL;
    index = 0;
    name = 0;
    value = __INT_MAX__;
    white = true;
}

~Node() {
    delete[] weight;
    delete[] son;
}
    
    void setNode(int length, int id);
    int getNumOfSons();
    int getName();
    Node** getSons();
    int* getWeight();
    int getValue();
    bool isWhite();
    void setColor(bool color);
    void setValue(int v);
    void addSon(Node* v, int w);
    void addSon(Node* v);
    bool isSonExist(Node* n);
    bool delSon(Node* v);
    void printNode();
};

class Graph {
private:
    Node* arr;
    const int num;

public:
    //Graph(int x);
    Graph(int x) : num(x) {
        arr = new Node[x];
        for (int i = 0; i < x; i++) {
            arr[i].setNode(x, i);
        }
    }
    /*
    ~Graph() {
        delete[] arr;
    }
      */
    void add(int v, int u, int w);
    void add(int v, int u);
    
    void del(int v, int u);
    void printGraph();
    int getNumOfNode();
    Node* getNodeAtIndex(int index);
};

} // namespace graph

#endif // GRAPH_H