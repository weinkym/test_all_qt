#include "ztestpublic.h"


QString ZTestPublic::toLink(const QString &src)
{
    QMap<int,QString> srcMap;
    srcMap.insert(0,src);
    QMap<int,QString> linkMap;
    QStringList rxList;
    rxList.append("(((http|ftp|https)://)|(www\\.))+([\\S]+\\.)+([a-zA-Z0-9]{2,6})+(:[0-9]{1,4})*(/[\\S]*)*");
//    rxList.append("(http|ftp|https):\/\/[\w\-_]+(\.[\w\-_]+)+([\w\-\.,@?^=%&amp;:/~\+#]*[\w\-\@?^=%&amx;/~\+#])?");
    foreach (QString rxSrc, rxList)
    {
        toLinkByRegExp(srcMap,linkMap,rxSrc);
    }
    QMap<int,QPair<QString,bool> > resultMap;
    addResultMap(srcMap,resultMap,false);
    addResultMap(linkMap,resultMap,true);
    QString newSrc;
    newSrc.append("<body>");

    QMapIterator<int,QPair<QString,bool> > inter(resultMap);
    while(inter.hasNext())
    {
        inter.next();
        QPair<QString,bool> valuePair = inter.value();
        QString html = toHtml(valuePair);
        newSrc.append(html);
    }
    newSrc.append("</body>");
//    qDebug()<<"(newSrc == src)  "<<(newSrc == src);
//    qDebug()<<"newSrc= "<<newSrc;
//    qDebug()<<"src= "<<src;
    return newSrc;
}

QString ZTestPublic::getMacAdress()
{
    QList<QNetworkInterface>list = QNetworkInterface::allInterfaces();
    QString macAddress = "undefined";
    for(int j = 0; j < list.size(); j++)
    {
        QNetworkInterface interface = list.at(j);
        QNetworkInterface::InterfaceFlags interFlags = interface.flags();
        if((interFlags&QNetworkInterface::IsUp) &&
        (interFlags&QNetworkInterface::IsRunning) &&
        (interFlags&QNetworkInterface::CanBroadcast) &&
        (interFlags&QNetworkInterface::CanMulticast) &&
        !(interFlags&QNetworkInterface::IsLoopBack))
        {
            macAddress = interface.hardwareAddress();
            break;
        }
    }
    return macAddress;
}

QString ZTestPublic::getSizeString(qint64 size, int prec)
{
    int index = 0;
    QString suffix = "B";
    double value = 0.0;
    while(size > 0)
    {
        switch (index) {
        case 0:
        {
            suffix = "B";
            value = size % 1024;
            break;
        }
        case 1:
        {
            suffix = "KB";
            value = value / 1024.0 + size % 1024;
            break;
        }
        case 2:
        {
            suffix = "MB";
            value = value / 1024.0 + size % 1024;
            break;
        }
        case 3:
        {
            suffix = "GB";
            value = value / 1024.0 + size % 1024;
            break;
        }
        case 4:
        {
            suffix = "TB";
            value = value / 1024.0 + size % 1024;
            break;
        }
        case 5:
        {
            suffix = "TB";
            value = value + size * 1024;
            return QString("%1%2").arg(QString::number(value,'f',prec)).arg(suffix);
            break;
        }
        default:
            break;
        }
        size /= 1024;
        index++;
    }
    return QString("%1%2").arg(QString::number(value,'f',prec)).arg(suffix);
}

void ZTestPublic::addResultMap(const QMap<int, QString> &srcMap, QMap<int,QPair<QString,bool> >& resultMap, bool isLink)
{
    QMapIterator<int,QString> inter(srcMap);
    while(inter.hasNext())
    {
        inter.next();
        resultMap.insert(inter.key(),QPair<QString,bool>(inter.value(),isLink));
    }
}

void ZTestPublic::toLinkByRegExp(QMap<int, QString> &srcMap, QMap<int, QString> &linkMap, const QString& rxSrc)
{
    QMap<int, QString> newSrcMap;
    QMapIterator<int,QString> inter(srcMap);
    while(inter.hasNext())
    {
        inter.next();
        toLinkByRegExp(inter.value(),inter.key(),newSrcMap,linkMap,rxSrc);
    }
    srcMap = newSrcMap;
    return;
}

void ZTestPublic::toLinkByRegExp(const QString &src, int startIndex, QMap<int, QString> &srcMap, QMap<int, QString> &linkMap, const QString& rxSrc)
{
    qDebug()<<"sr = "<<src;
    if(src.isEmpty())
    {
        qDebug()<<"line"<<__LINE__;
        return;
    }
//    QRegExp rx("(http|ftp|https):\/\/[\w\-_]+(\.[\w\-_]+)+([\w\-\.,@?^=%&amp;:/~\+#]*[\w\-\@?^=%&amp;/~\+#])?");
    QRegExp rx(rxSrc);
    int pos = src.indexOf(rx);
    qDebug()<< "pos = "<<pos;
    if(pos < 0)
    {
        srcMap.insert(startIndex,src);
        return;
    }

    int start = 0;
    while(pos >= 0)
    {

        QString cap = rx.cap(0);
        int len = rx.matchedLength();
        qDebug()<<"cap"<<cap;
        if(len <= 0 || cap.isEmpty())
        {
            break;
        }
        if(pos > 0)
        {
            QString unMatch  = src.mid(start,pos - start);
            srcMap.insert(startIndex + start,unMatch);
            qDebug()<<"unMatch = "<<unMatch;
        }
        linkMap.insert(startIndex + pos,cap);
        qDebug()<<"pos = "<<pos;
        pos += len;
        start = pos;
        pos = src.indexOf(rx,pos);
    }
    if(src.length() - 1 > start)
    {
        QString unMatch  = src.mid(start,src.length() - start);
        srcMap.insert(startIndex + start,unMatch);
    }
    return;
}

QString ZTestPublic::toHtml(const QPair<QString, bool> &pair)
{
    if(pair.second)
    {
        return QString("<a href=%1><font color=blue>%1</font></a>").arg(pair.first);
    }
    return pair.first;
}
