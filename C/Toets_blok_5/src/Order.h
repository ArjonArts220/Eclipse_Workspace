/*
 * Order.h
 *
 *  Created on: 13 feb. 2018
 *      Author: arjon
 */

#ifndef ORDER_H_
#define ORDER_H_
#include "Orderregel.h"
#define ORDER_ADD_ORDER                 1
#define ORDER_ADD_ORDERREGEL            2
#define ORDER_CHANGE_NAME_CUSTOMER      3
#define ORDER_CHANGE_ORDERREGEL         4
#define ORDER_DELETE_ORDER              5
#define ORDER_DELETE_ORDERREGEL         6
#define ORDER_PRINT_ALL_ORDERS          7
#define ORDER_SEARCH_ORDER              8

typedef struct
{
 unsigned int id; // order id
 char szName[20]; // naam van klant
 char szDatum[25]; // datum als tekst
 OrderRegel *orders; // dynamische array met orders
 unsigned int aantal; // aantal orderregels
} Order;

#endif /* ORDER_H_ */
