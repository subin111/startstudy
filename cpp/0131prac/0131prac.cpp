//c++ 함수 템플릿
//기존에는 변수 타입이 다르면 다른 변수를 처리하기 위해서
//함수를 따로 정의하여 overloading으로 동작하도록 하였다.
//함수 템플릿을 사용하면 overloading을 위해 함수를 따로 구현할 필요 없다.

/*
vector class
vector란: 여러 개의 가변적인 data를 저장이 가능하다.
- 특정 위치의 배열처럼 접근이 가능 a[]
- 새로운 데이터를 추가하거나 삭제가 가능하다.

vector를 사용하려면
std:: vector <typename> variable_name
#include <vector>

--주요 문법--
vector <T> v1 ==> T타입을 저장할 벡터 v1을 생성
                    vector <char> v1
vector <T> v2(v1) // v1을 복사하여 벡터 v1을 생성
vector <T> v3(n)// v1을 복사하여
vector <T> v5(a,b,c,d,e)

*/
#include <iostream>
using namespace std;

#if 1
#include <vector>
#include <string>

int main()
{
    vector <int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;

    vector <string> b = { "Open", "CV", "QT", "Building" };
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
    return 0;
}
#endif

// =========overloading 사용시의 예============
// =========template 사용======================
#if 0

template <typename T>
//템플릿
T arry_sum(T* arr, int len) {

    T sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;

}
#if 0
int arry_sum(int *iarr, int len) 
{

    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += iarr[i];
    return sum;
}

float arry_sum(float * iarr, int len)
{

    float sum = 0;
    for (int i = 0; i < len; i++)
        sum += iarr[i];
    return sum;
}
#endif
int main()
{
    int iarr[6] = { 1,2,3,4,5,6 };
    float farr[6] = { 1.1,1.2,1.3,1.4,1.5,1.6 };

    int isum = arry_sum(iarr, 6);
    cout << "isum: " << isum << endl;

    float fsum = arry_sum(farr, 6);
    cout << "fsum: " << fsum << endl;

}
#endif