#if 1

//생성자 / 소멸자
/*
1. 생성자: 객체가 생성 될 때 자동으로 호출되는 함수
(클래스 이름과 동일해야 한다.
생성자 정의를 안 해주면 클래스와 동일한 함수를 컴파일러가 만들어준다.
이 때 아무런 내용이 없다.)
- 변수를 초기화 할 때 유용하다.

2. 소멸자: 개체가 소멸될 때 자동으로 1번 호출이 된다.
- 동적 메모리를 반납 할 때 주로 쓰인다.
  소멸자는 클래스 이름과 동일한 함수 이지만 함수 이름 앞에 ~이 붙는다.
*/


#include <iostream> 
#include <cstdlib>  
using namespace std;
class Myclass {
public:
    int w, h;

    Myclass() {//생성자
        cout << "생성자 Myclass가 호출되었습니다.\n";
    }
    Myclass(int a, int b) {// 함수 이름이 같을 때, 매개변수 갯수나 타입이 다르면
        //컴파일러가 자동으로 구분해서 호출해주는 방식- overloading(c++, c#, Java)
        w = a;
        h = b;
        cout << "생성자 Myclass가 호출되었습니다.\n";
        cout << "w: " << w << " h: " << h << endl;
    }
    ~Myclass() {//소멸자
        cout << "소멸자 ~Myclass가 호출되었습니다.\n";
    }
};

int main(void)
{
    Myclass My(2, 3);//오브젝트 My, 객체가 생성되었으므로 생성자 자동 호출됨

    return 0;//소멸자 자동으로 1번 호출

}
#endif
#if 0
#include <iostream> 
#include <cstdlib>  
using namespace std; 
class Myclass {
public:
    int w, h;

    Myclass() {//생성자
        cout << "생성자 Myclass가 호출되었습니다.\n";
    }
    Myclass(int a, int b) {// 함수 이름이 같을 때, 매개변수 갯수나 타입이 다르면
        //컴파일러가 자동으로 구분해서 호출해주는 방식- overloading(c++, c#, Java)
        w = a;
        h = b;
        cout << "생성자 Myclass가 호출되었습니다.\n";
        cout << "w: " << w << " h: " << h << endl;
    }
    ~Myclass() {//소멸자
        cout << "소멸자 ~Myclass가 호출되었습니다.\n";
    }
};

int main(void)
{
    Myclass My(2,3);//오브젝트 My, 객체가 생성되었으므로 생성자 자동 호출됨

    return 0;//소멸자 자동으로 1번 호출

}
#endif
#if 0
#include <iostream> //stdio.h와 유사 
#include <cstdlib>  // stdlib.h ==> cstdlib
using namespace std; 
//single 변수 동적 할당
class Rectangle {
public:
    int width;
    int height;
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    int getArea();
};
    
int Rectangle::getArea() {
        return width*height;
}

int main()
{
    Rectangle rect(3,5);
    cout << "사각형의 면적은 " << rect.getArea() << endl;
}
#endif
#if 0
#include <iostream> //stdio.h와 유사 printf scanf...
#include <cstdlib>  // stdlib.h ==> cstdlib
using namespace std; //std라는 그룹 이름을 쓰지 않겠다.
//single 변수 동적 할당
class Circle {
public:
    int radius;
    Circle(); //반지름 1짜리 호출
    Circle(int r); // 반지름 r 호출
    double getArea();
};
Circle::Circle() {
    radius = 1;
    cout << "반지름 " << radius << "원 생성" << endl;
}
Circle::Circle(int r) {
    radius = r;
    cout <<"반지름 " << radius << "원 생성" << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}


int main()
{
    int num;
    int* p;//포인터 선언
    p = &num;//num의 주소가 200일 때 변수 p에 200을 넣음
    *p = 5;// 사용
    // 포인터 사용 - num에 간접 접근
    //num = 5;이면 num에 직접 접근


    Circle donut; // 매개 변수 없는 생성자 호출
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza(30); // 매개 변수 있는 생성자 호출
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;


}
#endif
#if 0
#include <iostream> //stdio.h와 유사 printf scanf...
#include <cstdlib>  // stdlib.h ==> cstdlib
using namespace std; //std라는 그룹 이름을 쓰지 않겠다.
//single 변수 동적 할당

