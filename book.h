#pragma once
#pragma warning(disable : 4996)
#include <stdbool.h>
/*
	�迭 -> ���Ḯ��Ʈ�� ����
	���Ϸ� �Է�
*/
typedef struct _Book_list{
	Book* head;
	Book* tail;
} Book_list;
typedef struct _Book {
	struct Book* next;
	struct Book* prev;
	char title[20];
	char author[10];
	int num;
	char rental; //1�̸� �뿩��
} Book;
typedef struct _Stud_list {
	Student* head;
	Student* tail;
} Stud_list;
typedef struct_ Student {
	struct Student* next;
	struct Student* prev;
	char name[20];
	int num;
	int r_book[10];//�뿩���� å ���
	//int rental; // x = 1�̸� �뿩��
} Student;
void menu();
void search_book(struct Book* book, int c);

void insert_book2(struct Book_List* book_list, struct Book* book);
void insert_stud(struct Student* stud, int c);
void search_stud(struct Student* stud, int s_count, struct Book* book, int b_count);
int r_book_size(struct Student stud);
void rental(struct Student* stud, struct Book* book, int s_count, int b_count);
void search_book_title(struct Book* book, char s_title);