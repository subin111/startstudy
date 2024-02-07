#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//exit 했으면 exit return 했으면 return으로 통일해주는게 좋다.
#if 0
#include <cstdlib> // RAND_MAX: stdlib에 매크로로 작성되어 있음, 32767임
// rand(); 함수 stdlib에 있음

class EvenRandom {
    //int seed = 0; //이건 왜?
public: // private로 하면, Random::next()
    //Random::nextInRange에서 에러 - 프라이빗 멤버에 접근할 수 없다
    int next();
    int nextInRange(int start, int end);
};

int EvenRandom::next() {

    int n = rand();
    return n;
}

int Random::nextInRange(int start, int end) {
    int n = rand() % (end - start + 1) + start;
    return n;
}

int main() {
    Random r;
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl << endl << "-- 0에서 " << RAND_MAX << "4 까지의 랜덤 정수 10 개--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4);
        cout << n << " ";
    }
    cout << endl;

}

#endif
#if 0
#include <cstdlib> // RAND_MAX: stdlib에 매크로로 작성되어 있음, 32767임
// rand(); 함수 stdlib에 있음

class Random {
    //int seed = 0; //이건 왜?
public: // private로 하면, Random::next()
    //Random::nextInRange에서 에러 - 프라이빗 멤버에 접근할 수 없다
    int next();
    int nextInRange(int start, int end);
};

int Random::next() {
    
    int n = rand();
    return n;
}

int Random::nextInRange(int start, int end) {
    int n = rand() % (end - start + 1) + start;
    return n;
}

int main() {
    Random r;
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
        }
    cout << endl <<endl<<"-- 0에서 " << RAND_MAX << "4 까지의 랜덤 정수 10 개--" << endl; 
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4);
        cout << n << " ";
        }
    cout << endl;
    
}

#endif
#if 0
class CoffeeMachine {
private:
    int coffee;
    int water;
    int sugar;
public:
    CoffeeMachine(int coffee, int water, int sugar);
    void drinkEspresso();
    void drinkAmericano();
    void drinkSugarCoffee();
    void show();
    void fill();

};

CoffeeMachine::CoffeeMachine(int coffee, int water, int sugar) {

    this->coffee = coffee;
    this->water = water;
    this->sugar = sugar;
}
void CoffeeMachine::drinkEspresso() {

    coffee = coffee - 1;
    water = water - 1;
}
void CoffeeMachine::drinkAmericano() {
    coffee = coffee - 1;
    water = water - 2;
}
void CoffeeMachine::drinkSugarCoffee() {
    coffee = coffee - 1;
    water = water - 2;
    sugar = sugar - 1;

}
void CoffeeMachine::show()
{
    cout << "커피 머신 상태, 커피:" << coffee << "\t물:" << water << "\t설탕:" << sugar << endl;
}
void CoffeeMachine::fill()
{
    coffee = 10;
    water = 10;
    sugar = 10;
}
int main() {
    CoffeeMachine java(5, 10, 3);
    java.drinkEspresso();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinkSugarCoffee();
    java.show();
    java.fill();
    java.show();
}

#endif
#if 0
class Account {
public:
    string name;
    int balance;
    int id;
    
    Account(string name, int id, int balance);

    //함수라 리턴값 가짐
    void deposit(int money);
    int withdraw(int money);
    string getOwner();
    int inquiry();

};
Account::Account(string name, int id, int balance) {
    this->name = name;
    this->id = id;
    this->balance = balance;

}void Account::deposit(int money) {

    balance = money + balance;
    

}
int Account::withdraw(int money){
    balance = balance - money;
    return balance;
}
string Account::getOwner() {

    return name;

}

int Account::inquiry() {

    return balance;
}
int main() {
    Account a("kitae", 1, 5000);
    a.deposit(50000);
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
    int money = a.withdraw(20000);
    cout<<a.getOwner()<< "의 잔액은 " << a.inquiry() << endl;
}

#endif
#if 0
class Date {

public: 
    int year;
    int month;
    int day;
    Date(string date);
    Date(int year, int month, int day);
    void show();
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() {return day;
    }

};
Date::Date(int year, int month, int day) {
    //int getYear(int year);
    this->year = year;
    this->month = month;
    this->day = day;
    //int getMonth(int month);
    //int getDay(int day);
}
Date::Date(string date) {
    int ind;
    this->year = stoi(date);

    ind = date.find('/');
    this->month = stoi(date.substr(ind + 1));

    ind = date.find('/', ind + 1);
    this->day = stoi(date.substr(ind + 1));
}
void Date::show(){
    cout << year << "년"<< month << "월" << day << "일" << endl;
    
}

int main() {

    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << "," << birth.getMonth() << ',' << birth.getDay()<< endl;
}


#endif
#if 0
class Tower {
public:    
    int height;
    Tower();
    Tower(int height);
    int getHeight();
};
Tower::Tower() {
    height = 1;
}
Tower::Tower(int height) {
    this->height = height;
}

int Tower::getHeight() {

    return height;
}

int main()
{
    Tower myTower;
    Tower seoulTower(100);
    cout << "높이는" << myTower.getHeight() << "미터" << endl;
    cout << "높이는" << seoulTower.getHeight() << "미터" << endl;
}

#endif