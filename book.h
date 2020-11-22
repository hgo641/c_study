#pragma once
#pragma warning(disable : 4996)
#include <stdbool.h>
/*
	�迭 -> ���Ḯ��Ʈ�� ����
	���Ϸ� �Է�
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
	char rental; //1�̸� �뿩��
} Book;


typedef struct _Stud_list {
	struct _Student *head;
	struct _Student *tail;
} Stud_list;

typedef struct _Student {
	struct _Student* next;
	char name[20];
	int num;
	struct _Book_list r_book;//�뿩���� å ���
	//int rental; // x = 1�̸� �뿩��
} Student;

void menu();
void print_menu();
void search_book(Book_list* book_list);
void search_book_title(Book* book, char* s_title);
void insert_book(Book_list* book_list);
void insert_stud(Stud_list* stud_list);
void search_stud(Stud_list* stud_list);
void search_stud_num(Student* stud, int s_num);
void print_book_list(Book* book);