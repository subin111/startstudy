#define _CRT_SECURE_NO_WARNINGS
#if 1
/////////////////////////////////////////
// 0. 
// 1.구조체 pointer를 활용하여  프로그램 작성
// 2.함수 포인터 배열선언, switch ~ case ---> 함수포인터로 호출
// 3.구조체 동적 메모리 할당 
/////////////////////////////////////////
#include <iostream>
//#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cstring>// malloc 등atoi itoa.....  
using namespace std;
#define NAME_LEN 20


class t_account {

private :
	int acc_id;     // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];  // 고객

public:
	void show_menu(void);
	void make_account(t_account* t, int* n);
	void deposit_money(t_account* t, int* n);
	void with_draw_money(t_account* t, int* n);
	void show_all_acc_info(t_account* t, int* n);
};

	void t_account::show_menu(void) {
		int i;

		const char* m[] =
		{
		 "-----Menu------\n",
		 "1. 계좌개설\n",
		 "2. 입    금\n",
		 "3. 출    금\n",
		 "4. 계좌정보 전체 출력\n",
		 "9. 종    료\n"
		};

		for (i = 0; i < 6; i++)
			cout << m[i];
	};       	// 메뉴출력

	void t_account::make_account(t_account* t, int* n)
	{
		int id = 0;
		int balance = 0;
		char name[NAME_LEN] = {};
		t_account* tp = new t_account;

		cout << "[계좌개설]\n";
		cout << "계좌ID: ";
		cin >> id;
		cout << "이  름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << endl;

		tp = t + *n;

		tp->acc_id = id;
		tp->balance = balance;
		strcpy(tp->cus_name, name);
		*n = *n + 1;
	};       	// 계좌개설을 위한 함수

	void t_account::deposit_money(t_account* t, int* n)
	{
		int money;
		int id, i;
		t_account* tp = t;

		cout << "[입    금]\n";
		cout << "계좌ID: ";
		cin >> id;
		cout << "입금액: ";
		cin >> money;

		for (i = 0; i < *n; i++, tp++)
		{
			if (tp->acc_id == id)
			{
				tp->balance += money;
				cout << "입금완료\n\n";
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다.\n\n";
	};       // 입    금

	void t_account::with_draw_money(t_account* t, int* n)
	{
		int money;
		int id, i;
		t_account* tp = t;

		cout << "[출    금]\n";
		cout << "계좌ID: ";
		cin >> id;
		cout << "출금액: ";
		cin >> money;

		for (i = 0; i < *n; i++)
		{
			if (tp->acc_id == id)
			{
				if (tp->balance < money)
				{
					cout << "잔액부족\n\n";
					return;
				}

				tp->balance -= money;
				cout << "출금완료\n\n";
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다.\n\n";
	} // 출금

	void t_account::show_all_acc_info(t_account* t, int* n)
	{
		int i;
		t_account* tp = t;

		for (i = 0; i < *n; i++, tp++)
		{
			cout << "계좌ID: " << tp->acc_id << endl;
			cout << "이  름: " << tp->cus_name << endl;
			cout << "잔  액: " << tp->balance << endl;
		}
	}	// 잔액조회이름



enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT = 9 };


//Rectangle* rect = new Rectangle;// c++식 동적 할당
//rect = (Rectangle*)malloc(sizeof(Rectangle)); // rect object를 동적 메모리 할당 


int main(void)
{
	int choice = 0;
	int acc_num = 0;
	t_account* acc_arr = new t_account[100];

	// 1. malloc을 활용 하여 280를 할당하여 시작번지를 temp에 저장
	// 2. temp에 저장된 메모리를 acc_arr 구조체 배열이 10개가
	//    생성 되도록 프로그램을 작성 하시 오   acc_arr[10]; 
#if 0
	
	
	

#endif 

#if 0
	t_account* acc_arr;

	// malloc(28*10);
	acc_arr = (t_account*)malloc(sizeof(t_account) * 10);
	if (acc_arr == NULL)
	{
		cout << "메모리 할당 실패!!!!!\n";
		return -1;
	}
	// malloc: char * 를 넘겨 준다 (char type의 시작 번지를 넘겨 준다
	// 구조체로 쓰기 위해서 구조체 t_account로 형 변환 해야 한다. 

	// t_account acc_arr[10];   	// Account 저장을 위한 배열
#endif 

	while (1)
	{
		acc_arr->show_menu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		if (choice == 9)
		{
			cout << "종료합니다.";
			delete[] acc_arr;  // 메모리 반납 
			break;
		}


		switch (choice)
		{
		
		case 1:
			acc_arr->make_account(acc_arr, &acc_num);
			break;
		case 2:
			acc_arr->deposit_money(acc_arr, &acc_num);
			break;
		case 3:
			acc_arr->with_draw_money(acc_arr, &acc_num);
			break;
		case 4:
			acc_arr->show_all_acc_info(acc_arr, &acc_num);
			break;
		default: 
			break;
		}

	}
	return 0;
}



#endif