#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
/*!
 * \brief The Triangle class предназначен для работы с типом данных Треугольник
 * \details Тип данных Треугольник задается координатами образующих его точек.
 * В данном классе происходит расчет уравнения плоскости которой принадлежат введенные точки треугольника.
 * Если введенные точки не образуют треугольник, программа выдает соответствующее предупреждение
 * и заканчивает свою работу
 */


class Triangle
{
protected:
  double A,B,C,D; ///< Коэффициенты плоскости
  Point P1,P2,P3; ///< Точки образующие треугольник
  void setTriangle(const Triangle &tri);
  void calc_Plane();
public:

  Triangle();
  Triangle(const Point &p1,const Point &p2,const Point &p3);
  Triangle(const Triangle &tri);
  virtual ~Triangle();
  Triangle& operator =(const Triangle &tri);
  void setTriangle(const Point &p1,const Point &p2,const Point &p3);

  double get_A()const {return A;}
  double get_B()const {return B;}
  double get_C()const {return C;}
  double get_D()const {return D;}
  Point get_P1()const {return P1;}
  Point get_P2()const {return P2;}
  Point get_P3()const {return P3;}
  void print();

};

#endif // TRIANGLE_H
