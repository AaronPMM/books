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
        /* ƒ|ƒŠƒ‰ƒCƒ“‚Ì•`‰æŠÖ”‚ğŒÄ‚Ño‚· */
        draw_polyline(shape);
        break;
      case RECTANGLE_PRIMITIVE:
        /* ’·•ûŒ`‚Ì•`‰æŠÖ”‚ğŒÄ‚Ño‚· */
        draw_rectangle(shape);
        break;
      case CIRCLE_PRIMITIVE:
        /* ‰~‚Ì•`‰æŠÖ”‚ğŒÄ‚Ño‚· */
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
