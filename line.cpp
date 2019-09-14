#include "line.h"
#include <iostream>

Line::Line():x1(0),y1(0),z1(0),ax(0),ay(0),az(0)
{

}

Line::Line(const Point &first, const Point &last)
{
  setLine(first,last);
}

Line::Line(const Line &line)
{
  setLine(line);
}

Line::~Line()
{

}

Line &Line::operator =(const Line &line)
{
  if(this == &line)
    {
      return *this;
    }
  setLine(line);

  return *this;
}

void Line::setLine(const Point &first, const Point &last)
{
    if(first==last)
      {
        std::cerr<<"ERROR! Line cannot be determined by matching points!"<<std::endl;
        exit(EXIT_FAILURE);
      }
    x1=first.x;
    y1=first.y;
    z1=first.z;

    ax=last.x-first.x;
    ay=last.y-first.y;
    az=last.z-first.z;

    P1=first;
    P2=last;
}

void Line::setLine(const Line &line)
{
  x1=line.x1;
  y1=line.y1;
  z1=line.z1;

  ax=line.ax;
  ay=line.ay;
  az=line.az;

  P1=line.P1;
  P2=line.P2;
}

void Line::print()
{
  std::cout<<"x="<<x1<<"+"<<ax<<"*n"<<std::endl;
  std::cout<<"y="<<y1<<"+"<<ay<<"*n"<<std::endl;
  std::cout<<"z="<<z1<<"+"<<az<<"*n"<<std::endl;
}
