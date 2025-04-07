//elyasafdnana@gmail.com

#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "algo.h"  // כלול את קובץ הקוד שלך (אם זה מתאים)
#include "ququ.h"
#include "graph.h"
using namespace graph;
using namespace Algorithms;
using namespace ququ;

TEST_CASE("Node addSon and delSon") {
    Node n1, n2, n3;
    n1.setNode(3, 1);
    n2.setNode(3, 2);
    n3.setNode(3, 3);

    // הוספת ילדים ל-n1
    n1.addSon(&n2, 5);
    n1.addSon(&n3, 3);

    // בדיקה שהוספו ילדים
    CHECK(n1.getNumOfSons() == 2);  // ל-n1 יש 2 ילדים
    CHECK(n1.getSons()[0]->getName() == 2);  // הילד הראשון הוא n2
    CHECK(n1.getSons()[1]->getName() == 3);  // הילד השני הוא n3

    // מחיקת ילד
    bool removed = n1.delSon(&n2);
    CHECK(removed == true);         // הילד n2 אמור להימחק
    CHECK(n1.getNumOfSons() == 1);  // ל-n1 נשאר ילד אחד (n3)
    CHECK(n1.getSons()[0]->getName() == 3);  // הילד שנותר הוא n3

    // נסיון למחוק ילד שלא קיים
    removed = n1.delSon(&n2);
    CHECK(removed == false);        // לא הצלחנו למחוק את n2 שוב
}

TEST_CASE("Graph class") {
    Graph g(5); // יצירת גרף עם 5 נודים

    // בדיקה שהגרף מכיל את כל הנודים
    CHECK(g.getNumOfNode() == 5);

    // הוספת קשתות
    g.add(0, 1, 10);  // הוספת קשת בין n0 ל-n1 עם משקל 10
    g.add(1, 2, 20);  // הוספת קשת בין n1 ל-n2 עם משקל 20
    g.add(3, 4, 30);  // הוספת קשת בין n3 ל-n4 עם משקל 30

    // בדיקה של הקשתות בגרף
    Node* node0 = g.getNodeAtIndex(0);
    CHECK(node0->getNumOfSons() == 1);  // ל-n0 יש ילד אחד (n1)
    CHECK(node0->getSons()[0]->getName() == 1);  // הילד הראשון הוא n1

    Node* node1 = g.getNodeAtIndex(1);
    CHECK(node1->getNumOfSons() == 2);  // ל-n1 יש 2 ילדים (n0, n2)
    CHECK(node1->getSons()[0]->getName() == 0);  // הילד הראשון הוא n0
    CHECK(node1->getSons()[1]->getName() == 2);  // הילד השני הוא n2

    // בדיקה של משקל הקשתות
    CHECK(node0->getWeight()[0] == 10);  // משקל הקשת בין n0 ל-n1 הוא 10
    CHECK(node1->getWeight()[1] == 20);  // משקל הקשת בין n1 ל-n2 הוא 20

    // מחיקת קשת
    g.del(0, 1);  // מחיקת הקשת בין n0 ל-n1
    CHECK(node0->getNumOfSons() == 0);  // עכשיו ל-n0 אין ילדים
    CHECK(node1->getNumOfSons() == 1);  // ל-n1 נשאר ילד אחד (n2)
}






