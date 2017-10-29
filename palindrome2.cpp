//David Sanchez Rodriguez
//lic.Matematicas aplicadas y computacion
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;
int longituddelnumero(int n){
int cont=0;
 while(n!=0)
 {
  n/=10;
  cont++;
 }
 return cont;
}

int main(){
 ifstream archivo;
 ofstream archivo1;
 int band=0,band1=0;
 char c;
 int num[100],i,cont;
 int nume[100];
 int prueba=0;
 int B,C,w;
  archivo.open("pinput.txt");
  i=0;
  while(archivo.good()){
   archivo >> num[i];
   i++;
  }
  archivo1.close();

  cont=i;
  for(i=0;i<cont;i++)cout<<num[i]<<endl;

    for(i=0;i<cont;i++)
    {
      band=0;
      if(longituddelnumero(num[i])>2)
      {
        num[i]=((num[i])/(11))*11;
        for(int n=9;n<100;n++)
        {
            if((num[i])%(11*n)==0 && band==0){
                B=11*n;band=1;
            }
            else if((num[i]%(11*n)!=0 && band!=1)){

               B=num[i];
               B-=(1100)*(n-9);
               if((B)%(11*n)==0 && band1==0){
                 C=11*n;band1=1;
                 num[i]=B;
             }
            }
           }
          }
         }
    archivo1.open("Output.txt");
    archivo1<<"Sample Output" << endl;
    cout<<"Sample Output" << endl;
    for(i=0;i<cont;i++)
    {
      archivo1<<num[i]<< endl;
      cout<<num[i]<<endl;
    }
  archivo1.close();
  return 0;
}
