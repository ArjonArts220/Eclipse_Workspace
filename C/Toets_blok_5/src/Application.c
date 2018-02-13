/*
 * Application.c
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

int getInputInt()
{
    char tempInput[30];
    int input = 0;
    while(1){
        fgets(tempInput, 29, stdin);
        input = atoi(tempInput); //check if inputId is int

        if(input != 0){
            break;
        }else{
            printf("I don't recognize this, enter again: ");
        }
        fflush(stdin);
    }
    fflush(stdin);
    return input;
}

int getInputIntBetween(int num1, int num2){
    int temp = 0;
    while(1){
        temp = getInputInt();
        printf("temp: %d, num1: %d, num2: %d \n", temp, num1, num2);
        if(temp >= num1 && temp <= num2){
            break;
        }else{
            printf("Invalid number! Enter again: ");
        }
    }
    return temp;
}

void checkEndOfString(char* input)
{
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n'){
        input[ln] = '\0';
    }else{
        input[strlen(input)] = '\0';
    }
}

void commaToSpatie(char *input){
    size_t ln = strlen(input);
    for(int i = 0 ; i < ln ; i++){
        if(input[i] == ','){
            input[i] = ' ';
        }
    }
}

void spatieToComma(char *input){
    size_t ln = strlen(input);
    for(int i = 0 ; i < ln ; i++){
        if(input[i] == ' '){
            input[i] = ',';
        }
    }
    printf("Spatie to comma %s \n", input);
}


