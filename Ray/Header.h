//
//  Header.h
//  Ray
//
//  Created by Nahom Negash on 9/14/20.
//

#ifndef Header_h
#define Header_h
#include "/usr/local/Cellar/cimg/2.9.2/include/CImg.h"
#include<math.h>
#include<vector>
#include<Eigen>


class Tracer{
public:
  Tracer(const std::string &file);
  ~Tracer();
  void writeImage(const int image_width, const int image_hig);
};

class Ray{
public:
 Eigen::Vector3d position, direction;
 Ray(){}
 Ray(const Eigen::Vector3d p, const Eigen::Vector3d d){ position = p; direction = d;}
 Eigen::Vector3d orig() const {return position;}
 Eigen::Vector3d dir() const {return direction;}
 Eigen::Vector3d location_at(float a) const {return (position + direction*a);}
};

Eigen::Vector3d color(const Ray& r){
    Eigen::Vector3d unit_direction;
    unit_direction = r.dir();
    unit_direction.normalize();
    float t = 0.5*(unit_direction.y() + 1.0);
    
    return (1.0-t) * Eigen::Vector3d(1.0,1.0,1.0) + t*Eigen::Vector3d(0.5,0.7,1.0);
};
// when a ray and an object intersect, some information needs to be stored about the instersection
class intersection{
};

class camera{
public:
    camera(Eigen::Vector3d from, Eigen::Vector3d at, Eigen::Vector3d up, float vfov, float aspect, float apeture);
};


class Fill{
public:
  Eigen::Vector3d color;
  double kd, ks, shine, transmittance, ior;
};

class hit{
public:
  double t,alpha, beta, gamma;
  Eigen::Vector3d p,n,v;
  Fill f;
  int raydepth;
};

#endif /* Header_h */
