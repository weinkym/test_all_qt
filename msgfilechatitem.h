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
    enum State
    {
        undefind,
        cancel,
        scuccessful,
        transfering
    };

    MsgFileChatItem(QGraphicsItem * parent = 0);
    ~MsgFileChatItem();
    virtual QRectF boundingRect() const;

protected:
    virtual void	paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
//    bool sceneEventFilter(QGraphicsItem * watched, QEvent * event);
     void mousePressEvent(QGraphicsSceneMouseEvent * event);

private:
    void updateLayout();

private:
    QGraphicsTextItem* m_stateItem;
    QGraphicsTextItem* m_fileNameItem;
    QGraphicsPixmapItem* m_fileIconItem;
    QGraphicsPixmapItem* m_btnIconItem;
//    QGraphicsProxyWidget* m_widget;
//    QProgressBar* m_progressBar;
    QPixmap m_btnPixmap;
    QRectF m_rect;
    qreal m_proBarWidth;
    State m_state;
};

#endif // MSGFILECHATITEM_H
