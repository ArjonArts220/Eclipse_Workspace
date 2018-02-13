/*
 * PointersAndFunctions.c
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#include <stdlib.h>
#include <string.h>

int maina()
{
 /*   int numberOne = 4;
    int numberTwo = 6;

    printf("main() number one: %d, number two %d \n", numberOne, numberTwo);

    change1(numberOne, numberTwo);
    change2(&numberOne, &numberTwo);

    printf("main() number one: %d, number two %d \n", numberOne, numberTwo);
 */

    char myText[] = "I have 6 apples";
    printf("main() myText: %s \n", myText);
    changeWord(myText); //the array myText is been threaten as a pointer, whatever you change in the method, it also change here
    printf("main() myText: %s \n", myText);
    changeWord1(myText);
    return 0;
}

void change1(int numberOne, int numberTwo){
    /*This method makes another numberOne and numberTwo in the memory map, it doesn't change the value of the ones in the main function*/
    printf("change1() number one: %d, number two %d \n", numberOne, numberTwo);

    numberOne = 12;
    numberTwo = 24;

    printf("change1() number one: %d, number two %d \n", numberOne, numberTwo);
}

void change2(int *pNumberOne, int *pNumberTwo){
    /*This method are pointing to numberOne and numberTwo in the main, they are pointing to the address of the integers in the main*/
    printf("change2() number one: %d, number two %d \n", *pNumberOne, *pNumberTwo);

    *pNumberOne = 12;
    *pNumberTwo = 24;

    printf("change2() number one: %d, number two %d \n", *pNumberOne, *pNumberTwo);
}

void changeWord(char myText[]){
    /*If you change the array here, you really change it because myText points already to the first element. You can say that or this: (char *myText)*/
    printf("changeWord() myText: %s \n", myText);
    myText[7] = '9';
    printf("changeWord() myText: %s \n", myText);
}

void changeWord1(char myText[]){
    /*If you change the array here, you really change it because myText points already to the first element. You can say that or this: (char *myText)*/
    printf("changeWord1() myText: %s \n", myText);
    myText[7] = '3';
    printf("changeWord1() myText: %s \n", myText);
}

