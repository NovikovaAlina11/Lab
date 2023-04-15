#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Car {
protected:
	string Model;
	string Brand;
public:
	Car(string model) : Model(model) {}
	virtual void printModel() {
		cout << "Model: " << Model << endl;
	}
	virtual void printBrand() {
		cout << "Brand: " << Brand << endl;
	}
	virtual ~Car() {}
};

class MercedesBenz : public Car {
public:
	MercedesBenz(string model) : Car(model) {}
	void printBrand() {
		cout << "Brand: Mercedes-Benz" << endl;
	}
};

class BMW : public Car {
public:
	BMW(string model) : Car(model) {}
	void printBrand() {
		cout << "Brand: BMW" << endl;
	}
};

class Toyota : public Car {
public:
	Toyota(string model) : Car(model) {}
	void printBrand() {
		cout << "Brand: Toyota" << endl;
	}
};

int main() {
	vector<Car*> cars;
	ifstream file("cars.txt");
	string brand, model;
	while (file >> brand >> model) {
		if (brand == "MercedesBenz") {
			cars.push_back(new MercedesBenz(model));
		}
		else if (brand == "BMW") {
			cars.push_back(new BMW(model));
		}
		else if (brand == "Toyota") {
			cars.push_back(new Toyota(model));
		}
	}
	file.close();
	for (auto car : cars) {
		car->printBrand();
		car->printModel();
		delete car;
	}
	return 0;
}