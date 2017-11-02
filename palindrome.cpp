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

int palindromo(int numero)
{
  char* cadena;
  int n,cont=0;
  n=longituddelnumero(numero);
  cadena=new char[n];
  itoa(numero,cadena,10);
  for(int i=0;i<=n/2;i++)
  {
   if(cadena[n/2-(i+1)]==cadena[n/2+i])
   {
    cont++;
   }
  }
  delete[] cadena;
  if(n/2==cont)return 1;
  else return 0;
}

int main()
{
 ifstream archivo;
 ofstream archivo1;
 int band=0,band1=0;
 char c;
 static int num[100];
 int i,cont,n,plndrm;
 int nume[100];
 int B,C,X,Y,TEMP,mayor;
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
      plndrm=0;
      band=0;Y=0,band1=0;
      if(longituddelnumero(num[i])>2)
      {
        B=(num[i])/(11);
        num[i]=B*11;
        C=B/11;
        X=num[i]/C;

          if(longituddelnumero(X)==3 && longituddelnumero(C)==3 && palindromo(num[i])==1)
          {
            band=0;
          }
          else if((longituddelnumero(X)!=3 || longituddelnumero(C)!=3) && band!=1)
          {  mayor=0;
             for(int m=100;m>0;m--)
             {
                X=0;C=0;B=0;
                Y=num[i];
                for(n=1;n<10;n++)
                {
                  TEMP=Y;
                  Y-=11*n*m;
                  if(palindromo(Y)==1){
                     //cout<<"Y:"<<Y;
                     for(int w=1;w<=999;w++){
                      if(Y%w==0)C=w;
                     }
                     //cout<<"C: "<<C;
                      if(mayor<C)
                      {
                        mayor=C;
                        X=Y/C;
                        plndrm=X*C;
                      }
                  }
                  Y=TEMP;
                }
             }
           num[i]=plndrm;
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
