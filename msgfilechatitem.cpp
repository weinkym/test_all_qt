#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QFontMetrics>
#include "msgfilechatitem.h"
#include "ztest_global.h"

MsgFileChatItem::MsgFileChatItem(QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    m_btnPixmap = QPixmap(":/images/search.png");
    m_filePixmap = QPixmap(":/images/cancel.png");

    m_rect = QRectF(0,0,264,70);
    m_proBarWidth = 0;
    m_state = Undefind;
    m_fileName ="starifish.xls";
    m_stateText = "undefined";
    m_textFont.setPointSize(12);
    updateLayout();
}

MsgFileChatItem::~MsgFileChatItem()
{

}

QRectF MsgFileChatItem::boundingRect() const
{
    return m_rect;
}

void MsgFileChatItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    QBrush brush(Qt::white);
    painter->setBrush(brush);
    painter->drawRoundedRect(m_rect,10,10);

    painter->drawPixmap(m_fileicnoRect,m_filePixmap);
    painter->drawPixmap(m_btnRect,m_btnPixmap);

    painter->setFont(m_textFont);
    QPen pen;
    pen.setColor("#000000");
    painter->setPen(pen);
    painter->drawText(m_filenameTextRect.bottomLeft(),m_fileName);
    if(m_state == Resend)
    {
        pen.setColor("#157bfb");
        painter->setPen(pen);
        painter->drawText(m_stateTextRect.bottomLeft(),m_stateText);
    }
    else
    {
        pen.setColor("#acb6c0");
        painter->setPen(pen);
        painter->drawText(m_stateTextRect.bottomLeft(),m_stateText);
    }

    if(m_state == Transfering)
    {
        qreal xRadius = 2.0;
        qreal yRadius = 3.0;
        pen.setColor("#62aff4");
        painter->setPen(pen);
        brush.setStyle(Qt::NoBrush);
        painter->setBrush(brush);
        painter->drawRoundedRect(m_progressBarRect,xRadius,yRadius);
        qreal curRate = 0.4;
        qreal curWidth = m_progressBarRect.width() * curRate;
        QRect curRect(m_progressBarRect.x(),m_progressBarRect.y(),curWidth,m_progressBarRect.height());
        brush.setColor("#98d4f8");
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);
        painter->drawRoundedRect(curRect,xRadius,yRadius);
        QString rateText = QString("%1%").arg(int(100 * curRate));
        pen.setColor("#acb6c0");
        painter->setPen(pen);
        QFontMetrics fontMetrics(m_textFont);
        QRect textRect = fontMetrics.tightBoundingRect(rateText);
        painter->drawText(m_progressBarRect.right() + 4,m_progressBarRect.center().y() + 0.5 * textRect.height(),rateText);
    }
}

void MsgFileChatItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        LOG_DEBUG(event->pos());
        if(m_state == Transfering)
        {
            LOG_DEBUG("transfering");
            m_state = Cancel;
            this->updateLayout();
        }
        else if(m_state == Cancel)
        {
            //todo open file
            LOG_DEBUG("cancel");
            m_state = Scuccessful;
            this->updateLayout();
        }
        else if(m_state == Scuccessful)
        {
            //todo open file
            LOG_DEBUG("scuccessful");
            m_state = Resend;
            this->updateLayout();
        }
        else if(m_state == Resend)
        {
            //todo open file
            LOG_DEBUG("Resend");
            m_state = Undefind;
            this->updateLayout();
        }
        else
        {
            //test
            LOG_DEBUG("OTHER");
            m_state = Transfering;
            this->updateLayout();
        }
    }
    return QGraphicsObject::mousePressEvent(event);
}

void MsgFileChatItem::updateLayout()
{
    m_rect.setWidth(224);
    switch (m_state) {
    case Scuccessful:
        m_btnPixmap = QPixmap(":/images/search.png");
        m_stateText = tr("scuccessful");
        break;
    case Cancel:
        m_stateText = tr("cancel");
        break;
    case Transfering:
        m_btnPixmap = QPixmap(":/images/cancel.png");
        m_stateText = tr("transfering");
        m_rect.setWidth(264);
        break;
    case Fail:
        m_stateText = tr("Fail");
        break;
    case Resend:
        m_stateText = tr("Resend");
        break;
    default:
        break;
    }

    qreal marginU = 14;
    qreal marginD = 14;
    qreal marginL = 15;
    qreal marginR = 10;
    qreal marginH1 = 8;
    qreal marginH2 = 4;
    qreal marginV1 = 4;
    qreal marginV2 = 3;
    qreal dw = 0;//40
    QSize fileSize(36,36);
    QSize btnSize(24,24);
    m_rect.setHeight(marginU+fileSize.height()+marginD);

    qreal startX = marginL;
    qreal startY = marginU;
    m_fileicnoRect = QRect(startX,startY,fileSize.width(),fileSize.height());
    startX += fileSize.width() + marginH1;
    QFontMetrics fontMetrics(m_textFont);
    QRect textRect = fontMetrics.tightBoundingRect(m_fileName);
    m_filenameTextRect = QRect(startX,startY,textRect.width(),textRect.height());
    startY += textRect.height() + marginV1;
    textRect = fontMetrics.tightBoundingRect(m_stateText);
    m_stateTextRect = QRect(startX,startY,textRect.width(),textRect.height());
    startY += textRect.height() + marginV2;
    m_progressBarRect = QRect(startX,startY,134,6);
    m_btnRect = QRect(m_rect.width() - marginR - btnSize.width()
                      ,m_rect.center().y() - 0.5 * btnSize.height()
                      ,btnSize.width()
                      ,btnSize.height());
    update();
}

