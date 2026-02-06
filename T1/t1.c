#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main(int argc, char* argv[]){

    if (argc != 2){
        printf("%s: Must specify a \e[1msingle\e[0m file\n",argv[0]); // esto es para bold
        return 1;
    }

    FILE* fileStreamPointer;

    const char* fileName = argv[1];

    fileStreamPointer = fopen(fileName, "r+"); // read & write

    if (fileStreamPointer == NULL){
        printf("%s: Could not open file: \e[1m%s\e[0m\n",argv[0],fileName);
        return 1;
    }

    fseek(fileStreamPointer, 0L, SEEK_END);

    size_t fileSize = ftell(fileStreamPointer); // size_t es standard para bytes o algo asi

    fseek(fileStreamPointer, 0L, SEEK_SET);
    
    char* fileText = malloc(fileSize);

    fread(fileText, sizeof(char),fileSize,fileStreamPointer);

    printf("%s",fileText);

    free(fileText);

    srand(time(NULL));

    int random = rand()%3;

    char* randomString;

    switch (random)
    {
    case 0:
        randomString = "\nLa ame tanto q se fue con Dios XD\n";
        break;
    case 1:
        randomString = "\nDude, esta opcion es rara y unica, como lo fue ella ;(\n";
        break;
    case 2:
        randomString = "\nQue hace con esta opcion, y pq juan murio??\n";
        break;
    default:
        randomString = "\nBuenas, si prueba esto, diga q soy fan de Megan Fox\n";
        break;
    }

    fputs(randomString,fileStreamPointer);

    fclose(fileStreamPointer);

    return 0;
}