int main()
{
    //single 변수 정적 할당 int a;
    //single 변수 동적 할당

    int length;
    int* iarr; // 동적 배열 메모리 할당 받은 시작 주소

    cout << "동적 할당 size: ";
    cin >> length;

    iarr = new int[length];

    for (int i = 0; i < length; i++) {
        iarr[i] = i;
        
    }
    for (int i = 0; i < length; i++) {
        cout << iarr[i] << " ";

    }
    cout << endl;
    delete[] iarr;

        

    
}
#endif

#if 0
#include <iostream> //stdio.h와 유사 printf scanf...
#include <cstdlib>  // stdlib.h ==> cstdlib
using namespace std; //std라는 그룹 이름을 쓰지 않겠다.
//single 변수 동적 할당

int main()
{
    //single 변수 정적 할당 int a;
    //single 변수 동적 할당
    int* a = new int(5); // a라는 변수를 int type으로 동적 할당 
    //후 변수 값을 5로 초기화
    cout << "a가 가리키는 주소: "<< a << endl;
    cout << "a가 가리키는 주소를 번지로 해서 찾아간 값: "<< * a << endl;
    
    *a = 10;
    cout << "a가 가리키는 주소: " << a << endl;
    cout << "a가 가리키는 주소를 번지로 해서 찾아간 값: " << *a << endl;

    delete a; // 메모리 반납 (해제)
}
#endif 
#if 0
/*
=================c++를 이용한
1. width 와 height이 값을 cin으로 받아들이도록
구현 하고 width와 height의 값이 0 0 이면
프로그램을 종료 한다.
2. rect object을 동적 메모리 할당
   malloc을 할당 하여 실행 후
    cout 출력 이 끝나면 free한다.
while(1)
{

}
3. 아래의 직접 access방식을 함수
 setWidthHeight(w, h) 구현 하여 동작 되도록 한다.
        cout << "width를 입력: ";
        cin >> rect.width;

        cout << "height를 입력: ";
        cin >> rect.height;
*/
#include <iostream> 
#include <cstdlib>  // stdlib.h ==> cstdlib
using namespace std;

class Circle { // Rectangle 클래스 선언
public:
    int width;
    int height;

};

int Rectangle::getArea() {
    return width * height;
}

int main()
{
    Rectangle* rect;
    int w, h; // 지역변수: stack에 저장됨

    Circle *cr = new Circle[10]; //배열 형태의 메모리 할당

    //rect = (Rectangle *) malloc(sizeof(Rectangle));

    while (1)
    {
        // sizeof : 총 byte수 
        //rect = (Rectangle*)malloc(sizeof(Rectangle)); c언어식
        Rectangle* rect = new Rectangle;// c++식 동적 할당
        //1) Rectangle: class
        //2) rect: object/instance 이름
        //3) new: (동적 할당)
        //4) 생성자
        cout << "width를 입력: ";
        cin >> w;

        cout << "height를 입력: ";
        cin >> h;
        if (w == 0 && h == 0)
            break;
        rect->setWidthHeight(w, h);  // 와 동일==> (*rect).setWidthHeight(w, h);

        cout << "사각형의 면적은 " << rect->getArea() << endl;
        //메모리 해제 (동적 메모리를 os에 반납)
        delete rect;
        //free(rect);
    }
    delete[] cr; // cr 배열 형태의 object 해제
}
#endif 
#if 0
#include <iostream>
#include <cstdlib> // = stdlib.h
using namespace std;

class Rectangle {


public:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    int width;
    int height;
    int getArea();

    void setWidthHeight(int w, int h) {
    
        width = w;
        height = h;
    }
};

int Rectangle::getArea() {
    return width * height;
}



