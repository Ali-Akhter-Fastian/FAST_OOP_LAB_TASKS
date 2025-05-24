// TASK # 02 by Ali Akhter 24k-0809
#include <iostream> 
using namespace std; 
class User 
{ 
     int ID; 
     string name; 
     string password; 
     string role; 
     void PasswordValidation() 
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
               << "Your password got accepted!"; 
     } 
 
public: 
     User() {} 
     User(int id, string name, string password) 
     { 
          this->ID = id; 
          this->name = name; 
          this->password = password; 
          PasswordValidation(); 
     } 
     User(int id, string name, string password, string role) 
     { 
          this->ID = id; 
          this->name = name; 
          this->password = password; 
          this->role = role; 
          PasswordValidation(); 
     } 
     int get_id() { return ID; } 
     string get_name() { return name; } 
     void set_role(string role) { this->role = role; } 
}; 
class Admin 
{ 
     int ID; 
     string name; 
     string password; 
 
public: 
     Admin(int id, string name, string password) 
     { 
          this->ID = id; 
          this->name = name; 
          this->password = password; 
     } 
     int get_id() { return ID; } 
     string get_name() { return name; } 
     void AddUser(User *&users, int &count_of_users) 
     { 
          cout << endl 
               << "Enter details for user : "; 
          int id; 
          cout << endl 
               << "ID : "; 
          cin >> id; 
          string name; 
          cout << endl 
               << "Name : "; 
          cin >> name; 
          string role; 
          cout << endl 
               << "Role : "; 
          cin >> role; 
          if (role == "admin") 
          { 
               cout << endl 
                    << "Admin cannot add another admin!"; 
               return; 
          } 
          string pass; 
          cout << endl 
               << "Enter password : "; 
          cin >> pass; 
          User u(id, name, password, role); 
          User *temp = new User[count_of_users + 1]; 
          for (int i = 0; i < count_of_users; i++) 
               temp[i] = users[i]; 
          temp[count_of_users] = u; 
          User *temp1 = users; 
          users = temp; 
          delete[] temp1; 
          count_of_users++; 
          cout << endl 
               << "User succesfully added"; 
     } 
     void RemoveUser(int idd, User *&users, int &count_of_users) 
     { 
          for (int i = 0; i < count_of_users; i++) 
          { 
               if (users[i].get_id() == idd) 
               { 
                    User *temp = new User[count_of_users - 1]; 
                    for (int j = 0; j < count_of_users; j++) 
                    { 
                         if (j < i) 
                              temp[j] = users[j]; 
                         if (j > i) 
                              temp[j - 1] = users[j]; 
                    } 
                    delete[] users; 
                    users = temp; 
                    count_of_users--; 
                    cout << endl 
                         << "User successfully removed!"; 
                    return; 
               } 
          } 
          cout << endl 
               << "User not found!"; 
     } 
     void SearchUser(int id, User *&users, int &count_of_users) 
     { 
          for (int i = 0; i < count_of_users; i++) 
          { 
               if (users[i].get_id() == id) 
               { 
                    cout << endl 
                         << "User found"; 
                    return; 
               } 
          } 
          cout << endl 
               << "User not found!"; 
     } 
     void DisplayUser(User *&users, int &count_of_users) 
     { 
          for (int i = 0; i < count_of_users; i++) 
          { 
               cout << endl 
                    << "Details for user " << i + 1 << " : "; 
               cout << endl 
                    << "ID : " << users[i].get_id(); 
               cout << endl 
                    << "Name : " << users[i].get_name(); 
          } 
     } 
     void AssignRole(int id, User *&users, int &count_of_users) 
     { 
          for (int i = 0; i < count_of_users; i++) 
          { 
               if (users[i].get_id() == id) 
               { 
                    cout << endl 
                         << "Enter new role : "; 
                    string role; 
                    cin >> role; 
                    users[i].set_role(role); 
                    cout << endl 
                         << "Role successfully assigned!"; 
                    return; 
               } 
          } 
          cout << endl 
               << "User with this id was not found!"; 
     } 
}; 
int main() 
{ 
     int UserCount=0; 
     cout << endl 
          << "Enter no. of initial users : "; 
     cin >> UserCount; 
     User *users = new User[UserCount]; 
     for (int i = 0; i < UserCount; i++) 
     { 
          cout << endl 
               << "Enter details for user " << i + 1 << " : "; 
          cout << endl 
               << "Id : "; 
          int id; 
          cin >> id; 
          cout << endl 
               << "Name : "; 
          string name; 
          cin >> name; 
          string pass; 
          cout << endl 
               << "Password : "; 
          cin >> pass; 
          cout << endl 
               << "Does this user have a role(y/n) : "; 
          string role; 
          cin >> role; 
          if (role == "n") 
          { 
               users[i] = User(id, name, pass); 
               continue; 
          } 
          cout << endl 
               << "Role : "; 
          cin >> role; 
          users[i] = User(id, name, pass, role); 
     } 
     cout << endl 
          << "Enter details for admin : "; 
     int id; 
     string name, pass; 
     cout << endl 
          << "Id : "; 
     cin >> id; 
     cout << endl 
          << "Name : "; 
     cin >> name; 
     cout << endl 
          << "Password : "; 
     cin >> pass; 
     Admin a(id, name, pass); 
     a.DisplayUser(users, UserCount); 
     a.AddUser(users, UserCount); 
     a.DisplayUser(users, UserCount); 
     cout << endl 
          << "Enter id of user to be removed : "; 
     cin >> id; 
     a.RemoveUser(id, users, UserCount); 
     a.DisplayUser(users, UserCount); 
     cout << endl 
          << "Enter id of user to be searched : "; 
     cin >> id; 
     a.SearchUser(id, users, UserCount); 
     cout << endl 
          << "Enter id of user you want to assign or change its role : "; 
     cin >> id; 
     a.AssignRole(id, users, UserCount); 
     return 0; 
} 