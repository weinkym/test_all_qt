#ifndef MSGFILECHATITEM_H
#define MSGFILECHATITEM_H

#include <QGraphicsObject>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QProgressBar>

class MsgFileChatItem : public QGraphicsObject
{
    Q_OBJECT

public:
    MsgFileChatItem(QGraphicsItem * parent = 0);
    ~MsgFileChatItem();
    virtual QRectF boundingRect() const;

protected:
    virtual void	paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

private:
    void updateLayout();

private:
    QGraphicsTextItem* m_stateItem;
    QGraphicsTextItem* m_fileNameItem;
    QGraphicsPixmapItem* m_fileIconItem;
    QGraphicsPixmapItem* m_btnIconItem;
//    QGraphicsProxyWidget* m_widget;
//    QProgressBar* m_progressBar;
    QPixmap m_pixmap;
    QRectF m_rect;
};

#endif // MSGFILECHATITEM_H
