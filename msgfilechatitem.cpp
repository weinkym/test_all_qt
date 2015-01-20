#include <QPainter>
#include "msgfilechatitem.h"

MsgFileChatItem::MsgFileChatItem(QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    m_pixmap = QPixmap(":/images/1.png");
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    m_stateItem = new QGraphicsTextItem("file is sending",this);
    m_stateItem->setFont(font);
    m_fileNameItem = new QGraphicsTextItem("fileName",this);
    m_fileNameItem->setFont(font);
    m_stateItem->setDefaultTextColor(QColor(Qt::darkCyan));

    m_fileIconItem = new QGraphicsPixmapItem(this);
    m_btnIconItem = new QGraphicsPixmapItem(this);
//    m_progressBar = new QProgressBar();
//    m_widget = new QGraphicsProxyWidget(this);
//    m_widget->setWidget(m_progressBar);
    m_rect = QRectF(0,0,300,70);
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
    QBrush brush(Qt::white);
    painter->setBrush(brush);
    painter->drawRect(m_rect);
}

void MsgFileChatItem::updateLayout()
{
    qreal iconRate = 0.3;
    qreal fileRate = 0.6;
    qreal btnRate = 0.1;

    qreal marginRate = 0.3;
    qreal tempW = m_rect.width() * iconRate;
    qreal tempDw = 0.5 * tempW * marginRate;
    qreal pixW = tempW - 2 * tempDw;
    qreal tempDh = 0.5 * (m_rect.height() - pixW);
    qreal starX = tempDw;
    m_fileIconItem->setPixmap(m_pixmap.scaled(pixW,pixW));
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

    starX += tempW - tempDw;
    marginRate = 0.3;
    tempW = m_rect.width() * btnRate;
    tempDw = 0.5 * tempW * marginRate;
    pixW = tempW - 2 * tempDw;
    tempDh = 0.5 * (m_rect.height() - pixW);
    m_btnIconItem->setPixmap(m_pixmap.scaled(pixW,pixW));
    m_btnIconItem->setPos(starX,tempDh);
}
