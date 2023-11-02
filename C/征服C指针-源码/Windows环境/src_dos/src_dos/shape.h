#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

typedef enum {
    COLOR_BLACK,                /* �� */
    COLOR_BLUE,                 /* �� */
    COLOR_RED,                  /* �� */
    COLOR_MAGENTA,              /* �� */
    COLOR_GREEN,                /* �� */
    COLOR_CYAN,                 /* ���F */
    COLOR_YELLOW,               /* ���F */
    COLOR_WHITE                 /* �� */
} Color;

typedef enum {
    FILL_NONE,                  /* �h��ׂ��Ȃ� */
    FILL_SOLID,                 /* �ׂ��h�� */
    FILL_HATCH,                 /* �ΐ��ɂ��n�b�`���O */
    FILL_CROSSHATCH             /* ���������n�b�`���O */
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
    Point       minPoint;       /* �����̍��W */
    Point       maxPoint;       /* �E��̍��W */
} Rectangle;

typedef struct {
    Point       center;         /* ���S */
    double      radius;         /* ���a */
} Circle;

typedef struct {
    /* �y��(�֊s)�̐F*/
    Color       pen_color;
    /* �h��ׂ��p�^�[���BFILL_NONE�̎��ɂ͓h��ׂ��Ȃ� */
    FillPattern fill_pattern;
    /* �h��ׂ����̐F */
    Color       fill_color;
    /* �}�`�̎�� */
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
