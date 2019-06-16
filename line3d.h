//
//  line3d.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef line3d_h
#define line3d_h

#include <stdio.h>
#include "point3d.h"
#include <math.h>
#include "vector3d.h"


typedef struct Line3D {
    // x - x0/a = y - y0/b = z - z0/c  p - point p(x0,y0,z0)  directional vector v(a, b, c)
    Point *p;
    Vector *v;
} Line;


Line *lineByPoints(const Point *p, const Point *q);
Line *lineByVectorPoint(const Vector *v, const Point *p);
Vector *lineGetDirectionalVector(Line *line);
bool lineIsPointOnLine(Line *line, Point *p);
void freeLine(Line **line);
#endif /* line3d_h */
