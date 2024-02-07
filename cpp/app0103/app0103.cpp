#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
//4장 객체 포인터와 객체 배열, 객체의 동적 생성
// ., ->, (),[]가 증감연산자보다 연산 우선순위 높음
//this의 용도: this를 이용하여 자기의 object이 할당된 주소를 알아낸다
//calling part에서도 called part에서도 별도로 명시를 하지 않는다.
//컴파일러가 자동으로 생성을 해주는 키워드이다.
// this: 자기가 소속된 객체의 주소가 들어있다. 잡아놓고 컨트롤 kc: 주석처리
////

//8장 상속
//기본 가솔린 자동차 <--- 하이브리드 차 <--- 수소차


class Car {

private: 
	int Gauge;//연료 표시기
public:
	Car(int gas) : Gauge(gas) // this->Gauge = gas와 동일
	{

	}
	int GetGauge() {
		return this->Gauge;
	}
};

class HybridCar : public Car {

private:
	int electricGauge;
public:
	HybridCar(int gas, int ele) : Car(gas), electricGauge(ele)
	{

	}
	int GetElecGauge() {

		return this->electricGauge;
	}

};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int ele, int water)
		: HybridCar(gas, ele), waterGauge(water)
	{


	}
	int GetWaterGauge() {
		return this->waterGauge;
	}

	void showCurrentGauge() {

		cout<< "가솔린 양" << GetGauge() << endl;
		cout <<"전기 양" << GetElecGauge() << endl;
		cout <<"수소 양" << GetWaterGauge() << endl;
	}
};

int main() {
	HybridWaterCar wCar(100, 200, 300);
	wCar.showCurrentGauge();
	return 0;
}
#endif


#if 0
class String {

private:
	int len = 0;
	char* str;
	
public: 
	 String(const char* s) {
		this->len = strlen(s) + 1;
		this->str = new char[len];//메모리 공간 확보
		strcpy(this->str, s);//str에다가 s를 카피해서 넣음
	}
	void ShowString() {
		
		cout << str << endl;
	}
};
int main(void)
{
	String str1 = "My String class Test";
	String str2("My name is Subin");

	str1.ShowString();
	str2.ShowString();
	

}
#endif
#if 0
int main(void)
{
	string s;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, s, '&'; // 문자열 입력
	cin.ignore();
	string f, r;
	cout << endl << "find: ";
	getline(cin, f, '\n'); // 검색할 문자열 입력
	cout << "replace: ";
	getline(cin, r, '\n'); // 대치할 문자열 입력

	int startIndex = 0;
	while (true) {
		int fIndex = s.find(f, startIndex); // startIndex부터 문자열 f 검색
		if (fIndex == -1)
			break; // 문자열 s의 끝까지 변경하였음
		s.replace(fIndex, f.length(), r); // fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
		startIndex = fIndex + r.length();
	}
	cout << s << endl;

}
#endif
#if 0
int main(void)
{
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n'); // 문자열 입력
	int sum = 0;
	int startIndex = 0; // 문자열 내에 검색할 시작 인덱스
	while (true) {
		int fIndex = s.find('+', startIndex);
		if (fIndex == -1) { // '+' 문자 발견할 수 없음
			string part = s.substr(startIndex);
			if (part == "") break; // "2+3+", 즉 +로 끝나는 경우
			cout << part << endl;
			sum += stoi(part); // 문자열을 수로 변환하여 더하기
			break;
		}
		int count = fIndex - startIndex; // 서브스트링으로 자를 문자 개수
		string part = s.substr(startIndex, count); // startIndex부터 count 개의 문자로 서브스트링 만들기
		cout << part << endl;
		sum += stoi(part); // 문자열을 수로 변환하여 더하기
		startIndex = fIndex + 1; // 검색을 시작할 인덱스 전진시킴
	}
	cout << "숫자들의 합은 " << sum;

}
#endif
#if 0
int main(void)
{
	string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	cout << s << endl;
	
	//getline(cin, s, '\n'); // 문자열 입력
	int len = s.length(); // 문자열의 길이

	for (int i = 0; i < len; i++) {
		string first = s.substr(0, 1); // 맨 앞의 문자 1개를 문자열로 분리
		string sub = s.substr(1, len - 1); // 나머지 문자들을 문자열로 분리
		s = sub + first; // 두 문자열을 연결하여 새로운 문자열로 만듦
		cout << s << endl;
	}

}
#endif


#if 0

#include <cstring> //string.h: strcpy, strncpy, strcmp, strncmp, strcat...
//this(자기 객체 주소)를 적용하기

using namespace std;

