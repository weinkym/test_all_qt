#ifndef CGRAPHICSSTATEITEM_H
#define CGRAPHICSSTATEITEM_H

#include <QGraphicsObject>
#include <QTimer>

class CGraphicsSateItem : public QGraphicsObject
{
    Q_OBJECT

public:
    enum State
    {
        Sending,
        Successful,
        Fail,
        UnRead,
        Read
    };

    CGraphicsSateItem(QGraphicsItem * parent = 0);
    ~CGraphicsSateItem();
    QRectF boundingRect() const;
//    QPainterPath shape() const;
    void setState(State state);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

private slots:
    void onDisappear();

private:
    QRectF m_rect;
    State m_state;
    QColor m_color;
    QTimer m_disappearTimer;
};

#endif // CGRAPHICSSTATEITEM_H
