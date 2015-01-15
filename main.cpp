#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextCodec>
#include <QDebug>
#include <QUuid>
#include "ztestpublic.h"
#include "ztest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec* t = QTextCodec::codecForLocale();
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForCStrings(t);
    QTextCodec::setCodecForLocale(t);
    QTextCodec::setCodecForTr(t);
#else
    QTextCodec::setCodecForLocale(t);
#endif
//    ZTest::test01(a);
//    ZTest::test02(a);
//    ZTest::test03(a);
//    ZTest::test04(a);
 ZTest::test06(a);
}
