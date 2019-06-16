//
//  triangle3D.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "triangle3D.h"

Triangle *triangleByPoints(Point *a, Point*b, Point *c)
{
    Triangle *triangle = (Triangle*) malloc(sizeof(Triangle));
    triangle->a = createPoint(a->x, a->y, a->z);
    triangle->b = createPoint(b->x, b->y, b->z);
    triangle->c = createPoint(c->x, c->y, c->z);

    return triangle;
}

Plane *trianglePlane(Triangle *triangle)
{
    return planeByPoints(triangle->a, triangle->b, triangle->b);
}

Vector *triangleGetNormal(Triangle *triangle)
{
    Plane *trPlane = trianglePlane(triangle);

    return planeGetNormalVector(trPlane);
}

float trianglePerimeter(Triangle *triangle)
{
    float a = sqrtf(powf(triangle->b->x-triangle->a->x, 2.0)
                    + powf(triangle->b->y-triangle->a->y, 2.0)
                    + powf(triangle->b->z-triangle->a->z, 2.0));

    float b = sqrtf(powf(triangle->c->x-triangle->b->x, 2.0)
                   + powf(triangle->c->y-triangle->b->y, 2.0)
                   + powf(triangle->c->z-triangle->b->z, 2.0));

    float c = sqrtf(powf(triangle->a->x-triangle->c->x, 2.0)
                    + powf(triangle->a->y-triangle->c->y, 2.0)
                    + powf(triangle->a->z-triangle->c->z, 2.0));

    return a + b + c;
}

float triangleSquare(Triangle *triangle)
{
    // Geron formula
    float p = trianglePerimeter(triangle);

    float a = sqrtf(powf(triangle->b->x-triangle->a->x, 2.0)
                    + powf(triangle->b->y-triangle->a->y, 2.0)
                    + powf(triangle->b->z-triangle->a->z, 2.0));

    float b = sqrtf(powf(triangle->c->x-triangle->b->x, 2.0)
                    + powf(triangle->c->y-triangle->b->y, 2.0)
                    + powf(triangle->c->z-triangle->b->z, 2.0));

    float c = sqrtf(powf(triangle->a->x-triangle->c->x, 2.0)
                    + powf(triangle->a->y-triangle->c->y, 2.0)
                    + powf(triangle->a->z-triangle->c->z, 2.0));

    return sqrtf(p*(p-a)*(p-b)*(p-c));
}
void freeTriangle(Triangle **triangle)
{
    free((*triangle)->a);
    free((*triangle)->b);
    free((*triangle)->c);
    free(*triangle);
    *triangle = NULL;

}
