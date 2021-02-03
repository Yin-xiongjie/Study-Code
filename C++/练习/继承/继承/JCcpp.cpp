#include<iostream>

using namespace std;

class point
{
private:
	int xpos;
	int ypos;

public:
	point(int x = 0, int y = 0)
	{
		xpos = x;
		ypos = y;
	}
	void disp()
	{
		cout << "(" << xpos << "," << ypos << ")" << endl;
	}
	int Getx()
	{
		return xpos;
	}
	int Gety()
	{
		return ypos;
	}
};
class point3D :public point
{
private:
	int zpos;

public:
	point3D(int x, int y, int z) :point(x, y)
	{
		zpos = z;
	}

	void disp()
	{
		cout << "(" << Getx() << "," << Gety()<<","<<zpos<< ")" << endl;
	}
	int Getsum()
	{
		int sum;
		sum = Getx() + Gety() + zpos;
		return sum;
	}

};

int main()
{
	point pt1(7, 8);
	cout << "pt1的坐标为：";
	pt1.disp();
	point3D pt2(4, 5, 6);
	cout << "pt2的坐标为：";
	pt2.disp();
	cout << "x,y,z坐标和为：" << pt2.Getsum() << endl;
	return 0;
}