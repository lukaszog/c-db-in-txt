#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fptr; //uchwyt do pliku

struct notification {
    char name[50];
    char lastname[50];
    char price[10];
    char descreption[100];
}notification;

void insertRecord()
{
    fptr=fopen("G:\\file.txt","a+");

    fflush(stdin);

    printf("Podaj imie: ");
    gets(notification.name);

    printf("Podaj nazwisko: ");
    gets(notification.lastname);

    printf("Podej cene: ");
    gets(notification.price);

    printf("Podaj opis usterki: ");
    gets(notification.descreption);

    strcat(notification.descreption,"\n");


    if(fwrite(&notification,sizeof(notification),1,fptr) != 1)
    {
        perror("Blad: ");
    } else{

        printf("Dane dodane poprawnie\n");

    }
    fclose(fptr);
}

void readDatabase()
{
    //czytanie z pliku
    struct notification *object2=malloc(sizeof(struct notification));
    fptr=fopen("G:\\file.txt","rb");

    fread(object2,sizeof(struct notification),1,fptr);

    while(!feof(fptr))
    {

        printf("Imie: %s\n", object2->name);
        printf("Nazwisko: %s\n", object2->lastname);
        printf("Cena: %s\n", object2->price);
        printf("Opis: %s\n", object2->descreption);
        printf("==========\n");
    }

    fclose(fptr);
}

int main() {
    int i,option=0,check=0;


    do{
        printf("1) Dodaj rekord do bazy \n");
        printf("2) Odczytaj rekordy z bazy \n");
        printf("0) Zakoncz program \n");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                insertRecord();
                break;
            case 2:
                readDatabase();
                break;
            default:

                break;
        }

        //jezeli uzytkownik poda 0 program zakonczy dzialanie
        if(option == 0)
        {
            check=1;
        }

    }while(check == 0); //petla dziala dopóki zmienna check bedzie równa 0

}