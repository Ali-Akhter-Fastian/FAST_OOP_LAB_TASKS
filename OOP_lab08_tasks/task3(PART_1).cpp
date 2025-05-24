// Yes, a friend function can be used to overload an operator that modifies the
// invoking (left-hand) object, including the += operator.There is a key point that: since
// friend functions do not have direct access to the invoking object through "this", the 
// left-hand operand must be passed by reference to allow modification.

//TASK 03(PART_01) BY ALI AKHTER 24K-0809



#include <iostream>
using namespace std;
class Counter {
private:
    int value;
public:
    Counter(int v = 0):value(v){}
    friend Counter& operator+=(Counter& lhs, const Counter& rhs);
    void display() const {
        cout << "Value: " << value << endl;
    }
};
Counter& operator+=(Counter& lhs, const Counter& rhs){
    lhs.value += rhs.value;
    return lhs;
}
int main(){
 Counter a(5), b(10);
a += b;
a.display();
return 0;
}
