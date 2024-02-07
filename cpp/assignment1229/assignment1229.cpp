#if 1

// pg 90 #7
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void) {


	return 0;
}

#endif

#if 0

// pg 90 #6
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void) {

	cout << "새 암호를 입력하세요>>"; 
	char a[10];
	cin >> a;
	//cin.getline(a, sizeof(a));
	cout << "새 암호를 다시 입력하세요>>";
	char b[10];
	//cin.getline(b, sizeof(b));
	cin >> b;

	if (strcmp(a, b) !=0)
		cout << "같지 않습니다.";
	else
		cout << "같습니다.";
	return 0;
}

#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#define NAME_LEN  20

void show_menu(void);       // 메뉴출력
void make_account(t_account* t, int* n);        // 계좌개설을 위한 함수
void deposit_money(t_account* t, int* n);         // 입    금
void with_draw_money(t_account* t, int* n);     // 출    금
void show_all_acc_info(t_account* t, int* n);     // 잔액조회


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT = 9 };

typedef struct
{
	int acc_id;      // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];   // 고객이름
} t_account;

t_account acc_arr[100];   // Account 저장을 위한 배열
int acc_num = 0;        // 저장된 Account 수

int main()  // int main(argc, char *argv[])
{
	int choice;
	t_account acc_arr[100];   // Account 저장을 위한 배열
	int acc_num = 0;           // 저장된 Account 수

	while (1)
	{
		show_menu();
		printf("선택: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case MAKE:
			make_account(acc_arr, &acc_num);
			break;
		case DEPOSIT:
			deposit_money(acc_arr, &acc_num);
			break;
		case WITHDRAW:
			with_draw_money(acc_arr, &acc_num);
			break;
		case INQUIRE:
			show_all_acc_info(acc_arr, &acc_num);
			break;
		case EXIT:
			return 0;
		default:
			printf("Illegal selection..\n");
		}
	}
	return 0;
}

void show_menu(void)
{
	char* menu[] =
	{
		"-----Menu------\n",
		"1. 계좌개설\n",
		"2. 입    금\n",
		"3. 출    금\n",
		"4. 계좌정보 전체 출력\n",
		"9. 종    료\n"
	};
	int i;

	for (i = 0; i < 6; i++)
		printf("%s", *(menu + i));
}

void make_account(t_account *t, int *n)
{
	int id;
	char name[NAME_LEN];
	int balance;

	printf("[계좌개설]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("이  름: ");
	scanf("%s", name);
	printf("입금액: ");
	scanf("%d", &balance);
	printf("\n");

	acc_arr[acc_num].acc_id = id;
	acc_arr[acc_num].balance = balance;
	strcpy(acc_arr[acc_num].cus_name, name);
	acc_num++;
}

void deposit_money(t_account* t, int* n)
{
	int money = 0;
	int id = 0, i = 0;

	printf("[입    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);

	for (i = 0; i < acc_num; i++)
	{
		if (acc_arr[i].acc_id == id)
		{
			acc_arr[i].balance += money;
			printf("입금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account* t, int* n)
{
	int money;
	int id, i;

	printf("[출    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);

	for (i = 0; i < acc_num; i++)
	{
		if (acc_arr[i].acc_id == id)
		{
			if (acc_arr[i].balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			acc_arr[i].balance -= money;  // acc_arr[i].balance = acc_arr[i].balance - money;
			printf("출금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account* t, int* n)
{
	int i;

	for (i = 0; i < acc_num; i++)
	{
		printf("계좌ID: %d\n", acc_arr[i].acc_id);
		printf("이  름: %s\n", acc_arr[i].cus_name);
		printf("잔  액: %d\n\n", acc_arr[i].balance);
	}
}
#endif


