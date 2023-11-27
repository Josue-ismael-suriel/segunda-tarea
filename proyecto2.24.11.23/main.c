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



    printf("Programa de memoria dinamica\n");
    printf("Cuantas unidades de memoria necesitas?");
    int cantidad = 0;
    scanf("%d",&cantidad);



    int *ptrNumero = (int *) malloc(cantidad * sizeof(int));
    st1 *ptrSt = (st1 *) malloc(cantidad * sizeof(st1));



    if(ptrNumero == NULL || ptrSt == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        return 100;
    }else{
        int i;
        char str[100];



        for(i = 0;i<cantidad;i++)
        {
            ptrNumero[i] = i;



            ptrSt[i].n1 = i;
            itoa(i,str,10);
            strcpy(ptrSt[i].numero, str);
        }



        for(i = 0;i<cantidad;i++)
        {
            printf("\n\nValor de Numero[%d]: %d",i,ptrNumero[i]);
            printf("\n\nptrSt[%d].n1 = %d",i,ptrSt[i].n1);
            printf("\nptrSt[%d].numero = %s",i,ptrSt[i].numero);
        }



    }



    free(ptrNumero);
    free(ptrSt);
    printf("\nprograma terminado");
    return 0;
}
