//[Task#1 by Keertan 24k-0716]
#include <iostream>
#include <cstring>
using namespace std;



class User
{
public:
    int id;
    string name;
    string password;
    string role;

public:
    // defualt

    User()
    {
    }

    // construcot 1 -> fully paramitrized
    User(int id, string name, string password, string role)
    {

        this->id = id;
        this->name = name;
        this->password = password;
        this->role = role;
    }

    // constructor 2-> partially paramitrized

    User(int id, string name, string password)
    {

        this->id = id;
        this->name = name;
        this->password = password;
        role = "None";
    }

    // copy_constructor

    User(User &ob)
    {
        id = ob.id;
        name = ob.name;
        password = ob.password;
        role = ob.role;
    }
};

class Admin
{
int no_of_users;
    User *users;

public:

Admin() : users(nullptr), no_of_users(0) {}

    void add_user(int id, string name, string password, string role)
    {
        no_of_users++;

        User *new_users = new User[no_of_users];
        for (int i = 0; i < no_of_users - 1; i++)
        {
            new_users[i] = users[i];
        }
        new_users[no_of_users - 1] = User(id, name, password, role);
        delete[] users;

        users = new_users;
    }
   

    void remove_user(int id)
    {
    if(no_of_users==0){
    cout<<"no users to remvoe";
   
}
else{
 no_of_users--;

        User *new_users = new User[no_of_users];
        for (int i = 0; i < no_of_users; i++)
        {
            if (new_users[i].id != id)
                new_users[i] = users[i];
        }

        delete[] users;

        users = new_users;
}
     
    }

    User &search_user(int id)
    {
        for (int i = 0; i < no_of_users; i++)
        {
            if (users[i].id == id)
            {
                return users[i];
            }
        }
    }

    void display_user(int id)
    {
   
    if(no_of_users==0) cout<<"No users"<<endl;
    else
    {
    for (int i = 0; i < no_of_users; i++)
        {
            if (users[i].id == id)
            {
                cout << "Name: " << users[i].name << endl;
                cout << "Id: " << users[i].id << endl;
                cout << "Role: " << users[i].role << endl;
            }
        }
}
       
    }
};

int main()
{

    Admin a1;
    a1.add_user(22,"Keertan","hello","emp");
    cout <<(a1.search_user(22)).name;
   
}