//
// Created by McArthur on 27/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userentry[400];
    //Levée des drapeaux
    char chaine1_1[25] = "M1fnP2Q~b6qZfm1w4vhx\0";
    char chaine1_2[25] ;
    for (int i=0;i<25;i++){
        if (chaine1_1[i]!='\0'){
            chaine1_2[i]=chaine1_1[i]^0x5;}
        else chaine1_2[i]='\0';
    }
    char chaine2_1[25] = "O3dlR0S|t4d7icXw7nisX4uz\0";
    char chaine2_2[25] ;
    for (int i=0;i<25;i++){
        if (chaine2_1[i]!='\0'){
            chaine2_2[i]=chaine2_1[i]^0x7;}
        else chaine2_2[i]='\0';
    }
    char flag1[25];
    char *flag2;
    flag2 = malloc(25 );

    strcpy(flag2, chaine2_2);
    strcpy(flag1, chaine1_2);


    strcpy(chaine2_2, "aaaaaaaaaaaaaaaaaaaaaaaa\0");
    strcpy(chaine2_1, chaine2_2);
    strcpy(chaine1_1, chaine2_1);
    strcpy(chaine1_2, chaine1_1);



    //Début du programme
    int IQ = 99;
    printf("Please enter your name: ");
    if (fgets(userentry, sizeof(userentry), stdin)) {
        userentry[strcspn(userentry, "\n")] = '\0';
    }

    printf("\nCalculating your IQ ...\n");
    printf("Result of ");
    printf(userentry);
    printf(" :\n");

    if (IQ == 100) {
        char xor[100]="A5b§9&éeaokfeiç)zA5b§9&ée$0aokfeiç)z";
        char flag3[20];
        char real_flag3[20];
        flag3[0]=0x9;
        flag3[1]=0x1;
        flag3[2]=0x1;
        flag3[3]=0xa9;
        flag3[4]=0xf2;
        flag3[5]=0xe;
        flag3[6]=0x72;
        flag3[7]=0xb8;
        flag3[8]=0xcb;
        flag3[9]=0x54;
        flag3[10]=0x6;
        flag3[11]=0x30;
        flag3[12]=0x9;
        flag3[13]=0x14;
        flag3[14]=0x51;
        flag3[15]=0x58;
        flag3[16]=0xad;
        flag3[17]=0xda;
        flag3[18]='\0';
        for (int i=0;i<25;i++){
            if (flag3[i]!='\0') {
                real_flag3[i] = flag3[i] ^ xor[i];
            }
            else {
                real_flag3[i]='\0';
            }
        }
        printf("\nWell done, your IQ is 100, here is your flag : %s\n",real_flag3);
    } else if (IQ != 99) {
        printf("\nWell done, but you must have an IQ of 100, not %d", IQ);
    } else {
        printf("You're still too stupid :\n%p : %d\n", &IQ, IQ);
    }
}


