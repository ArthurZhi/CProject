//
//  computeGeometry3d.c
//  Geometry3D_02
//
//  Created by Arthur Zhilka on 29/05/2019.
//  Copyright © 2019 ArtZhi. All rights reserved.
//

#include "computeGeometry3d.h"


//  is point r lies on line segment 'pq'

bool isPointOnSegment(Segment *segment, Point *r)
{
    if (r->x <= fmax(segment->p->x, segment->q->x) && r->x >= fmin(segment->p->x, segment->q->x) &&
        r->y <= fmax(segment->p->y, segment->q->y) && r->y >= fmin(segment->p->y, segment->q->y) &&
        r->z <= fmax(segment->p->z, segment->q->z) && r->z >= fmin(segment->p->z, segment->q->z)
        )
        return true;

    return false;
}

/*
 To find orientation of ordered triplet (p, q, r).
 The function returns following values
 0 --> p, q and r are colinear
 1 --> Clockwise
 2 --> Counterclockwise

 https://math.stackexchange.com/questions/2386810/orientation-of-three-points-in-3d-space
 three points are 𝑝⃗1=(𝑥1,𝑦1,𝑧1), 𝑝⃗2=(𝑥2,𝑦2,𝑧2), and 𝑝⃗3=(𝑥3,𝑦3,𝑧3).

 Let
 𝑛⃗ =(𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)
 i.e.
 𝑥𝑛=(𝑦2−𝑦1)(𝑧3−𝑧1)−(𝑧2−𝑧1)(𝑦3−𝑦1)
 𝑦𝑛=(𝑧2−𝑧1)(𝑥3−𝑥1)−(𝑥2−𝑥1)(𝑧3−𝑧1)
 𝑧𝑛=(𝑥2−𝑥1)(𝑦3−𝑦1)−(𝑦2−𝑦1)(𝑥3−𝑥1)

 If the three points are collinear, then 𝑛⃗ =(0,0,0)=0. Otherwise, the three points are on a plane,
 with 𝑛⃗  being normal (perpendicular) to the plane.

 As mentioned in a comment, if we look at the triangle from the side the normal vector 𝑛⃗  points to,
 the points are in counterclockwise order; but, if we look at the triangle from the other side, they
 are in clockwise order.

 If we know that the three points are on a plane with normal vector 𝑘⃗ , then

 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) > 0, counterclockwise
 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) < 0, clockwise
 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) = 0, oops

 The "oops" case covers several possible situations. For example, if the three points are collinear,
 then 𝑛⃗ =0. Or, if the three points are on a plane parallel to 𝑘⃗ , the result is zero also.
 */

int orientationOfThreePoints(Point *p, Point *q, Point *r)
{
    Plane *plane = NULL;
    Vector *n = NULL;

    plane = planeByPoints(p, q, r);
    n = planeGetNormalVector(plane);

    float orient = vectorMultiplyDot(n, n);

    if (orient > 0.0) return COUNTERCLOCKWISE;
    else if (orient < 0.0) return CLOCKWISE;
    else return OOPS;

}

Point *intersectPlaneAndLine(Plane *plane, Line *line)
{
    Point *intersect_point = NULL;

    Vector *linePoint = createVector(line->p->x, line->p->y, line->p->z);

    Point *somePlanePoint = planeGetSomePointOfPlane(plane);

    Vector *planePoint = createVector(somePlanePoint->x, somePlanePoint->y, somePlanePoint->z);
    /*
     vector diff = subVectors(linePoint,planePoint);

     return addVectors(addVectors(diff,planePoint),scaleVector(-dotProduct(diff,planeNormal)/dotProduct(lineVector,planeNormal),lineVector));
     */

    Vector *diff = vectorSubstractVector(linePoint, planePoint);
    Vector *planeNormal = planeGetNormalVector(plane);
    float d = vectorMultiplyDot(line->v, planeNormal);

    if (fabsf(d)>= FLT_EPSILON)
    {

        Vector *intersect_vector = vectorAddVector(vectorAddVector(diff, planePoint),
                                                   vectorMultiplyFloat(line->v,-vectorMultiplyDot(diff,planeNormal)/d));

        intersect_point = createPoint(intersect_vector->x, intersect_vector->y, intersect_vector->z);
        freePoint(&somePlanePoint);
        freeVector(&linePoint);
        freeVector(&diff);
        freeVector(&planeNormal);
    }
    else // if d=0 plane and line parralel, or line fully lies on plane
    {
        // check is  line's point lies on plane?
        if (isPointOnPlane(plane, line->p)) intersect_point = createPoint(INFINITY, INFINITY, INFINITY);
        else intersect_point = createPoint(INFINITY, -INFINITY, 0);
    }

    return intersect_point;
}

Line *intersectTwoPlanes(Plane *plane1, Plane *plane2)
{
    Line *intersect_line = NULL;
    // TODO: check if planes parallels or mutch up
    /*
     https://stackoverflow.com/questions/6408670/line-of-intersection-between-two-planes/18092154#18092154
     // Intersection of 2-planes: a variation based on the 3-plane version.
     // see: Graphics Gems 1 pg 305
     //
     // Note that the 'normal' components of the planes need not be unit length
     bool isect_plane_plane_to_normal_ray(
            const Plane& p1, const Plane& p2,
            // output args
            Vector3f& r_point, Vector3f& r_normal)
     {
     // logically the 3rd plane, but we only use the normal component.
        const Vector3f p3_normal = p1.normal.cross(p2.normal);
        const float det = p3_normal.length_squared();

     // If the determinant is 0, that means parallel planes, no intersection.
     // note: you may want to check against an epsilon value here.
        if (det != 0.0) {
            // calculate the final (point, normal)
            r_point = ((p3_normal.cross(p2.normal) * p1.d) +
            (p1.normal.cross(p3_normal) * p2.d)) / det;
            r_normal = p3_normal;
            return true;
        }
        else {
        return false;
        }
     }
     */

    /*  To get the intersection of 2 planes, we need a point on the line and the direction of that line.
    Finding the direction of that line is  just cross the 2 normals of the 2 planes that are intersecting.
    */

    // Find normal of two planes
    Vector *n1 = planeGetNormalVector(plane1);
    Vector *n2 = planeGetNormalVector(plane2);

    // Direction of intersected line
    Vector *d = vectorMultiplyCross(n1, n2);
    float det = vectorLengthSquared(d);

    if(fabsf(det) >= FLT_EPSILON)
    {

        Vector *vpoint = vectorAddVector(vectorMultiplyFloat(vectorMultiplyCross(d,n2), plane1->d),
                                         vectorMultiplyFloat(vectorMultiplyCross(d,n1), plane2->d));
        vpoint = vectorDivideFloat(vpoint, det);
        Point *point = createPoint(vpoint->x, vpoint->y, vpoint->z);

        intersect_line = lineByVectorPoint(d,point);
    }


    return intersect_line;
}

