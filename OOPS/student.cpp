#include<iostream>
using namespace std;

class Student{
   
    
    string Name;
    
    int Age;
    bool Gender;
   
    public:
    Student(){
        cout<<"Default Constructor called with no data members"<<endl;
    }

    Student(string name,int age,bool gender){
        Name=name;
        Age=age;
        Gender=gender;
    } //parameterised Constructor

    Student(Student &a){
        Name=a.Name;
        Age=a.Age;
        Gender=a.Gender;
        cout<<"Copy Constructor"<<endl;
    }
    void setName(string s){
        Name=s;
    }
    void setAge(int a){
        Age=a;
    }
    void setGender(bool g){
       Gender=g;
    }

    void display(){
        cout<<"\n";
        cout<<"Name Entered: ";
        cout<<Name<<endl;
        cout<<"Age Entered: ";
        cout<<Age<<endl;
        cout<<"Gender Entered: ";
        cout<<Gender<<endl;
        cout<<"\n";
       
    }
};



int main(){
//     Student arr[3];
//    for(int i=0;i<3;i++){
//     string s;
//     int age;
//     bool gender;
//     cout<<"Name: ";
//     cin>>s;
//     arr[i].setName(s);
//     cout<<"Age: ";
//     cin>>age;
//     arr[i].setAge(age);
//     cout<<"Gender: ";
//     cin>>gender;
//     arr[i].setGender(gender);
//    }
//     for(int j=0;j<3;j++){
//         arr[j].display();
//         cout<<"\n";
//     }
    Student a("Arpana",21,0);
    a.display();
    Student b("Gaurav",20,1);
    b.display();
    Student c=a;
    c.display();
    Student d(b);
    d.display();
    return 0;
}