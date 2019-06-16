//
//  computeGeometry3d.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef computeGeometry3d_h
#define computeGeometry3d_h

#include <stdio.h>
#include <math.h>
#include "point3d.h"
#include "vector3d.h"
#include "segment3d.h"
#include "line3d.h"
#include "plane3d.h"


enum PointOrientation {
    COUNTERCLOCKWISE,
    CLOCKWISE,
    OOPS
};

int orientationOfThreePoints(Point *p, Point *q, Point *r);
Line *intersectTwoPlanes(Plane *plane1, Plane *plane2);
Point *intersectPlaneAndLine(Plane *plane, Line *line);
#endif /* computeGeometry3d_h */
