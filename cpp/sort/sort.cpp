#include <string>
#include <cstring>
#include <iostream>
using namespace std;
//#define SWAP(a,b,tmp){tmp = a; a= b; b = tmp; }

void bubblesort(int *data[], int n) {

	int temp = 0;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);

			}
		}

	}
}
int main()
{
	cout << "입력할 정수의 개수는?";
	int n;
	int* data = NULL;
	cin >> n;
	if (n <= 0) return 0;
	data = new int[n];
	
	if (!data) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;//에러 난 거니까 return 0보다 -1이런 값으로 리턴
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 정수: ";
		cin >> data[i];
		//if문으로 에러났을 때 break해주는 경우 만들어주기
		

	}
	bubblesort(data, n);
	//int *q = new int[n];
	
	
		//if (i > 0) { cout << " "; }
	
	for (int i = 0; i < n; i++) {
		cout << "정렬된 결과를 출력: " << data[i] << endl;
	}




	
		
	
	delete[] data;



}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
