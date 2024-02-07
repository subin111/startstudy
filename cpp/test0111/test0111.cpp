#if 1
/*
301:aaaa:010-3355-1111:200000:aaaaaa:2023-11-20:2023-11-24 18.00:
302:aaaaa:010-3355-1111:200000:aaaaaaa:2023-11-20:2023-11-24 18.00:
304:qqqq:010-3355-1111:200000:bbbbbbbb:2023-11-20:2023-11-24 18.00:
305:aaaaa:010-3355-1111:200000:vvvvvvv:2023-11-20:2023-11-24 18.00:
								 < reservation.txt >
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>    // printf scanf fgets
#include <cstring>   // strcpy strcat strncpy strncmp
#include <cstdlib>   // atoi, itoa
using namespace std;
//#define NULL \0

//FILE* fp;
typedef struct _node {
	char roomno[10];
	char name[20];
	char phone[40];
	int  price;
	char address[40];
	char enter_date[20];
	char exit_date[20];
} t_NODE;

t_NODE NODE[10];  // 임시로 정적 구조체로 구현
				  // double linked list로 변환
int input_check(int* col, char* buff);
int reservation_management(void);
void exit_program();
void menu_display();

//함수
void input();
void delete_reservation();
void modify_reservation();
void one_person_display();
void all_display();

ifstream fin;
ofstream fout;

//FILE* fp;

int num = 0;

void input()
{
	if (num >= 10) {
		cout << "더 이상 예약할 수 없습니다." << endl;
		return;
	}

	cout << "객실 번호를 입력하세요: ";
	cin >> NODE[num].roomno;

	cout << "이름을 입력하세요: ";
	cin >> NODE[num].name;

	cout << "전화번호를 입력하세요: ";
	cin >> NODE[num].phone;

	cout << "가격을 입력하세요: ";
	cin >> NODE[num].price;

	cout << "주소를 입력하세요: ";
	cin >> NODE[num].address;

	cout << "입실일을 입력하세요: ";
	cin >> NODE[num].enter_date;

	cout << "퇴실일을 입력하세요: ";
	cin >> NODE[num].exit_date;

	num++;
}

void delete_reservation()
{
	char room_to_delete[10];
	cout << "퇴실할 객실 번호를 입력하세요: ";
	cin >> room_to_delete;

	for (int i = 0; i < num; i++) {
		if (strcmp(NODE[i].roomno, room_to_delete) == 0) {
			// 삭제할 예약 정보를 찾았을 경우
			for (int j = i; j < num - 1; j++) {
				// 해당 예약 정보를 삭제하고 뒤의 정보들을 앞으로 옮김
				strcpy(NODE[j].roomno, NODE[j + 1].roomno);
				strcpy(NODE[j].name, NODE[j + 1].name);
				strcpy(NODE[j].phone, NODE[j + 1].phone);
				NODE[j].price = NODE[j + 1].price;
				strcpy(NODE[j].address, NODE[j + 1].address);
				strcpy(NODE[j].enter_date, NODE[j + 1].enter_date);
				strcpy(NODE[j].exit_date, NODE[j + 1].exit_date);
			}
			num--;
			cout << "퇴실이 완료되었습니다." << endl;
			return;
		}
	}

	cout << "해당 객실 번호의 예약이 없습니다." << endl;
}

void modify_reservation()
{
	char room_to_modify[10];
	cout << "수정할 예약 정보의 객실 번호를 입력하세요: ";
	cin >> room_to_modify;

	for (int i = 0; i < num; i++) {
		if (strcmp(NODE[i].roomno, room_to_modify) == 0) {
			// 수정할 예약 정보를 찾았을 경우
			cout << "수정할 내용을 입력하세요" << endl;

			cout << "이름을 입력하세요: ";
			cin >> NODE[i].name;

			cout << "전화번호를 입력하세요: ";
			cin >> NODE[i].phone;

			cout << "가격을 입력하세요: ";
			cin >> NODE[i].price;

			cout << "주소를 입력하세요: ";
			cin >> NODE[i].address;

			cout << "입실일을 입력하세요: ";
			cin >> NODE[i].enter_date;

			cout << "퇴실일을 입력하세요: ";
			cin >> NODE[i].exit_date;

			cout << "예약 정보가 수정되었습니다." << endl;
			return;
		}
	}

	cout << "해당 객실 번호의 예약이 없습니다." << endl;
}

void one_person_display()
{
	char room_to_display[10];
	cout << "조회할 예약자의 객실 번호를 입력하세요: ";
	cin >> room_to_display;

	for (int i = 0; i < num; i++) {
		if (strcmp(NODE[i].roomno, room_to_display) == 0) {
			// 조회할 예약 정보를 찾았을 경우
			cout << "객실 번호: " << NODE[i].roomno << endl;
			cout << "이름: " << NODE[i].name << endl;
			cout << "전화번호: " << NODE[i].phone << endl;
			cout << "가격: " << NODE[i].price << endl;
			cout << "주소: " << NODE[i].address << endl;
			cout << "입실일: " << NODE[i].enter_date << endl;
			cout << "퇴실일: " << NODE[i].exit_date << endl;
			return;
		}
	}

	cout << "해당 객실 번호의 예약이 없습니다." << endl;
}

void all_display()
{
	for (int i = 0; i < num; i++) {
		cout << "객실 번호: " << NODE[i].roomno << endl;
		cout << "이름: " << NODE[i].name << endl;
		cout << "전화번호: " << NODE[i].phone << endl;
		cout << "가격: " << NODE[i].price << endl;
		cout << "주소: " << NODE[i].address << endl;
		cout << "입실일: " << NODE[i].enter_date << endl;
		cout << "퇴실일: " << NODE[i].exit_date << endl;
		cout << "---------------------------" << endl;
	}
}


int main(void)
{
	char input_buff[200];
	char price[20];
	int i;  // input_buff의 배열 index를 가리키는 변수
	int j, c;  // 현재 토큰의 문자 수
	int n = 0;

	
	fin.open("reservation.txt");

	if (!fin)   // 해당 화일이 없을 경우 null반환
	{
		cout << "can't open: reservation.txt\n";
		reservation_management();
		// 객실 관리 프로그램을 돌린다.
	}
	else   // 화일이 존재 하면
	{
		
		while (fin.getline(input_buff, 200))  // 화일로.
		{
			i = 0;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].roomno, input_buff, j);  // &input_buff[0]

			i++;   // 이름이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].name, input_buff + c, j);

			i++;   // phone이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].phone, input_buff + c, j);

			i++;   // price이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy(price, input_buff + c, j);
			NODE[num].price = atoi(price);

			i++;   // address이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].address, input_buff + c, j);

			i++;   // enter_date이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].enter_date, input_buff + c, j);

			i++;   // exit_date이 들어 있는 첫번방의 index
			c = i;
			j = input_check(&i, &input_buff[i]);
			strncpy((char*)&NODE[num].exit_date, input_buff + c, j);	// input_buff+i ==> &input_buff[i]

			num++;  // 다음 save할 NODE방의 index를 준비
		}
		//--------------------------
		// !!!!! 이곳에다 NODE구조체에 들어 있는 정보를
		// double linked list로 집어 넣는 프로그램을 구현 한다
		//
		reservation_management();

		
		cout << "프로그램이 종료 되었습니다 !!!!!\n";
		/*
		------------------ < 객실 관리 >----------------------
		   1. 입력(예약)
		   2. 삭제(퇴실)
		   3. 수정(예약내역수정)
		   4. 조회(개별조회)
		   5. 전체조회(예약자 전쳬조회)
		   9. 종료

		 Select:  1

		*/
		// ---- test를 위해서 NODE에 들어 있는
		// 9번 종료 버튼을 누르면 아래의 프로그램이 동작 되도록 한다. 
		// 정보를 reversation.txt에 write하는 프로그램을 작성 
	}
	return 0;  // 0를 return 하는 이유는 no error 
}

