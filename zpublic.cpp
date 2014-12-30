#include "zpublic.h"


QString ZPublic::getMacAdress()
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
