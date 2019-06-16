//
//  vector3d.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "vector3d.h"


Vector *createVector(float x, float y, float z)
{
    Point *vector = (Point*) malloc(sizeof(Point));
    vector->x = x;
    vector->y = y;
    vector->z = z;

    return vector;
}

bool vector3D_is_zero(Vector *v)
{
    return fabsf(v->x) < FLT_EPSILON && fabsf(v->y) < FLT_EPSILON && fabsf(v->z) < FLT_EPSILON;
}

bool vectorIsEqual(Vector *v, Vector *u)
{
    return fabsf(v->x - u->x) < FLT_EPSILON && fabsf(v->y - u->y) < FLT_EPSILON && fabsf(v->z - u->z) < FLT_EPSILON;
}

float vectorLength(Vector *v)
{
    return sqrtf(powf(v->x, 2.0) + powf(v->y, 2.0) + powf(v->z, 2.0));
}



Vector *vectorAddVector(Vector *v, Vector *u)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x + u->x;
    vect->y = v->y + u->y;
    vect->z = v->z + u->z;
    return vect;
}

Vector *vectorAddFloat(Vector *v, float f)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x + f;
    vect->y = v->y + f;
    vect->z = v->z + f;
    return vect;
}

Vector *vectorSubstractVector(Vector *v, Vector *u)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x - u->x;
    vect->y = v->y - u->y;
    vect->z = v->z - u->z;
    return vect;
}

Vector *vectorSubstractFloat(Vector *v, float f)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x - f;
    vect->y = v->y - f;
    vect->z = v->z - f;
    return vect;
}

float vectorMultiplyDot(Vector *v, Vector *u)
{
    return v->x * u->x + v->y * u->y + v->z * u->z;
}

Vector *vectorMultiplyFloat(Vector *v, float f)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x * f;
    vect->y = v->y * f;
    vect->z = v->z * f;
    return vect;
}

Vector *vectorDivideFloat(Vector *v, float f)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->x / f;
    vect->y = v->y / f;
    vect->z = v->z / f;
    return vect;
}

Vector *vectorMultiplyCross(Vector *v, Vector *u)
{
    Vector *vect = (Vector*) malloc(sizeof(Vector));
    vect->x = v->y * u->z  - v->z * u->y;
    vect->y = v->z * u->x  - v->x * u->z;
    vect->z = v->x * u->y  - v->y * u->x;
    return vect;
}

Vector *vectorFromPoint(Point *p)
{
    Vector *v = (Vector*) malloc(sizeof(Vector));
    v->x = p->x;
    v->y = p->y;
    v->z = p->z;
    return v;
}

Vector *vectorFromTwoPoints(Point *p, Point *q)
{
    Vector *v = (Vector*) malloc(sizeof(Vector));
    v->x = q->x - p->x;
    v->y = q->y - p->y;
    v->z = q->z - p->z;
    return v;
}

float vectorLengthSquared(Vector *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

void freeVector(Vector **v)
{
    free(*v);
    *v = NULL;
}
