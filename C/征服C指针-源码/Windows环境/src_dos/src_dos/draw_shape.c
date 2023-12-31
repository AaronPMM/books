#include <stdio.h>
#include <assert.h>
#include "shape.h"

void draw_polyline(Shape *shape);
void draw_rectangle(Shape *shape);
void draw_circle(Shape *shape);

void draw_primitive(Shape *shape)
{
    switch (shape->u.primitive.type) {
      case POLYLINE_PRIMITIVE:
        /* ポリラインの描画関数を呼び出す */
        draw_polyline(shape);
        break;
      case RECTANGLE_PRIMITIVE:
        /* 長方形の描画関数を呼び出す */
        draw_rectangle(shape);
        break;
      case CIRCLE_PRIMITIVE:
        /* 円の描画関数を呼び出す */
        draw_polyline(shape);
        break;
      default:
        assert(0);
    }
}

void draw_all_shapes(Shape *head)
{
    Shape       *pos;

    for (pos = head; pos != NULL; pos = pos->next) {
        switch (pos->type) {
          case PRIMITIVE_SHAPE:
            draw_primitive(pos);
            break;
          case GROUP_SHAPE:
            draw_all_shapes(pos->u.group.head);
            break;
          default:
            assert(0);
        }
    }
}
