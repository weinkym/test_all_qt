#ifndef ZTEST_GLOBAL_H
#define ZTEST_GLOBAL_H

#include <QDebug>

#define LOG_WARRING(X) qWarning()<<(X)
#define LOG_ERROR(X) qCritical()<<(X)

#ifndef _DEBUG
#define LOG_DEBUG(X) qDebug()<<(X)<<__LINE__
#else
#define LOG_DEBUG(X)
#endif

//void outDebugMsg(x);
#endif // ZTEST_GLOBAL_H
