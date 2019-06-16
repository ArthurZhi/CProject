//
//  main.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "segment3d.h"
#include "plane3d.h"
#include "computeGeometry3d.h"
#include "triangle3D.h"
#include "pyramid3d.h"

int main(int argc, const char * argv[]) {

    Point *p = createPoint(-2.0, 3.0, -1.0);
    Vector *v = createVector(1.0, 3.0, 2.0);
    Line *line = lineByVectorPoint(v, p);
    Plane *plane = planeByCoeficients(0.0, 2.0, -1.0, -11.0);
    Point *iPoint = intersectPlaneAndLine(plane, line);
    printf(" Point  ( %f, %f, %f )  \n", iPoint->x,iPoint->y,iPoint->z); // must be (-1, 6, 1)
    printf("Is point on Line? %i \n\n", lineIsPointOnLine(line, iPoint));


    Point *p1 = createPoint(0.0, 5.0, -1.0);
    Vector *v1 = createVector(3.0, -2.0, 4.0);
    Line *line1 = lineByVectorPoint(v1, p1);
    Plane *plane1 = planeByCoeficients(2.0, -3.0, -3.0, 12.0);
    Point *iPoint1 = intersectPlaneAndLine(plane1, line1);
    printf(" Point  ( %f, %f, %f )  \n", iPoint1->x,iPoint1->y,iPoint1->z); // must be (INF, INF, INF)
    printf("Is point on Line? %i \n\n", lineIsPointOnLine(line1, iPoint1));



    Point *p2 = createPoint(2.0, -5.0, 0.0);
    Vector *v2 = createVector(-4.0, -1.0, 5.0);
    Line *line2 = lineByVectorPoint(v2, p2);
    Plane *plane2 = planeByCoeficients(5.0, 0.0, 4.0, -13.0);
    Point *iPoint2 = intersectPlaneAndLine(plane2, line2);
    printf(" Point ( %f, %f, %f ) \n", iPoint2->x,iPoint2->y,iPoint2->z); // must be (INF, -INF, 0)
    printf("Is point on Line? %i \n\n", lineIsPointOnLine(line, iPoint));


    Point *a = createPoint(0.0, -4.0, 0.0);
    Point *b = createPoint(3.0, 0.0, 0.0);
    Point *c = createPoint(-2.0, 2.0, 0.0);
    Point *d = createPoint(0.0, 0.0, 5.0);

    printf(" \n\n Triangle \n");
    Triangle *triangle = triangleByPoints(a, b, c);
    printf(" Perimeter ( %f ) \n", trianglePerimeter(triangle));
    printf(" Square ( %f ) \n", triangleSquare(triangle));

    printf(" \n\nPyramid \n");
    Pyramid *pyramid = pyramidByPoints(a, b, c, d);
    printf(" Square ( %f ) \n", pyramidSquare(pyramid));
    printf(" Square side1  ( %f ) \n", pyramidSquare1(pyramid));
    printf(" Square side2  ( %f ) \n", pyramidSquare2(pyramid));
    printf(" Square side3  ( %f ) \n", pyramidSquare3(pyramid));
    printf(" Square side3  ( %f ) \n", pyramidSquare4(pyramid));
    printf(" Volume  ( %f ) \n", pyramidVolume(pyramid));
    Point *centerMass = pyramidCenterMass(pyramid);
    printf(" Center Mass ( %f, %f, %f ) \n", centerMass->x,centerMass->y,centerMass->z);
    return 0;
}
