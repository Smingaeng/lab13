#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw()=0;
}; //virtual -> �ڽ� Ŭ�������� Override

class Rectangle : public Shape {
public:
	void draw() {
		cout << "Shape: Rectangle" << endl;
	} //override
};

class Circle : public Shape {
public:
	void draw() {
		cout << "Shape: Circle" << endl;
	} //override
};

class ShapeDecorator : public Shape {
protected:
	Shape* decoratedShape;
public:
	ShapeDecorator(){}
	ShapeDecorator(Shape* decoratedShape) {
		this->decoratedShape = decoratedShape;
	}
	void draw() {
		decoratedShape->draw();
	} //override
};

class RedShapeDecorator : public ShapeDecorator {
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}
	//������ ���
	void draw() {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	} //override
private:
	void setRedBorder(Shape* decoratedShape) {
		cout << "Border Color: Red" << endl;
	}
};

int main() {
	Shape *circle = new Circle(); //�����Ҵ�
	Shape *redCircle = new RedShapeDecorator(new Circle()); //�����Ҵ�
	Shape *redRectangle = new RedShapeDecorator(new Rectangle()); //�����Ҵ�
	cout << "Circle with normal border" << endl;
	circle->draw();
	cout << "\nCircle of red border" << endl;
	redCircle->draw();
	cout << "\nRectangle of red border" << endl;
	redRectangle->draw();
	return 0;
}
