



#include <iostream>
using namespace std;

class Animal {
public:
    Animal() : age(0), alive(true), id(++count), location(make_pair(0,0)) {}

    Animal(int age, double x, double y) : age(age), alive(true), id(++count), location(make_pair(x, y)) {}

    Animal(const Animal& other) : age(other.age), alive(other.alive), id(++count), location(other.location) {}

    virtual ~Animal() {}

    virtual void move(double x, double y) {
        location = make_pair(x, y);
    }

    virtual void sleep() {
        cout << "The animal is asleep." << endl;
    }

    virtual void eat() {
        cout << "The animal is eating." << endl;
    }

    void setAlive(bool value) {
        alive = value;
    }

    friend ostream& operator<<(ostream& os, Animal& animal) {
        os << "ID: " << animal.id << ", Age: " << animal.age << ", Location: (" << animal.location.first << ", " << animal.location.second << "), Alive: " << animal.alive;
        return os;
    }

protected:
    int age;
    long id;
    bool alive;
    pair<double, double> location;

private:
    static long count;
};

long Animal::count = 0;

class Bird : public Animal {
public:
    Bird() : Animal() {}
    
    Bird(int age, double x, double y) : Animal(age, x, y) {}

    virtual ~Bird() {}

    void move(double x, double y) {
        cout << "The bird is flying to (" << x << ", " << y << ")." << endl;
        Animal::move(x, y);
    }
    
    void sleep() {
        cout << "The bird is asleep." << endl;
    }
    
    void eat() {
        cout << "The bird is eating." << endl;
    }
};

class Canine : public Animal {
public:
    Canine() : Animal() {}

    Canine(int age, double x, double y) : Animal(age, x, y) {}

    virtual ~Canine() {}

    void move(double x, double y) {
        cout << "The canine is running to (" << x << ", " << y << ")." << endl;
        Animal::move(x, y);
    }

    void sleep() {
        cout << "The canine is asleep." << endl;
    }

    void eat() {
        cout << "The canine is eating." << endl;
    }
};

int main() {
    Canine obj(5, 10.0, 20.0);
    obj.sleep();
    obj.eat();
    obj.move(30.0, 40.0);
    cout << obj << endl;
 return 0;
}
