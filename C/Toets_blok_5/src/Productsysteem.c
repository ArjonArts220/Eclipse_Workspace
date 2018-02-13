/*
 * Productsysteem.c
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#include <stdio.h>
#include <stdlib.h>
#include "Product.h"
#include "Order.h"
#include "Orderregel.h"
#include "Application.h"

void fillProductArray(Product *product , int *lengte);
void addProduct(Product *product, int *sizeProductArray);
void changeFieldOfProduct(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
int getInputInt();
void checkEndOfString(char* input);
void printAllProducts(Product *product, int *sizeProductArray);
void printOneProduct(Product *product, int *sizeProductArray, int select);
void deleteProductInArray(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
int getProductIdPostition(Product *product, int *sizeProductArray, int input);
int checkForAvailableProductID(Product *product, int *sizeProductArray);

void fillProductArray(Product *product , int *lengte)
{
    /*FILE *fpw = fopen("productbestand.txt", "w");
    fpw = fopen("productbestand.txt", "wb");

    product = (Product*) realloc(product, ((*lengte) + 1) * sizeof(Product));
    product[(*lengte)].id = 17;
    strcpy(product[(*lengte)].name, "M8x50");
    strcpy(product[(*lengte)].description, "Koperen schroef");
    strcpy(product[(*lengte)].verpakkingsEenheid, "prijs/gram");
    product[(*lengte)].prijsInCenten = 7;
    (*lengte)++;

    product = (Product*) realloc(product, ((*lengte) + 1) * sizeof(Product));
    product[(*lengte)].id = 23;
    strcpy(product[(*lengte)].name, "M6x35");
    strcpy(product[(*lengte)].description, "Stalen schroef");
    strcpy(product[(*lengte)].verpakkingsEenheid, "prijs/gram");
    product[(*lengte)].prijsInCenten = 3;
    (*lengte)++;

    product = (Product*) realloc(product, ((*lengte) + 1) * sizeof(Product));
    product[(*lengte)].id = 45;
    strcpy(product[(*lengte)].name, "M45");
    strcpy(product[(*lengte)].description, "Stalen moer");
    strcpy(product[(*lengte)].verpakkingsEenheid, "prijs/gram");
    product[(*lengte)].prijsInCenten = 210;
    (*lengte)++;
    fwrite(product, sizeof(Product), 3, fpw);

    fclose(fpw);*/

    FILE *fp = fopen("productbestand.txt", "rb");
    int num = 0;
    while(!(feof(fp))){
        fread(product, sizeof(Product), 1, fp);
        num++;
    }
    num--;
    printf("Product num: %d \n", num);
    fclose(fp);


    FILE *fpr = fopen("productbestand.txt", "rb");
    fread(product, sizeof(Product), num, fpr);


    (*lengte) = num;
}

/*
fread(product, sizeof(Product), 1, fp);
        printf("%d %s \n", product[0].id, product[0].description);
*/




void addProduct(Product *product, int *lengte)
{
    printf("*******************ADD PRODUCT*******************\n");
    int p_id = -1;
    int checkID = -1;
    char p_name[10] = "";
    char p_description[20] = "";
    char p_verpakkingsEenheid[25] = "";
    int p_prijsInCenten = -1;
    fflush(stdin);

    printf("Enter id: ");
    while(1){ //check if id is not already taken
        checkID = 0;
        p_id = getInputInt();
        for(int i = 0 ; i < (*lengte) ; i++){
            if(product[i].id == p_id){
                checkID = 1;
            }
        }
        if(checkID == 0){
            break;
        }
        printf("Id is not available! Enter again: ");
    }
    product[(*lengte)].id = p_id;
    fflush(stdin);

    printf("Enter name: ");
    fgets(p_name, 10, stdin);
    checkEndOfString(p_name);
    strcpy(product[(*lengte)].name, p_name);
    fflush(stdin);

    printf("Enter description: ");
    fgets(p_description, 20, stdin);
    checkEndOfString(p_description);
    strcpy(product[(*lengte)].description, p_description);
    fflush(stdin);

    printf("Enter verpakkingsEenheid: ");
    fgets(p_verpakkingsEenheid, 25, stdin);
    checkEndOfString(p_verpakkingsEenheid);
    strcpy(product[(*lengte)].verpakkingsEenheid, p_verpakkingsEenheid);
    fflush(stdin);

    printf("Enter prijs in centen: ");
    p_prijsInCenten = getInputInt();
    product[(*lengte)].prijsInCenten = p_prijsInCenten;
    fflush(stdin);
    (*lengte)++;

    printf("\nNew list: \n");
    printAllProducts(product, lengte);
}

