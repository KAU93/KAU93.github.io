#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

/*!
 *  \brief Класс для работы с типом данных точка
 *  \details Этот класс предназначен для работы с типом данных точка в 3D пространстве,
 *  которая задается тремя декартовыми координатами x,y,z
 */

class Line;
class Triangle;

class Point
{
protected:
  double x,y,z; ///< Заданные координаты точки. По умолчанию координаты равны 0
public:
  friend class Line;
  friend class Triangle;
  /*!
   * \brief DetMinor - Функция для расчета определителя минора матрицы
   *   {[i  ;  j  ;  k];
   * [p1.x ; p1.y ; p1.z];
   * [p2.x ; p2.y ; p2.z]}
   * разложенной по первой строке
   * \param [in] p1 - первая точка
   * \param [in] p2 - вторая точка
   * \param [out] M1 - определитель первого минора
   * \param [out] M2 - определитель второго минора
   * \param [out] M3 - определитель третьего минора
   */
  friend void DetMinor(const Point &p1,const Point &p2, double &M1, double &M2, double& M3);
  /*!
   * \brief Square - Функция рассчета площади треугольника заданного точками
   * \param [in] p1 - первая точка треугольника
   * \param [in] p2 - вторая точка треугольника
   * \param [in] p3 - третья точка треугольника
   * \return Возвращает численное значение площади треугольника
   */
  friend double Square(const Point &p1,const Point &p2,const Point &p3);
  Point(double X=0, double Y=0, double Z=0);
  Point(const Point &P);
  virtual ~Point();

  void setPoint(double X=0, double Y=0, double Z=0);


  Point& operator= (const Point &P);
  bool operator ==(const Point &P)const;
  bool operator !=(const Point &P)const;
  friend const Point operator+ (const Point &r_P,const Point &l_P);
  friend const Point operator- (const Point &r_P,const Point &l_P);

  void set_x(double X);
  void set_y(double Y);
  void set_z(double Z);

  double get_x()const ;
  double get_y()const ;
  double get_z()const ;

  void print();

};



#endif // POINT_H
