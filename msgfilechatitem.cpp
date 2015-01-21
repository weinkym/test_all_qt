#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QFontMetrics>
#include "msgfilechatitem.h"
#include "ztest_global.h"

MsgFileChatItem::MsgFileChatItem(QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    m_btnPixmap = QPixmap(":/images/search.png");
//    m_btnPixmap = QPixmap(":/images/cancel.png");

    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    m_stateItem = new QGraphicsTextItem("file is sending",this);
    m_stateItem->setFont(font);
    m_fileNameItem = new QGraphicsTextItem("fileName",this);
    m_fileNameItem->setFont(font);
    m_stateItem->setDefaultTextColor(QColor(Qt::gray));

    m_fileIconItem = new QGraphicsPixmapItem(this);
    m_btnIconItem = new QGraphicsPixmapItem(this);
//    m_progressBar = new QProgressBar();
//    m_widget = new QGraphicsProxyWidget(this);
//    m_widget->setWidget(m_progressBar);
    m_rect = QRectF(0,0,300,70);
    m_proBarWidth = 0;
    m_state = undefind;
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
    QBrush brush(Qt::lightGray);
    painter->setBrush(brush);
    painter->drawRect(m_rect);


    QString text = "100%";
    QFont font;
    font.setPixelSize(18);
    QFontMetrics fontMetrics(font);
    QRect textRect = fontMetrics.tightBoundingRect(text);

    QRect proRect(m_stateItem->x(),m_stateItem->y()+10,m_proBarWidth - textRect.width(),5);
    brush.setColor("#3a595e");
    painter->setBrush(brush);
    QPen pen(Qt::NoPen);
    qreal xRadius = 2.0;
    qreal yRadius = 3.0;
    painter->setPen(pen);
    painter->drawRoundedRect(proRect,xRadius,yRadius);
    qreal curRate = 0.4;
    qreal curWidth = proRect.width() * curRate;
    QRect curRect(proRect.x(),proRect.y(),curWidth,proRect.height());


    brush.setColor("#d3b706");
    painter->setBrush(brush);
    painter->drawRoundedRect(curRect,xRadius,yRadius);

    painter->restore();
    QPoint textPos(proRect.right(),proRect.center().y()  + 0.5 * textRect.height());
    painter->setFont(font);
    painter->drawText(textPos,text);
//    painter->drawRect(textRect);
//    painter->drawText(QPoint(0,0),text);
}

void MsgFileChatItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(m_btnIconItem->isVisible())
        {
            QRectF rect(m_btnIconItem->x()
                        ,m_btnIconItem->y()
                        ,m_btnIconItem->boundingRect().width()
                        ,m_btnIconItem->boundingRect().height());
            if(rect.contains(event->pos()))
            {
//                static bool ok = false;
//                m_btnPixmap = ok ? QPixmap(":/images/1.png") : QPixmap(":/images/4004_4.png");
//                m_stateItem->setVisible(ok);
//                ok = !ok;
                LOG_DEBUG(event->pos());
                if(m_state == transfering)
                {
                    LOG_DEBUG("transfering");
                    m_state = cancel;
                    this->updateLayout();
                }
                else if(m_state == cancel)
                {
                    //todo open file
                    LOG_DEBUG("cancel");
                    m_state = scuccessful;
                    this->updateLayout();
                }
                else if(m_state == scuccessful)
                {
                    //todo open file
                    LOG_DEBUG("scuccessful");
                    m_state = undefind;
                    this->updateLayout();
                }
                else
                {
                    //test
                    LOG_DEBUG("OTHER");
                    m_state = transfering;
                    this->updateLayout();
                }

            }
        }
    }
    return QGraphicsObject::mousePressEvent(event);
}

void MsgFileChatItem::updateLayout()
{
    switch (m_state) {
    case scuccessful:
        m_btnPixmap = QPixmap(":/images/search.png");
        m_stateItem->setPlainText(tr("scuccessful"));
        m_stateItem->setVisible(true);
//        m_btnIconItem->setVisible(true);
        break;
    case cancel:
        m_stateItem->setPlainText(tr("cancel"));
        m_stateItem->setVisible(true);
//        m_btnIconItem->setVisible(false);
        break;
    case transfering:
        m_btnPixmap = QPixmap(":/images/cancel.png");
        m_stateItem->setVisible(false);
//        m_btnIconItem->setVisible(true);
        break;
    default:
        m_stateItem->setVisible(false);
//        m_btnIconItem->setVisible(true);//Ó¦¸ÃÊÇfalse
        break;
    }

    qreal iconRate = 0.3;
    qreal fileRate = 0.6;
    qreal btnRate = 0.1;

    qreal marginRate = 0.3;
    qreal tempW = m_rect.width() * iconRate;
    qreal tempDw = 0.5 * tempW * marginRate;
    qreal pixW = tempW - 2 * tempDw;
    qreal tempDh = 0.5 * (m_rect.height() - pixW);
    qreal starX = tempDw;
    m_fileIconItem->setPixmap(m_btnPixmap.scaled(pixW,pixW));
    m_fileIconItem->setPos(starX,tempDh);
    starX += pixW + tempDw;

    marginRate = 0.01;
    tempW = m_rect.width() * fileRate;
    tempDw = 0.5 * tempW * marginRate;
    starX += tempDw;
    qreal sartY = 0.25 * m_rect.height() - 0.5 * m_fileNameItem->boundingRect().height();
    m_fileNameItem->setPos(starX,sartY);
    sartY = 0.55 * m_rect.height() - 0.5 * m_fileNameItem->boundingRect().height();
    m_stateItem->setPos(starX,sartY);
    m_proBarWidth = tempW - 2 * tempDw - 10;

    starX += tempW - tempDw;
    marginRate = 0.3;
    tempW = m_rect.width() * btnRate;
    tempDw = 0.5 * tempW * marginRate;
    pixW = tempW - 2 * tempDw;
    tempDh = 0.5 * (m_rect.height() - pixW);
    m_btnIconItem->setPixmap(m_btnPixmap.scaled(pixW,pixW));
    m_btnIconItem->setPos(starX,tempDh);

}
