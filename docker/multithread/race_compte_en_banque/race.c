#include <stdio.h>
#include <unistd.h> 
int main(){


    int solde,debit;
    scanf("%d", &debit);
    FILE *file = fopen("compte.txt", "r+");

    
    if (file == NULL) {
        
        printf("%s","Erreur lors de l'ouverture du fichier");
        return 1 ;
    }

    fscanf(file, "%d", &solde);

    solde-=debit;
    usleep(100);
    
    rewind(file);                                                                  // place le curseur au début du fichier
    fprintf(file, "%-10d",solde);                                              //-10d pour écraser le dernier chiffre lorsque le nombre final a moins de chffre que l'initial ex : 1000->900
    fclose(file);

    return 0;
}
