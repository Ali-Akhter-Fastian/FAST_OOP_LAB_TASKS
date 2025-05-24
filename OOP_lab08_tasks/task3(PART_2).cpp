// Yes, it is possible to overload an operator using a friend function even if one of the
// operands is a primitive data type, such as object + int.
// In fact, using a friend function is often necessary in such cases because member functions
// can only handle expressions where the object is on the left-hand side (i.e., object + int),
// but not when the primitive is on the left (i.e., int + object).

//TASK 03(PART_02) BY ALI AKHTER 24K-0809


#include <iostream>
using namespace std;
class Box {
private:
    int length;
public:
    Box(int l = 0):length(l){}
    friend Box operator+(const Box& b, int value);
    friend Box operator+(int value, const Box& b);
    void display()const{
        cout << "Length: " << length << endl;
    }
};
Box operator+(const Box& b, int value){
    return Box(b.length + value);
}
Box operator+(int value, const Box& b){
    return Box(value + b.length);
}
int main(){
Box b1(10);
Box b2 = b1 + 5;
Box b3 = 7 + b1;
b2.display();
b3.display(); 
return 0;
}
