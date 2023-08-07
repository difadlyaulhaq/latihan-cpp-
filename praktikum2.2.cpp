#include <iostream>
using namespace std;
void parray(int array[],int jarray);
int getnbesar (int array[],int jarray);
 int main(){
 	cout<<"nama:difa dlyaul haq\n";
 	cout<<"nim : 22.61.0234"<<endl;
	const int size = 3;
	int nilaarr [size];
	
	for ( int i = 0; i < size; i++)
	{
	cout<<"nilai ke #"<<i+1<< " : ";
	 cin >> nilaarr[i] ;
	}
	
	for (int i = 0; i < size; i++)
	{
		int jarray = sizeof(nilaarr[i]) /sizeof (int);
		int nbesar = getnbesar (nilaarr,jarray);
		cout<<"nilai terbesar dari daftar array berikut adalah"<<endl;
		parray (nilaarr,jarray);
		cout<<"adalah : "<<nbesar<<endl;
		return 0;
	}
	
	
}



void parray(int array[],int jarray)
{
	for (int i=0;i < jarray;i++){
	cout << array[i] <<" ";
}
cout<<endl;
}
int getnbesar (int array[],int jarray)
{
	int nbesar = 0;
	for (int i = 0; i<jarray;i++)
	{
		if (nbesar < array[i])
		    nbesar = array[i];
	}
	return nbesar;
}
class program
{
	static void Main
	program(/* args */);
	~program();
};

program::program(/* args */)
{
}

program::~program()
{
}
()
void Enque 
