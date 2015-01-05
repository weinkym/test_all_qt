#include "ztest.h"
#include "mainwindow.h"

int ZTest::test01(QApplication &a)
{
    MainWindow w;
    w.show();
    return a.exec();
}

int ZTest::test02(QApplication &a)
{
    qDebug()<<"QUuid = "<<QUuid::createUuid().toString();
    ZTestPublic::getMacAdress();
    return -2;
}

int ZTest::test03(QApplication &a)
{
    QString src = "asdhttp://regxlib.com/Default.aspx | http://electron@ics.cnet.com/electronics/0sdfas.html  www@qq.comS  SDF www.baidu.com adsf www.blah.com:8103 | www.blah.com/blah.asp?sort=ASC |www.blah.com/blah.htm#blah";
    QString newSrc = ZTestPublic::toLink(src);
    qDebug()<<"newSrc = "<<newSrc;
    return -3;
}

int ZTest::test04(QApplication &a)
{
    QString src("www.baidu.com adsf http://baike.baidu.com/link?url=b_ChetrN8n5010KUsyV0u3Pn-LvfduYqbEVBcehL8QmADXO6ABDfXaZFSBmz65Ooz4Ieh_Q3PFl4JV_zCNjr4K");
    QString text = getUrl(src);
    QGraphicsView* view =ZTest::getView(text);
    view->show();
    return a.exec();
}

int ZTest::test05(QApplication &a)
{
    ZTextEdit dlg;
    dlg.show();
    return a.exec();
}

QGraphicsView *ZTest::getView(const QString &text)
{
    QGraphicsView* view = new QGraphicsView;
    QGraphicsScene* scene = new QGraphicsScene;
    view->setScene(scene);
    int height = 0;
    int dY = 30;
    //    QString text = "<body>‘⁄”“¥∞ø⁄œ‘ ættttttttt<a href=www.baidu.com><font color=red>www.baidu.com</font></a></body>";
    {
        QGraphicsTextItem* textItem = scene->addText(text) ;
        textItem->setHtml(text);
        textItem->setTextInteractionFlags(Qt::TextBrowserInteraction);
        textItem->setPos(0,height);
        textItem->setFlags(QGraphicsItem::ItemIsFocusable);
        textItem->setOpenExternalLinks(true);
        height += dY;
    }
    {
        QGraphicsTextItem* textItem = scene->addText(text) ;
        textItem->setHtml(text);
        //        textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
        textItem->setPos(0,height);
        textItem->setOpenExternalLinks(true);
        height += dY;
    }
    return view;
}

QString ZTest::getUrl(const QString &src)
{
    QRegExp rx("(((http|ftp|https)://)|(www\\.))+([\\S]+\\.)+([a-zA-Z0-9]{2,6})+(:[0-9]{1,4})*(/[a-zA-Z0-9\&%_\\./-~-]*)*");
    //    QRegExp rx("");
    int pos=src.indexOf(rx);
    qDebug()<< "pos = "<<pos;
    QString result;
    while(pos>=0)
    {
        QString cap = rx.cap(0);
        result.append(cap).append("     ");
        qDebug()<<"cap = "<<rx.cap(0);
        int len = rx.matchedLength();
        qDebug()<<"len = "<<len;
        pos += rx.matchedLength();
        pos=src.indexOf(rx,pos);
    }
    return result;
}
