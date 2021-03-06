#ifndef ZTEST_H
#define ZTEST_H
#include "ztestpublic.h"

class ZTest
{
public:
    static int test01(QApplication& a);
    static int test02(QApplication& a);
    static int test03(QApplication& a);
    static int test04(QApplication& a);
    static int test05(QApplication& a);
    static int test06(QApplication& a);
    static int test07(QApplication& a);
    static int test08(QApplication& a);


    static QGraphicsView* getView(const QString& text);
    static QString getUrl(const QString& src);

};

#endif // ZTEST_H
