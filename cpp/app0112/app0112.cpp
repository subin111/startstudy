#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 10장, 11장. 입출력, 파일 입출력
// fprintf(stdout, "OK\n"); 
// NULL: 0000 0000 <-- display 안 됨
// fprintf(stderr, "NOT OK\n"); standard error 이 파일에 집어 넣어라
// 나머지는 다 되지만, 2진수는 프로그램 짜서 display
// 
// 
// 
// 7장 프렌드
// 클래스 멤버 함수가 아닌 외부함수지만
// 클래스의 모든 멤버를 자유롭게 접근할 수 있음
// 
// 
#if 1
class Rect;
bool equals(Rect r, Rect s); // equals() 함수 선언

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) { // 외부 함수
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}

#endif
//=== 문제#2 ===
// 화일 처리 프로그램 
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string>  

#define  NAME_LEN  20

void ShowMenu(void);        // menu display
void MakeAccount(void);     // Make account 
void DepositMoney(void);    // input money
void WithdrawMoney(void);   // output money
void ShowAllAccInfo(void);  // display accout 

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT = 9 };


typedef struct
{
	int accID;   // account 
	int balance; // remain
	char cusName[NAME_LEN];   // name
} Account;

Account accArr;
int accNum = 0;   // account number

FILE* fp;
int  count;

int main(void)
{
	int choice;
    
	if ((fp = fopen("money_file", "rb+")) == NULL)
	{
	fprintf(stderr, "can't Open file wb+ : money_file....\n");
		exit(1);
	}
    
	while (1)
	{
		ShowMenu();
		printf("Select: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			fclose(fp);
			return 0;
		default:
			fprintf(stderr, "Illegall Select :%d\n", choice);
			break;
		}

	}
}

void ShowMenu(void)
{
	printf("-----MENU-----\n");
	printf("1. Open Account\n");
	printf("2. Deposit Money\n");
	printf("3. With Draw Money\n");
	printf("4. Show All Account info\n");
	printf("9. End\n");
}

void MakeAccount(void)
{
	int i, id, balance;
	char name[NAME_LEN];
	Account accArr;

	printf("[Open Account]\n");
	printf("Account ID: ");
	scanf("%d", &id);
	printf("Name: ");
	scanf("%s", name);
	printf("Money: ");
	scanf("%d", &balance);
	printf("\n");

	rewind(fp);//하드디스크의 헤더를 있던 곳에서 맨 처음으로 돌려준다.
	for (i = 0; ; i++)
	{
		if (fread((char*)&accArr.accID, 1, sizeof(accArr), fp) == NULL)
		{
			break;
		}
		else if (accArr.accID == id)
		{
			printf("Already exist ID %d\n", id);
			return;
		}
	}

	fseek(fp, 0, SEEK_END);

	accArr.accID = id;
	accArr.balance = balance;
	strcpy(accArr.cusName, name);

	fwrite((char*)&accArr.accID, 1, sizeof(accArr), fp);
	accNum++;
}


void DepositMoney(void)
{

	int money;
	int id, size;

	printf("[Deposit Money]\n");
	printf("Account ID: ");
	scanf("%d", &id);
	printf("Money: ");
	scanf("%d", &money);

	rewind(fp);
	for (int i = 0; i < accNum; i++)
	{
		if (fread((char*)&accArr.accID, 1, sizeof(accArr), fp) == NULL)
		{
			break;
		}
		else if (accArr.accID == id)
		{
			accArr.balance += money;
			size = sizeof(Account);
			fseek(fp, -size, SEEK_CUR);
			fwrite((char*)&accArr.accID, 1, sizeof(accArr), fp);
			printf("Input End!!!\n\n");
			return;
		}
	}
	printf("Account does't exist.... \n");
}


