#include <iostream>
#include <vector>
#include <string>
#include "Element.h"
#include "List.h"

#define FILENAME "tasklist.txt"

using std::vector;

int main() {

    bool running = true;

    List *l = new List;
    while(running)
    {
        cout<<"1. Add task to list\n";
        cout<<"2. Remove task from list\n";
        cout<<"3. Load tasks from file\n";
        cout<<"4. End app\n";

        int option;
        cin>>option;

        switch(option)
        {
            case 1: {
                int d=0,m=0,y=0;
                string name;
                string place;
                cout<<"Input date of task (d/m/y): ";
                if(scanf("%d/%d/%d",&d,&m,&y) < 3)return 1;

                Date date = {d,m,y};

                cout<<"What is the task: ";
                getline(cin, name);
                getline(cin, name);

                cout<<"Where do you want to do it: ";
                getline(cin, place);
                int id = 1;
                l->Load(FILENAME);
                if(l->size>0)id = l->elements[l->size-1].id+1;
                l->Clear();
                auto *el = new Element(id,name,place,date);
                l->AddElement(el);
                l->Save(FILENAME);
                l->Clear();
                delete el;
                break;
            }

            case 2:{
                int id;
                cout<<"What task do you want to remove (id): ";
                cin>>id;
                int res = l->RemoveElement(id);
                if(res==-1)cout<<"Couldn't remove element\n";
                else cout<<"Element removed succesfully\n";
                break;
            }

            case 3: {
                l->Clear();
                l->Load(FILENAME);
                l->Show();
                break;
            }

            case 4: {
                running = false;
                break;
            }

            default: {
                cout << "Wrong choice.\n";
            }
        }
    }

    return 0;

}
