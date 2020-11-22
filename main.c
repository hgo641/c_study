#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)

void main() {
    Book_list* L = (Book_list*)malloc(sizeof(Book_list));
    L->head = NULL;
    L->tail = NULL;
	menu();


}
