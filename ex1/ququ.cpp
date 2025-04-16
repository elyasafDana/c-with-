//elyasafdnana@gmail.com


#include "ququ.h"

namespace ququ {

    


    int Ququ::getIndex() {
        return index;
    }

    void Ququ::add(Node* n) {
        if (index == arrSize) {
            arrSize = arrSize * 2;
            Node** tempArr = new Node*[arrSize];
            for (int i = 0; i < index; i++) {
                tempArr[i] = arr[i];
                delete arr[i];
            }
            arr = tempArr;
        }
        arr[index] = n;
        index++;
    }

    Node* Ququ::getFirst() {
        return remove(0);
    }

    bool Ququ::isInside(Node* n) {
        for (int i = 0; i < index; i++) {
            if (arr[i]->getName() == n->getName()) {
                return true;
            }
        }
        return false;
    }

    Node* Ququ::remove(int x) {
        Node* r = arr[x];

        while (x < index && x != arrSize && arr[x] != NULL) {
            arr[x] = NULL;
            arr[x] = arr[x + 1];
            x++;
        }
        if (arr[x] != NULL) {
            arr[x] = NULL;
        }
        index--;

        return r;
    }

    void Ququ::printQ() {
        for (int i = 0; i < index; i++) {
            cout << arr[i]->getName() << endl;
        }
    }

    bool Ququ::isEmpty() {
        if (index == 0) {
            return true;
        }
        return false;
    }

    Node* Ququ::getMin() {
        int minValue=__INT_MAX__;
            Node* min;
            int minIndex=0;
            for (int i = 0; i < index; i++)
            {
                if(arr[i]->getValue()<minValue){
                    minValue=arr[i]->getValue();
                    min=arr[i];
                    minIndex=i;
                }

            }
            
            Node * c=remove(minIndex);
            return c;
    }

   
    WeightNode::WeightNode() : from(NULL), to(NULL), w(0) {}

    WeightNode::WeightNode(Node* v, Node* u, int weight) : from(v), to(u), w(weight) {}

    Node* WeightNode::getFrom() const {
        return from;
    }

    void WeightNode::setFrom(Node* v) {
        from = v;
    }

    Node* WeightNode::getTo() const {
        return to;
    }

    void WeightNode::setTo(Node* u) {
        to = u;
    }

    int WeightNode::getW() const {
        return w;
    }

    void WeightNode::setW(int weight) {
        w = weight;
    }
     

    void WList::resize() {
        capacity *= 2;
        WeightNode** newWeightNodes = new WeightNode*[capacity];
        for (int i = 0; i < size; ++i) {
            newWeightNodes[i] = weightNodes[i];
        }
        delete[] weightNodes;
        weightNodes = newWeightNodes;
    }

    void WList::add(const WeightNode& wn) {
        if (size == capacity) {
            resize();
        }
        weightNodes[size++] = new WeightNode(wn);
    }

    WeightNode* WList::get(int index) {
        if (index >= 0 && index < size) {
            return weightNodes[index];
        }
        throw out_of_range("Index out of range");
    }

    void WList::remove(int index) {
        if (index >= 0 && index < size) {
            delete weightNodes[index];
            for (int i = index; i < size - 1; ++i) {
                weightNodes[i] = weightNodes[i + 1];
            }
            --size;
        } else {
            cout << "Index out of range." << endl;
        }
    }

    void WList::add(Node* from, Node* to, int weight) {
        WeightNode wn(from, to, weight);
        add(wn);
    }

    void WList::print() {
        for (int i = 0; i < size; ++i) {
            cout << "WeightNode " << i << " -> from: " << weightNodes[i]->getFrom()
                 << ", to: " << weightNodes[i]->getTo()
                 << ", weight: " << weightNodes[i]->getW() << endl;
        }
    }

    int WList::getSize() {
        return size;
    }

    void WList::sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (weightNodes[j]->getW() > weightNodes[j + 1]->getW()) {
                    WeightNode* temp = weightNodes[j];
                    weightNodes[j] = weightNodes[j + 1];
                    weightNodes[j + 1] = temp;
                }
            }
        }
    }

}
