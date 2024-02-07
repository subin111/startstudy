#define _CRT_SECURE_NO_WARNINGS // 컨트롤 + d: 바로 위 줄 복사
//포인터는 주소 값을 담는 그릇
#include <iostream>
//#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
//과제 14번
#if 1
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
    string name;
public:
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class GamblingGame {
    Player p[2];
public:
    void run();
    bool turn(string name);
    ~GamblingGame();
};

void GamblingGame::run() {
    string name;
    srand((unsigned)time(NULL));

    cout << "***** 갬블링 게임을 시작합니다. *****\n";
    cout << "첫번째 선수 이름 >> ";
    cin >> name;
    p[0].setName(name);
    cout << "두번째 선수 이름 >> ";
    cin >> name;
    p[1].setName(name);
    cin.ignore();

    int end = 0;
    while (1) {
        for (int i = 0; i < 2; i++)
        {
            if (turn(p[i].getName())) {
                cout << p[i].getName() << "님 승리!!!\n";
                end = 1;
                break;
            }
            else
                cout << "아쉽군요!\n";
        }
        if (end == 1) break;
    }
}

bool GamblingGame::turn(string name) {
    string enter;
    cout << name << " : <Enter>";

    while (1) {
        char ch;
        cin.get(ch);
        if (ch == '\n') break;
    }

    int random[3] = { 0, };

    for (int i = 0; i < 3; i++)
        random[i] = rand() % 3;

    cout << random[0] << '\t' << random[1] << '\t' << random[2] << '\t';

    if (random[0] == random[1] && random[1] == random[2])
        return true;
    else
        return false;
}

GamblingGame::~GamblingGame() { cout << "게임을 종료합니다.\n"; }

int main() {
    GamblingGame g;
    g.run();
}

#endif

//과제 13번
#if 0
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Histogram {
    string str;
    int alpha[26] = { 0 };
public:
    Histogram(string str) { this->str = str; }
    void put(string nstr) { this->str.append(nstr); }
    void putc(char ch) { this->str.append(&ch); }
    void print();
    int getAlphaSize();
    void cntAlpha();
};

void Histogram::print() {
    cout << str << "\n\n";
    cout << "총 알파벳 수 " << getAlphaSize() << "\n\n";

    cntAlpha();
    char ch = 'a';
    while (ch <= 'z') {
        cout << ch << " (" << alpha[(int)ch - 'a'] << ")\t: ";
        for (int i = 0; i < alpha[(int)ch - 'a']; i++) {
            cout << "*";
        }
        cout << endl;
        ch++;
    }
}

int Histogram::getAlphaSize() {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            cnt++;
    }
    return cnt;
}

void Histogram::cntAlpha() {
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int ind = str[i] - 'A';
            alpha[ind]++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            int ind = str[i] - 'a';
            alpha[ind]++;
        }
    }
}

int main() {
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presley");
    elvisHisto.print();
}


#endif

//과제 12번
#if 0
#include <iostream>
using namespace std;


class Circle {
    int radius;
    string name;
public:
    void setCircle(string name, int radius)
    {
        this->name = name;
        this->radius = radius;
    }
    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
};


class CircleManager {
    Circle* p;
    int size;
public:
    CircleManager(int size)
    {
        p = new Circle[size];
        this->size = size;
    }
    ~CircleManager() { delete[] p; }
    Circle* getCircle() { return p; }
    void searchByName();
    void searchByArea();
};

void CircleManager::searchByName()
{
    string f;
    cout << "검색하고자 하는 원의 이름 >> ";
    cin >> f;

    for (int i = 0; i < size; i++)
    {
        if (f == p[i].getName())
        {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
            break;
        }
    }
}


void CircleManager::searchByArea()
{
    int minArea;

    cout << "최소 면적을 정수로 입력하세요 >>";
    cin >> minArea;
    cout << minArea << "보다 큰 원을 검색합니다." << endl;

    for (int i = 0; i < size; i++)
    {
        if (p[i].getArea() > minArea)
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
    }
}

