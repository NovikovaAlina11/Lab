#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Class1 {
public:
    virtual void print() {
        cout << "Class1" << endl;
    }
    virtual Class1* clone() {
        return new Class1(*this);
    }
};

class Class2 : public Class1 {
public:
    void print() override {
        cout << "Class2" << endl;
    }
    Class1* clone() override {
        return new Class2(*this);
    }
};

void my_copy(Class1* obj, vector<Class1*>& db) {
    db.push_back(obj->clone());
}

int main() {
    vector<Class1*> db;

    Class1 obj1;
    Class2 obj2;
    Class1 obj3;
    Class2 obj4;

    my_copy(&obj1, db);
    my_copy(&obj2, db);
    my_copy(&obj3, db);
    my_copy(&obj4, db);

    for (auto obj : db) {
        cout << typeid(*obj).name() << endl;
        obj->print();
        delete obj;
    }

    return 0;
}