class Person
{
private:
	char* name; // name의 주소 저장 동적 할당
	int age;
public:
	Person(/*Person *this,*/ char* myname, int myage) // 생성자 처음 한 번 호출되고 안 됨
	{
		int len = strlen(myname) + 1;
		this->name = new char[len];
		strcpy(name, myname);
		this->age = myage;
	}
	Person(/*Person* this*/)//생성자
	{
		this->name = NULL;
		this->age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		this->name = myname; //myname은 주소를 받음
		this->age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;//메모리 해제
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person* parr[3]; // 객체 배열 포인터.
	//parr이 배열 타입으로 3개가 존재하는데 
	// 이는 person type의 주소를 저장하는 공간
	char namestr[100];
	char* strptr = {};
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		//len = strlen(namestr) + 1;
		//strptr = new char[len];
		//strcpy(strptr, namestr);

		//parr[i].SetPersonInfo(strptr, age);
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	(*parr[1]).ShowPersonInfo();
	(*parr[2]).ShowPersonInfo();

	//메모리 해제
	delete[] parr[0];
	delete[] parr[1];
	delete[] parr[2];
	return 0;
}
#endif

#if 0

#include <cstring> //string.h: strcpy, strncpy, strcmp, strncmp, strcat...
//this를 return받아 자기 주소를 알아 내기 함수 작성

using namespace std;

class Person
{
private:
	char* name; // name의 주소 저장 동적 할당
	int age;
public:
	Person(/*Person *this,*/ char* myname, int myage) // 생성자 처음 한 번 호출되고 안 됨
	{
		int len = strlen(myname) + 1;
		this->name = new char[len];
		strcpy(name, myname);
		this->age = myage;
	}
	Person(/*Person* this*/)//생성자
	{
		this->name = NULL;
		this->age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		this->name = myname; //myname은 주소를 받음
		this->age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;//메모리 해제
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person* parr[3]; // 객체 배열 포인터.
	//parr이 배열 타입으로 3개가 존재하는데 
	// 이는 person type의 주소를 저장하는 공간
	char namestr[100];
	char* strptr = {};
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		//len = strlen(namestr) + 1;
		//strptr = new char[len];
		//strcpy(strptr, namestr);

		//parr[i].SetPersonInfo(strptr, age);
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	(*parr[1]).ShowPersonInfo();
	(*parr[2]).ShowPersonInfo();

	//메모리 해제
	delete[] parr[0];
	delete[] parr[1];
	delete[] parr[2];
	return 0;
}
#endif

//this를 return받아 자기 주소를 알아 내기 함수 작성
#if 0
class MyClass {

public:
	void PrintThis() {
		cout << "나의 주소: " << this << endl;
	}

	MyClass *MyAddress() {//MyClass 타입의 주소

		return this;
	}
};

int main(void) {

	MyClass a, b;//정적 할당
	//1. 하드 코딩에 의한 주소 알아내기
	cout << "a의 주소: " << &a << endl;
	cout << "b의 주소: " << &b << endl;

	//2. obj 내의 함수에서 주소 출력
	a.PrintThis();
	b.PrintThis();

	//3. object 내의 함수로 부터 주소를 리턴받아서 출력
	cout << "a 리턴 주소: "<< a.MyAddress()<<endl;
	cout << "b 리턴 주소: " << b.MyAddress();
	return 0;
}
#endif

#if 0
class MyClass {

public:
	void PrintThis() {
		cout << "나의 주소: " << this << endl;
	}
};

int main(void) {

	MyClass a, b;//정적 할당
	cout << "a의 주소: " << &a << endl;
	cout << "b의 주소: " << &b << endl;


	a.PrintThis();
	b.PrintThis();

	return 0;
}
#endif
#if 0
class MyClass {

public:
	void PrintThis() {
		cout << "나의 주소: " << this << endl;
	}
};

int main(void) {

	MyClass a, b;//정적 할당
	cout << "a의 주소: " << &a << endl;
	cout << "b의 주소: " << &b << endl;


	a.PrintThis();
	b.PrintThis();

	return 0;
}
#endif

#if 0
#include <cstring> //string.h: strcpy, strncpy, strcmp, strncmp, strcat...

using namespace std;

class Person
{
private:
	char* name; // name의 주소 저장 동적 할당
	int age;
public:
	Person(char* myname, int myage) // 생성자 처음 한 번 호출되고 안 됨
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
}
	Person()//생성자
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname; //myname은 주소를 받음
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;//메모리 해제
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person* parr[3]; // 객체 배열 포인터.
	//parr이 배열 타입으로 3개가 존재하는데 
	// 이는 person type의 주소를 저장하는 공간
	char namestr[100];
	char* strptr = {};
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		//len = strlen(namestr) + 1;
		//strptr = new char[len];
		//strcpy(strptr, namestr);

		//parr[i].SetPersonInfo(strptr, age);
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	(*parr[1]).ShowPersonInfo();
	(*parr[2]).ShowPersonInfo();

	//메모리 해제
	delete[] parr[0];
	delete[] parr[1];
	delete[] parr[2];
	return 0;
}
#endif
#if 0
int main()
{
	int* p = new int(20);// 20으로 초기화된 int 타입 할당
	char* pchar = new char('z');//z으로 초기화된 char 타입 할당

	//int* parr = new int[10](20); 배열은 동적 할당 시 초기화 불가능
	int* parr = new int;;
}
#endif
#if 0
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main()
{
	Circle donut;
	Circle pizza(30);
	cout << donut.getArea() <<  endl;// 객체 이름으로 멤버 접근

	//객체 포인터로 멤버 접근
	Circle* p;
	p = &donut;
	cout << p->getArea() << endl; // donut의 getArea() 호출
	cout << (*p).getArea() << endl; // donut의 getArea() 호출

	p = &pizza;
	cout << p->getArea() << endl; // pizza의 getArea() 호출
	cout << (*p).getArea() << endl; // pizza의 getArea() 호출
}
#endif