int main() {
    int numc = 0;
    string name;
    int r;
    cout << "원의 개수 >> ";
    cin >> numc;

    CircleManager c(numc);

    for (int i = 0; i < numc; i++)
    {
        cout << "원 " << i + 1 << "의 이름과 반지름 >> ";

        cin >> name >> r;
        c.getCircle()[i].setCircle(name, r);
    }
    c.searchByName();
    c.searchByArea();

    return 0;
}
#endif

//과제 11번
#if 1
class Container {
    int size;
public:
    Container() { size = 10; }
    void fill() { size = 10; };
    void consume() { size = size - 1; };
    int getSize() { return size; };
};

class CoffeeVendingMachine {

    Container tong[3];
    void fill();
    void selectEspresso();
    void selectAmericano();
    void selectSugarCoffee();
    void show();
public:
    void run();
};

// container의 통[0] = 커피, 통[1]은 물, 통[2]은 설탕
void CoffeeVendingMachine::fill() {

    for (int i = 0; i < 3; i++) 
        tong[i].fill();
    show();
}

void CoffeeVendingMachine::selectEspresso() {
    if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
        tong[0].consume();
        tong[1].consume();
        cout << "에스프레소 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }
}

void CoffeeVendingMachine::selectAmericano() {
    if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
        tong[0].consume();
        tong[1].consume();
        tong[1].consume();
        cout << "아메리카노 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }
}


void CoffeeVendingMachine::selectSugarCoffee() {

    if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
        tong[0].consume();
        tong[1].consume();
        tong[1].consume();
        tong[2].consume();
        cout << "설탕커피 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }

}
void CoffeeVendingMachine::show() {
    cout << "커피 " << tong[0].getSize() << ", 물" << tong[1].getSize() << ", 설탕" << tong[2].getSize();
}
void CoffeeVendingMachine::run() {
    cout << "***** 커피자판기를 작동합니다. *****\n";
    while (true) {
        int num;
        cout<<"메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
        cin >> num;
        switch (num) {
        case 1:
            selectEspresso();
            break;
        case 2:
            selectAmericano();
            break;
        case 3:
            selectSugarCoffee();
            break;
        case 4: show(); 
            break;
        case 5: 
            fill(); 
            break;
        default:
            break;
        }
    
    }   
    
}

int main() {
    CoffeeVendingMachine cm;
    cm.run();
}

#endif

//과제 10번
#if 0
#include <string>

class Person { //클래스 person
    string name;

public:
    Person() { };//생성자
    Person(string name) { this->name = name; }//생성자
    string getName() { return name; }
    void setName(string name) { this->name = name; }

};


class Family {//클래스 family
    Person* p;
    string familyName;
    int size;
public:
    Family(string name, int size);//생성자
    void show();
    void setName(int index, string name) {

        p[index].setName(name);
    }
    ~Family();
};

Family::Family(string name, int size) {

    p = new Person[size];
    this->familyName = name;
    this->size = size;
}
void Family::show() {

    cout << familyName << "가족은 다음과 같이 " << size << "입니다.\n";
    for (int i = 0; i < size; i++) {
        cout << p[i].getName() << "\t";
    }

    cout << endl;
}

Family::~Family() {
    delete[] p;
}