void WithdrawMoney(void)
{
	int money, id, size;

	printf("[With Draw Money]\n");
	printf("Account ID: ");
	scanf("%d", &id);
	printf("Money: ");
	scanf("%d", &money);

	rewind(fp);
	for (int i = 0; i < accNum; i++)
	{
		if (fread((char*)&accArr.accID, 1, sizeof(accArr), fp) == NULL)
		{
			break;
		}
		else if (accArr.accID == id)
		{
			if (accArr.balance < money)
			{
				printf("out of money....\n\n");
				return;
			}
			accArr.balance -= money;
			size = sizeof(Account);
			fseek(fp, -size, SEEK_CUR);
			fwrite((char*)&accArr.accID, 1, sizeof(accArr), fp);
			printf("Output Money!!!\n\n");
			return;
		}

	}
	printf("Invalid Account ID %d\n", id);
}


void ShowAllAccInfo(void)
{
	rewind(fp);

	for (int i = 0; i < accNum; i++)
	{
		if (fread((char*)&accArr.accID, 1, sizeof(accArr), fp) == NULL)
		{
			break;
		}
		printf("Account ID: %d\n", accArr.accID);
		printf("Name : %s\n", accArr.cusName);
		printf("balance : %d\n\n\n", accArr.balance);
	}
	printf("\n");
}
/*------------------------  end of program -----------------------*/
#endif


//c언어에서 파일을 다이렉트로 찾아가는 방법
#if 0
#include <stdio.h>
#include <string>
FILE* fp;

int main(void) {

    fp = fopen("student.txt", "w");

    fseek(fp, 20, SEEK_SET); //20번째 record를 찾아감
    fclose(fp);
    
    return 0;
}


#endif

//c++, 파일에서 1줄씩 읽어서 다른 파일로 출력
#if 0
#include <fstream>
#include <string>
#pragma execution_character set("utf-8")
ifstream inf;
ofstream outf;

int main(void) {
    
    inf.open("bin.txt");
    outf.open("out.txt");
    string line;


    while (!inf.eof()) 
    {
        getline(inf, line);
        cout << line << endl;
        outf << line << endl;
    }
    inf.close();
    outf.close();

    return 0;
}


#endif

//c++, 파일에서 1줄씩 읽어오기
#if 0
#include <cstdio>//stdio.h
#include <cstdlib>
#include <cstring>
#include <string>
/*
----0----|----10---|----20---|----30---|----40---|
123456789|123456789|123456789|123456789|123456789|

                   ASCII CODE TABLE
                   ================
   DEC       HEX       OCT       BIN        CHR
   ===       ===       ===       ===        ===
    0        0x00       0      00000000     NULL

*/
int binary(int i) {
    
    int mok, nmg;
    int j = 0;
    int k = 0;
    int temp[8] = { 0, };
    char ch[8][1] = {0, };
 
    do {
        mok = i / 2;
        nmg = i - mok * 2;
        temp[k++] = nmg;
        i = mok; 
        temp[k];
    } while (mok != 0);

    for (int j = 0; j < 8; j++) {
        sprintf(ch[j], "%d", temp[j]);
    }
    return 0;
}
int main(void)
{
    int temp[8] = { 0, };
    //char tp[10];
    char ch[8][1];
    int i = 0;
    char arr[33][5] = { "NULL", "SOH","SOH", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT",
                        "LF", "VT",   "FF",  "CR",  "SO",  "SI", "DLE", "DC1", "DC2", "DC3",
                        "DC4", "NAK", "SYN", "ETB","CAN",  "EM", "SUB", "ESC", "FS", "GS",
                        "RS", "US", "SP"
    };
    printf("%35s\n", "ASCII CODE TABLE\n");
    //-%35s: 왼쪽부터 채워놓음
    printf("%35s\n", "================\n\n");

    for (int i = 0; i < 128; i++)
    {   
        
        if (i % 30 == 0)
        {
            printf("%10s%10s%10s%10s%10s\n", "DEC", "HEX", "OCT", "BIN", "CHR");
            printf("%10s%10s%10s%10s%10s\n", "===", "===", "===", "===", "===");

        }

        if (i < 33)
        {
            binary(i);
#if 0
            printf("%10d%10.2x%10o  %s%10s\n", i, i, i,
                _itoa(i, tp ,2), arr[i]);
#endif
            printf("%10d%10.2x%10o  %8s%10s\n", i, i, i,
                ch, arr[i]);
        } else
        {
            binary(i);
#if 0
            printf("%10d%10.2x%10o  %s%10c\n", i, i, i,
                _itoa(i,tp,2), i);
#endif
            printf("%10d%10.2x%10o  %8s%10c\n", i, i, i, 
                ch, i);
        }
    }
    return 0;
}
#endif

