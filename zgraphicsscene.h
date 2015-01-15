#ifndef ZGRAPHICSSCENE_H
#define ZGRAPHICSSCENE_H
#include <QGraphicsScene>

class ZGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ZGraphicsScene();
    ~ZGraphicsScene();

private slots:
    void	onLinkActivated(const QString & link);
    void	onLinkHovered(const QString & link);

private:

};

#endif // ZGRAPHICSSCENE_H
