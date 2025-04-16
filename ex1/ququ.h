//elyasafdnana@gmail.com


#ifndef QUQU_H
#define QUQU_H

#include "graph.h"

namespace ququ {

    using namespace graph;

    
    class Ququ {
    private:
        Node** arr;
        int index;
        int arrSize;

    public:
    Ququ(const Ququ& other) {
        arrSize = other.arrSize;
        index = other.index;
        arr = new Node*[arrSize];  // הקצה מערך חדש

        for (int i = 0; i < index; i++) {
            arr[i] = new Node(*other.arr[i]);  // העתקה של כל Node
        }
    }

    // Operator= (אופרטור השמה)
    Ququ& operator=(const Ququ& other) {
        if (this != &other) {  // מניעת השמה עצמית
            // שחרור הזיכרון הקודם
            for (int i = 0; i < index; i++) {
                delete arr[i];
            }
            delete[] arr;

            // ביצוע העתקה חדשה
            arrSize = other.arrSize;
            index = other.index;
            arr = new Node*[arrSize];

            for (int i = 0; i < index; i++) {
                arr[i] = new Node(*other.arr[i]);  // העתקה של כל Node
            }
        }
        return *this;
    }

    
        Ququ() {
            arr = new Node*[5];
            index = 0;
            arrSize = 5;
        }
    
        Ququ(Node* n) {
            arr = new Node*[5];
            index = 1;
            arr[0] = n;
            arrSize = 5;
        }
        
        ~Ququ() {
        
                
            delete[] arr;   
        }
            
        
        int getIndex();
        void add(Node* n);
        Node* getFirst();
        bool isInside(Node* n);
        Node* remove(int x);
        void printQ();
        bool isEmpty();
        Node* getMin();
    };

    
    class WeightNode {
    private:
        Node* from;
        Node* to;
        int w;

    public:
        WeightNode();
        WeightNode(Node* v, Node* u, int weight);
        Node* getFrom() const;
        void setFrom(Node* v);
        Node* getTo() const;
        void setTo(Node* u);
        int getW() const;
        void setW(int weight);
    };

    
    class WList {
    private:
        WeightNode** weightNodes;
        int capacity;
        int size;

        void resize();

    public:
        
        WList() : capacity(2), size(0) {
            weightNodes = new WeightNode*[capacity];
        }
        
        ~WList() {
            
            for (int i = 0; i < size; ++i) {
                delete weightNodes[i];
            }
                
            delete[] weightNodes;
        }
        
        void add(const WeightNode& wn);
        WeightNode* get(int index);
        void remove(int index);
        void add(Node* from, Node* to, int weight);
        void print();
        int getSize();
        void sort();
    };

}

#endif // QUQU_H