TEST_CASE("Ququ class") {
    // יצירת Ququ
    Ququ q;
    CHECK(q.getIndex() == 0);  // לא הוספו נודים, אינדקס הוא 0

    // יצירת נוד
    Node n1, n2, n3;
    n1.setNode(3, 1);
    n2.setNode(3, 2);
    n3.setNode(3, 3);

    // הוספת נוד ל-Ququ
    q.add(&n1);
    CHECK(q.getIndex() == 1);  // הוספנו נוד אחד

    q.add(&n2);
    CHECK(q.getIndex() == 2);  // הוספנו נוד שני

    q.add(&n3);
    CHECK(q.getIndex() == 3);  // הוספנו נוד שלישי

    // בדיקה אם נוד קיים ב-Ququ
    CHECK(q.isInside(&n1) == true);  // n1 אמור להיות בתוך ה-Ququ
    CHECK(q.isInside(&n2) == true);  // n2 אמור להיות בתוך ה-Ququ
    CHECK(q.isInside(&n3) == true);  // n3 אמור להיות בתוך ה-Ququ

    // בדיקה של פונקציית getFirst
    Node* first = q.getFirst();
    CHECK(first->getName() == 1);  // first צריך להיות n1

    // בדיקה של פונקציית isEmpty
    CHECK(q.isEmpty() == false);  // Ququ לא ריק

    // מחיקת נוד
    Node* removed = q.remove(0);
    CHECK(removed->getName() == 1);  // n1 אמור להימחק
    CHECK(q.getIndex() == 2);  // עכשיו יש 2 נודים ב-Ququ

    // בדיקה אחרי מחיקה אם נוד קיים
    CHECK(q.isInside(&n1) == false);  // n1 לא אמור להיות בתוך ה-Ququ אחרי המחיקה
}

TEST_CASE("Ququ class - getMin") {
    // יצירת Ququ
    Ququ q;

    // יצירת נודים עם ערכים שונים
    Node n1, n2, n3;
    n1.setNode(3, 1);
    n1.setValue(10);  // n1 עם ערך 10
    n2.setNode(3, 2);
    n2.setValue(5);   // n2 עם ערך 5
    n3.setNode(3, 3);
    n3.setValue(7);   // n3 עם ערך 7

    // הוספת נודים ל-Ququ
    q.add(&n1);
    q.add(&n2);
    q.add(&n3);

    // בדיקה של getMin
    Node* minNode = q.getMin();
    CHECK(minNode->getName() == 2);  // n2 אמור להיות הנוד עם הערך הכי קטן (5)
    CHECK(q.getIndex() == 2);  // אחרי הוצאת ה-min, נשארו 2 נודים
}

TEST_CASE("WeightNode class") {
    // יצירת WeightNode
    Node n1, n2;
    n1.setNode(3, 1);
    n2.setNode(3, 2);

    WeightNode wn(&n1, &n2, 15);  // יצירת WeightNode עם משקל 15

    CHECK(wn.getFrom()->getName() == 1);  // מקור של WeightNode צריך להיות n1
    CHECK(wn.getTo()->getName() == 2);    // יעד של WeightNode צריך להיות n2
    CHECK(wn.getW() == 15);  // המשקל של WeightNode צריך להיות 15
}

TEST_CASE("WList class") {
    // יצירת WList
    WList wList;

    // יצירת נודים
    Node n1, n2;
    n1.setNode(3, 1);
    n2.setNode(3, 2);

    // יצירת WeightNode
    WeightNode wn(&n1, &n2, 10);

    // הוספת WeightNode ל-WList
    wList.add(wn);
    CHECK(wList.getSize() == 1);  // עכשיו יש אחד ב-WList

    // הוספת עוד WeightNode
    WeightNode wn2(&n2, &n1, 5);
    wList.add(wn2);
    CHECK(wList.getSize() == 2);  // עכשיו יש שניים ב-WList

    // בדיקה של הסרת WeightNode
    wList.remove(0);
    CHECK(wList.getSize() == 1);  // אחרי מחיקת WeightNode אחד, נשאר אחד ב-WList

    // הוספת מספר WeightNodes
    WeightNode wn3(&n1, &n2, 20);
    WeightNode wn4(&n2, &n1, 25);
    wList.add(wn3);
    wList.add(wn4);
    CHECK(wList.getSize() == 3);  // אחרי הוספת WeightNodes חדשים, יש 3 ב-WList

    // בדיקה של מיון WeightNodes
    wList.sort();
    CHECK(wList.get(0)->getW() == 5);  // המשקל הקטן ביותר הוא 5
    CHECK(wList.get(1)->getW() == 10); // המשקל הבא אחרי 5 הוא 10
    CHECK(wList.get(2)->getW() == 20); // המשקל הגדול ביותר הוא 20
}

