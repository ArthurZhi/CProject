//
//  pyramid3d.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "pyramid3d.h"

Pyramid *pyramidByPoints(const Point *a, const Point *b, const Point *c, const Point *d)
{
    Pyramid *pyramid = (Pyramid*) malloc(sizeof(Pyramid));
    pyramid->a = createPoint(a->x, a->y, a->z);
    pyramid->b = createPoint(b->x, b->y, b->z);
    pyramid->c = createPoint(c->x, c->y, c->z);
    pyramid->d = createPoint(d->x, d->y, d->z);

    return pyramid;
}

float pyramidSquare1(Pyramid *pyramid)
{
    Triangle *side1 = triangleByPoints(pyramid->a, pyramid->b, pyramid->c);
    float S = triangleSquare(side1);
    freeTriangle(&side1);
    return S;
}

float pyramidSquare2(Pyramid *pyramid)
{
    Triangle *side2 = triangleByPoints(pyramid->a, pyramid->d, pyramid->c);

    float S = triangleSquare(side2);
    freeTriangle(&side2);
    return S;
}

float pyramidSquare3(Pyramid *pyramid)
{
    Triangle *side3 = triangleByPoints(pyramid->b, pyramid->d, pyramid->a);

    float S = triangleSquare(side3);
    freeTriangle(&side3);
    return S;
}

float pyramidSquare4(Pyramid *pyramid)
{
    Triangle *side4 = triangleByPoints(pyramid->c, pyramid->d, pyramid->b);

    float S = triangleSquare(side4);
    freeTriangle(&side4);
    return S;
}

float pyramidSquare(Pyramid *pyramid)
{
    Triangle *side1 = triangleByPoints(pyramid->a, pyramid->b, pyramid->c);
    Triangle *side2 = triangleByPoints(pyramid->a, pyramid->d, pyramid->c);
    Triangle *side3 = triangleByPoints(pyramid->b, pyramid->d, pyramid->a);
    Triangle *side4 = triangleByPoints(pyramid->c, pyramid->d, pyramid->b);

    float S = triangleSquare(side1) + triangleSquare(side2) + triangleSquare(side3) + triangleSquare(side4);

    freeTriangle(&side1);
    freeTriangle(&side2);
    freeTriangle(&side3);
    freeTriangle(&side4);

    return S;

}


float pyramidVolume(Pyramid *pyramid)
{
    // V = 1/3 * H*S
    Triangle *base = triangleByPoints(pyramid->a, pyramid->b, pyramid->c);
    float S = triangleSquare(base);
    Plane *basePlane = planeByPoints(pyramid->a, pyramid->b, pyramid->c);
    Vector *n =  planeGetNormalVector(basePlane);
    Line *h = lineByVectorPoint(n, pyramid->d);
    Point *d0 = intersectPlaneAndLine(basePlane, h);
    Segment *s = segmentByPoints(d0, pyramid->d);
    float H = segmentLength(s);


    freeTriangle(&base);
    freeVector(&n);
    freeLine(&h);
    freePoint(&d0);
    freeSegment(&s);

    return H * S * 1.0/3.0;
}

Point *pyramidCenterMass(Pyramid *pyramid)
{
    Plane *basePlane1 = planeByPoints(pyramid->a, pyramid->b, pyramid->c);
    Vector *n1 =  planeGetNormalVector(basePlane1);
    Line *h1 = lineByVectorPoint(n1, pyramid->d);
    Point *p = intersectPlaneAndLine(basePlane1, h1);
    Plane *tempPlane = planeByPoints(pyramid->d, p, pyramid->c);


    Plane *basePlane2 = planeByPoints(pyramid->a, pyramid->d, pyramid->c);
    Vector *n2 =  planeGetNormalVector(basePlane2);
    Line *h2 = lineByVectorPoint(n2, pyramid->b);

    Point *m = intersectPlaneAndLine(tempPlane, h2);

    return m;
}




void freePyramid(Pyramid **pyramid)
{
    free((*pyramid)->a);
    free((*pyramid)->b);
    free((*pyramid)->c);
    free((*pyramid)->d);
    free(*pyramid);
    *pyramid = NULL;

}
