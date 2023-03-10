#include <iostream>
using namespace std;

class Leaf {
	float greeness;
};

class Potato {

private:
	float size = 0;
	float weight = 0;
	const char* origin;
	Leaf* leaves;


public:
	Potato() { //constructor from inside the class
		cout << "new potato" << endl;
		size = rand() * 10;
		weight = rand() * 10;
		leaves = new Leaf[100];
	}
	Potato(float size_, float weight_, const char* origin_) {
		cout << "new potato" << endl;
		size = size_;
		weight = weight_;
		origin = origin_;
	}
	void Grow() {
		size++;
		weight++;
	}
	float getSize() {
		return size;
	}

	//~Potato() { //default destructor

	//}

	~Potato() {
		cout << "Goodbye World" << endl;
		delete(leaves); // an object of a class declared dynamically inside another class needs to be deleted in the destructor of the class where its been initialized 
	}

};

class Vector3 {
private:

	int x, y, z;
	const char* name;

public:

	Vector3() : x(9), y(99), z(999)
	{
		x = 0;
		y = 0;
		z = 0;
		name = "name";
		//default constructor overwrites previous values (if defined)
	}

	Vector3(int x_, int y_, int z_) : Vector3() { //calling the class here will give it the default values it has been first initialized to
		x = x_;
		y = y_;
		z = z_;
		//change parameters' names so it makes sense to the compiler (otherwise, x = x would be the same as saying 1=1;
	}

	Vector3(const Vector3& old) { //copy constructor: makes a new instance of the class with the same values as the one passed as parameters
		x = old.x;
		y = old.y;
		z = old.z;
	}

	void print() {
		cout << "x: " << x << "y: " << y << "z: " << z << endl;
	}

	int getX() const { //not allowed to modify its value by writing const after the parenthesis
		return x;
	}

	void setX(int x) {
		this->x = x; //the kewyword "this->" refers to the variable from the class, its another way of avoiding an x = x like we did with x_
	}

};


	

int main() {
	{
		Potato papa(2, 4, "Spain");
		papa.Grow();
		cout << papa.getSize() << endl;
		//whenever we get out of the scope where the object has been (locally) constructed, it gets destructed automatically (destructor gets called)
	}
	
	
	cout << papa.getSize() << endl; //got out of the scope so papa got destructed

	Potato* potatoPtr = new Potato(10, 10, "Farm");//since we defined parameters, neither the constructor or the destructor are called, so it's your reponsability to delete it from the heap
	Potato* potatoPtr2 = new Potato(10, 10, "Lab");
	delete(potatoPtr);
	delete(potatoPtr2);

	Vector3 v1(5, -9, 10);
	Vector3 v2();
	Vector3* v3 = new Vector3(3, 4, 5);
	(*v3).print();
	v3->print(); // same as previous line, called indirection operator

	Vector3 v2();
	
	delete(v3);
	
	return 0;
}