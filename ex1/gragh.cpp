#include "graph.h"

namespace graph {




void Node::setNode(int length, int id) {
    weight = new int[length];
    son = new Node*[length];
    name = id;
    white = true;
    index = 0;
}

int Node::getNumOfSons() {
    return index;
}

int Node::getName() {
    return name;
}

Node** Node::getSons() {
    return son;
}

int* Node::getWeight() {
    return weight;
}

int Node::getValue() {
    return value;
}

bool Node::isWhite() {
    return white;
}

void Node::setColor(bool color) {
    white = color;
}

void Node::setValue(int v) {
    value = v;
}

void Node::addSon(Node* v, int w) {
    if (v==nullptr) cout<<"not legal"<<endl;
    if (v->getName() != name && !isSonExist(v)) {
        son[index] = v;
        weight[index] = w;
        index++;
    } else {
        cout << "Node already exists" << endl;
    }
}

void Node::addSon(Node* v) {
    if (v==nullptr) cout<<"not legal"<<endl;
    if (v->getName() != name && !isSonExist(v)) {
        son[index] = v;
        weight[index] = 1;
        index++;
    } else {
        cout << "Node already exists" << endl;
    }
}

bool Node::isSonExist(Node* n) {
    if (n==NULL) cout<<"not legal"<<endl;
    for (int i = 0; i < index; i++) {
        if (son[i]->getName() == n->getName()) {
            return true;
        }
    }
    return false;
}

bool Node::delSon(Node* v) {
    if (v==nullptr) cout<<"not legal"<<endl;
    int delNum = v->getName();
    bool found = false;
    for (int i = 0; i < index; i++) {
        if (son[i]->getName() == delNum) {
            found = true;
            son[i] = NULL;
            weight[i] = 0;
            while (i < index) {
                son[i] = son[i + 1];
                weight[i] = weight[i + 1];
                i++;
            }
            index--;
        }
    }
    if (!found) {
        cout << "Couldn't find such son" << endl;
        return false;
    }
    return true;
}

void Node::printNode() {
    for (int i = 0; i < index; i++) {
        cout << "," << son[i]->getName() << ",";
    }
}



void Graph::add(int v, int u, int w) {
    if (v>num || u>num || v<0 || u<0)
            {
                cout<<"ileagal"<<endl;
                return;
            }
    arr[v].addSon(&arr[u], w);
    arr[u].addSon(&arr[v], w);
}

void Graph::add(int v, int u) {
    if (v>num || u>num || v<0 || u<0)
            {
                cout<<"ileagal"<<endl;
                return;
            }
    arr[v].addSon(&arr[u], 1);
    arr[u].addSon(&arr[v], 1);
}

void Graph::del(int v, int u) {
    if (v>num || u>num || v<0 || u<0)
            {
                cout<<"ileagal"<<endl;
                return;
            }
    arr[v].delSon(&arr[u]);
    arr[u].delSon(&arr[v]);
}

void Graph::printGraph() {
    for (int i = 0; i < num; i++) {
        cout << i << ":";
        arr[i].printNode();
        cout << endl;
    }
}

int Graph::getNumOfNode() {
    return num;
}

Node* Graph::getNodeAtIndex(int index) {
    return &arr[index];
}

} // namespace graph
