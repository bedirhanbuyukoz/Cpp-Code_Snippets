#include<iostream>
	using namespace std;
/* Arama Algoritmasý */

int linearSearch(int dizi[],int n, int aranan)
{
 int i;
 for ( i=0; i<n; i++)
 {
 	if(aranan==dizi[i])
 	return i;
 }
 
 return -1;
}
int main()
{
	int n;
	cout<<"Dizi boyunu giriniz: " ; cin>>n;
	int dizi[n];
	int i=0;
	while(i<n)
	{
	  cout<<"sayi : "; cin>>dizi[i];
	  i++;
		
	}
	int aranan;
	cout<<"aranan sayiyi giriniz: "; cin>>aranan;
	int sonuc = linearSearch(dizi,n,aranan);
	if(sonuc==-1)
	cout<<"aranan sayi dizide yok"<<endl;
	else
	cout<<"aranan sayi budur "<<sonuc+1<<" "<<endl;
	
	
	
}
