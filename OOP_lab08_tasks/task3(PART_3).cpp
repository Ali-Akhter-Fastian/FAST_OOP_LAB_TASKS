// No,a friend function cannot access private or protected members of a class without an object.
// Even though a friend function has access to private and protected members of a class, it still
// needs an object to access instance-specific data, because these members are tied to specific
// objects.

//TASK 03(PART_03) BY ALI AKHTER 24K-0809


#include <iostream>
using namespace std;
class MyClass {
private:
    int secret;
public:
    MyClass(int s) : secret(s) {}
    friend void revealSecret(const MyClass& obj);
};
// Friend function definition
void revealSecret(const MyClass& obj) {
    cout << "Secret is: " << obj.secret << endl;  // Valid: accessing via object
}

// void invalidAccess() {
//     cout << secret;     Error: No object, can't access non-static private member
// }
//THE ABOVE FUNCTION WILL CREATE ERROR BECAUSE IN THIS FUNCTION I AM ACCESSING THE FRIEND'S
//CLASS MEMBER WITHOUT ANY INSTANCE


int main() {
    MyClass a(42);
    revealSecret(a);
    return 0;
}
