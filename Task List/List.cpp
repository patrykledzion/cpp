//
// Created by patry on 17.05.2022.
//

#include <vector>
#include <fstream>
#include <string>
#include "List.h"

#define FILENAME "tasklist.txt"

using std::vector;

int List::AddElement(Element *element) {

    if(element->id<1)return -1;
    this->elements.push_back(*element);
    this->size++;
    return size;
}

int List::RemoveElement(int id) {

    this->Clear();
    this->Load(FILENAME);
    int wi = 0;
    while(this->elements[wi++].id!=id)if(wi>=this->size)return -1;
    this->elements.erase(this->elements.begin()+wi-1);
    this->size--;
    this->Save(FILENAME,true);
    this->Clear();
    return wi;
}

void List::Show() {
    cout<<"\n\n------TASKS-------\n";
    if(this->size==0)cout<<"List is empty\n";
    for(const Element& e : this->elements)
    {
        if(e.id<1)
        {
            continue;
        }
        cout<<e.id<<". ";
        e.ShowDate();
        cout<<", "<<e.name<<" in:"<<e.place<<endl;
    }

    cout<<"------------------\n\n";

    cout<<endl;
}

int List::Save(const string& filename, bool del) {

    if(!del)
    {
        auto *temp = new Element(this->elements[0].id, this->elements[0].name,
                            this->elements[0].place, this->elements[0].date);
        this->Clear();
        this->Load(filename);
        this->AddElement(temp);
    }

    for(const Element& e : this->elements)
    {
        if(e.id<1)break;
        if(e.name.empty() || e.place.empty())return 1;
    }

    fstream f;
    f.open(filename, ios::out);
    if(f.is_open())
    {
        for(const Element& e : this->elements)
        {
            if(e.id<1)continue;
            f<<e.id<<"\n";
            f<<e.date.day<<"."<<e.date.month<<"."<<e.date.year<<"\n";
            f<<e.name<<"\n";
            f<<e.place<<"\n";
        }
    }
    f.close();

    return 0;
}

int List::Load(const string& filename)
{

    fstream f;
    f.open(filename, ios::in);
    if(f.is_open())
    {
        while(!f.eof())
        {
            string id;
            string date;
            int d,m,y;
            string name;
            string place;

            getline(f,id);
            if(!List::IsNumber(id))
            {
                this->Clear();
                return 3;
            }
            getline(f,date);
            if(!List::GetDateFromString(date,&d, &m, &y))
            {
                this->Clear();
                return 3;
            }
            getline(f,name);
            getline(f,place);
            auto *e = new Element(atoi(id.c_str()),name,place,Date{d,m,y});
            this->AddElement(e);
        }
    }
    f.close();

    return 0;
}

void List::Clear() {

    if(this->size<1)return;

    this->elements.erase(
    this->elements.begin(),this->elements.begin()+this->size);
    this->size = 0;
}

bool List::IsNumber(const string& number)
{
    for(const char& d : number)
    {
        if(!isdigit(d))return false;
    }

    return true;
}

bool List::GetDateFromString(const string &date, int *d, int *m, int *y) {

    string s[3] = {"","",""};

    int it = 0;
    for(const char& c : date)
    {
        if(isdigit(c))
        {
            s[it]+=c;
        }else if(c=='.'){
            it++;
        }else{
            return false;
        }
    }

    *d = atoi(s[0].c_str());
    *m = atoi(s[1].c_str());
    *y = atoi(s[2].c_str());
    return true;
}