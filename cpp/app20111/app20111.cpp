#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#if 1

class Person {
public:
    int money; // 개인 소유의 돈
    void addMoney(int money) {
        this->money += money;
    }

    static int sharedMoney; // 공금, 전역변수처럼 사용 가능
    static void addShared(int n) {
        sharedMoney += n;
    }
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10;  // 10으로 초기화

// main() 함수
int main() {
    Person::addShared(50); // static 멤버 접근, 공금=60
    cout << Person::sharedMoney << endl;

    Person han;
    han.money = 100;
    han.sharedMoney = 200; // static 멤버 접근, 공금=200
    Person::sharedMoney = 300; // static 멤버 접근, 공금=300
    Person::addShared(100); // static 멤버 접근, 공금=400

    cout << han.money << ' '
        << Person::sharedMoney << endl;
}

#endif
#if 1

class Person{
public:
    int money; // 개인 소유의 돈
    void addMoney(int money) {
        this->money += money;
    }

    static int sharedMoney; // 공금, 전역변수처럼 사용 가능
    static void addShared(int n) {
        sharedMoney += n;
    }
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10;  // 10으로 초기화

// main() 함수
int main() {
    Person::addShared(50); // static 멤버 접근, 공금=60
    cout << Person::sharedMoney << endl;

    Person han;
    han.money = 100;
    han.sharedMoney = 200; // static 멤버 접근, 공금=200
    Person::sharedMoney = 300; // static 멤버 접근, 공금=300
    Person::addShared(100); // static 멤버 접근, 공금=400

    cout << han.money << ' '
        << Person::sharedMoney << endl;
}

#endif

//overloading 함수 중복
#if 0

int big(int a, int b) {
    if (a > b) return a;
    else return b;
}

int big(int a[], int size) {

    int res = a[0];
    for (int i = 1; i < size; i++) {

        if (res < a[i]) res = a[i];
    }
    return res;
}

int avg(int a, int b) {

    return (a + b) / 2;
};
int avg(int* a, int size) {
    int i = 0;
    int s = 0;
    a[size] = { 0, };
    for (int i = 0; i <= size; i++)
        s += a[i];
    return s/size;
};

int sum(int a, int b) {
    int s = 0;
    for (int i = a; i <= b; i++)
        s += i;
    return s;
};
int sum(int* a, int size) {

    int s = 0;
    a[size] = { 0, };
    for (int i = 0; i <= size; i++)
        s += a[i];
    return s;
};

int main() {

    int array[5] = { 1,9,-2,8,6 };
    cout << big(2, 3) << endl;
    cout << big(array, 5) << endl;
    cout << avg(2, 3) << endl;
    cout << avg(array, 5) << endl;
    cout << sum(2, 3) << endl;
    cout << sum(array, 5) << endl;
}

#endif
//깊은 복사 생성자  //뭘 추가해야하는데,,,
// 
#if 0

class Person { // Person 클래스 선언
    char* name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    Person(const Person& person); // 복사 생성자
    ~Person(); // 소멸자
    void changeName(const char* name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) { // 생성자
    this->id = id;
    int len = strlen(name); // name의 문자 개수
    this->name = new char[len + 1]; // name 문자열 공간 핟당
    strcpy(this->name, name); // name에 문자열 복사
}

Person::Person(const Person& person) { // 복사 생성자
    this->id = person.id; // id 값 복사
    int len = strlen(person.name);// name의 문자 개수
    this->name = new char[len + 1]; // name을 위한 공간 핟당
    strcpy(this->name, person.name); // name의 문자열 복사
    cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() {// 소멸자
    if (name) // 만일 name에 동적 할당된 배열이 있으면
        delete[] name; // 동적 할당 메모리 소멸
}

void Person::changeName(const char* name) { // 이름 변경
    if (strlen(name) > strlen(this->name))
        return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
    strcpy(this->name, name);
}

#endif
//얕은 복사 생성자 - 프로그램 비성장으로 종료됨
#if 0
class Person { // Person 클래스 선언
    char* name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    ~Person(); // 소멸자
    void changeName(const char* name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) { // 생성자
    this->id = id;
    int len = strlen(name); // name의 문자 개수
    this->name = new char[len + 1]; // name 문자열 공간 핟당
    strcpy(this->name, name); // name에 문자열 복사
}

Person::~Person() {// 소멸자
    if (name) // 만일 name에 동적 할당된 배열이 있으면
        delete[] name; // 동적 할당 메모리 소멸
}

void Person::changeName(const char* name) { // 이름 변경
    if (strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

int main(void) {
    Person father(1, "Kitae");			// (1) father 객체 생성
    Person daughter(father);			// (2) daughter 객체 복사 생성. 복사생성자호출

    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();						// (3) father 객체 출력
    daughter.show();					// (3) daughter 객체 출력

    daughter.changeName("Grace"); // (4) daughter의 이름을 "Grace"로 변경
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();						// (5) father 객체 출력
    daughter.show();					// (5) daughter 객체 출력

    return 0;


}
#endif

//포인터 변수, 참조 변수
#if 0

void change(int* n) {
    *n += 1; // n의 주소에 들어가 있는 값을 1 증가
}

int return_change(int n) {

    return (n + 1);

}


int main()
{
    cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
    int i = 1;
    int n = 2;

    n = 4;
    change(&n);
    cout << i << '\t' << n << '\t' << endl;


    n = return_change(n);
    cout << i << '\t' << n << '\t' << endl;

    int* p = &n; // p는 n의 주소를 가짐
    *p = 20; // refn=20, n=20
    cout << i << '\t' << n << '\t'<< endl;
}
#endif
#if 0

int main(){
    int i = 0;
    int n = 0;

    cout << "정수 i, n을 입력하시오(0 0 입력시 종료): "; 
    cin >> i >> n;
    cout << "i" << '\t' << "n" << '\t' <<"refn" << endl;
    //cin >> i >> n;
    while (1) {
       
        if (i == 0 && n == 0) break;
        //calling(&)
        int& refn = n;
        
        refn++;
        cout << i << '\t' << n << '\t' << refn << endl;

        refn = i;
        refn++;
        cout << i << '\t' << n << '\t' << refn << endl;

        int* p = &refn;
        *p = 20;
        cout << i << '\t' << n << '\t' << refn << endl; 
        cout << '\n';

        cout << "정수 i, n을 입력하시오(0 0 입력시 종료): "; 
        cin >> i >> n;
        cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
    }

}
#endif

//값에 의한 호출로 객체 전달
#if 0
class Circle {
private:
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int radius);
    ~Circle();
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) {
        this->radius = radius;
    }
};



void increase(Circle c) { 
    
    int r = c.getRadius();
    c.setRadius(r+1); //a에 들어있는 값: m 주소
  
}

int main()
{
    Circle waffle(30);
    increase(waffle);
    cout << waffle.getRadius() << endl;
}
#endif

//지역변수에 있는 내용을 swap에서 엑세스해서 수정을 가한다.
//주소를 넘겨줘야 함.
#if 0
void swap(int *a, int *b) { // int a, int b. swap(a,b)는 틀림
    //a, b에 m,n의 주소를 전달
    int tmp;
    tmp = *a; //a에 들어있는 값: m 주소
    *a = *b; //b에 들어있는 값을 a에 넣기.. 
    *b = tmp; //b안에는 이제 a에 들어있는 값: m 주소가 들어가잇음
}

int main()
{
    int m = 2, n = 9;
    swap(&m, &n);
    cout << m << ' ' << n;
}
#endif