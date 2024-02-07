#include <iostream>
using namespace std;

//9장 10번
#if 0

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
public:
	static int getMenu() {
		int key;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> key;
		return key;
	}
	static int getShapeTypeToInsert() {
		int key;
		cout << "선:1, 원:2, 사각형:3 >>";
		cin >> key;
		return key;
	}
	static int getShapeIndexToDelete() {
		int key;
		cout << "삭제하고자 하는 도형의 인덱스 >>";
		cin >> key;
		return key;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = pLast = NULL; }
	void insertItem(int type) {
		Shape* p = NULL;
		switch (type) {
		case 1:
			p = new Line();
			break;
		case 2:
			p = new Circle();
			break;
		case 3:
			p = new Rectangle();
			break;
		default:
			break;
		}
		if (pStart == NULL) {
			pStart = p;
			pLast = p;
			return;
		}
		pLast->add(p);
		pLast = pLast->getNext();
	}
	void deleteItem(int index) {
		Shape* pre = pStart;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "도형이 없습니다!" << endl;
			return;
		}
		for (int i = 1; i < index; i++) {
			pre = tmp;
			tmp = tmp->getNext();
		}
		if (tmp == pStart) {			//첫번째 도형을 삭제하는 경우
			pStart = tmp->getNext();
			delete tmp;
		}
		else {
			pre->add(tmp->getNext());
			delete tmp;
		}
	}
	void show() {
		Shape* tmp = pStart;
		int i = 1;
		while (tmp != NULL) {
			cout << i++ << ": ";
			tmp->paint();
			tmp = tmp->getNext();
		}
	}
	void run() {
		cout << "그래픽 에디터입니다." << endl;
		int menu, index, type;
		while (true) {
			menu = UI::getMenu();
			switch (menu) {
			case 1:
				type = UI::getShapeTypeToInsert();
				insertItem(type);
				break;
			case 2:
				index = UI::getShapeIndexToDelete();
				deleteItem(index);
				break;
			case 3:
				show();
				break;
			default:
				return;
			}
		}
	}
};

int main() {
	GraphicEditor graphicEditor;
	graphicEditor.run();

	return 0;
}

#endif
// 9장 9번
#if 0
class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo = "", string me = "", int a = 0) {
		this->model = mo;
		this->manufacturer = me;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }
	void setModel(string model) { this->model = model; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	void setPrintedCount(int printedCount) { this->printedCount = printedCount; }
	void setAvailableCount(int availableCount) { this->availableCount = availableCount; }

	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableInk(getAvailableInk() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 잉크 " << getAvailableInk() << endl;
	}
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int availableInk) { this->availableInk = availableInk; }
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableToner(getAvailableToner() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 토너 " << availableToner << endl;
	}
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int availableToner) { this->availableToner = availableToner; }
};

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laser->show();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->print(paper); break;
		case 2: laser->print(paper); break;
		default: break;
		}
		ink->show();
		laser->show();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	}

	return 0;
}
#endif

//9장 8번
#if 0

class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() = 0;
	string getname() { return name; }
};

class Oval :public Shape {
public:
	Oval(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 3.14;
	}
};

class Rect :public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height;
	}
};

class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 0.5;
	}
};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++) {
		cout << p[i]->getname() << " 넓이는 " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
	return 0;
}


#endif

// 9장 7번
#if 0
class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }
	string getname() { return name; }
};

class Oval :public Shape {
public:
	Oval(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 3.14;
	}
};

class Rect :public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height;
	}
};

class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 0.5;
	}
};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++) {
		cout << p[i]->getname() << " 넓이는 " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
	return 0;
}
#endif