#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}tCoord;

int main(int argc, char *argy[]) {
    /*int *a, *b;

    a= (int *)malloc(sizeof(int));
    b= (int *)malloc(sizeof(int));

    *a = 5;
    *b = 10;

    printf("El valor de a es: %d" , *a);
    printf("'\nEL valor de b es: %d", *b);

    printf("EL valor de la suma entre a y b es: %d" , (*a + *b));

    free(a) ; a=NULL;
    free(b) ; b=NULL;*/

    /*tCoord *punto;

    punto = (tCoord *)malloc(sizeof(tCoord));

    printf("Indrese x: "); scanf("%d", &punto->x);
    printf("Indrese y: "); scanf("%d", &punto->y);

    printf("valor de x: %d, valor de y: %d", punto->x, punto->y);

    free(punto); punto=NULL;*/

    int i, n, *lis;

    printf("Ingrese el tamanio de la lista: "); scanf("%d",&n);
    lis = (int *)calloc(n, sizeof(int));

    for(i=0; i<n; i++){
            printf("Infrese el dato %d: ",i);
            scanf("%d", &lis[i]);
    }

     for(i=0; i<n; i++){
            printf("\nEL dato %d: %d", i, lis[i]);
     }

     free(lis); lis=NULL;

    return 0;
}