void changeFieldOfProduct(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************CHANGE FIELD OF PRODUCT*******************\n");
    printf("Which product do you want to change? \n");
    for(int i = 0 ; i < (*sizeProductArray) ; i++){
        printf("%d) ", (i+1));
        printOneProduct(product, sizeProductArray, i);
    }
    printf("\n");

    printf("Enter number: ");
    int p_positionInArray = getInputIntBetween(1, (*sizeProductArray));
    p_positionInArray--;

    printf("\nThe product you want to change is: \nid(1)\tname(2)   beschrijving(3)     verpakkingsEenheid(4)    prijsInCenten(5)\n");
    printOneProduct(product, sizeProductArray, p_positionInArray);

    printf("Wich field do you want to change? \n");
    printf("Fieldnumber: ");
    int fieldType = getInputIntBetween(1, 5);

    int a = 0;
    int checkID = 0;
    char na[10];
    char des[20];
    char verpak[25];
    printf("Change into: ");
    switch(fieldType){
        case 1:
            while(1){ //check if id is not already taken
                checkID = 0;
                a = getInputInt();
                for(int i = 0 ; i < (*sizeProductArray) ; i++){
                    if(product[i].id == a && !(product[p_positionInArray].id == a)){
                        checkID = 1;
                    }
                }
                if(checkID == 0){
                    break;
                }
                printf("Id is not available! Enter again: ");
            }

            /*change orders id*/
            for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){ //check every order
                for(int j = 0 ; j < orderArray[i].aantal ; j++){ //check every orderregel
                    if(orderArray[i].orders[j].id == product[p_positionInArray].id){
                        orderArray[i].orders[j].id = a;
                    }
                }
            }
            product[p_positionInArray].id = a;
            break;
        case 2:
            fgets(na, 10, stdin);
            checkEndOfString(na);
            strcpy(product[p_positionInArray].name, na);
            break;
        case 3:
            fgets(des, 20, stdin);
            checkEndOfString(des);
            strcpy(product[p_positionInArray].description, des);
            break;
        case 4:
            fgets(verpak, 25, stdin);
            checkEndOfString(verpak);
            strcpy(product[p_positionInArray].verpakkingsEenheid, verpak);
            break;
        case 5:
            a = getInputInt();
            product[p_positionInArray].prijsInCenten = a;
        break;

    }

    printf("\nNew list: \n");
    printAllProducts(product, sizeProductArray);
}

void searchField(Product *product, int *sizeProductArray)
{
    printf("*******************SEARCH PRODUCT*******************\n");
    printf("Do you want to search for an exact match(1) or for a part(2)?\nEnter number: ");
    int searchMethode = getInputIntBetween(1, 2);

    printf("Type in the name of the product: ");
    char input[15];
    int compareArr[(*sizeProductArray)];
    int i;
    if(searchMethode == 1){
        fgets(input, 15, stdin);
        checkEndOfString(input);
        for(i = 0 ; i < (*sizeProductArray) ; i++){
            (strcmp(product[i].name, input) == 0) ? (compareArr[i] = 1) : (compareArr[i] = 0);
        }
    }else{
        fgets(input, 15, stdin);
        checkEndOfString(input);
        for(i = 0 ; i < (*sizeProductArray) ; i++){
            (strstr(product[i].name, input) != NULL) ? (compareArr[i] = 1) : (compareArr[i] = 0);
        }
    }
    for(i = 0 ; i < (*sizeProductArray) ; i++){
         if(compareArr[i] == 1){
            break;
         } else if(compareArr[(*sizeProductArray) - 1] == 0){
             printf("No match found! \n");
             return;
         }
    }

    printf("id   \tname      beschrijving        verpakkingsEenheid       prijsInCenten\n");
    for(i = 0 ; i < (*sizeProductArray) ; i++){
        if(compareArr[i] == 1){
            printOneProduct(product, sizeProductArray, i);
        }
    }

}

