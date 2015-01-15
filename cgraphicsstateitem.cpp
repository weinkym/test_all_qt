#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "cgraphicsstateitem.h"
#include "ztest_global.h"

CGraphicsSateItem::CGraphicsSateItem(QGraphicsItem *parent)
    :QGraphicsObject(parent),m_rect(QRect(0,0,15,15)),m_color(Qt::green)
{
    m_state = Sending;
    connect(&m_disappearTimer,SIGNAL(timeout()),this,SLOT(onDisappear()));
}

CGraphicsSateItem::~CGraphicsSateItem()
{
    //
}

QRectF CGraphicsSateItem::boundingRect() const
{
    return m_rect;
}

void CGraphicsSateItem::setState(CGraphicsSateItem::State state)
{
    if(m_state != state)
    {
        m_state = state;
        if(state == Successful || state == Read)
        {
            m_disappearTimer.start(100);
        }
        else
        {
            update();
        }
    }
}

void CGraphicsSateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    switch (m_state) {
    case Sending:
        m_color = QColor(Qt::blue);
        break;
    case Fail:
    case UnRead:
        m_color = QColor(Qt::red);
//    case Successful:
//    case Read:
//        m_color = QColor(Qt::green);
//        break;
    default:
        break;
    }
    QRectF rect = option->exposedRect;
    QBrush brush(m_color);
    QPen pen(m_color);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(rect);
    painter->restore();
}

void CGraphicsSateItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    LOG_DEBUG("mousePressEvent");
    if(event->buttons() & Qt::LeftButton)
    {
        LOG_DEBUG("LeftButton");
        if(m_state == Successful)
        {
            m_state = Fail;
        }
        else
        {
        setState(Successful);
        }
    }
}

void CGraphicsSateItem::onDisappear()
{
    qreal op = this->opacity();
    op -=0.1;
    if(op > 0)
    {
        if(!this->isVisible())
        {
            this->setVisible(true);
        }
        this->setOpacity(op);
    }
    else
    {
        m_disappearTimer.stop();
        this->setVisible(false);
//        this->setOpacity(1);
    }
}
