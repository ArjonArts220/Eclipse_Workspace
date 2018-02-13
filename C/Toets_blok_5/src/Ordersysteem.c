/*
 * Ordersysteem.c
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#include <stdio.h>
#include <stdlib.h>
#include "Order.h"
#include "Application.h"
#include "Product.h"

void addOrder(Order *orderArray, int *sizeOfOrderArray);
void changeNameOfCustomer(Order *orderArray, int *sizeOfOrderArray);
void addOrderregelToOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
void changeOrderregel(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
void printOneOrder(Order *orderArray, Product *product, int *sizeProductArray, int o_positionInArray);
void searchOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
void showAllOrders(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
void deleteOrderregel(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
int checkForAvailableOrderID(Order *orderArray, int *sizeOfOrderArray);
void deleteOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);
void swapProductElement(OrderRegel a, OrderRegel b);
void changeOrderArray(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray, int status);
void fillOrderArray(Order *orderArray, int *sizeOfOrderArray);

void fillOrderArray(Order *orderArray, int *sizeOfOrderArray){
    int numberOfOrder = 0;

    FILE *fp = fopen("orderbestand.txt", "r");
    fscanf(fp, "%d", &numberOfOrder);
    //orderArray = (Order*) realloc(orderArray, numberOfOrder * sizeof(Order));
    printf("numberOfOrder: %d \n", numberOfOrder);
    for(int i = 0 ; i < numberOfOrder ; i++){
        fscanf(fp, "%d", &orderArray[i].id);
        fscanf(fp, "%d", &orderArray[i].aantal);
        orderArray[i].orders = (OrderRegel*) realloc(orderArray[i].orders, (orderArray[i].aantal * sizeof(OrderRegel)));
        fscanf(fp, "%s", &orderArray[i].szName);
        fscanf(fp, "%s", &orderArray[i].szDatum);
        commaToSpatie(orderArray[i].szName);
        commaToSpatie(orderArray[i].szDatum);
        for(int j = 0 ; j < orderArray[i].aantal ; j++){
            fscanf(fp, "%d", &orderArray[i].orders[j].id);
            fscanf(fp, "%d", &orderArray[i].orders[j].hoeveelheid);
        }
        (*sizeOfOrderArray)++;
    }
    fclose(fp);


    /*int num = 0;
    while(!(feof(fp))){
        fread(orderArray, sizeof(Order), 1, fp);
        num++;
    }
    printf("Order num: %d \n", --num);
    fclose(fp);

    (*sizeOfOrderArray) = num;*/
}

void addOrder(Order *orderArray, int *sizeOfOrderArray)
{
    printf("*******************ADD ORDER*******************\n");
    char o_nameCustomer[20];
    printf("Enter name of customer: ");
    fgets(o_nameCustomer, 20, stdin);
    checkEndOfString(o_nameCustomer);
    fflush(stdin);

    char o_date[25];
    printf("Enter date: ");
    fgets(o_date, 25, stdin);
    checkEndOfString(o_date);
    fflush(stdin);

    strcpy(orderArray[(*sizeOfOrderArray)].szName, o_nameCustomer);
    strcpy(orderArray[(*sizeOfOrderArray)].szDatum, o_date);
    orderArray[(*sizeOfOrderArray)].id = ((*sizeOfOrderArray) + 1);

    /*malloc memory for orderregel*/
    orderArray[(*sizeOfOrderArray)].orders = (OrderRegel*) malloc(1 * sizeof(OrderRegel));
    orderArray[(*sizeOfOrderArray)].aantal = 0;
    printf("Aantal: %d \n", orderArray[(*sizeOfOrderArray)].aantal);
    (*sizeOfOrderArray)++;
}

void changeNameOfCustomer(Order *orderArray, int *sizeOfOrderArray)
{
    printf("*******************CHANGE NAME*******************\n");
    printf("Select id to change name, available id's are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orders!\n");
        return ;
    }
    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter id: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int positionInArray = (o_id - 1);

    /*Change name*/
    char o_newNameCustomer[20];
    printf("Name was: %s, change into: ", orderArray[positionInArray].szName);
    fgets(o_newNameCustomer, 20, stdin);
    checkEndOfString(o_newNameCustomer);
    fflush(stdin);
    strcpy(orderArray[positionInArray].szName, o_newNameCustomer);
}

void addOrderregelToOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************ADD ORDERREGEL*******************\n");
    printf("Available orders are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orders!\n");
        return;
    }

    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter id: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int o_positionInArray = (o_id - 1);


    printf("Available product you can add to your order: \n");
    for(int i = 0 ; i < (*sizeProductArray) ; i++){
        printf("%d) ", (i+1));
        printOneProduct(product, sizeProductArray, i);
    }
    printf("\n");



    printf("Which product do you want to add. \nEnter number: ");
    int p_positionInArray = getInputIntBetween(1, (*sizeProductArray));
    p_positionInArray--;

    /*reallocate memory*/
    orderArray[o_positionInArray].orders = (OrderRegel*) realloc(orderArray[o_positionInArray].orders, ((orderArray[o_positionInArray].aantal) + 1) * sizeof(OrderRegel));

    printf("How many do you want to add? \nEnter number: ");
    int or_hoeveelheid = getInputInt();

    orderArray[o_positionInArray].orders[orderArray[o_positionInArray].aantal].hoeveelheid = or_hoeveelheid;
    orderArray[o_positionInArray].orders[orderArray[o_positionInArray].aantal].id = product[p_positionInArray].id;

    orderArray[o_positionInArray].aantal++;

    printOneOrder(orderArray, product, sizeProductArray, o_positionInArray);

}

void changeOrderregel(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************CHANGE ORDERREGEL*******************\n");
    printf("Available orders are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orderregels!\n");
        return;
    }

    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter id: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int o_positionInArray = (o_id - 1);

    if(orderArray[o_positionInArray].aantal == 0){
        printf("No orderregels available! \n");
    }else{
        printf("Wich orderregel do you want to change? \n");
        for(int i = 0 ; i < orderArray[o_positionInArray].aantal ; i++){
            printf("%d) id: %d, hoeveelheid %d \n", (i+1), orderArray[o_positionInArray].orders[i].id, orderArray[o_positionInArray].orders[i].hoeveelheid);
        }

        /*Get orderregel*/
        printf("Enter number: ");
        int or_positionInArray = getInputIntBetween(1, orderArray[o_positionInArray].aantal);
        or_positionInArray--;
        printf("o_positionInArray: %d, or_positionInArray: %d \n", o_positionInArray, or_positionInArray);

        /*change id*/
        printf("Change id into: ");
        int or_id = checkForAvailableProductID(product, sizeProductArray);
        orderArray[o_positionInArray].orders[or_positionInArray].id = or_id;

        /*change hoeveelheid*/
        printf("Change hoeveelheid into: ");
        int or_hoeveelheid = getInputInt();
        orderArray[o_positionInArray].orders[or_positionInArray].hoeveelheid = or_hoeveelheid;

        printf("New orderregel: id: %d, hoeveelheid: %d \n", orderArray[o_positionInArray].orders[or_positionInArray].id, orderArray[o_positionInArray].orders[or_positionInArray].hoeveelheid);
    }

}

void deleteOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************DELETE ORDER*******************\n");
    printf("Available orders are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orders!\n");
        return;
    }

    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter id: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int o_positionInArray = (o_id - 1);

    printf("Oud o_position id: %d \n", orderArray[o_positionInArray].id);

    /*Swap last and chosen element*/
    Order temp = orderArray[o_positionInArray];
    orderArray[o_positionInArray] = orderArray[(*sizeOfOrderArray) - 1];
    orderArray[(*sizeOfOrderArray) - 1] = temp;

    printf("Nieuw o_position id: %d \n", orderArray[o_positionInArray].id);

    free(orderArray[o_positionInArray].orders);

    orderArray = (Order*) realloc(orderArray, ((*sizeOfOrderArray) - 1) * sizeof(Order));
    (*sizeOfOrderArray)--;

}

