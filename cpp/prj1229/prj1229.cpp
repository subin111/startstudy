#if 1

//1.구조체(struct)
// c언어: 서로 다른 타입의 변수들의 집합체
// c++: 변수 외 함수 집합체
//      1) class와 모양은 동일하나 상속이 안 된다.
//      2) default: public이다.

//2.클래스(class)
//  ==> 변수 (자료 저장) + 함수(자료처리) 모아 놓은 틀

//3.객체(object, instance)
//  ==> class라는 틀을 이용하여 찍어낸 것(메모리 상에 존재하는 것)

#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
struct TV {

    bool powerOn;
    int channel;
    int volume;
    
    void setVolume(int vol) {

        if (vol >= 1 && vol <= 100)
            volume = vol;
        else
            cout << "볼륨이 너무 큽니다.";
    }
};

int main()
{
    TV lg; // lg: object 혹은 인스턴스

    lg.powerOn = true;
    lg.channel = 10;
    // lg.volume = 300; ==> 이런 문제점 때문에 내부 함수를 사용
    lg.setVolume(50);
    
    cout << "POWER: " << lg.powerOn << endl;
    cout << "channel: " << lg.channel<< endl;
    cout << "volume: " << lg.volume << endl;

    return 0;
}
#endif
#if 0
#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
int main()
{
    string song("Falling in love with you");
    string elvis("Elvis Presley");
    string singer;

    while (1) {
        cout << song + " 노래를 부른 가수는";
        cout << "(힌트: 첫 글자는 " << elvis[0] << ")?";
        
        getline(cin,singer);
        //name[strlen(name)] = '\0';


        if (singer == elvis) {
            cout << "맞았습니다.";
            break;
        }
        else if (singer == "exit") break;
        else 
            cout << "틀렸습니다." + elvis + "입니다." << endl;
        


    }
    cout << "종료되었습니다.";
    return 0;
}
#endif
#if 0
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    while (1) {
        cout << "이름 입력(종료:exit):";
        char name[100];
        cin.getline(name, 100, '\n');
        name[strlen(name)] = '\0';


        if (strncmp(name, "exit",4) == 0) break;
        if (strncmp(name, "subin", 5) == 0 || strncmp(name, "SUBIN", 5) == 0) {
            
            cout << "이름: " << name << "이 맞습니다.\n";
        } else 
            cout << "이름: " << name << "이 틀렸습니다.\n";
        
        
        
    } 
    cout<<"종료되었습니다.";
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main()
{

    while (1) {
        cout << "너비와 높이를 입력하세요 종료(99):";//너비 띄어쓰고 높이 입력
        int width, height;
        cin >> width >> height;


        if ((width == 99)||(height == 99)) break;

        int area = width * height;
        cout << "면적은 : " << area << "\n";
    }

    cout << "종료되었습니다.";


    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main()
{

        while (1) { 
            cout << "너비를 입력하세요 종료(999):";
            int width; 
            cin >> width;

       
            if (width == 999) break;
            
            cout << "높이를 입력하세요>>";
            int height;
            cin >> height;
            int area = width * height;
            cout << "면적은 : " << area << "\n";
           
        }

        cout << "종료되었습니다.";
    

    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
    int ch = 0x61; // ch = 'a', ch = 0x61;
    for (int i = 0; i <= 25; i++) {
        cout << char(ch + i) << " ";
    }
       cout << endl;
     for (int i = 0; i <= 25; i++) {
         cout << ch + i << " ";
      }
      cout << endl;
      return 0;
}
#endif
#if 0
#include <iostream> 
using namespace std; // std 안에 있는 함수나 변수는 cin,cout,endl등
                     //그룹 이름을 붙이지 않고 사용하겠다.

int year() {
    return 2024;
}
//printf
int main()
{
    
    cout << "Happy new year! ";
    cout << year() << endl; // endl: end line, printf("%4d", year());
    cout << "Hello World!\n"<< endl;
    return 0;
}

#endif

#if 0
#include <iostream> //stdio.h의 기능과 유사

int main()
{
    std::cout << "Hello World!\n";// << : 이어준다.
    //std그룹(namespace) 안에 있는 cout이라는 함수를 실행한다.
    //cout: console로 output: 화면으로 출력한다.
    std::cout << "";
    return 0;// main 함수는 int를 리턴하는 함수
    // return 0; 에러 없이 정상적으로 끝난 것을 os에 알려줌.
}
#endif
