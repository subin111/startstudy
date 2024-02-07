#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
using namespace std;
#include <iostream>
//4장 객체 포인터와 객체 배열, 객체의 동적 생성
// ., ->, (),[]가 증감연산자보다 연산 우선순위 높음
//this의 용도: this를 이용하여 자기의 object이 할당된 주소를 알아낸다
//calling part에서도 called part에서도 별도로 명시를 하지 않는다.
//컴파일러가 자동으로 생성을 해주는 키워드이다.
// this: 자기가 소속된 객체의 주소가 들어있다. 잡아놓고 컨트롤 kc: 주석처리
//
//
#if 1

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

	MyClass* MyAddress() {//MyClass 타입의 주소

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
	cout << "a 리턴 주소: " << a.MyAddress() << endl;
	cout << "b 리턴 주소: " << b.MyAddress();
	return 0;
}
#endif