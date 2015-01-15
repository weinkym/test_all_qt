
#include "zgraphicstextitem.h"
#include <QGraphicsSceneHoverEvent>
#include "ztest_global.h"

ZGraphicsTextItem::ZGraphicsTextItem()
    :QGraphicsTextItem()
{
    //
}

ZGraphicsTextItem::~ZGraphicsTextItem()
{
    //
}

void ZGraphicsTextItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    LOG_DEBUG("");
    this->setSelected(true);
    return QGraphicsTextItem::hoverEnterEvent(event);
}

void ZGraphicsTextItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    LOG_DEBUG("");
    this->setSelected(false);
    return QGraphicsTextItem::hoverLeaveEvent(event);
}
