//TASK 12 BY ALI AKHTER 24K-0809
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("file.txt");
    char check;
    int byteOffSet;
    char ch;
    do
    {
        cout << "Enter the number of bytes you want to move forward: ";
        cin >> byteOffSet;

        f.seekg(byteOffSet);

        for (int i = 0; (i < 100) && (f.get(ch)); i++)
        {
            cout << ch;
        }

        cout << endl<<"Press 'y' for another input else 'n': ";
        cin >> check;
        cin.ignore();
    } while (check != 'n');
    return 0;
}
