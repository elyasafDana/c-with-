#README - מטלה 3 - אלגוריתמים על גרפים
מטרת המטלה:
המטלה כוללת מימוש של מספר אלגוריתמים קלאסיים על גרפים, אשר מאפשרים ביצוע סריקות ופתרון בעיות על גרפים מכוונים ובלתי מכוונים. הפונקציות שמיושמות במטלה הן:

BFS (חיפוש ברוחב)

DFS (חיפוש בעומק)

Dijkstra (אלגוריתם לחישוב מסלולים קצרים ביותר)

Prim (חישוב עץ פורש מינימלי)

Kruskal (חישוב עץ פורש מינימלי)

האלגוריתמים מבוצעים על גרפים שמיוצגים באמצעות מחלקות Graph ו-Node, וישנו גם מבנה נתונים נוסף שנקרא Ququ, המשמש לתמיכה באלגוריתמים.

מבנה הקבצים:
הפרויקט כולל את הקבצים הבאים:

README - מטלה 3 - אלגוריתמים על גרפים
מטרת המטלה:
המטלה כוללת מימוש של מספר אלגוריתמים קלאסיים על גרפים, אשר מאפשרים ביצוע סריקות ופתרון בעיות על גרפים מכוונים ובלתי מכוונים. הפונקציות שמיושמות במטלה הן:

BFS (חיפוש ברוחב)

DFS (חיפוש בעומק)

Dijkstra (אלגוריתם לחישוב מסלולים קצרים ביותר)

Prim (חישוב עץ פורש מינימלי)

Kruskal (חישוב עץ פורש מינימלי)

האלגוריתמים מבוצעים על גרפים שמיוצגים באמצעות מחלקות Graph ו-Node, וישנו גם מבנה נתונים נוסף שנקרא Ququ, המשמש לתמיכה באלגוריתמים.

מבנה הקבצים:
הפרויקט כולל את הקבצים הבאים:

graph.h: קובץ המממש את מחלקת Node ואת מחלקת Graph. המחלקה Node מייצגת קודקוד בגרף, והמחלקה Graph מייצגת את הגרף, כולל פונקציות לניהול הקודקודים והצלעות. גרף זה בנוי מקודקודים מסוג Node.

ququ.h: קובץ המממש את מבנה הנתונים Ququ, שהוא תור רגיל (Queue) עם תמיכה במיון, המשמש באלגוריתמים כמו Dijkstra ו-Prim. בנוסף, בקובץ זה יש מימוש של מחלקה נוספת בשם WList, שהיא רשימה המיועדת לאלגוריתמים Dijkstra ו-Prim, ומכילה סוגים שונים של Node.

algo.h: קובץ המממש את האלגוריתמים עצמם (BFS, DFS, Dijkstra, Prim, Kruskal).

main.cpp: קובץ בדיקה (לא כלול בקובץ README).

שימו לב: ייתכן שהבדיקות לא יפעלו כראוי משום שהקובץ doctest לא מזוהה על ידי הטסטר, ולכן לא כל הטסטים רצים בצורה תקינה.
