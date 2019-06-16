//
//  point3d.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef point3d_h
#define point3d_h

#include <stdio.h>
#include <stdlib.h>


typedef struct Point3D {
    float x, y, z;
} Point;

Point *createPoint(float x, float y, float z);
void freePoint(Point **point);
#endif /* point3d_h */

