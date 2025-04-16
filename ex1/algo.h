//elyasafdnana@gmail.com
#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include "graph.h"  // כולל את הקובץ שמכיל את מחלקת Node ו-Graph
#include "ququ.h"  // כולל את מחלקות Ququ, WeightNode, WList אם נחוץ

namespace Algorithms {
    using namespace graph;

    // פונקציה המבצעת חיפוש BFS על הגרף
    Graph bfs(Graph g, Node* n);

    // פונקציה המבצעת חיפוש DFS על הגרף
    void dfsVISIT(Node* n, Graph* rg);

    // פונקציה המייצרת גרף בעזרת חיפוש DFS
    Graph DFS(Graph g, Node* n);

    // אלגוריתם דייקסטרה למציאת הדרך הקצרה ביותר מגרף
    Graph DIKSTRA(Graph& g, Node* n);

    // אלגוריתם פרים למציאת המינימום העץ המתחבר
    Graph PRIME(Graph g);

    // פונקציה שבודקת אם יש נתיב בין שני צמתים בגרף
    bool canReach(Graph g, int from, int to);

    // אלגוריתם קרוסקאל למציאת עץ פרישה מינימלי (MST)
    Graph KRUSKAL(Graph g);
};

#endif // GRAPH_ALGORITHMS_H
