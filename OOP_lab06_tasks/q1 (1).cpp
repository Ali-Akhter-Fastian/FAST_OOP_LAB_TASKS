//Task # 01 by Ali Akhter 24k-0809
#include<iostream>
using namespace std;
class Message{
    private:
        string text;

        public:

        string tostring()const{return text;};
        void SetText(string text){
            this->text=text;
        }
};
class SMS:public Message{
    private:
    string recipientContactNo;

    public:
    SMS(){};
    SMS(string contact,string text){
        this->recipientContactNo=contact;
        this->SetText(text);
    }
    string getContactNumber(){return recipientContactNo;};
    void setContactNumber(string number){
        this->recipientContactNo=number;
    }
    virtual string tostring()const{
        return Message::tostring()+recipientContactNo;
    }
};
class Email:public Message{
    private:
    string sender;
    string receiver;
    string subject;


    public:
    Email(){};
    Email(string sender,string receiver, string subject,string text){
        this->sender=sender;
        this->receiver=receiver;
        this->subject=subject;
        this->SetText(text);
    }
    void setSender(const string& sender) {
        this->sender = sender;
    }

    // Getter for sender
    string getSender() const {
        return sender;
    }

    // Setter for receiver
    void setReceiver(const string& receiver) {
        this->receiver = receiver;
    }

    // Getter for receiver
    string getReceiver() const {
        return receiver;
    }

    // Setter for subject
    void setSubject(const string& subject) {
        this->subject = subject;
    }

    // Getter for subject
    string getSubject() const {
        return subject;
    }

    virtual string tostring()const{
        return sender+receiver+subject+Message::tostring();
    }
    bool ContainsKeyword(const Message& messageObject, const string& keyword){
        string message=messageObject.tostring();
        int keywordlength=keyword.length();
        int lenght=message.length();
        int count=0;
        for(int i=0;i<lenght;i++){
            for(int j=0;j<keywordlength;j++){
                if(message[i+j]==keyword[j]) count++;
                else break;
            }
            if(count==keywordlength) return true;
            count=0;
        }
        return false;
    }
    void MessageEncoding(Message& messageObject){
        string message=messageObject.tostring();
        int lenght=message.length();    
        for(int i=0;i<lenght;i++){
            if((message[i]>='A' && message[i]<='Z')  || (message[i]>='a' && message[i]<='z')){
                if(message[i]!='Z' && message[i]!='z')
                message[i]++;
                else message[i]-=26;
            }
            else continue;
        }
        messageObject.SetText(message);
    }
};
int main(){
    SMS s("4203940394023","Hello");
    Email e("Umer","Ali","Burney","Programmer");
    cout<<e.tostring()<<endl;
    cout<<s.tostring()<<endl;
    if(e.ContainsKeyword(s,"llo"))  cout<<"KeyWord Present"<<endl;
    else cout<<"KeyWord Not Present"<<endl;
    e.MessageEncoding(e);
    cout<<"Encoded Message: "<<e.Message::tostring()<<endl;
    return 0;
}