#define _CRT_SECURE_NO_WARNINGS
#if 1
/////////////////////////////////////////
// 0.
// 1.구조체 pointer를 활용하여 프로그램 작성
// 2.함수 포인터 배열선언, switch ~ case ---> 함수포인터로 호출
// 3.구조체 동적 메모리 할당
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc 등atoi itoa.....
#define NAME_LEN 20
typedef struct
{
	int acc_id; // 계좌번호
	int balance; // 잔 액
	char cus_name[NAME_LEN]; // 고객이름
} t_account; // 28bytes
void show_menu(void); // 메뉴출력
void make_account(t_account* t, int* n); // 계좌개설을 위한 함수
void deposit_money(t_account* t, int* n); // 입 금
void with_draw_money(t_account* t, int* n); // 출 금
void show_all_acc_info(t_account* t, int* n); // 잔액조회
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT = 9 };
int main(void)
{
	int choice;
	int acc_num = 0; // 저장된 Account 수
	char* temp;
	t_account* acc_arr;
	// 1. malloc을 활용 하여 280를 할당하여 시작번지를 temp에 저장
	// 2. temp에 저장된 메모리를 acc_arr 구조체 배열이 10개가
	// 생성 되도록 프로그램을 작성 하시 오 acc_arr[10];
#if 1
	temp = (char*)malloc(280);
	printf("temp 시작 번지: %u\n", temp);
	acc_arr = (t_account*)temp;
#endif
#if 0
	t_account* acc_arr;

	// malloc(28*10);
	acc_arr = (t_account*)malloc(sizeof(t_account) * 10);
	if (acc_arr == NULL)
	{
		printf("메모리 할당 실패!!!!!\n");
		return -1;
	}
	// malloc: char * 를 넘겨 준다 (char type의 시작 번지를 넘겨 준다
	// 구조체로 쓰기 위해서 구조체 t_account로 형 변환 해야 한다.
	// t_account acc_arr[10]; // Account 저장을 위한 배열
#endif
	void (*fp[]) (t_account*, int*) = // 1. 함수 포인터 배열 완
	{
	NULL, // 0번방
	make_account, // 1
	deposit_money,
	with_draw_money,
	show_all_acc_info // 4
	};
	while (1)
	{
		show_menu();
		printf("선택: ");
		scanf("%d", &choice);
		printf("\n");
		if (choice == 9)
		{
			free(acc_arr); // 메모리 반납
			break;
		}
		if (choice >= 1 && choice <= 4)
			fp[choice](acc_arr, &acc_num); // 2.함수 포인터 활용 함수호출

		
	}
	return 0;
}
void show_menu(void)
{
	int i;
	const char* m[] =
	{
	"-----Menu------\n",
	"1. 계좌개설\n",
	"2. 입 금\n",
	"3. 출 금\n",
	"4. 계좌정보 전체 출력\n",
	"9. 종 료\n"
	};
	for (i = 0; i < 6; i++)
		printf("%s", m[i]);

}
void make_account(t_account* t, int* n)
{
	int id;
	int balance;
	char name[NAME_LEN];
	t_account* tp;
	printf("[계좌개설]\n");
	printf("계좌ID: ");
	scanf("%d", &id);

	printf("이 름: ");
	scanf("%s", name);
	printf("입금액: ");
	scanf("%d", &balance);
	printf("\n");
	tp = t + *n;
	tp->acc_id = id;
	tp->balance = balance;
	strcpy(tp->cus_name, name);
	*n = *n + 1;
}
void deposit_money(t_account* t, int* n)
{
	int money;
	int id, i;
	t_account* tp = t;
	printf("[입 금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);
	for (i = 0; i < *n; i++, tp++)
	{
		if (tp->acc_id == id)
		{
			tp->balance += money;
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
	t_account* tp = t;
	printf("[출 금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);
	for (i = 0; i < *n; i++)
	{
		if (tp->acc_id == id)
		{
			if (tp->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}
			tp->balance -= money;
			printf("출금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}
void show_all_acc_info(t_account* t, int* n)
{

	int i;
	t_account* tp = t;
	for (i = 0; i < *n; i++, tp++)
	{
		printf("계좌ID: %d\n", tp->acc_id);
		printf("이 름: %s\n", tp->cus_name);
		printf("잔 액: %d\n\n", tp->balance);
	}
}
#endif
