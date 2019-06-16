//
//  matrix.h
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <stdio.h>

typedef struct Matrix3x3 {
    float m11;
    float m21;
    float m31;
    float m12;
    float m22;
    float m32;
    float m13;
    float m23;
    float m33;
} mat3;

float mat3_det(mat3 *m);

#endif /* matrix_h */
