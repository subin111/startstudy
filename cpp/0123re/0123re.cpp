#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

//7장 상속 복습
#if 0
int main()
{
    std::cout << "Hello World!\n";
}
#endif
//7장 상속 복습
#if 0
int main()
{
    std::cout << "Hello World!\n";
}
#endif

//4장 객체 포인터 복습
#if 1
int main()
{
    ;
}
#endif
//3장 class 복습
#if 0
class Rectangle {

public:
    int height;
    int width;
    int length;
    Rectangle();
    Rectangle(int width, int height);
    Rectangle(int length);
    bool isSquare();

};
Rectangle::Rectangle() {

    width = height = 1;
}
Rectangle::Rectangle(int w, int h) {

    width = w;
    height = h;
}
Rectangle::Rectangle(int length) {

    width = height = length;
}
bool Rectangle::isSquare() {
    
    if (width != height) return false;
    else return true;

}

int main(void) {

    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
    if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;

    return 0;
}
#endif

#if 0
class Circle {
public:
    int radius;
    Circle();
    Circle(int r);
    ~Circle();
    double getArea();
};
Circle::Circle() {

    radius = 1;
    cout << "반지름 " << radius << "원 생성" << endl;
}
Circle::Circle(int r) {

    radius = r;
    cout << "반지름 " << radius << "원 생성" << endl;
}

Circle::~Circle() {

    cout << "반지름 " << radius << "원 소멸" << endl;
}
double Circle::getArea() {

    return 3.14 * radius * radius;

}

Circle globalDonut(1000); //전역 객체 생성
Circle globalPizza(2000);

void f() {
    Circle fDonut(100);//지역 객체 생성
    Circle fPizza(200);
}


int main()
{
    //Circle donut; // 매개변수 없는 생성자 호출이엇던거임
    //double area = donut.getArea();
    //cout << "donut 면적은 " << area << endl;

    //Circle pizza(30);//매개변수 있는 생성자 호출
    //cout << "pizza 면적은 " << pizza.getArea()<< endl;
    
    Circle mainDonut; // 지역 객체 생성
    Circle mainPizza(30);
    f();

}
#endif