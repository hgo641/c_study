#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)

void main() {
    Book_list* book_list = (Book_list*)malloc(sizeof(Book_list));
    book_list->head = NULL;
    book_list->tail = NULL;
	menu();


}
