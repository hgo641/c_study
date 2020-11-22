#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	�迭 -> ���Ḯ��Ʈ�� ����
	���Ϸ� �Է�
*/


void search_book(Book_list* book_list) {
	
	printf("å ������ �Է��ϼ��� : ");
	char s_title[20];
	scanf("%s", &s_title);
	search_book_title(book_list->head, s_title);
		
	return;
};
void search_book_title(Book* book, char* s_title) {
	if (book == NULL) {
		printf("���������ʽ��ϴ�");
		return;
	}
	int a = strcmp(s_title, book->title);
	if (a == 0) {
		printf("�˻��Ͻ� �����Դϴ�\n");
		printf(" ���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book->title, book->author, book->num, book->rental);
		return;
	}
	else search_book_title(book->next, s_title);
};

void insert_book (Book_list* book_list) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("å ����: ");
	scanf("%s", new_book->title);
	printf("�۰� : ");
	scanf("%s", new_book->author);
	printf("å ��ȣ: ");
	scanf("%d", &new_book->num);
	new_book->rental = 'X';
	 //�տ������� ����
	if (book_list->head == NULL) {
		new_book->next = NULL;
		book_list->head = new_book;
		book_list->tail = new_book;
		
	}
	else {
		new_book->next = book_list->head;
		book_list->head = new_book;
		
	}
	return;
};

void insert_stud(Stud_list* stud_list) {
	Student* new_stud = (Student*)malloc(sizeof(Student));
	printf("�л� �̸�: ");
	scanf("%s", &new_stud->name);
	printf("�й� : ");
	scanf("%d", &new_stud->num);
	
	new_stud->r_book.head = NULL;
	new_stud->r_book.tail = NULL;
	//�տ������� ����
	if (stud_list->head == NULL) {
		new_stud->next = NULL;
		stud_list->head = new_stud;
		stud_list->tail = new_stud;

	}
	else {
		new_stud->next = stud_list->head;
		stud_list->head = new_stud;

	}
	return;
};
void search_stud(Stud_list* stud_list) {

	printf("�й��� �Է��ϼ��� : ");
	int s_num;
	scanf("%d", &s_num);
	search_stud_num(stud_list->head, s_num);

	return;
};

void search_stud_num(Student* stud, int s_num) {
	if (stud == NULL) {
		printf("���������ʽ��ϴ�");
		return;
	}
	
	if (s_num == stud->num) {
		printf("�˻��Ͻ� �л��Դϴ�\n");
		printf(" �̸� : %s\n �й� : %d\n" ,stud->name, stud->num);
		if (stud->r_book.head == NULL) {
			printf("�뿩���� å�� �����ϴ�");
		}
		else {
			print_book_list(stud->r_book.head);
		}
		printf("\n");
		return;
	}
	else search_stud_num(stud->next, s_num);
};

void print_book_list(Book* book) {
	if (book == NULL) return;
	else {
		printf("%s ", book->title);
		print_book_list(book->next);
	}
};
void print_menu() {
	printf("\n---���� ���� �ý���---\n");
	printf("1. ����ã��\n");
	printf("2. ���� ������Ʈ\n");
	printf("3. �л� ã��\n");
	printf("4. �л� ������Ʈ\n");
	printf("5. ���� �뿩\n");
	printf("6. ����\n");
	printf("���ϴ� ����� ��ȣ�� �Է��ϼ��� : ");
}
void menu() {
	
	Book_list* book_list = (Book_list*)malloc(sizeof(Book_list));
	book_list->head = NULL;
	book_list->tail = NULL;
	Stud_list* stud_list = (Stud_list*)malloc(sizeof(Stud_list));
	stud_list->head = NULL;
	stud_list->tail = NULL;
	int cmd;
	print_menu();
	scanf("%d", &cmd);

	while (cmd != 6) {
		switch (cmd) {
		case 1:
			search_book(book_list);
			break;
		case 2:
			insert_book(book_list);
			break;
		case 3:
			search_stud(stud_list);
			break;

		case 4:
			insert_stud(stud_list);
			break;
		};
		print_menu();
		scanf("%d", &cmd);
	};
};
