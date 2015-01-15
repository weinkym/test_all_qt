#ifndef ZGRAPHICSTEXTITEM_H
#define ZGRAPHICSTEXTITEM_H
#include <QGraphicsTextItem>

class ZGraphicsTextItem : public QGraphicsTextItem
{
    Q_OBJECT

public:
    ZGraphicsTextItem();
    ~ZGraphicsTextItem();

protected:
    virtual void	hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    virtual void	hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

private:

};

#endif // ZGRAPHICSTEXTITEM_H