int main()
{
    Rectangle *rect;// rect = (Rectangle *)malloc (sizeof(Rectangle));
    int w, h;

    while (1) {
       
        rect = (Rectangle*)malloc(sizeof(Rectangle)); // rect object를 동적 메모리 할당 
        // sizeof: 총 바이트 수
        
        cout << "너비를 입력: ";
        cin >> w;
        //rect.width = *w;
        cout << "높이를 입력: ";
        cin >> h;
        

        
        if (w == 0 && h == 0) {
            cout << "종료합니다."; break;
        }
        rect->setWidthHeight(w, h);// 와 동일==> (*rect).setWidthHeight(w, h);
        
        cout << "사각형 면적은 " << rect->getArea() << endl; // 포인터가 클래스에 접근할 때는 ->
        free(rect);

    }
    return 0;
}
#endif
#if 0
#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle { // 내가 짠 코드
    

public:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    int width;
    int height;
    int getArea();
};

int Rectangle::getArea() {
    return width * height;
}

int main()
{
    Rectangle rect;
    
    while (1) {
        int* w = (int*)malloc(sizeof(int));
        int* h = (int*)malloc(sizeof(int));

        cout << "너비와 높이를 입력하세요 - 종료 0 0>>";
        cin >> *w >> *h;

        if (*w == 0 && *h == 0) {
            cout << "종료합니다."; break;
        }
        rect.width = *w;
        rect.height = *h;
        cout << "사각형 면적은 " << rect.getArea() << endl;
        free(w);
        free(h);

    }
    return 0;
}
#endif
#if 0
#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
class Circle {

public:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    int radius;
    double getArea();
};


double Circle::getArea() {
    return 3.14 * radius * radius;
}

   


int main()
{
    Circle donut; // lg: object 혹은 인스턴스
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30; // pizza 객체의 반지름을 30으로 설정
    area = pizza.getArea(); // pizza 객체의 면적 알아내기
    cout << "pizza 면적은 " << area << endl;


    return 0;
}
#endif
#if 0

//1.구조체(struct)
// c언어: 서로 다른 타입의 변수들의 집합체
// c++: 변수 외 함수 집합체
//      1) class와 모양은 동일하나 상속이 안 된다.
//      2) default: public이다., private이다.
//      3) 

//2.클래스(class)
//  ==> 변수 (자료 저장) + 함수(자료처리) 모아 놓은 틀

//3.객체(object, instance)
//  ==> class라는 틀을 이용하여 찍어낸 것(메모리 상에 존재하는 것)

//4. private 변수로 선언을 하면 변수를 외부에서 변경하는 것이
//   불가능하다. 변경을 하기 위해서는 struct안에 있는 함수를 
//   호출해서만 가능하다.
//   외부에서 함부로 바꾸지 못하도록 하는 것을 캡슐화라고 한다.

#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
class TV {

public:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    bool power;
    int channel;
    int volume;

public: //아무데서나 엑세스 가능
    void powerOn() {

        power = true;
        cout << "TV를 켰습니다." << endl;
    }

    void increase_Channel(int ch) {
        channel = ch;
        cout << "채널을 증가 시켰습니다. " << ch << endl;
        
    }


    void decrease_Channel(int ch) {
        channel = ch;
        cout << "채널을 감소 시켰습니다. " << ch << endl;
        
    }

    void increase_Volume(int vol) {
        volume = vol;
        cout << "음량을 증가 시켰습니다." << vol << endl;
        

    }
    void decrease_Volume(int vol) {
        volume = vol;
        cout << "음량을 감소 시켰습니다." <<  vol << endl;
        

    }
    void powerOff() {
        power = false;
        cout << "TV를 껐습니다." << endl;
    }

};


int main()
{
    TV lg; // lg: object 혹은 인스턴스

    //lg.powerOn = true;
    lg.powerOn();
    //lg.channel = 10;
    lg.increase_Channel(100);
    lg.decrease_Channel(50);
    // lg.volume = 300; ==> 이런 문제점 때문에 내부 함수를 사용
    lg.increase_Volume(90);
    lg.decrease_Volume(40);
    lg.powerOff();

    //cout << "POWER: " << lg.setPowerOn << endl;
    //cout << "channel: " << lg.setChannel << endl;
    //cout << "volume: " << lg.setVolume << endl;

    return 0;
}
#endif
#if 0

//1.구조체(struct)
// c언어: 서로 다른 타입의 변수들의 집합체
// c++: 변수 외 함수 집합체
//      1) class와 모양은 동일하나 상속이 안 된다.
//      2) default: public이다., private이다.
//      3) 

