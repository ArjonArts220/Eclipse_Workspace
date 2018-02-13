/*
 * Product.h
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#define PRODUCT_ADD             1
#define PRODUCT_CHANGE_FIELD    2
#define PRODUCT_SEARCH_NAME     3
#define PRODUCT_DELETE          4
#define PRODUCT_PRINT_LIST      5

#define PRINT_ALL               -1

typedef struct
{
    unsigned int id;
    char name[10];
    char description[20];
    char verpakkingsEenheid[25];
    unsigned int prijsInCenten;
} Product;

#endif /* PRODUCT_H_ */
