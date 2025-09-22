//Programa principal práctica 15
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

#include <string.h>
#include "matrix.h"
using namespace math;

//Defino una matriz que albergue ambas funciones
matrix<double> f(matrix<double> xx){
  //Obtengo los elementos del vector xx
  double x=xx(0,0);
  double y=xx(1,0);
  //enero una matriz solución
  matrix<double>func(2,1);
  //Establezco las constantes que vamos a utilizar
  double l=1;
  double g=9.80665;
  //Defino los dos elementos de la función
  func(0,0)=-(g/l)*sin(y);
  func(1,0)=x;
  return func;
}

//Defino el método de euler
matrix<double> euler(matrix <double> (*f)(matrix<double>),double h,matrix<double> x){
  //Leo el número de ecuaciones diferenciales
  double n=x.RowNo();
  double j=x.ColNo();
  //Genero el número que alberga el resultado
  matrix<double> y(2,1);
  //Calculo el nuevo valor de la solución
  y=x+h*f(x);
  return y;
}

//Defino el método de Runge Kutta 2
matrix<double> RK2(matrix<double> (*f)(matrix<double>),double h, matrix<double> x){
  double n=x.RowNo();
  double j=x.ColNo();
  //Genero el valor de las solución
  matrix<double>y(2,1);
  //Genero el valor de a2,p y q
  double a2=1;
  double p=1/(2.*a2);
  double q=1/(2.*a2);
  double a1=1-a2;
  //Obtengo el valor de las y
  y=x+h*(a1*f(x)+a2*f(x+q*h*f(x)));
  return y;
}

//Defino el método de Runge Kutta 4
matrix<double> RK4(matrix<double> (*f)(matrix<double>),double h, matrix<double> x){
  double n=x.RowNo();
  double j=x.ColNo();
  //Genero una matriz para la solución
  matrix<double> y(2,1);
  //Calculo el valor de las k
  matrix<double>k1(2,1);
  k1=f(x);
  matrix<double>k2(2,1);
  k2=f(x+0.5*k1*h);
  matrix<double>k3(2,1);
  k3=f(x+0.5*k2*h);
  matrix<double>k4(2,1);
  k4=f(x+h*k3);
  //Nuevo valor de la solución
  y=x+((1./6.)*(k1+(2.*k2)+(2.*k3)+k4)*h);
  return y;
  }

//Función principal
int main(){
  //Método de euler
  double pi=acos(-1);
  double thetain=pi/4.;
  double omegain=0;
  matrix<double>coin(2,1);
  coin(0,0)=omegain;
  coin(1,0)=thetain;
  double h=0.01;
  double N=300;
  double tmin=0;
  matrix<double>x(2,1);
   double omega2=0;
  double theta2=pi/4.;
  matrix<double> coin2(2,1);
  coin2(0,0)=omega2;
  coin2(1,0)=theta2;
  matrix<double> x2(2,1);
   double omega3=0;
  double theta3=pi/4.;
  matrix<double> coin3(2,1);
  coin3(0,0)=omega3;
  coin3(1,0)=theta3;
  double tmin3=0;
  matrix<double> x3(2,1);
  //Abro un fichero para guardar los datos
  ofstream values1("Datos2.txt");
  //Guardo la condición inicial
  values1 << tmin << " " << coin(1,0) << " " << coin2(1,0) << " " << coin3(1,0) <<  endl;
  while(tmin<3){
    tmin=tmin+h;
    x=euler(f,h,coin);
    x2=RK2(f,h,coin2);
    x3=RK4(f,h,coin3);
    //Guardo los valores en el fichero
    values1 << tmin << " " << x(1,0) << " " << x2(1,0) << " " << x3(1,0) <<  endl;
    //Matrix auxiliar
    coin=x;
    coin2=x2;
    coin3=x3;
  }
  values1.close();
  return 0;
  
}