int reservation_management(void)
{
	//ifstream fin;// ("D:\cpp\test0111\reservation.txt");
	char input_buff[20];
	

	while (1)
	{
		menu_display();
		cout << "menu select: ";
		fgets(input_buff, 20, stdin);   // stdin : keybord 
		switch (input_buff[0])   // 1 ~ 9
		{
		case '1':  // 입력
			cout << "입력(예약)을 선택 했습니다.\n";
			input();	
			break;
		case '2':  // 삭제(퇴실)
			cout << "삭제(퇴실)을 선택 했습니다.\n";
			delete_reservation();
			break;

		case '3':  // 수정 
			cout << "수정을 선택 했습니다.\n";
			modify_reservation();
			break;

		case '4':  // 조회(개별조회)\n
			cout << "조회(개별조회)를 선택 했습니다.\n";
			one_person_display();
			break;

		case '5':  // 전체조회(예약자 전체조회)
			cout << "전체조회(예약자 전체조회)를 선택 했습니다.\n";
			all_display();
			break;
		case '9':  // 종료 
			exit_program();
			cout << "프로그램이 종료 되었습니다.  !!!!\n";
			return 0;
		}
	}

	return 0;
}

void exit_program()
{
	int i;
	//ifstream fin;
	//fin.close();
	//ofstream fout;

	
	fout.open("reservation.txt", ios::out | ios::app);
	// 기존에 들어있는reservation.txt가 다 없어진다.   
	if (!fout)   // 해당 화일이 없을 경우  
	{
		cout<< "can't open: reservation1.txt\n";
	}

	for (i = 0; i < num; i++)  // node에 들어있느 갯수 만큼 loop 
	{
		// linked list에 있는 node정보를 아래와 같이 출력 하도록 해야 한다.  
		fout << NODE[i].roomno<<":" << NODE[i].name << ":" << NODE[i].phone << ":"
			<< NODE[i].price << ":" << NODE[i].address << ":" << NODE[i].enter_date << ":"
			<< NODE[i].exit_date;
	}
	fout.close();  // fclose: 현재 프로그램과 화일의 연결고리를 끊는 작업이다. 
}

char menu[10][60] = {
"------------------ < 객실 관리 >----------------------",
"   1. 입력(예약)",
"   2. 삭제(퇴실)",
"   3. 수정(예약내역수정)",
"   4. 조회(개별조회)",
"   5. 전체조회(예약자 전체조회)",
" ",
"   9. 종료"
};

void menu_display()
{
	int i;

	for (i = 0; i < 8; i++)
		cout << menu[i]<<endl;
}
//301:홍길동:010-3355-1111:200000:경기 용인:2023-11-20:1800:2023-11-24 18.00:
// 현재 col: 4 
int input_check(int* col, char* buff)
{
	int i, j;

	char* p = buff;   // buff의 주소가 p에 들어 간다. 
	i = *col;  // 토큰의 시작위치 의 내용을 가져온다. 
	j = 0;   // 토큰의 길이를 count 
	while (*p++ != ':')   // 1) *p != ':'  2)p++
	{
		i++;   // 해당되는 필드의 위치 byte를 count 
		j++;   // 토큰의 문자수 
	}
	*col = i;   // :이 들어 있는 index 
	// 해당되는 필드의 byte수 col에 저장
	return j;  // 토큰의 문자수 
}
#endif 