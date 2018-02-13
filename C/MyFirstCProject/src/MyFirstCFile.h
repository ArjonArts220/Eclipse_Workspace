/*
 * MyFirstCFile.h
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#ifndef MYFIRSTCFILE_H_
#define MYFIRSTCFILE_H_

//this is called a header

#define MYFOOD "Tuna"
#define MYAGE 18

struct userInfo{
    int userID;
    char firstName[25];
    char lastName[25];
    int age;
    float weight;
} ;  // 1) }arjon;

typedef struct{
    /*Now you make the type "CarType"*/
    char *name;
    int people;
    int speed;
}CarType;

int calculateGirlToDate(){
    int girlsAge = (MYAGE / 2) + 7;
    return girlsAge;
}

void printInfo(struct userInfo ab){
    printf("userId: %d \n", ab.userID);
    printf("first name: %s \n", ab.firstName);
    printf("last name: %s \n", ab.lastName);
    printf("age: %d \n", ab.age);
    printf("weight: %.2f \n", ab.weight);
}




#endif /* MYFIRSTCFILE_H_ */
