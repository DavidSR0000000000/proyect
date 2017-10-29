//DAVID SANCHEZ RODRIGUEZ
//LIC. MATEMATICAS APLICADAS Y COMPUTACION
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

void numeros(  char str[], int &a , int &b ){
   char str1[80];
    char cpy1[4] ;
    char cpy2[4] ;
    int coun=0;
    const char s1[2] = " ";
    char *token=NULL;


   strcpy(str1,str);
   token = strtok(str, s1);

   while( token != NULL )
   {
      if(coun==0)
      {
      strcpy(cpy1,token);
      token = strtok(NULL, s1);
      }
      if(coun==1)
      {
      strcpy(cpy2,token);
      token = strtok(NULL, s1);
      }
      coun++;
   }
       a=atoi(cpy1);
       b=atoi(cpy2);
}

int main()
{
	FILE *archivo;
	char caracter;
    int K,N,a,b;
    char romper[]="\n";
    int i=0;
    int j=0;
    int band=0;
    char *str,mensaje[200];
    char cadena[20][15];
    int nmros,nmrs,nmrom,cn;
    archivo = fopen("prueba.txt","r");
    ofstream archivo1;  // objeto de la clase ofstream

    int numdecade=0;
        if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            printf("\nSample Input:  \n\n");
            i=0;
            while (feof(archivo) == 0)
	        {
                caracter = fgetc(archivo);
                mensaje[i]=caracter;
                printf("%c",mensaje[i]);
                i++;
	        }
        }
        fclose(archivo);


        //printf("\n");
        str=strtok( mensaje, romper );

        while( str!= NULL )
        {
           //printf("Tokenized string using * is:: %s\n", str );
           strcpy(cadena[j],str);
           str = strtok(NULL,romper);
           j++;
        }

        numdecade=j;
        archivo1.open("Output");
        archivo1<<"Sample Output" << endl;
        cout<<"Sample Output"<<endl;
        //printf("\nnumero de lineas:%i\n",numdecade-1);
        for(i=0;i<numdecade-1;i++)
        {      nmrom=-1;
               band=0;
               for(j=0;j<15;j++)if(cadena[i][j]==' ')band=1;
               if(band==1)
               {
                 numeros(cadena[i], a, b);
                 if(a<b){
                 K=a;//printf("\nK=%i",K);
                 N=b;//printf("N=%i\n",N);
                 }
                 if(b<a){
                 K=b;//printf("\nK=%i",K);
                 N=a;//printf("N=%i\n",N);
                 }
                 if(K<=N && K>=1 && K<=7){
                          for(int z=0;z<strlen(cadena[i+1])-(K-1);z++)
                          {
                           fflush(stdin);
                           nmrs=1;nmros=0,cn=0;
                           for(j=0;j<K;j++)
                            {
                              nmros=cadena[i+1][j+z]-48;
                              //printf("no: %i ",nmros);
                              if(nmros>0)
                              {
                               cn++;
                              }
                              nmrs=nmrs*nmros;
                            }
                             if(nmrom<nmrs)nmrom=nmrs;
                           }
                           str=NULL;
                           archivo1 <<nmrom << endl;
                           cout<<nmrom<<endl;
                          }

               }
               a=0;b=0;
        }
       	archivo1.close();
        getchar();
        getchar();
	return 0;
}
