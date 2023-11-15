#include <stdio.h>
#include <stdlib.h>

struct Registro
{
    int id;
    char nombre[50];
    double valor;
};

void mostrarMenu()
{
    printf("\n--- Menu ---\n");
    printf("1. Ingresar un registro\n");
    printf("2. Grabar registros en un archivo\n");
    printf("3. Leer registros desde un archivo\n");
    printf("4. Salir\n");
    printf("Selecciona una opcion: ");
}

void ingresarRegistro(struct Registro *registro)
{
    printf("Ingrese el ID: ");
    scanf("%d", &registro->id);
    printf("Ingrese el Nombre: ");
    scanf("%s", registro->nombre);
    printf("Ingrese el Valor: ");
    scanf("%lf", &registro->valor);
}

void grabarRegistros(struct Registro *registros, int numRegistros, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < numRegistros; i++)
    {
        fprintf(archivo, "%d %s %.2lf\n", registros[i].id, registros[i].nombre, registros[i].valor);
    }

    fclose(archivo);
    printf("Registros guardados en %s\n", nombreArchivo);
}

void leerRegistros(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    struct Registro registro;
    printf("\n--- Registros almacenados ---\n");
    while (fscanf(archivo, "%d %s %lf", &registro.id, registro.nombre, &registro.valor) != EOF)
    {
        printf("ID: %d, Nombre: %s, Valor: %.2lf\n", registro.id, registro.nombre, registro.valor);
    }

    fclose(archivo);
}

int main()
{
    int opcion;
    int numRegistros = 0;
    struct Registro registros[100]; // Puedes ajustar el tamaño del arreglo según tus necesidades
    const char *nombreArchivo = "registros.txt";

    while (1)
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (numRegistros < 100)    // Verifica si hay espacio en el arreglo
            {
                ingresarRegistro(&registros[numRegistros]);
                numRegistros++;
            }
            else
            {
                printf("El arreglo está lleno. No se pueden agregar más registros.\n");
            }
            break;
        case 2:
            grabarRegistros(registros, numRegistros, nombreArchivo);
            break;
        case 3:
            leerRegistros(nombreArchivo);
            break;
        case 4:
            exit(0);
        default:
            printf("Opción no válida. Por favor, elige una opción válida.\n");
        }
    }

    return 0;
}
