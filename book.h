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

//typedef struct _Book_list book_list;
typedef struct _Book{
	struct _Book* next;
	struct _Book* prev;
	char title[20];
	char author[10];
	int num;
	char rental; //1이면 대여중
} Book;
//typedef struct _Book Book;
/*
typedef struct _Stud_list {
	_Student *head;
	_Student *tail;
} Stud_list;

typedef struct _Student {
	Student* next;
	Student* prev;
	char name[20];
	int num;
	int r_book[10];//대여중인 책 목록
	//int rental; // x = 1이면 대여중
} Student;
*/
void menu();
void search_book(struct Book* book, int c);

void insert_book2(struct Book_List* book_list, struct Book* book);
/*
void insert_stud(struct Student* stud, int c);
void search_stud(struct Student* stud, int s_count, struct Book* book, int b_count);
int r_book_size(struct Student stud);
void rental(struct Student* stud, struct Book* book, int s_count, int b_count);
void search_book_title(struct Book* book, char s_title);
*/