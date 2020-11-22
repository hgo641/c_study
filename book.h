#pragma once
#pragma warning(disable : 4996)
#include <stdbool.h>
/*
	배열 -> 연결리스트로 변경
	파일로 입력
*/
typedef struct _Book_list {
	struct _Book* head;
	struct _Book* tail;
} Book_list;

typedef struct _Book{
	struct _Book* next;
	//struct _Book* prev;
	char title[20];
	char author[10];
	int num;
	char rental; //1이면 대여중
} Book;


typedef struct _Stud_list {
	struct _Student *head;
	struct _Student *tail;
} Stud_list;

typedef struct _Student {
	struct _Student* next;
	char name[20];
	int num;
	Book_list r_book;//대여중인 책 목록
	//int rental; // x = 1이면 대여중
} Student;

void menu();
void print_menu();
void search_book(Book_list* book_list);
void search_book_title(Book* book, char* s_title);
void insert_book(Book_list* book_list, Book* new_book);
void insert_totalbook(Book_list* book_list);
void insert_stud(Stud_list* stud_list);
void search_stud(Stud_list* stud_list);
Student* search_stud_num(Student* stud, int s_num);
Book* search_book_num(int r_num, Book* book);
void print_book_list(Book* book);
void rental(Book_list* book_list, Stud_list* stud_list);
