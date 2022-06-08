#include <iostream>

float fabs(float num)
{
	if(num<0)return -num;
	return num;
}


class zespolona{
	public: float r;
	public: float i;

	zespolona(int r,int i)
	{
		this->r = r;
		this->i = i;
	}

	public: void show()
	{
		char s;
		s='+';
		if(this->i<0)
		{
			s='-';
		}
		printf(" %f%c%fi\n",this->r,s,fabs(this->i));
	}

	public: void suma(zespolona z1,zespolona z2)
	{
		//return zespolona(z1->r+z2->r,z1->i+z2->i);
		this->r = z1.r+z2.r;
		this->i = z1.i+z2.i;
	}

	public: void roznica(zespolona z1, zespolona z2)
	{
		this->r = z1.r-z2.r;
		this->i = z1.i-z2.i;
	}

	public: void iloczyn(zespolona z1,zespolona z2)
	{
		this->r = z1.r*z2.r - z1.i*z2.i;
		this->i = z1.r*z2.i + z1.i*z2.r;
	}

	public: void iloraz(zespolona z1,zespolona z2)
	{
		zespolona licznik = iloczyn(z1,z2);
		zespolona mianownik = z2.r*z2.r - z2.i*z2.i;
		
	}





};

int main()
{
	zespolona z(5,2);
	zespolona z2(3,-7);
	z.show();
	z2.show();
	printf("Dodawanie: \n");
	zespolona w(0,0);
	w.suma(z,z2);
	w.show();
	printf("Odejmowanie: \n");
	w.roznica(z,z2);
	w.show();
	printf("Iloczyn: \n");
	w.iloczyn(z,z2);
	w.show();

	return 0;

}
