#pragma once
#pragma warning(disable : 4996)
/*
	�Լ����

	�޴� ���
	���� ã��
	���� ������Ʈ
	�л� ���� ������Ʈ
*/

struct Book {
	char title[20];
	char author[10];
	int num;
	char rental; //1�̸� �뿩��
};
struct Student {
	char name[20];
	int num;
	int r_book[10];//�뿩���� å ���
	//int rental; // x = 1�̸� �뿩��
};
void menu();
void search_book(struct Book* book, int c);
void insert_book(struct Book* book, int c);
void insert_stud(struct Student* stud, int c);
void search_stud(struct Student* stud, int s_count, struct Book* book, int b_count);
int r_book_size(struct Student stud);
void rental(struct Student* stud, struct Book* book, int s_count, int b_count);