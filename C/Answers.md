# שאלה 9

נרוויח פר מחשב 0.00004387 BTC	בחודש (רק בהתחשב בסוג המעבד - https://www.betterhash.net/Intel(R)-Core(TM)-i5-6500-CPU-@-3.20GHz-mining-profitability-434926.html ). 
אם ישנם 26 מחשבים משמע נרוויח 0.00114062 BTC בחודש, שהם 28.34$ בחודש (0.944$ ביום בממוצע) , שהם 101.28 ש"ח בחודש (3.376 ש"ח ביום). כל זאת כמובן בהנחה שהם לא משומשים באף צורה אחרת, מתוחזקים בצורה שוטפת, ובלי להתחשב בעלות החשמל שדרוש לתפקוד המחשבים.

# שאלה 10

**עשרה דברים שרוני אלרגית אליהם:**
- דשא
- בוטנים
- אבוקדו
- מונסודיום גלוטומט
- קיווי
- אגוזי מלך
- פקאנים
- אבקנים (חילופי עונות)
- אבק
- שקדים(?)

**בונוס:**
- בוקר ("אני אלרגית לבוקר!!!" ~רוני בבוקר של אימון בשבוע של ה19/2)
- היביסקוס (מאחרי הפריסה של דרור)
-

# שאלה 11 

הפונקציה sizeof() מחזירה מספר המייצג את כמות הזיכרון שהוקצבה לארגומנט שנשלח הפונקציה. שפת C מחשבת כמות זיכרון לפי size_t: קבוע מסוג unsigned int שמוגדר בשלל קבצי header (stdio.h,stdlib.h,string.h). 

הפונקציה strlen() מחזירה את אורכה של המחרוזת שנשלחה כארגומנט לפונקציה. הפונקציה תחזיר שגיאה במידה והארגומנט היה מטיפוס שונה ממחרוזת. גודלה של המחרוזת יהיה אורך המחרוזת, פלוס אחד (size_t).

הסיבה לכך שגודלה של מחרוזת יהיה תמיד גדול ב-1 מאורכה היא מכיוון שהתו '0\' נוסף באופן דיפולטי לסוף של מחרוזות בC בכדי שנדע מתי המחרוזת נגמרת. כל מחרוזת מכיוון שגודלו של תו (char) בC הוא 1, ומחרוזת היא מערך של תווים, התו '0\' גם תופס מקום בזיכרון ולכן strlen(s) + 1 = sizeof(s). 

