/*
 ============================================================================
 Name        : Toets_blok_5.c
 Author      : Arjon Arts
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Application.h"
#include "Order.h"
#include "Product.h"


void applicationOn(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray);

int main()
{
    int sizeOfOrderArray = 0;
    Order *orderArray = (Order*) malloc(0); //2 * sizeof(Order)

    int sizeOfProductArray = 0;
    Product *productArray = (Product*) malloc(0); //1 * sizeof(Product)

    productArray = (Product*) realloc(productArray, 20 * sizeof(Product));
    fillProductArray(productArray, &sizeOfProductArray);
    productArray = (Product*) realloc(productArray, sizeOfProductArray * sizeof(Product));

    orderArray = (Order*) realloc(orderArray, 20 * sizeof(Order));
    fillOrderArray(orderArray, &sizeOfOrderArray);
    orderArray = (Order*) realloc(orderArray, sizeOfOrderArray * sizeof(Order));

    applicationOn(orderArray, &sizeOfOrderArray, productArray, &sizeOfProductArray);

    free(productArray);
    free(orderArray);
    return 0;
}

void applicationOn(Order *orderArray, int *sizeOfOrderArray, Product *product, int *sizeProductArray)
{
     while(1){
        printf("Do you want to change product(1), order(2) or do you want to quit(3)? \n");
        printf("Enter number: ");
        int number = getInputIntBetween(1, 3);

        int action = 0;
        switch(number){
            case 1:
                printf("Product actions are: \nAdd product(1), change field(2), search field(3), delete(4) or printf list(5)? \nEnter number: ");
                action = getInputIntBetween(1, 5);
                fflush(stdin);
                switch(action){
                    case PRODUCT_ADD:
                        product = (Product*) realloc(product, ((*sizeProductArray) + 1) * sizeof(Product));
                        addProduct(product, sizeProductArray);
                        break;
                    case PRODUCT_CHANGE_FIELD:
                        changeFieldOfProduct(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case PRODUCT_SEARCH_NAME:
                        searchField(product, sizeProductArray);
                        break;
                    case PRODUCT_DELETE:
                        deleteProductInArray(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case PRODUCT_PRINT_LIST:
                        printAllProducts(product, sizeProductArray);
                        break;
                    default:
                        printf("Fout in product case! \n");
                        break;
                }
                fflush(stdin);
            break;
            case 2:
                printf("Order actions are: \nAdd order(1), add orderregel(2), change name customer(3), change orderregel(4), delete order(5) or delete orderregel(6), print orders(7) or search order(8)? \nEnter number: ");
                action = getInputIntBetween(1, 8);
                fflush(stdin);
                switch(action){
                    case ORDER_ADD_ORDER:
                        /*Reallock memory for oderArray*/
                        orderArray = (Order*) realloc(orderArray, ((*sizeOfOrderArray) + 1) * sizeof(Order));
                        addOrder(orderArray, sizeOfOrderArray);
                        break;
                    case ORDER_ADD_ORDERREGEL:
                        addOrderregelToOrder(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case ORDER_CHANGE_NAME_CUSTOMER:
                        changeNameOfCustomer(orderArray, sizeOfOrderArray);
                        break;
                    case ORDER_CHANGE_ORDERREGEL:
                        changeOrderregel(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case ORDER_DELETE_ORDER:
                        deleteOrder(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case ORDER_DELETE_ORDERREGEL:
                        deleteOrderregel(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case ORDER_PRINT_ALL_ORDERS:
                        showAllOrders(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                    case ORDER_SEARCH_ORDER:
                        searchOrder(orderArray, sizeOfOrderArray, product, sizeProductArray);
                        break;
                }
                fflush(stdin);
            break;
            case 3:
                printf("Have a nice day:) \n");

                FILE *fp_p = fopen("productbestand.txt", "wb");
                fwrite(product, sizeof(Product), (*sizeProductArray), fp_p);
                fclose(fp_p);

                FILE *fp_o = fopen("orderbestand.txt", "w");
                printf("aaa\n");
                fprintf(fp_o, "%d\n", (*sizeOfOrderArray));
                printf("sizeOfOrderArray %d \n", (*sizeOfOrderArray));
                for(int i = 0 ; i < (*sizeOfOrderArray) ; i++){
                    fprintf(fp_o, "%d\n",orderArray[i].id);
                    fprintf(fp_o, "%d\n",orderArray[i].aantal);
                    spatieToComma(orderArray[i].szName);
                    spatieToComma(orderArray[i].szDatum);
                    fprintf(fp_o, "%s\n",orderArray[i].szName);
                    fprintf(fp_o, "%s\n",orderArray[i].szDatum);
                    for(int j = 0 ; j < orderArray[i].aantal ; j++){
                        fprintf(fp_o, "%d\n",orderArray[i].orders[j].id);
                        fprintf(fp_o, "%d\n",orderArray[i].orders[j].hoeveelheid);
                    }
                }
                fclose(fp_o);

                printf("Seize productArray: %d \n", (*sizeProductArray));
                printf("Seize orderArray: %d \n", (*sizeOfOrderArray));

                return;
                break;
        }
        printf("\n\n");
    }
}