/*
----0----|----10---|----20---|----30---|----40---|
123456789|123456789|123456789|123456789|123456789|

                   ASCII CODE TABLE
                   ================
        DEC       HEX       OCT       CHR
        ===       ===       ===       ===
         0        0x00       0        NULL

*/

#if 0
#include <cstdio>//stdio.h

int main(void)
{
    char arr[33][5] = {"NULL", "SOH","SOH", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT",
                        "LF", "VT",   "FF",  "CR",  "SO",  "SI", "DLE", "DC1", "DC2", "DC3", 
                        "DC4", "NAK", "SYN", "ETB","CAN",  "EM", "SUB", "ESC", "FS", "GS", 
                        "RS", "US", "SP"
    };
    printf("%35s\n", "ASCII CODE TABLE\n");
    //-%35s: 왼쪽부터 채워놓음
    printf("%35s\n", "================\n\n");

    for (int i = 0; i < 128; i++)
    {
        
        if (i % 30 == 0)
        {
            printf("%10s%10s%10s%10s\n", "DEC", "HEX", "OCT", "CHR");
            printf("%10s%10s%10s%10s\n", "===", "===", "===", "===");
            
        }
        //printf("%10d%10.2x%10o%10c\n", i,i,i,i);
        if (i < 33)
        {
            printf("%10d%10.2x%10o%10s\n", i, i, i, arr[i]);
        }
        else 
        {
            printf("%10d%10.2x%10o%10c\n", i, i, i, i);
        }
    }
    return 0;
}
#endif


//입출력 함수
#if 0
FILE* inf;

if ((inf = fopen("input.txt", "r") == NULL) {
    fprintf(stderr, "cant open input.txt")
}

istream $ignore(int n = 1, int delim = EOF)
cin.getline(line, 80);
cin.gcount()//입력 스트림에서 읽은 바이트 수(문자 개수)리턴.enter키 포함
cin.ignore(10,';');//입력 스트림에서 10개 문자 제거, 제거 도중 ';'을 만나면 종료

int main()
{
    return 0;
}
#endif


//p555
//3d 1e 0x1e 0x1E
//23.500 . .
#if 0
int main()
{
    int a = 0;
    double b = 0.00;

    cout << "두 수를 입력(int double): ";
    cin >> a >> b;
    while (1) {
        if ((a == 0) && (b == 0.0)) { break; }

        cout.unsetf(ios::dec);//10진수 해제

        cout.setf(ios::hex);//16진수
        cout << a << " ";

        cout.setf(ios::showbase);//0x1e
        cout << a << " ";

        cout.setf(ios::uppercase);//0xiE
        cout << a << endl;
        //
        cout.setf(ios::hex);//16진수
        cout << b << " ";

        cout.setf(ios::showbase);//0x1e
        cout << b << " ";

        cout.setf(ios::uppercase);//0xiE
        cout << b << endl;

        cout << "두 수를 입력(int double): ";
        cin >> a >> b;
    }
        //cout.setf(ios::dec | ios::showpoint);

        //cout << a << " " << b << endl;

        //cout.setf(ios::scientific);
        //cout << a << " " << b << endl;

       // cout.setf(ios::showpos);
        //cout << a << " " << b << endl;
    
    return 0;
}
#endif