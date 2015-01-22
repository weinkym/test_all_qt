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
        Undefind
        ,Transfering //传输中,包括发送和接收
        ,Scuccessful //传输成功,包括发送和接收
        ,Cancel //传输取消,包括发送和接收
        ,Fail //传输失败,包括发送和接收
        ,Resend //重新发送
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
//    QGraphicsTextItem* m_stateItem;
//    QGraphicsTextItem* m_fileNameItem;
//    QGraphicsPixmapItem* m_fileIconItem;
//    QGraphicsPixmapItem* m_btnIconItem;
    QPixmap m_btnPixmap;
    QPixmap m_filePixmap;
    QRectF m_rect;
    qreal m_proBarWidth;
    State m_state;

    QRect m_filenameTextRect;
    QRect m_stateTextRect;
    QRect m_fileicnoRect;
    QRect m_progressBarRect;
    QRect m_btnRect;

    QString m_fileName;
    QString m_stateText;
    QFont m_textFont;
};

#endif // MSGFILECHATITEM_H
