#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	�迭 -> ���Ḯ��Ʈ�� ���� o
	���Ϸ� �Է� x
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
		printf(" ���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book->title, book->author, book->num, book->rental);
		return;
	}
	else search_book_title(book->next, s_title);
};

void insert_totalbook (Book_list* book_list) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("å ����: ");
	scanf("%s", new_book->title);
	printf("�۰� : ");
	scanf("%s", new_book->author);
	printf("å ��ȣ: ");
	scanf("%d", &new_book->num);
	new_book->rental = 'X';
	 //�տ������� ����
	insert_book(book_list, new_book);
	return;
};

void insert_book(Book_list* book_list, Book* new_book) {
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
	if (search_stud_num(stud_list->head, s_num) != NULL) {
		Student* s_stud = (Student*)malloc(sizeof(Student));
		s_stud = search_stud_num(stud_list->head, s_num);
		printf("�˻��Ͻ� �л��Դϴ�\n");
		printf(" �̸� : %s\n ��ȣ : %d\n", s_stud->name, s_stud->num);
		if (s_stud->r_book.head == NULL) {
			printf("�뿩���� å�� �����ϴ�");
		}
		else {
			printf("�뿩���� å ����Դϴ�.\n");
			print_book_list(s_stud->r_book.head);
		}
		printf("\n");

	}

	return;
};



void print_book_list(Book* book) {
	if (book == NULL) return;
	else {
		printf("%s ", book->title);
		print_book_list(book->next);
	}
};
Book*  search_book_num(int r_num, Book* book) {
	if (book == NULL) { 
		printf("�ش� ��ȣ�� ������ ���������ʽ��ϴ�.\n");
		return NULL; }
	if (book->num == r_num) {
		printf(" ���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book->title, book->author, book->num, book->rental);
		return book;
	}
	else search_book_num(r_num, book->next);
};
void rental(Book_list* book_list, Stud_list* stud_list) {
	int r_bnum, r_snum;
	Book* r_book = (Book*)malloc(sizeof(Book));
	printf("�뿩�ϴ� ������ ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &r_bnum);
	if (search_book_num != NULL) {
		if (book_list->head == NULL) {
			printf("��������Ʈ�� ���������ʽ��ϴ�.\n");
			return;
		}
		
		r_book = search_book_num(r_bnum, book_list->head);
		if (r_book->rental != 'X') {
			printf("�̹� �뿩���� å�Դϴ�.\n");
			return;
		}
		r_book->rental = 'O';
	}
	printf("�뿩�ϴ� �л��� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &r_snum);
	Student* r_stud = (Student*)malloc(sizeof(Student));
	
	if (search_stud_num(stud_list->head, r_snum) != NULL) {
		
		r_stud = (search_stud_num(stud_list->head, r_snum));
		insert_book(&r_stud->r_book, r_book);
		printf("�뿩 �Ϸ�Ǿ����ϴ�.\n");
	}
	return;

};

Student* search_stud_num(Student* stud, int s_num) {
	if (stud == NULL) {
		printf("�ش� �л��� ���������ʽ��ϴ�");
		return NULL;
	}

	if (s_num == stud->num) {
		return stud;
	}
	else search_stud_num(stud->next, s_num);
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
			insert_totalbook(book_list);
			break;
		case 3:
			search_stud(stud_list);
			break;

		case 4:
			insert_stud(stud_list);
			break;
		case 5:
			rental(book_list,stud_list);
			break;
		};
		print_menu();
		scanf("%d", &cmd);
	};
};
