#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

//   Lab 2 Variant 10

class Line ;
class Ray ;
class Point
{
public:
	Point() 
	{
		x = 0;
		y = 0;
	}
	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	double x, y;
};
class Line 
{
public:
	Line() 
	{
		set_distance();
	}
	Line(Point a, Point b)
	{
		A = a;
		B = b;
	}
	Point A,B;
	double length;

	double Distance(Point a, Point b)
	{
		//Pifagor
		return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	}
	void set_distance()
	{
		length = abs(Distance(A, B));
	}
	void   display() {
		cout << "\nDisplay info for line:\n";
		cout << "\tLength: " << length << endl;
		cout << "\tCordinate A(" << A.x << "," << A.y << ") and B(" << B.x << ", " << B.y << ")\n";
	}
	friend std::ostream& operator<< (std::ostream& out, const Point& point) {return out;}
};

class Ray : Line  // ³??????
{
public:
	Point a, b;

	Ray(Point _a, Point _b)
	{
		a = _a;
		b = _b;
		set_distance();
	}
	Ray() 
	{
		set_distance();
	}
private:
	double length;
public:
	double get_length() { return length; }
	void   substract_len() 
	{
		cout << "\n???????? ??????? ??????? AB ?? 5: \n";
		cout << "??????? ???????: " << length;
		length -= 5;
		cout << "\n??????? ????? ????????? ?? 5";
	}
	void   display() 
	{
		cout << "\nDisplay info for ray:\n";
		cout << "\tLength: " << length << endl;
		cout << "\tCordinate A(" << a.x << "," << a.y << ") and B(" << b.x << ", " << b.y << ")\n";
	}
	double Distance(Point a, Point b) 
	{
		//Pifagor
		return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	}
	void set_distance()
	{
		length = abs(Distance(a, b));
	}
	friend std::ostream& operator<< (std::ostream& out, const Ray& point) ;
};
std::ostream& operator<<(std::ostream& out, const Ray& t)
{
	out << "\n³?????? ??????? ????? ????????: " << t.length << " ? ????????????, A(" << t.a.x << ", " << t.a.y << ") and B(" << t.b.x << ", " << t.b.y << ")" << endl;
	return out;
}

Ray generate_Point(Point& A, Point& B)
{
	Ray r;
	r.a.x = rand() % 20,
		r.a.y = rand() % 20,
		r.b.x = rand() % 20,
		r.b.y = rand() % 20;
	return r;
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");
	srand(time(0));
	Point A, B;
	A.x = rand() % 10,
		A.y = rand() % 10,
		B.x = rand() % 10,
		B.y = rand() % 10;
	Line l(A, B);
	l.set_distance();
	l.display();
	Ray r = generate_Point(A, B);
	r.set_distance();
	r.display();
	r.substract_len();
	cout << r;
	return 0;
}