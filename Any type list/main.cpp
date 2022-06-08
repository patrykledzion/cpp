#include <iostream>
#include <cmath>

using namespace std;



template<typename type>
class List {
private:
    bool first;
    int capacity = 1;
    type *d = new type[1];
public:
    List():first(false){}

    int push_back(type elem)
    {
        if(!first)first = true;
        else capacity++;
        type *new_list = new type[this->capacity];

        for(int i=0;i<this->capacity-1;i++)
        {
            new_list[i] = this->d[i];
        }

        new_list[capacity-1] = elem;
        delete[] this->d;
        this->d = new_list;

        return capacity;
    }

    void show()
    {
        cout<<"Lista<"<<typeid(this->d).name()<<">("<<capacity<<"): {\n ";
        for(int i=0;i<capacity;i++)
        {
            cout<<this->d[i]<<"  ";
        }
        cout<<"\n}\n";
    }

    void sort()
    {
        for(int i=0;i<this->capacity;i++)
        {
            for(int j=i;j<this->capacity;j++)
            {
                if(this->d[i]>this->d[j])
                {
                    type temp = this->d[i];
                    this->d[i] = this->d[j];
                    this->d[j] = temp;
                }
            }
        }

    }

    int find(type element)
    {
        for(int i=0;i<capacity;i++)
        {
            if(this->d[i]==element)return i;
        }
        return -1;
    }

    type min()
    {
        type min_ = this->d[0];
        for(int i=0;i<capacity;i++)
        {
            if(this->d[i]<min_)min_ = this->d[i];
        }

        return min_;
    }

    type max()
    {
        type max_ = this->d[0];
        for(int i=0;i<capacity;i++)
        {
            if(this->d[i]>max_)max_ = this->d[i];
        }

        return max_;
    }

};

int main() {
    List<int> l = List<int>();
    l.push_back(7);
    l.push_back(12);
    l.push_back(6);
    l.push_back(2);
    l.show();
    l.sort();
    l.show();
    cout<<l.find(14)<<endl;
    cout<<l.min()<<endl;
    cout<<l.max()<<endl<<endl;

    List<float> l_f = List<float>();

    l_f.push_back(2.1);
    l_f.push_back(9.1);
    l_f.push_back(6);
    l_f.push_back(3.7);
    l_f.show();
    l_f.sort();
    l_f.show();
    cout<<l_f.find(3.7)<<endl;
    cout<<l_f.min()<<endl;
    cout<<l_f.max();

}