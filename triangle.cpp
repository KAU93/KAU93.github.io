#include "triangle.h"


Triangle::Triangle():A(0),B(0),C(0),D(0),P1(0),P2(0),P3(0)
{

}

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
{
  setTriangle(p1,p2,p3);
}

Triangle::Triangle(const Triangle &tri)
{
    setTriangle(tri);
}

Triangle::~Triangle()
{

}

Triangle &Triangle::operator = (const Triangle &tri)
{
    if(this == &tri)
      {
        return *this;
      }
    setTriangle(tri);
    return *this;
}

void Triangle::setTriangle(const Point &p1, const Point &p2, const Point &p3)
{
  P1=p1;
  P2=p2;
  P3=p3;
  calc_Plane();
}

void Triangle::print()
{
  std::cout<<A<<"x+"<<B<<"y+"<<C<<"z+"<<D<<"=0"<<std::endl;
}

void Triangle::setTriangle(const Triangle &tri)
{
  P1=tri.P1;
  P2=tri.P2;
  P3=tri.P3;
  calc_Plane();

}

void Triangle::calc_Plane()
{
   // double Mi,Mj,Mk;

    DetMinor(P2-P1,P3-P1,A,B,C);
    if((0==A) && (0==B) && (0==C))
      {
        std::cerr<<"ERROR! The points is not make triangle!";
        exit(EXIT_FAILURE);
      }
    D=-(A*P1.x+B*P1.y+C*P1.z);

}
