#include "scene_mouse.h"

scene_mouse::scene_mouse()
{
}

void scene_mouse::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent){
    emit mmoved(mouseEvent);
}




