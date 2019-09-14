#include <iostream>
#include <cmath>
#include "line.h"
#include "point.h"
#include "triangle.h"

using namespace std;

/*!
 * \brief FindPointIntersection - функция поиска пересечения отрезка и треугольника.
 * \warning Программа не рассчитывает точку пересечения в случае,
 * если отрезок и треугольник принадлежат одной плоскости. В данном случае, функция
 * выдает соответсвующее предупреждение и возвращает false!!!
 * \param [in] tri - Треугольник
 * \param [in] line - Отрезок
 * \param [out] RezPoint - Точка пересечения
 * \return true - если точка пересечения Треугольника и Отрезка найдена\n
 *        false - если точка пересечения не найдена.
 */
bool FindPointIntersection(const Triangle &tri, const Line &line,Point &RezPoint);

int main()
{

  double x,y,z;

  while(true)
    {
      cout<<"Triangle data entry"<<endl;
      cout<<"Coordinates of the first point: ";
      cin>>x>>y>>z;

      Point T1(x,y,z);

      cout<<"Coordinates of the second point: ";
      cin>>x>>y>>z;

      Point T2(x,y,z);

      cout<<"Coordinates of the third point: ";
      cin>>x>>y>>z;

      Point T3(x,y,z);

      Triangle tri(T1,T2,T3);

      cout<<"\n\nLine segment data entry"<<endl;
      cout<<"Coordinates of the first point: ";
      cin>>x>>y>>z;

      Point L1(x,y,z);

      cout<<"Coordinates of the second point: ";
      cin>>x>>y>>z;

      Point L2(x,y,z);

      Line line(L1,L2);

      Point Rez;
      cout<<"\n\nStart calculation intersection point\n"<<endl;

      if(FindPointIntersection(tri,line,Rez)==true)
        {
          cout<<"Point intersection: ";
          Rez.print();
          cout<<endl;
        }

      cout<<"\nEnd calculation\n\n\n";

    }



  return 0;
}


bool FindPointIntersection(const Triangle &tri, const Line &line,Point &RezPoint)
{

  double ind_fist=tri.get_A()*line.get_P1().get_x() + tri.get_B()*line.get_P1().get_y() + tri.get_C()*line.get_P1().get_z()+tri.get_D();
  double ind_last=tri.get_A()*line.get_P2().get_x() + tri.get_B()*line.get_P2().get_y() + tri.get_C()*line.get_P2().get_z()+tri.get_D();


  if((ind_fist==0)&&(ind_last==0))
    {
      cerr<<"ERROR! The line segment and the triangle lie in the same plane"<<endl;
      return false;

    }
  else if((ind_fist!=0) && (ind_last!=0) && (int(ind_fist/abs(ind_fist))==int(ind_last/abs(ind_last)))) // Если знаки совпадают, то точки отрезка лежат по одну сторону плоскости
    {
      cerr<<"ERROR! The line segment and the triangle is not intersection!"<<endl;
      return false;
    }
  else
    {
        double det_lam=line.get_ax()*tri.get_A()+line.get_ay()*tri.get_B()+line.get_az()*tri.get_C();
        double det=-(line.get_x1()*tri.get_A()+line.get_y1()*tri.get_B()+line.get_z1()*tri.get_C()+tri.get_D());

        double lam=det/det_lam;
        Point Rez;
        Rez.set_x(line.get_x1()+line.get_ax()*lam);
        Rez.set_y(line.get_y1()+line.get_ay()*lam);
        Rez.set_z(line.get_z1()+line.get_az()*lam);

        // Проверка принадлежности точки треугольнику Sобщ=S1+S2+S3

         double S_ob=Square(tri.get_P1(),tri.get_P2(),tri.get_P3());
         double Sum_S=Square(Rez,tri.get_P1(),tri.get_P2())+
                      Square(Rez,tri.get_P2(),tri.get_P3())+
                      Square(Rez,tri.get_P1(),tri.get_P3());

         double eps=1e-10;

         if(abs(S_ob-Sum_S)<=eps)
           {
             RezPoint=Rez;
             return true;
           }
         else
           {
             cout<<"The point intersection is not lie in triangle"<<endl;

             return false;
           }



    }

}
