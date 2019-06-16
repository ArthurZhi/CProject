//
//  plane3d.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "plane3d.h"

Plane *planeByPoints(const Point *p, const Point *q, const Point *r)
{
    Plane *plane = (Plane*) malloc(sizeof(Plane));

    // find normal vector of plane 𝑛⃗ = v1 x v2,  v1 v2 - directional vector of two lines from three points
    // Set the first point p as M(x0,y0,z0);
    Line *l1 = lineByPoints(p, q);
    Line *l2 = lineByPoints(p, r);
    Vector *v1 = lineGetDirectionalVector(l1);
    Vector *v2 = lineGetDirectionalVector(l2);
    Vector *n = vectorMultiplyCross(v1, v2);

    // equation of plane => n * (x-x0, y-y0, z-z0) = 0  -->  ax + by + cz + d = 0
    plane->a = n->x;
    plane->b = n->y;
    plane->c = n->z;
    plane->d = -1.0 * (n->x * p->x + n->y * p->y + n->z * p->z);

    return plane;
}

Plane *planeByCoeficients(const float a, const float b, const float c, const float d)
{
    Plane *plane = (Plane*) malloc(sizeof(Plane));
    plane->a = a;
    plane->b = b;
    plane->c = c;
    plane->d = d;

    return plane;
}

Point *planeGetSomePointOfPlane(Plane *plane)
{
    //  if a!=0 y=0, z=0 so ax+d=0  x=-d/a
    if(fabsf(plane->a) >= FLT_EPSILON)
    {
        return createPoint(-1*plane->d/plane->a, 0.0, 0.0);
    }
    else if (fabsf(plane->b) >= FLT_EPSILON)
    {
        return createPoint(0.0, -1*plane->d/plane->b, 0.0);
    }
    else if (fabsf(plane->c) >= FLT_EPSILON)
    {
        return createPoint(0.0, 0.0,-1*plane->d/plane->c);
    }
    else
    {
        return NULL; // this is not a plane
    }
}

bool isPointOnPlane(Plane *plane, Point *p)
{
    return fabsf(plane->a*p->x + plane->b*p->y + plane->c*p->z + plane->d) < FLT_EPSILON;
}
Vector *planeGetNormalVector( const Plane *plane)
{
    return createVector(plane->a, plane->b, plane->c);
}

void freePlane(Plane **plane) {
    free(*plane);
    *plane = NULL;
}
