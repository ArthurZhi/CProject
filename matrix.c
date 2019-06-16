//
//  matrix.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "matrix.h"
float mat3_det(mat3 *m)
{
    float determinant =
      m->m11 * m->m22 * m->m33
    + m->m12 * m->m23 * m->m31
    + m->m13 * m->m21 * m->m32
    - m->m11 * m->m23 * m->m32
    - m->m12 * m->m21 * m->m33
    - m->m13 * m->m22 * m->m31;

    return determinant;
}
