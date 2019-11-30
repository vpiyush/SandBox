
#include<iostream>
using namespace std;


class Animal {
    private:
        int speed = 4;
        int totalFood = 87;
    public:
        void setSpeed(int sp) {
            speed = sp;
        }
        int getSpeed() {
            return speed;
        }
         int calculateSpeed() {
            cout << "in Animal" << endl;

            return speed* totalFood;
        }

        static void calculateSpeed(int mulFactor) {
            cout << "in Animal" << endl;
        }
};

class cow: public Animal {
    private:
        int numberofHorns;
    public:
/*        static void calculateSpeed(int mulFactor) {
            cout << "in COW" << endl;
        }*/
        int calculateSpeed() {
            cout << "in cow" << endl;
            return 4;
        }
};

class dog: public Animal {
};

int main () {
    Animal *a;
    Animal *a1 = new Animal();
    cow *c1= new cow();

    a = c1;
    cout << a->calculateSpeed() << endl;
    cout << a1->calculateSpeed() << endl;
    cout << c1->calculateSpeed() << endl;
     cow::calculateSpeed(78);
    return 0;
}
