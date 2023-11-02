#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

typedef enum {
    COLOR_BLACK,                /* 黒 */
    COLOR_BLUE,                 /* 青 */
    COLOR_RED,                  /* 赤 */
    COLOR_MAGENTA,              /* 紫 */
    COLOR_GREEN,                /* 緑 */
    COLOR_CYAN,                 /* 水色 */
    COLOR_YELLOW,               /* 黄色 */
    COLOR_WHITE                 /* 白 */
} Color;

typedef enum {
    FILL_NONE,                  /* 塗り潰さない */
    FILL_SOLID,                 /* べた塗り */
    FILL_HATCH,                 /* 斜線によるハッチング */
    FILL_CROSSHATCH             /* 交差したハッチング */
} FillPattern;

typedef enum {
    POLYLINE_PRIMITIVE,
    RECTANGLE_PRIMITIVE,
    CIRCLE_PRIMITIVE,
} PrimitiveType;

typedef struct {
    double      x;
    double      y;
} Point;

typedef struct {
    int         npoints;
    Point       *point;
} Polyline;

typedef struct {
    Point       minPoint;       /* 左下の座標 */
    Point       maxPoint;       /* 右上の座標 */
} Rectangle;

typedef struct {
    Point       center;         /* 中心 */
    double      radius;         /* 半径 */
} Circle;

typedef struct {
    /* ペン(輪郭)の色*/
    Color       pen_color;
    /* 塗り潰しパターン。FILL_NONEの時には塗り潰さない */
    FillPattern fill_pattern;
    /* 塗り潰す時の色 */
    Color       fill_color;
    /* 図形の種類 */
    PrimitiveType   type;
    union {
        Polyline        polyline;
        Rectangle       rectangle;
        Circle          circle;
    } u;
} Primitive;

typedef struct Shape_tag Shape;

typedef struct {
    Shape   *head;
    Shape   *tail;
} Group;

typedef enum {
    PRIMITIVE_SHAPE,
    GROUP_SHAPE
} ShapeType;

struct Shape_tag {
    ShapeType           type;
    union {
        Primitive       primitive;
        Group           group;
    } u;
    struct Shape_tag *prev;
    struct Shape_tag *next;
};

#endif /* SHAPE_H_INCLUDED */
