#include <iostream>
#include <vector>

#define null nullptr
using namespace std;

class Person {
public:
    string name;
    string surname;
    string adress;
    string PESEL;

    Person(string name, string surname, string adress, string PESEL)
    {
        this->name = name;
        this->surname = surname;
        this->adress = adress;
        this->PESEL = PESEL;
    }

};

class People {
private:
    vector<Person> data;
public:

    void AddPerson(Person *p)
    {
        if(p==null)return;
        this->data.push_back(*p);
    }

    void DeletePerson(string PESEL)
    {
        for(int i=0;i<data.size();i++)
        {
            if(data[i].PESEL==PESEL)
            {
                data.erase(data.begin()+i);
            }
        }
    }

    void Show() {
        for (const Person& i : data)
        {
            cout<<i.name<<" "<<i.surname<<" "<<i.adress<<" "<<i.PESEL<<endl;
        }
    }
};


int main() {
    People people;
    Person person1("Adam","Kowalski","Janusha 21","98122807875");
    Person person2("Patryk","Ledzion","Przemyslawa 3","98112807875");
    Person person3("Jan","Grzeszy","Rafala 7","97122307875");
    people.AddPerson(&person1);
    people.AddPerson(&person2);
    people.AddPerson(&person3);
    people.Show();
    cout<<endl;
    people.DeletePerson("98112807875");
    people.Show();
    return 0;
}
