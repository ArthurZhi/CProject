//
//  pyramid3d.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef pyramid3d_h
#define pyramid3d_h

#include <stdio.h>
#include "point3d.h"
#include "triangle3D.h"
#include "plane3d.h"
#include "computeGeometry3d.h"
#include "segment3d.h"

typedef struct Pyramid3D {
    Point *a;
    Point *b;
    Point *c;
    Point *d;
} Pyramid;


Pyramid *pyramidByPoints(const Point *a, const Point *b, const Point *c, const Point *d);
float pyramidSquare(Pyramid *pyramid);
float pyramidSquare1(Pyramid *pyramid);
float pyramidSquare2(Pyramid *pyramid);
float pyramidSquare3(Pyramid *pyramid);
float pyramidSquare4(Pyramid *pyramid);
float pyramidVolume(Pyramid *pyramid);
Point *pyramidCenterMass(Pyramid *pyramid);
#endif /* pyramid3d_h */
