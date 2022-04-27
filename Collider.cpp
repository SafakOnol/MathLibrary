#include "Collider.h"
#include <math.h>

using namespace std;
Vec4 quadVec(0.0f, 0.0f, 0.0f, 0.0f);

bool Collider::RaySphereCollisionDetected(Ray ray_, Sphere sphere_) {
    printf("Ray Start: \n");
    printf("Start: %f, %f, %f\n", ray_.start.x, ray_.start.y, ray_.start.z);
    printf("Ray Direction: \n");
    printf("Dir: %f, %f, %f\n", ray_.dir.x, ray_.dir.y, ray_.dir.z);

    Collider::quadraticEquation(ray_, sphere_);
    printf("Quadratic Eq: \n");
    printf("x: %f, y: %f, z: %f, w: %f\n", quadVec.x, quadVec.y, quadVec.z, quadVec.w);

    // check if the discriminant (quaVec.w) is negative
    if (quadVec.w < 0.0f)
        return false; // no collision
    else
        return true;
}

Vec3 Collider::RaySphereCollisionPoint(Ray ray_, Sphere sphere) {

    float t;
    //t1= -B-sqrt(Discriminant)/2A
    float t1 = (-quadVec.y - sqrt(quadVec.w)) / (2 * quadVec.x);
    //t2= -B+sqrt(Discriminant)/2A
    float t2 = (-quadVec.y + sqrt(quadVec.w)) / (2 * quadVec.x);

    if (t1 >= 0 && t2 >= 0) {
        t = min(t1, t2);
        return ray_.currentPosition(t);
    }
    else if (t1 < 0 && t2 < 0) {
        //No collision, the sphere is behind the ray, return null
        return Vec3(0.0f, 0.0f, 0.0f);
    }
    else if (t1 >= 0 && t2 < 0) {
        //we are inside sphere, we have two intersection points , one behind and one at the front . 
        printf("\n TWO INTERSECTIONS\n");

        return ray_.currentPosition(t1);
    }
    else if (t2 >= 0 && t1 < 0) {
        //we are inside sphere, we have two intersection points , one behind and one at the front . 
        printf("\n TWO INTERSECTIONS\n");

        return ray_.currentPosition(t2);
    }


}

void Collider::quadraticEquation(Ray ray, Sphere sphere) {
    //A=V^2=V.V
    Vec3 testV = ray.dir;
    quadVec.x = testV.dotV3(ray.dir);

    //B=2(S-C).V
    Vec3 testY = ray.dir;
    quadVec.y = 2 * testV.dotV3((ray.start));

    //C =(S-C)^2 -R^2
    Vec3 testZ = (ray.start);
    quadVec.z = testZ.dotV3((ray.start)) - pow(sphere.radius, 2);

    //discriminant = B*B-4*A*C
    quadVec.w = quadVec.y * quadVec.y - (4 * quadVec.x * quadVec.z);// discriminant

}


bool Collider::isInside(const AAB& box, Vec3 p) {
    if ((0 <= p.x <= box.rx) && (0 <= p.y && p.y <= box.ry) && (0 <= p.z && p.x <= box.rz)) {
        return true;
    }
    return false;

}

Vec3 Collider::RayAABCollisionPoint(Ray& ray, const AAB& box) {
    ///.....
    float tx, ty, tz;
    //X Intersection
    if (ray.dir.x == 0) {
        tx = NULL;
    }
    else if (ray.dir.x > 0) {
        tx = (0 - ray.start.x) / ray.dir.x;
    }
    else if (ray.dir.x < 0) {
        tx = (box.rx - ray.start.x) / ray.dir.x;
    }

    //Y Intersection y=0, y=ry
    if (ray.dir.y == 0) {
        ty = NULL;
    }
    else if (ray.dir.y > 0) {
        ty = (0 - ray.start.y) / ray.dir.y;
    }
    else if (ray.dir.y < 0) {
        ty = (box.ry - ray.start.y) / ray.dir.y;
    }

    //Z Intersection z=0, z=rz
    if (ray.dir.z == 0) {
        tz = NULL;
    }
    else if (ray.dir.z > 0) {
        tz = (0 - ray.start.z) / ray.dir.z;
    }
    else if (ray.dir.z < 0) {
        tz = (box.rz - ray.start.z) / ray.dir.z;
    }
    Vec3 p;

    if (tx != NULL) {
        p = ray.currentPosition(tx);
        if (isInside(box, p) == true) {
            return p;
        }
    }
    else if (ty != NULL) {
        p = ray.currentPosition(ty);
        if (isInside(box, p) == true) {
            return p;
        }
    }
    else if (tz != NULL) {
        p = ray.currentPosition(tz);
        if (isInside(box, p) == true) {
            return p;
        }
    }

    else {
        printf("NO INTERSECTIONS\n");
        return Vec3(0.0f, 0.0f, 0.0f);

    }
}