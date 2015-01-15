#include "zgraphicsscene.h"
#include "ztest_global.h"

ZGraphicsScene::ZGraphicsScene()
    :QGraphicsScene()
{

}

ZGraphicsScene::~ZGraphicsScene()
{

}

void ZGraphicsScene::onLinkActivated(const QString &link)
{
    LOG_DEBUG(link);
}

void ZGraphicsScene::onLinkHovered(const QString &link)
{
    LOG_DEBUG(link);
}
