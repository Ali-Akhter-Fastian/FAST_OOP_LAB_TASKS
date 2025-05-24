#include<iostream>
#include<fstream>
using namespace std;
class Card_Company{
private:
string username;
string message;
public:
Card_Company(){
cout<<"Enter your name: ";
getline(cin,username);
cout<<"Enter a short message: ";
getline(cin,message);
};
void WriteMessageToFile(){
      ofstream f;
      f.open("greetings.txt",ios::app);
      if(!f.is_open()){
        cout<<"Can't open!!!";
        return ;
      }
      f<<"Dear "<<username<<",\n"<<message<<"\n"<<"Best Regards,\n";
}
  

};
int main(){
Card_Company c;
c.WriteMessageToFile();
}