//2.클래스(class)
//  ==> 변수 (자료 저장) + 함수(자료처리) 모아 놓은 틀

//3.객체(object, instance)
//  ==> class라는 틀을 이용하여 찍어낸 것(메모리 상에 존재하는 것)

//4. private 변수로 선언을 하면 변수를 외부에서 변경하는 것이
//   불가능하다. 변경을 하기 위해서는 struct안에 있는 함수를 
//   호출해서만 가능하다.
//   외부에서 함부로 바꾸지 못하도록 하는 것을 캡슐화라고 한다.

#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
class TV {

private:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    bool powerOn;
    int channel;
    int volume;

public: //아무데서나 엑세스 가능
    void setPowerOn() {

        powerOn = true;
        cout << "TV를 켰습니다." << endl;
    }

    void setChannel(int ch) {// 1~200 channel 범위

        if (ch >= 1 && ch <= 200) {
            channel = ch;
            cout << "TV의 channel: " << channel << endl;
        }

    }

    void setVolume(int vol) { // 1~100 volume 범위

        if (vol >= 1 && vol <= 100) {
            volume = vol;
            cout << "VOL을 " << volume << "로 set 했습니다." << endl;
        }
        else
            cout << "볼륨이 너무 큽니다.";
    }

    void setPowerOff() {
        powerOn = false;
        cout << "TV를 껐습니다." << endl;
    }
};

int main()
{
    TV lg; // lg: object 혹은 인스턴스

    //lg.powerOn = true;
    lg.setPowerOn();
    //lg.channel = 10;
    lg.setChannel(10);
    // lg.volume = 300; ==> 이런 문제점 때문에 내부 함수를 사용
    lg.setVolume(50);
    lg.setPowerOff();

    //cout << "POWER: " << lg.setPowerOn << endl;
    //cout << "channel: " << lg.setChannel << endl;
    //cout << "volume: " << lg.setVolume << endl;

    return 0;
}
#endif
#if 0

//1.구조체(struct)
// c언어: 서로 다른 타입의 변수들의 집합체
// c++: 변수 외 함수 집합체
//      1) class와 모양은 동일하나 상속이 안 된다.
//      2) default: public이다., private이다.
//      3) 

//2.클래스(class)
//  ==> 변수 (자료 저장) + 함수(자료처리) 모아 놓은 틀

//3.객체(object, instance)
//  ==> class라는 틀을 이용하여 찍어낸 것(메모리 상에 존재하는 것)

//4. private 변수로 선언을 하면 변수를 외부에서 변경하는 것이
//   불가능하다. 변경을 하기 위해서는 struct안에 있는 함수를 
//   호출해서만 가능하다.
//   외부에서 함부로 바꾸지 못하도록 하는 것을 캡슐화라고 한다.

#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
struct TV {

private:
    //public: // default가 public이지만 public:으로 선언하는 것이 좋다.
        // c++인 경우 default가 private이다.
    bool powerOn;
    int channel;
    int volume;

public: //아무데서나 엑세스 가능
    void setPowerOn() {

        powerOn = true;
        cout << "TV를 켰습니다." << endl;
    }

    void setChannel(int ch) {// 1~200 channel 범위

        if (ch >= 1 && ch <= 200) {
            channel = ch;
            cout << "TV를 ON 하였습니다. channel: " << channel << endl;
        }

    }

    void setVolume(int vol) { // 1~100 volume 범위

        if (vol >= 1 && vol <= 100) {
            volume = vol;
            cout << "VOL을 " << volume << "로 set 했습니다." << endl;
        }
        else
            cout << "볼륨이 너무 큽니다.";
    }
};

int main()
{
    TV lg; // lg: object 혹은 인스턴스

    //lg.powerOn = true;
    lg.setPowerOn();
    //lg.channel = 10;
    lg.setChannel(10);
    // lg.volume = 300; ==> 이런 문제점 때문에 내부 함수를 사용
    lg.setVolume(50);

    //cout << "POWER: " << lg.setPowerOn << endl;
    //cout << "channel: " << lg.setChannel << endl;
    //cout << "volume: " << lg.setVolume << endl;

    return 0;
}
#endif
#if 0


int main()
{
   cout << "Hello World!\n";
}
#endif
