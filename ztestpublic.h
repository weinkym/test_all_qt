#ifndef ZTESTPUBLIC_H
#define ZTESTPUBLIC_H
#include <QDebug>
#include <QMap>
#include <QVariant>
#include <QDate>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QTextCodec>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QColor>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QRegExp>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QUuid>

class ZTestPublic
{
public:
    static QString toLink(const QString& src);
    //======================================
    static QString getMacAdress();

private:
    //======================================
    //======================================
    //======================================
    static void addResultMap(const QMap<int,QString> &srcMap,QMap<int,QPair<QString,bool> >&resultMap,bool isLink);
    static void toLinkByRegExp(QMap<int,QString>& srcMap,QMap<int,QString>& linkMap,const QString& rxSrc);
    static void toLinkByRegExp(const QString& src,int startIndex,QMap<int,QString>& srcMap,QMap<int,QString>& linkMap,const QString& rxSrc);
    static QString toHtml(const QPair<QString,bool>& pair);
    //======================================
};

#endif // ZTESTPUBLIC_H
