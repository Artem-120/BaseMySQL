// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
double f(double x) 
{
	return (exp(x) * (1 + sin(x))) / (1 + cos(x));

}
double Left_Rect(double a, double b, int n) 
{
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 0; i <= n - 1; i++) {
		sum += h * f(a + i * h);
	}
	return sum;
}
double Right_Rect(double a, double b, int n) 
{
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		sum += h * f(a + i * h);
	}
	return sum;
}
int main() 
{
	double a, b;
	int n;
	a = 1;
	b = 2;
	n = 1000;
	
	cout << "Left_rect" << Left_Rect(a, b, n) << endl;
	cout << "Right_Rect" << Right_Rect(a, b, n) << endl;
	return 0;
}