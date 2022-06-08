#include <iostream>

using namespace std;


long long int fact(int num)
{
    if(num==1)return 1;
    return num * fact(num-1);

}

int main()
{
    printf("%lld",fact(20));
}
