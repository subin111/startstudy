#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
//8장 상속. 다중 상속, 가상 상속
//가상상속으로 다중 상속의 모호성 해결.

//9장. 가상 함수와 추상 클래스

// exe 파일은 폴더 > x64 > 디버그 >에 있음
// 명령 프롬프트에서 매개변수를 처리할 때 쓰임
// argv = argument vector : 전달된 argument 배열 요소
// argc = argument count : argv 배열의 크기
// 리눅스 쓸 때 사용된다.

// 오버라이딩: 파생 클래스에서 구현할 함수 인터페이스 제공
// (파생 클래스의 다형성. 
// 
// 동적 바인딩. 파생 클래스에 대해, 기본 클래스에 대한 포인터로 가상 함수
// 를 호출하는 경우. 객체 내에 오버라이딩한 파생 클래스의 함수를 찾아 실행
// 
// mul(a,b), div(a,b) 함수 구현 후 calculator에 다중 상속한다.
// main 함수 내 wihle(1)로 구현
// a,b 값을 키보드로부터 입력받고 0,0 이면 종료
// 
// 
//추상 클래스:  최소한 하나의 순수 가상 함수를 가진 클래스





#if 0
class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};

class Multiplier {
protected:
	int mul(int a, int b) { return a * b; }

};

class Divider {
protected:
	float div(int a, int b) { return a / b; }

};

//다중 상속을 받은 추상 클래스
class Calculator : public Adder, public Subtractor, public Multiplier, public Divider {
public:
	virtual int add(int a, int b) = 0;
	virtual int minus(int a, int b) = 0;
	virtual int mul(int a, int b) = 0;
	virtual int div(int a, int b) = 0;

	virtual double average(int a[], int size) = 0;
};
/*
int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	case '*': res = mul(a, b); break;
	case '/': res = (float)div(a, b); break;
	}
	return res;
}
*/
class GoodCalc : public Calculator {

public:
	int add(int a, int b) { return a + b; }
	int minus(int a, int b) { return  a - b; }
	int mul(int a, int b) { return  a * b; }
	int div(int a, int b) { return  a / b; }

	double average(int c[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += c[i];
		return sum / size;
	}
};


#if	0
int main(int argc, char* argv[]) // 배열의 값, 배열의 크기 둘 다 정수
{
	
	Calculator *p = new GoodCalc();

	int a, b;


	if (argc != 4) // 배열 크기가 4가 아니라면 에러
	{
		cout << " error argument !!!!\n";
		return -1;
	}

	a = atoi(argv[2]); // argv[2]에 a 넣음
	b = atoi(argv[3]); // argv[3]에 b 넣음
	int c[] = { a,b };

	cout << a << " " << '+' << " " << b << " = " << p->add(a, b) << endl;
	cout << a << " " << '-' << " " << b << " = " << p->minus(a, b) << endl;
	cout << " average: " << p->average(c, 4) << endl;
	delete p;
	return 0;
}
#endif
#endif

#if 0
class Shape {//추상 클래스:
	Shape* next;
public:
	void paint(){ draw(); }
	virtual void draw() = 0;//순수 가상 함수
	
};

void Shape::paint() {
	draw(); // 순수 가상 함수라도 호출은 가능
}
int main(void) {
	Shape* p;//추상 클래스의 포인터 선언 가능. 객체 생성은 안 됨
	return 0;

}
#endif

#if 0
class Person {
public:
	int id = 10;
};

class Student : virtual public Person {};
class Worker : virtual public Person {};

class StudentWorker : public Student, public Worker {
public: 
	int getId() { return id; }

};

int main(void) {
	int id = 0;
	StudentWorker st;
	id = st.getId();
	return 0;

}
#endif

#if 0
class Adder {
protected:
    int add(int a, int b) { return a + b; }
};

class Subtractor {
protected:
    int minus(int a, int b) { return a - b; }
};

class Multiplier {
protected:
	int mul(int a, int b) { return a * b; }

};

class Divider {
protected:
	float div(int a, int b) { return a / b; }

};
//다중 상속
class Calculator : public Adder, public Subtractor, public Multiplier, public Divider {
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	case '*': res = mul(a, b); break;
	case '/': res = (float)div(a, b); break;
	}
	return res;
}

#if	0
int main(int argc, char *argv[]) // 배열의 값, 배열의 크기 둘 다 정수
{
Calculator handCalculator;
int a, b;


if (argc != 4) // 배열 크기가 4가 아니라면 에러
{
	cout<< " error argument !!!!\n";
	return -1;
}
 
a = atoi(argv[2]); // argv[2]에 a 넣음
b = atoi(argv[3]); // argv[3]에 a 넣음


cout << a << " " << '+' << " " << b << " = " << handCalculator.calc('+', a, b) << endl;
return 0;
}
/*cout << "2 + 4 = "
	<< handCalculator.calc('+', 2, 4) << endl;
cout << "100 - 8 = "
	<< handCalculator.calc('-', 100, 8) << endl;
	*/


#else
int main()
{

	Calculator handCalculator;
	int a, b;
	char op;//변수 와일문 밖에 두기
	
	while (1) {
		
		cout << "정수 a, b를 입력하세요(연산 +-*/): ";
		cin >> a >> op >> b;
		if (a == 0 && b == 0) break;
		cout << a << " "<< op <<" "<< b << " = "<<handCalculator.calc(op, a, b) << endl;
	
	}
	/*cout << "2 + 4 = "
		<< handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = "
		<< handCalculator.calc('-', 100, 8) << endl;
		*/
    return 0;
}
#endif 

#endif