void deleteProductInArray(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************DELETE PRODUCT*******************\n");
    printf("Wich product do you want to delete? \n");
    for(int i = 0 ; i < (*sizeProductArray) ; i++){
        printf("%d) ", (i+1));
        printOneProduct(product, sizeProductArray, i);
    }
    printf("\n");

    printf("Enter number: ");
    int p_positionInArray = getInputIntBetween(1, (*sizeProductArray));
    p_positionInArray--;

    printf("The following product will be deleted: \n");
    printf("id   \tname      beschrijving        verpakkingsEenheid       prijsInCenten\n");
    printOneProduct(product, sizeProductArray, p_positionInArray);

    /*Check if order has the product*/
    for(int o = 0 ; o < (*sizeOfOrderArray) ; o++){ //check every order
        for(int or = 0 ; or < orderArray[o].aantal ; or++){ //check every orderregel
            if(orderArray[o].orders[or].id == product[p_positionInArray].id){
                /*Swap last and chosen element*/
                OrderRegel temp = orderArray[o].orders[or];
                orderArray[o].orders[or] = orderArray[o].orders[orderArray[o].aantal - 1];
                orderArray[o].orders[orderArray[o].aantal - 1] = temp;

                orderArray[o].orders = (OrderRegel*) realloc(orderArray[o].orders, (orderArray[o].aantal - 1) * sizeof(OrderRegel));
                orderArray[o].aantal--;
            }
        }
    }


    /*Swap elements*/
    Product temp = product[p_positionInArray];
    product[p_positionInArray] = product[(*sizeProductArray) - 1];
    product[(*sizeProductArray) - 1] = temp;

    (*sizeProductArray)--;
    product = (Product*) realloc(product, (*sizeProductArray) * sizeof(Product));

    printf("\nNew list: \n");
    printAllProducts(product, sizeProductArray);
}

void printAllProducts(Product *product, int *sizeProductArray) //printAllProducts
{
    printf("id\tname      beschrijving        verpakkingsEenheid       prijsInCenten\n");
    for(int i = 0 ; i < (*sizeProductArray) ; i++){
        printOneProduct(product, sizeProductArray, i);
    }

}

void printOneProduct(Product *product, int *sizeProductArray, int select)
{
    printf("%d   \t", product[select].id);
    printf("%s", product[select].name); for(int i = 0 ; i < (10 - strlen(product[select].name)) ; i++){ printf(" "); }
    printf("%s", product[select].description); for(int i = 0 ; i < (20 - strlen(product[select].description)) ; i++){ printf(" "); }
    printf("%s", product[select].verpakkingsEenheid); for(int i = 0 ; i < (25 - strlen(product[select].verpakkingsEenheid)) ; i++){ printf(" "); }
    printf("%d \n", product[select].prijsInCenten);
}

int getProductIdPostition(Product *product, int *sizeProductArray, int input)
{
    int position = 0;
    for(int i = 0 ; i < (*sizeProductArray) ; i++){
        if(product[i].id == input){
            break;
        }else{
            position++;
        }
    }
    return position;
}

int checkForAvailableProductID(Product *product, int *sizeProductArray)
{
    int or_id = -1;
        int check = 0;
        while(1){
            or_id = getInputInt();
            for(int i = 0 ; i < (*sizeProductArray) ; i++){
                if(product[i].id == or_id){
                    check = 1;
                }
            }
            if(check == 1){
                break;
            }
            else{
                printf("Number doesn't match id! Enter again: ");
            }
        }
    return or_id;
}

