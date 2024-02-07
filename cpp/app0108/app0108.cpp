#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//8장 상속
//기본 가솔린 자동차 <--- 하이브리드 차 <--- 수소차
//시퀀스 차트,  상태 처리도를 그릴 줄 알아야
//임베디드에서 중요하다.
//virtual: 껍데기만 있음: 나중에 자식 클래스에서 상속 받아서 무슨 타입.. 등을 만들려고.
//interface: 가상함수만 모아놓은 것
// 인터페이스를 상속할 경우 그 자식 클래스들은
// 인터페이스의 가상함수들을 무조건 오버라이딩 해줘야 한다.
//overiding: 가상 함수의 재정의
// protected: 선언 클래스, 파생 클래스에서만 접근 허용
// public: 모든 외부 함수에 접근 허용
// private: 선언된 클래스 내에서만 접근 가능, 파생 클래스도 기본 클래스 접근 X
// //업 캐스팅: 파생 클래스 포인터가 기본 클래스 포인터에 치환되는 것
// //다운 캐스팅: 기본 클래스의 포인터가 파생 클래스의 포인터에 치환되는 것
#if 1
#include <string>
#include <iostream>
using namespace std;
class Person {
	string name;
public:	
	Person(string name);
	string toString();
	string getName();
	~Person();
};

class Student : public Person {
	int status;
public:
	Student(string name, int status);
	//string toString();
	string getStatus();
	~Student();
};
class Employee : public Person {
	int salary;
public:
	Employee(string name, int salary);
	//string toString();
	int getSalary();
	~Employee();

};

class Staff : public Employee {
	string title;
	//string toString();
public:
	Staff(string name, int salary, string title);
	string getTitle();
	~Staff();
};

class Faculty : public Employee {
	int rank;
public:
	Faculty(string name, int salary, int rank);
	//string toString();
	int getRank();
	~Faculty();
};

#endif
#if 0
class Base {
	int a;
private:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : public Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	x.a = 5; 					// ①
	x.setA(10); 				// ②
	x.showA(); 				// ③
	x.b = 10; 				// ④
	x.setB(10); 				// ⑤
	x.showB(); 				// ⑥
}

#endif
#if 0
#include <string>

class Point {
public:
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	};
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	};
};

class ColorPoint : public Point { //point에서 상속받은 클래스
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << ":";
		showPoint();
	};
	bool equals(ColorPoint p) {
		if (x == p.x && y == p.y && color == p.color) // ①
			return true;
		else
			return false;
	};
};
//public을 protected로 바꾸면 오류.
int main() {
	Point p; // 기본 클래스의 객체 생성
	p.set(2, 3);													// ②
	p.x = 5;													// ③
	p.y = 5;													// ④
	p.showPoint();

	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.x = 10;												// ⑤
	cp.y = 10;												// ⑥
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false"); // ⑦
}

#endif

#if 0
#include <string>

class Point {
public:
	int x, y;
public:
	void set(int x, int y){
	this->x = x;
	this->y = y;
	};
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	};
};

class ColorPoint : public Point { //point에서 상속받은 클래스
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << ":";
		showPoint();
	};
	bool equals(ColorPoint p) {
		if (x == p.x && y == p.y && color == p.color) // ①
			return true;
		else
			return false;
	};
};
//public을 protected로 바꾸면 오류.
int main() {
	Point p; // 기본 클래스의 객체 생성
	p.set(2, 3);													// ②
	p.x = 5;													// ③
	p.y = 5;													// ④
	p.showPoint();

	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.x = 10;												// ⑤
	cp.y = 10;												// ⑥
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false"); // ⑦
}

#endif

#if 0

//interface
class CheckLogic {
public:
	virtual bool isTrue() = 0;
};

class DateCheckLogic : CheckLogic {
public:
	//override
	virtual bool isTrue() {
		return true;
	}
};

int main(void) {
	DateCheckLogic* d = new DateCheckLogic();
	cout << "true: " << d->isTrue();
	return 0;
}
#endif

#if 0

//interface
class CheckLogic {
public:
	virtual bool isTrue() = 0;
};

class DateCheckLogic : CheckLogic {
public:
	//override
	virtual bool isTrue() {
		return true;
	}
};

int main(void) {
	DateCheckLogic* d = new DateCheckLogic();
	cout << "true: " << d->isTrue();
	return 0;
}
#endif
#if 0
#include <string>
class Person {
public:
	string name;
	int Age;
	double size;
	string haircolor;

	void Walk(double distance) {
		cout << name << "walk "<<
		distance << "meter" << endl;
	}
	void Eat(string food) {
		cout << name << "ate" << food << endl;
	}
	void Sleep(int hours) {}
};

class Student : public Person { //person을 상속 받은 student
public:
	void Study(string name, string subject) {
		cout << name << "learned " << subject << endl;
	}
};

class Teacher : public Person {
public: 
	void teach(string name, string subject) {
	cout << name << "teach " << subject << endl;}
};

class Children : public Person {
public:
	void Sleep(string name, string haircolor) {
		cout << name << " is sleeping now\nhaircolor is " << haircolor << endl;
	}
};
int main(void)
{
	Teacher* t = new Teacher();
	Student* s = new Student();
	Children* c = new Children();

	t->teach("mint Kim","English");
	t->Walk(15.5);
	s->Study("subinlee","Math");
	s->Study("subinlee","History");
	c->Sleep("mable", "black");
	return 0;
}

#endif

#if 0
class Employee {
private:
	string name;
	int empID;
public:
	void displayEmployee() {
		cout << "name: " << name << endl;
		cout << "Employee ID: " << empID << endl;
	}
};


#endif

#if 0

class Phone {
	void call();
	void receive();
};

class MobilePhone : public Phone {

	void connectWireless();
	void recharge();
};

class MusicPhone : public MobilePhone {

	void downloadMusic();
	void play();
};

int main() {
	MusicPhone leephone();
	return 0;
}

#endif


#if 0

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

		cout << "가솔린 양" << GetGauge() << endl;
		cout << "전기 양" << GetElecGauge() << endl;
		cout << "수소 양" << GetWaterGauge() << endl;
	}
};

int main() {
	HybridWaterCar wCar(100, 200, 300);
	wCar.showCurrentGauge();
	return 0;
}
#endif

