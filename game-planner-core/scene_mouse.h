#ifndef SCENE_MOUSE_H
#define SCENE_MOUSE_H

#include <QObject>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class scene_mouse : public QGraphicsScene
{
    Q_OBJECT

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

signals:
    void mmoved(QGraphicsSceneMouseEvent * event);

public:
    scene_mouse();

};

#endif // SCENE_MOUSE_H
