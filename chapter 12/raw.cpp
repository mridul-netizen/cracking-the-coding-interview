#include <iostream>
using namespace std;

#define NAME_SIZE 50

class Person{
    int id;
    char name[NAME_SIZE];

    public:
    virtual void aboutMe()
    {
        cout<<"I am a Person"<<endl;

    }
    virtual bool addCourse(string s) = 0;

    virtual ~Person()
    {
        cout<<"deleting a person"<<endl;
    }
};

class Student : public Person{
    public:
    void aboutMe()
    {
        cout<<"I am a Student"<<endl;
    }
    
    bool addCourse(string s){
        cout<<"Added Course "<<s<<" to student "<<endl;
        return true;
    }
    ~Student()
    {
        cout<<"deleting a student"<<endl;
    }
};

int main()
{
    Person *p = new Student();
    p -> aboutMe();
    p -> addCourse("History");
    delete p;
    return 0;
}