#ifndef LINE_H
#define LINE_H

#include "point.h"

/*!
 * \brief Класс для работы с отрезком заданном в 3D
 * \details Данный класс предназначен для работы с отрезком прямой
 *  заданой координатами образующих точек. В данном классе реализовано вычисление
 *  уравнения прямой (которой принадлежит заданный отрезок) в параметрическом виде.
 * Если введенные точки совпадают, то программа выдает соответствующее предупреждение
 * и заканчивает свою работу
 */

class Line
{
protected:
   Point P1,P2;     ///< Точки образующие  отрезок

   /*!
    * \brief x1,y1,z1,ax,ay,az - Параметры прямой к которой принадлежит отрезок ограниченный точками P1 и P2
    */
   double x1,y1,z1;
   double ax,ay,az;
public:
  Line();
  Line(const Point& first, const Point& last);
  Line(const Line &line);
  virtual ~Line();
  Line& operator = (const Line &line);
  void setLine(const Point& first, const Point& last);
  void setLine(const Line &line);

  double get_x1()const {return x1;}
  double get_y1()const {return y1;}
  double get_z1()const {return z1;}
  double get_ax()const {return ax;}
  double get_ay()const {return ay;}
  double get_az()const {return az;}
  Point get_P1()const {return P1;}
  Point get_P2()const {return P2;}

  void print();
};



#endif // LINE_H