void deleteOrderregel(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************DELETE ORDERREGEL*******************\n");
    printf("Available orders are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orderregels!\n");
        return;
    }

    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter id: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int o_positionInArray = (o_id - 1);


    if(orderArray[o_positionInArray].aantal == 0){
        printf("No orderregels available! \n");
        return;
    }
    printf("Wich orderregel do you want to delete? \n");
    int p_print_positionInArray = 0;
    for(int i = 0 ; i < orderArray[o_positionInArray].aantal ; i++){
        printf("%d) ", (i+1));
        printOrderregel(orderArray, product, sizeProductArray, o_positionInArray, i);
    }

    printf("Enter number: ");
    int or_positionInArray = getInputIntBetween(1, (orderArray[o_positionInArray].aantal ));
    or_positionInArray--;
    printf("or_positionInArray: %d \n", or_positionInArray);
    printf("Oud o_position id: %d \n", orderArray[o_positionInArray].orders[or_positionInArray].id);

    /*Swap last and chosen element*/
    OrderRegel temp = orderArray[o_positionInArray].orders[or_positionInArray];
    orderArray[o_positionInArray].orders[or_positionInArray] = orderArray[o_positionInArray].orders[orderArray[o_positionInArray].aantal - 1];
    orderArray[o_positionInArray].orders[orderArray[o_positionInArray].aantal - 1] = temp;

    printf("nieuw o_position id: %d \n", orderArray[o_positionInArray].orders[or_positionInArray].id);

    orderArray[o_positionInArray].orders = (OrderRegel*) realloc(orderArray[o_positionInArray].orders, (orderArray[o_positionInArray].aantal - 1) * sizeof(OrderRegel));
    orderArray[o_positionInArray].aantal--;
}


void searchOrder(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************SHOW ONE ORDER*******************\n");
    printf("Available orders are: ");
    if((*sizeOfOrderArray) == 0){
        printf("no available orders!\n");
        return;
    }

    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printf("%d ", orderArray[i].id);
    }printf("\n");

    /*Get id*/
    printf("Enter number: ");
    int o_id = checkForAvailableOrderID(orderArray, sizeOfOrderArray);

    /*Get position in array*/
    int o_positionInArray = (o_id - 1);
    printf("o_positionInArray %d \n", o_positionInArray);

    /*Print one order*/
    printOneOrder(orderArray, product, sizeProductArray, o_positionInArray);
}

void showAllOrders(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
    printf("*******************SHOW ALL ORDERS*******************\n");
    for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
        printOneOrder(orderArray, product, sizeProductArray, i);
        printf("\n");
    }
}

void printOneOrder(Order *orderArray, Product *product, int *sizeProductArray, int o_positionInArray)
{
    int p_print_positionInArray = 0;
    printf("%d\n%s\n%s\n\n", orderArray[o_positionInArray].id, orderArray[o_positionInArray].szName, orderArray[o_positionInArray].szDatum);
    for(int i = 0 ; i < orderArray[o_positionInArray].aantal ; i++){
        printOrderregel(orderArray, product, sizeProductArray, o_positionInArray, i);
    }
}

void printOrderregel(Order *orderArray, Product *product, int *sizeProductArray, int o_positionInArray, int or_postionInArray)
{
    int p_print_positionInArray = getProductIdPostition(product, sizeProductArray, orderArray[o_positionInArray].orders[or_postionInArray].id);
    printf("%d\t%s\t%d\t%d\n",  orderArray[o_positionInArray].orders[or_postionInArray].id, product[p_print_positionInArray].name, orderArray[o_positionInArray].orders[or_postionInArray].hoeveelheid, (orderArray[o_positionInArray].orders[or_postionInArray].hoeveelheid * product[p_print_positionInArray].prijsInCenten));
}

int checkForAvailableOrderID(Order *orderArray, int *sizeOfOrderArray)
{
    int o_id = 0;
    int check = 0;
    while(1){
        o_id = getInputInt();

        for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
            if(orderArray[i].id == o_id){
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
    return o_id;
}

