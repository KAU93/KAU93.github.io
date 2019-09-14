#include "point.h"
//#include <iostream>

void DetMinor(const Point &p1, const Point &p2, double &M1, double &M2, double &M3)
{
    M1=p1.y*p2.z-p1.z*p2.y;
    M2=p2.x*p1.z-p1.x*p2.z;
    M3=p1.x*p2.y-p2.x*p1.y;
}


double Square(const Point &p1, const Point &p2, const Point &p3)
{
  double  M1,M2,M3;
  DetMinor(p2-p1,p3-p1,M1,M2,M3);

  return 0.5*sqrt(M1*M1+M2*M2+M3*M3);
}

Point::Point(double X, double Y, double Z):x(X),y(Y),z(Z){}

Point::Point(const Point &P)
{
  x=P.get_x();
  y=P.get_y();
  z=P.get_z();
}

Point::~Point()
{

}

void Point::setPoint(double X, double Y, double Z)
{
  set_x(X);
  set_y(Y);
  set_z(Z);
}

Point &Point::operator =(const Point &P)
{
  if(this==&P)
    {
      return *this;
    }

  x=P.get_x();
  y=P.get_y();
  z=P.get_z();

  return *this;
}

bool Point::operator ==(const Point &P)const
{
  if(x==P.get_x() && y==P.get_y() && z==P.get_z())
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Point::operator !=(const Point &P)const
{
  if(this->operator ==(P))
    {
      return false;
    }
  else
    {
      return true;
    }
}

const Point operator +(const Point &r_P, const Point &l_P)
{
  Point Rez;
  Rez.x=r_P.x+l_P.x;
  Rez.y=r_P.y+l_P.y;
  Rez.z=r_P.z+l_P.z;

  return Rez;
}

const Point operator -(const Point &r_P, const Point &l_P)
{
  Point Rez;
  Rez.x=r_P.x-l_P.x;
  Rez.y=r_P.y-l_P.y;
  Rez.z=r_P.z-l_P.z;

  return Rez;
}

void Point::set_x(double X)
{
  x=X;
}

void Point::set_y(double Y)
{
  y=Y;
}

void Point::set_z(double Z)
{
  z=Z;
}

double Point::get_x() const
{
  return x;
}

double Point::get_y() const
{
  return y;
}

double Point::get_z() const
{
  return z;
}

void Point::print()
{
  std::cout<<"("<<x<<";"<<y<<";"<<z<<")"<<std::endl;
}
