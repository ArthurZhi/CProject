//
//  vector3d.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef vector3d_h
#define vector3d_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include "point3d.h"

typedef struct Vector3D {
    float x, y, z;
} Vector;


Vector *createVector(float x, float y, float z);
bool vectorIsZero(Vector *v);
bool vectorIsEqual(Vector *v, Vector *u);
float vectorLength(Vector *v);
Vector *vectorAddVector(Vector *v, Vector *u);
Vector *vectorAddFloat(Vector *v, float f);
Vector *vectorSubstractVector(Vector *v, Vector *u);
Vector *vectorSubstractFloat(Vector *v, float f);
float vectorMultiplyDot(Vector *v, Vector *u);
Vector *vectorMultiplyFloat(Vector *v, float f);
Vector *vectorDivideFloat(Vector *v, float f);
Vector *vectorMultiplyCross(Vector *v, Vector *u);
Vector *vectorFromPoint(Point *p);
Vector *vectorFromTwoPoints(Point *p, Point *q);
float vectorLengthSquared(Vector *v);
void freeVector(Vector **v);
#endif /* vector3d_h */
