#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#if 1
//객체 배열 타입으로 작성된 프로그램
//객체 배열 포인터로 수정
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
	Person *parr[3]; // 객체 배열 포인터.
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
		parr[i] = new Person(namestr,age);
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
//객체 배열 타입으로 작성된 프로그램
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
	Person parr[3]; // 정적 메모리 할당

	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}
#endif