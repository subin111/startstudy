
#if 1
/*
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

class Rectangle { // Rectangle 클래스 선언
public:
    int width;
    int height;
    int getArea(); // 면적을 계산하여 리턴하는 함수
    void setWidthHeight(int w, int h)
    {
        width = w;
        height = h;
    }
};

int Rectangle::getArea() {
    return width * height;
}

int main()
{
    Rectangle *rect;
    int w, h;

    //rect = (Rectangle *) malloc(sizeof(Rectangle));

    while (1)
    {
        // sizeof : 총 byte수 
        rect = (Rectangle *)malloc(sizeof(Rectangle));
        cout << "width를 입력: ";
        cin >> w;

        cout << "height를 입력: ";
        cin >> h;
        if (w == 0 && h == 0)
            break;
        rect->setWidthHeight(w, h);  // 와 동일==> (*rect).setWidthHeight(w, h);

        cout << "사각형의 면적은 " << rect->getArea() << endl;

        free(rect);
    }
}
#endif 


#if 0
#include <iostream> 
using namespace std;

class Rectangle { // Rectangle 클래스 선언
public:
    int width;
    int height;
    int getArea(); // 면적을 계산하여 리턴하는 함수
};

int Rectangle::getArea() {
    return width * height;
}

int main() 
{
    Rectangle rect;


    while (1)
    {
        cout << "width를 입력: ";
        cin >> rect.width;

        cout << "height를 입력: ";
        cin >> rect.height;
        if (rect.width == 0 && rect.height == 0)
            break;

        cout << "사각형의 면적은 " << rect.getArea() << endl;
    }
}
#endif 



#if 0
// 1.구조체 (struct) 
//  C언어 : 서로 다른 타입의 변수들의 집합체
//  c++   : 변수 와 함수 집합체
//          (1)  구조체 default: public이다. 
//          (2)  c++ 인경우 defualt가 private이다. 
// 2. 클래스 (class) 
//    ==> 변수(자료 저장) + 함수(자료처리) 모아 놓은 틀
// 3. 객체 (object라고도 하고 instance라고도 함)
//    ==> class라는 틀을 이용 하여 찍어낸것( 메모리 상에 존재 하는것)
// 4. private 변수로 선언을 하면 변수를 외부에서 변경하는것이 
//    불가 하다. 변경을 하기 위해서는 struct안에 있는 
//    함수를 호출해서만 가능 하다. 
//    외부에서 함부로 바꾸지 못하모록 하는것을 캡슐화
#include <iostream>
using namespace std;
class TV
{
    // default가 public이지만 public:으로 선언 하는것이 좋다
      // c++ 인경우 defualt가 private이다. 
private:
    bool powerOn;
    int  channel;
    int  volume;
public:
    void setPowerOn()
    {
        powerOn = true;
        cout << "TV를 켰습니다" << endl;
    }
    void setPowerOff()
    {
        powerOn = true;
        cout << "TV를 컸습니다" << endl;
    }
    void setChannel(int ch)   // 1~200 채널범위 
    {
        if (ch >= 1 && ch <= 200)  // 1~200 채널범위
        {
            channel = ch;
            cout << "TV ch을 선택했습니다" << channel << endl;
        }
    }

    void setVolume(int vol)
    {
        if (vol >= 1 && vol <= 100)
        {
            volume = vol;
            cout << "VOL을 " << volume << "로 set했습니다\n";
        }
    }
};
int main()
{
    TV lg;  // lg: object혹은 instance라고 함

    // lg.powerOn = true;
    lg.setPowerOn();
    // lg.channel = 10;
    lg.setChannel(10);
    // lg.volume = 300; 이런 문제점을 때문에 내부 함수를 사용
    lg.setVolume(50);
    lg.setPowerOff();
    //cout << "POWER: " << lg.powerOn << endl;
    //cout << "channel: " << lg.channel << endl;
    //cout << "volume: " << lg.volume << endl;

    return 0;
}
#endif 


#if 0
// 1.구조체 (struct) 
//  C언어 : 서로 다른 타입의 변수들의 집합체
//  c++   : 변수 와 함수 집합체
//          (1)  구조체 default: public이다. 
//          (2)  c++ 인경우 defualt가 private이다. 
// 2. 클래스 (class) 
//    ==> 변수(자료 저장) + 함수(자료처리) 모아 놓은 틀
// 3. 객체 (object라고도 하고 instance라고도 함)
//    ==> class라는 틀을 이용 하여 찍어낸것( 메모리 상에 존재 하는것)
// 4. private 변수로 선언을 하면 변수를 외부에서 변경하는것이 
//    불가 하다. 변경을 하기 위해서는 struct안에 있는 
//    함수를 호출해서만 가능 하다. 
//    외부에서 함부로 바꾸지 못하모록 하는것을 캡슐화
#include <iostream>
using namespace std;
class TV
{
  // default가 public이지만 public:으로 선언 하는것이 좋다
    // c++ 인경우 defualt가 private이다. 
private:
    bool powerOn;
    int  channel;
    int  volume;
public:
    void setPowerOn()
    {
        powerOn = true;
        cout << "TV를 켰습니다" << endl;
    }
    void setPowerOff()
    {
        powerOn = true;
        cout << "TV를 컸습니다" << endl;
    }
    void setChannel(int ch)   // 1~200 채널범위 
    {
        if (ch >= 1 && ch <= 200)  // 1~200 채널범위
        {
            channel = ch;
            cout << "TV ch을 선택했습니다" << channel << endl;
        }
    }

    void setVolume(int vol)
    {
        if (vol >= 1 && vol <= 100)
        {
            volume = vol;
            cout << "VOL을 " << volume << "로 set했습니다\n";
        }
    }
};
int main()
{
    TV lg;  // lg: object혹은 instance라고 함

    // lg.powerOn = true;
    lg.setPowerOn();
    // lg.channel = 10;
    lg.setChannel(10);
    // lg.volume = 300; 이런 문제점을 때문에 내부 함수를 사용
    lg.setVolume(50);
    lg.setPowerOff();
    //cout << "POWER: " << lg.powerOn << endl;
    //cout << "channel: " << lg.channel << endl;
    //cout << "volume: " << lg.volume << endl;

    return 0;
}
#endif 


#if 0
// 1.구조체 (struct) 
//  C언어 : 서로 다른 타입의 변수들의 집합체
//  c++   : 변수 와 함수 집합체
//          (1)  구조체 default: public이다. 
//          (2)  c++ 인경우 defualt가 private이다. 
// 2. 클래스 (class) 
//    ==> 변수(자료 저장) + 함수(자료처리) 모아 놓은 틀
// 3. 객체 (object라고도 하고 instance라고도 함)
//    ==> class라는 틀을 이용 하여 찍어낸것( 메모리 상에 존재 하는것)
// 4. private 변수로 선언을 하면 변수를 외부에서 변경하는것이 
//    불가 하다. 변경을 하기 위해서는 struct안에 있는 
//    함수를 호출해서만 가능 하다. 
//    외부에서 함부로 바꾸지 못하모록 하는것을 캡슐화
#include <iostream>
using namespace std;
struct TV
{
private:  // default가 public이지만 public:으로 선언 하는것이 좋다
         // c++ 인경우 defualt가 private이다. 
    bool powerOn;
    int  channel;
    int  volume;
public:
    void setPowerOn()
    {
        powerOn = true;
        cout << "TV를 켰습니다" << endl;
    }
    void setChannel(int ch)   // 1~200 채널범위 
    {
        if (ch >= 1 && ch <= 200)  // 1~200 채널범위
        {
            channel = ch;
            cout << "TV ch을 선택했습니다" << channel << endl;
        }
    }

    void setVolume(int vol)
    {
        if (vol >= 1 && vol <= 100)
        {
            volume = vol;
            cout << "VOL을 " << volume << "로 set했습니다\n";
        }
    }
};
int main()
{
    TV lg;  // lg: object혹은 instance라고 함

    // lg.powerOn = true;
    lg.setPowerOn();
    // lg.channel = 10;
    lg.setChannel(10);
    // lg.volume = 300; 이런 문제점을 때문에 내부 함수를 사용
    lg.setVolume(50);

    //cout << "POWER: " << lg.powerOn << endl;
    //cout << "channel: " << lg.channel << endl;
    //cout << "volume: " << lg.volume << endl;

    return 0;
}
#endif 

#if 0
#include <iostream>
#include <string> // 

using namespace std;

int main()
{
    string name;

    while (1)
    {
        cout << "이름 입력 (종료:exit) >> ";

   
        getline(cin, name);
        if (name == "exit")
            break;
        if (name == "SIKWON")
            cout << "이름: " << name << "이 맞습니다\n";
        else
            cout << "이름: " << name << "이 틀렸습니다.\n";
    }

    cout << "프로그램이 종료 되었습니다.!!!!\n";

    return 0;

}
#endif 

#if 0
#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
    while (1)
    {
        cout << "이름 입력 (종료:exit) >> ";

        char name[100];
        cin.getline(name, 100, '\n');
        name[strlen(name)] = '\0';  // SIKOWN\0
        if (strncmp(name, "exit",4) == 0)
            break;
        if (strncmp(name, "SIKWON", 6) == 0)
            cout << "이름: " << name << "이 맞습니다\n";
        else
            cout << "이름: " << name << "이 틀렸습니다.\n";
    }

    cout << "프로그램이 종료 되었습니다.!!!!\n";

    return 0;
   
}
#endif 

#if 0
#include <iostream> 
using namespace std;

int main() {
    int width;
    int height; // scanf("%d", height);

    while (1)
    {

        cout << "너비와 높이를 입력 (종료 9 9)  >>";

         cin >> width >> height;  // scanf ("%d%d", &width, &height);
        if (width == 9 && height ==9)
            break;

        int area = width * height;	 // 사각형의 면적 계산
        cout << "면적은 " << area << "\n"; // 면적을 출력하고 다음 줄로 넘어감
    }
    cout << " 종료 되었습니다 !!!!\n";
    return 0;
}
#endif 

#if 0
#include <iostream> 
using namespace std;

int main() {

    while (1)
    {

        cout << "너비를 입력하세요 종료(999) >> ";

        int width;
        cin >> width; // 키보드로부터 너비를 읽어 width 변수에 저장
        if (width == 999)
            break;
        cout << "높이를 입력하세요>>";

        int height; // scanf("%d", height);
        cin >> height; // 키보드로부터 높이를 읽어 height 변수에 저장

        int area = width * height;	 // 사각형의 면적 계산
        cout << "면적은 " << area << "\n"; // 면적을 출력하고 다음 줄로 넘어감
    } 
    cout << " 종료 되었습니다 !!!!\n";
    return 0;
}
#endif 


#if 0
#include <iostream>  // stdio.h의 기능과 유사
using namespace std;   // std안에 있는 함수 나 변수 는 그룹 이름을 


int main()
{
    int ch=0x61;  // ch='a', ch=0x61;
    // a b c d ..........z
    // 
    for (int i = 0; i < 26; i++)
        // cout << char(ch + i) << " ";
        cout << ch + i << " ";
    cout << endl;
 
    return 0;  // main함수는 int를 리턴 하는 함수 

}
#endif 

#if 0
#include <iostream>  // stdio.h의 기능과 유사
using namespace std;   // std안에 있는 함수 나 변수 는 그룹 이름을 
                       // 붙이지 않고 사용 하겠다는 의미
int year()
{
    return 2024; 
}
// printf
int main()
{
  
    cout << "Happy New Year ";
    cout << year() << endl;   // printf("%4d\n", year());
    cout << "SIKWON" <<  endl;
  
    // std그룹(namespace)안에 있는 cout이라는 함수를 실행 한다. 
    // cout: Console output의 약자 : 화면으로 출력 한다는 의미 

    return 0;  // main함수는 int를 리턴 하는 함수 
    // return 0 : error없이 정상적으로 종료 되었다고 
    // OS에 알려 준다. 
}
#endif 

#if 0
#include <iostream>  // stdio.h의 기능과 유사

int main()
{
    std::cout << "Hello World!\n";
    // std그룹(namespace)안에 있는 cout이라는 함수를 실행 한다. 
    // cout: Console output의 약자 : 화면으로 출력 한다는 의미 

    return 0;  // main함수는 int를 리턴 하는 함수 
               // return 0 : error없이 정상적으로 종료 되었다고 
               // OS에 알려 준다. 
}
#endif 