int main() {
    Family *simpson = new Family("Simpson", 3); // 클래스 family의 객체 simpson, 포인터 배열로 크기 3만큼 선언됨
    simpson->setName(0, "Mr. Simpson");//포인터 simpson으로 setName함수 접근
    simpson->setName(1, "Mrs. Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson->show();//
    delete simpson;//배열 delete
    return 0;
}
#endif

//과제 9번
#if 0
#include <string>

class Person {
    string name;
    string tel;
public:
    Person();
    string getName() { return name; }
    string getTel() { return tel; }
    void set(string name, string tel);
};
Person::Person(){

}
void Person::set(string name, string tel) {

    this->name = name;
    this->tel = tel;

}
int main() {

    cout << "이름과 전화 번호를 입력해 주세요\n";
    Person people[3];
    for (int i = 0; i < 3; i++) {
        string name, tel;
        cout << "사람 " << i+1 << ">>";
        cin >> name >> tel;
        people[i].set(name, tel);

    }

    cout << "모든 사람의 이름은 ";

    for (int i = 0; i <= 2; i++) {

        cout << people[i].getName() << ' ';
    }
    cout << endl;


    cout << "전화번호 검색합니다. 이름을 입력하세요>>";
    string namefind;
    cin >> namefind;


    for (int i = 0; i <= 2; i++) {
        if (namefind.compare(people[i].getName()) == 0) {

            cout << "전화번호는 " << people[i].getTel() << ' ';

        }
    }
}

#endif

//과제 8번
#if 0
class Circle {
    int radius;
public:
    void setRadius(int radius) {
        this->radius = radius;
    };
    double getArea() {

        return 3.14 * radius * radius;
    };
};



int main() {
    cout << "원의 개수 >>";
    int a = 0;
    int cnt = 0;

    cin >> a;
    Circle* circles = new Circle[a];
    //Circle circles[a]; 이게 아니었네,,,

    
    for (int i = 0; i < a; i++) {

        int r;
        cout << "원 " << i + 1 << "의 반지름 >> ";
        cin >> r;
        circles[i].setRadius(r);

        if (circles[i].getArea() > 100) {
            cnt++;
        }
    }

    delete[] circles;
    cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";

    return 0;
}
#endif

//과제 7번
#if 0
class Circle {
    int radius;
public:
    void setRadius(int radius) {
        this->radius = radius;
    };
    double getArea() {
    
        return 3.14 * radius * radius;
    };
};



int main() {
    Circle circles[3];
    int cnt = 0;
    
    for (int i = 0; i < 3; i++) {

        int r;
        cout << "원 " << i + 1 << "의 반지름 >> ";
        cin >> r;
        circles[i].setRadius(r);

        if (circles[i].getArea() > 100) {
            cnt++;
        }
    }

    cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";

    return 0;
}
#endif

//과제 6번
#if 0
#include <string>
#include <ctime>

int main() {

    cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)";
    cout << "\n";

    while (1) {
        
        cout << ">>";

        string str;
        getline(cin, str);
        if (str.compare("exit") == 0) break;
        
        for (int i = str.length() - 1; i >= 0; i--) {
            cout << str[i];
        }
        
        cout << endl;

    }

    return 0;

}
#endif


//과제 5번
#if 0
#include <string>
#include <ctime>

int main() {
 
    cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)";
    cout << "\n";
    
    while (1){

        string str;
        getline(cin, str);

        if (str.compare("exit") == 0) break;
        
        srand((unsigned)time(0));
        int n = rand() % (str.length());

        srand((unsigned)time(0));
        char ch = 'a' + rand() % 26;

        str[n] = ch;
        cout << ">>" << str << endl;

    }

        
    return 0;

}
#endif

//과제 4번
#if 0
class Sample {

    int* p;//포인터배열
    int size;
public:
    Sample(int n) {//생성자
        size = n;
        p = new int[n];//동적 할당, n크기 만큼
    }
    void read();
    void write();
    int big();
    ~Sample();//소멸자

};
void Sample::read() {//범위 지정 연산자 :: 클래스의 멤버 함수를 구현
    for (int i = 0; i < size; i++)
        cin >> p[i];//배열 한 칸마다 cin으로 들어온 정수 저장
}

void Sample::write() {//클래스의 멤버 함수를 구현
    for (int i = 0; i < size; i++)
        cout << p[i]<<" ";
    cout << endl;
}
int Sample::big() {//클래스의 멤버 함수를 구현
    int max = 0;
    for (int i = 0; i < size; i++) {
    
        if (p[i] > max)
            max = p[i];
    }
    return max;
}

