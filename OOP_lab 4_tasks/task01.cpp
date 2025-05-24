#include <iostream>
using namespace std;
class user
{
private:
  int id;
  string name;
  string password;
  string role;
  void password_validation()
  {
    bool check = true;
    while (1)
    {
      if (password.size() < 8)
      {
        cout << endl
             << "Password too short!" << endl
             << "Enter again : ";
        cin >> password;
        continue;
      }
      for (int i = 0; password[i] != 0; i++)
      {
        if ((password[i] >= 'A' && password[i] <= 'Z') ||
            (password[i] >= 'a' && password[i] <= 'z'))
          continue;
        else
        {
          check = false;
          break;
        }
      }
      if (check)
        break;
      check = true;
      cout << endl
           << "Password must not contain special character!";
      cout << endl
           << "Enter again : ";
      cin >> password;
    }
    cout << endl
         << "Your password is accepted!";
  }

public:
  user() {};
  user(int id, string name, string password, string role)
  {
    this->id = id;
    this->name = name;
    this->password = password;
    this->role = role;
    password_validation();
  }
  user(int id, string name, string password)
  {
    this->id = id;
    this->name = name;
    this->password = password;
    this->role = "Guest";
    password_validation();
  }
  int getID() { return id; }
  string getName() { return name; }
  string getPassword() { return password; }
  string getRole() { return role; }
};
class Admin
{
private:
  user **records;
  int UserCount;

public:
  Admin()
  {
    UserCount = 0;
  }
  void addUsers()
  {
    int id;
    string name;
    string password;
    int choice;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> password;
    cout << "Role: " << endl
         << "1.User" << endl
         << "2.Guest" << endl
         << "Press Choice: ";
    cin >> choice;
    user **temp = new user *[UserCount];
    for (int i = 0; i < UserCount; i++)
    {
      temp[i] = records[i];
    }
    if (choice == 1)
      temp[UserCount] = new user(id, name, password, "User");
    else
      temp[UserCount] = new user(id, name, password, "Guest");
    delete[] records;
    records = temp;
    UserCount++;
  };
  void removeUser()
  {
    int remID;
    int Indexrem = -1;
    cout << "Enter the ID of user to remove: ";
    cin >> remID;
    for (int i = 0; i < UserCount; i++)
    {
      if (records[i]->getID() == remID)
      {
        Indexrem = i;
        break;
      }
    }
    if (Indexrem == -1)
      cout << "User not found in records!!" << endl;
    else
    {
      delete records[Indexrem];
      cout << "User removed successfully!!" << endl;
    }
    for (int i = Indexrem; i < UserCount - 1; i++)
    {
      records[i] = records[i + 1];
    }
    user **temp = new user *[UserCount - 1];
    for (int i = 0; i < UserCount - 1; i++)
    {
      temp[i] = records[i];
    }
    delete[] records;
    records = temp;
    UserCount--;
  }
  void display()
  {
    for (int i = 0; i < UserCount; i++)
    {
      cout << "ID: " << records[i]->getID() << endl;
      cout << "Name: " << records[i]->getName() << endl;
      cout << "Password: " << records[i]->getPassword() << endl;
      cout << "Role: " << records[i]->getRole() << endl;
    }
  }
  void search()
  {
    int searchID, flag = 0;
    cout << "Enter ID of user you want to search: ";
    cin >> searchID;
    for (int i = 0; i < UserCount; i++)
    {
      if (records[i]->getID() == searchID)
      {
        cout << "User found successfully,you can preview the details!!" << endl;
        cout << "ID: " << records[i]->getID() << endl;
        cout << "Name: " << records[i]->getName() << endl;
        cout << "Password: " << records[i]->getPassword() << endl;
        cout << "Role: " << records[i]->getRole() << endl;
        flag++;
        break;
      }
    }
    if (flag == 0)
      cout << "User not found!!" << endl;
  }
};
int main()
{
  Admin a;
  a.addUsers();
  a.addUsers();
  a.display();
  a.removeUser();
  a.display();
  a.search();
}
