#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   typedef struct st

   {
       int n1;
       char numero[1000000];
   }st1;
   printf("programa de memoria dinamica\n");
   printf("cuantas unidades de memoria necesitas?");
   int cantidad = 0;
   scanf("%d",&cantidad);

   int*ptrNumero=(int*)malloc(cantidad * sizeof(int));

   if(ptrNumero==NULL)
   {
     printf("\No hay memoria disponible\n");
     return 100;
   }else{
       int i;

       for(i=0;i<cantidad;i++)
       {
           ptrNumero[i]=i;
       }


       for(i=0;i<cantidad;i++)
       {
           printf("\nValor de Numero[%d]:%d",i,ptrNumero[i]);
       }

    }

    free(ptrNumero);
    printf("\nprograma terminado");
    return 0;
}