Sample::~Sample() {//소멸자
    delete [] p;
}

int main() {
    cout << "정수 10개를 입력하세요: ";
    Sample s(10);//객체 s(크기 10)을 생성
    s.read();//s의 멤버함수 read에 접근
    s.write();//s의 멤버함수 write에 접근
    cout << "가장 큰 수는 " << s.big() << endl;
    return 0;

}
#endif


//과제 3-2번
#if 0
#include <string>

int main() {

    string str;
    int cnt = 0, ind = 0;

    cout << "문자열 입력>>";
    getline(cin, str);

    while (true) {
        ind = str.find('a', ind + 1);
        if (ind == -1) break;
        else cnt++;
    }

    cout << "문자 a는" << cnt << " 개 있습니다.";

    return 0;

}
#endif

//과제 3-1번
#if 0
#include <string>

int main() {
   
    string str;
    int cnt = 0;

    cout << "문자열 입력>>";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') cnt++;
    }

    cout << "문자 a는" << cnt << " 개 있습니다.";

    return 0;

}
#endif

//과제 2번
#if 0
#include <string>



int main() {
    int* arr = new int[5];
    float average = 0.0f;

    cout << "정수 5개 입력>>";
    for (int i = 0; i < 5; i++) {

        cin >> arr[i];
        average += arr[i];

    }
    average /= 5;
    cout << "평균 " << average << endl;
    
    return 0;

}
#endif
//과제 1번
#if 0
#include <string>

class Color {
    int red, green, blue;
public:
    Color() { red = green = blue = 0; }//생성자, 색상 초기값
    Color(int r, int g, int b) {//생성자, 
        red = r; green = g; blue = b;
    }
    void setColor(int r, int g, int b) {//입력 값을 색상 변수로
        red = r; green = g; blue = b;
    }
    void show() {
        cout << red << ' ' << green << ' ' << blue << endl;
    }
};

int main() {

    Color screenColor(255, 0, 0);//빨간색 screencolor 객체 생성
    Color* p;// 포인터변수 p
    p = &screenColor;//screenColor의 주소를 저장
    p->show();// show함수를 가리킴

    Color colors[3];
    p = colors;

    p->setColor(255, 0, 0);//setColor함수를 가리킴
    (p + 1)->setColor(0, 255, 0);
    (p + 2)->setColor(0, 0, 255);

    for (int i = 0; i < 3; i++) {
        (p + i)->show();
    }
    return 0;

}
#endif





// 명함 만들기
#if 0
//0: 사원 CLERK
//1: 주임 SENIOR
//2: 대리 ASSIST
//3: 과장 MANAGER

#define CLERK 0
#define SENIOR 1
#define ASSIST 2
#define MANAGER 3

// 이름:
// 회사:
// 전화번호:
// 직급:

namespace COMP_POS {
    void ShowPositionInfo(int position) {

        switch (position) {
        case CLERK:
            cout << "사원\n"; break;

        case SENIOR:
            cout << "주임\n"; break;

        case ASSIST:
            cout << "대리\n"; break;

        case MANAGER:
            cout << "과장\n"; break;

        }
    }
};

class NameCard
{
private:
        char* name;
        char* company;
        char* phone;
        int   position;


public:

    NameCard(const char* n, const char* c, const char* p, const int pos)
    {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);

        this->company = new char[strlen(c) + 1];
        strcpy(this->company, c);

        this->phone = new char[strlen(p) + 1];
        strcpy(this->phone, p);

        position = pos;
    }

    void ShowNameCardInfo() const
    {        
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직급: ";

            COMP_POS::ShowPositionInfo(position);
            cout << endl;
    }

        ~NameCard()
        {
            delete[] name;
            delete[] company;
            delete[] phone;
        }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", SENIOR);
    NameCard manAssist("Kim", "SoGoodCompa", "010-5555-6666", ASSIST);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}
#endif