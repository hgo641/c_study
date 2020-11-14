#include <stdio.h>
#include <string.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	�Լ����

	�޴� ���
	���� ã��
	���� ������Ʈ
	�л� ���� ������Ʈ
*/

void search_print() {
	printf("----------------------\n");
	printf("1. å �������� �˻�\n");
	printf("2. ���ڷ� �˻�\n");
	printf("3. å ��ȣ�� �˻�\n");
	printf("���ڸ� �Է����ּ���\n");
};
void search_book(struct Book* book,int c) {
	search_print();
	int cmd_s;
	scanf("%d",&cmd_s);
	switch (cmd_s){
	case 1:
		printf("å ������ �Է��ϼ��� : ");
		char s_title[20];
		scanf("%s", &s_title);
		

		for (int i = 0; i < c; i++) {
			int a = strcmp(s_title, book[i].title);
			if (a==0) {
				printf("�˻��Ͻ� �����Դϴ�\n");
				printf(" ���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book[i].title, book[i].author, book[i].num, book[i].rental);
				return;
			}
		}
		printf("���������ʽ��ϴ�");
		break;
	case 2:
		printf("���ڸ� �Է��ϼ��� : ");
		char s_author[10];
		scanf("%s", &s_author);
		
		for (int i = 0; i < c; i++) {
			int a = strcmp(s_author, book[i].author);
			if (a==0) {
				printf("�˻��Ͻ� �����Դϴ�\n");
				printf("���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book[i].title, book[i].author, book[i].num, book[i].rental);

				return;
			}
		}
		printf("���������ʽ��ϴ�");
		break;
	case 3:
		printf("å ��ȣ�� �Է��ϼ��� : ");
		int n;
		scanf("%d", &n);

		for (int i = 0; i < c; i++) {
			if (n == book[i].num) {
				printf("�˻��Ͻ� �����Դϴ�\n");
				printf("���� : %s\n �۰� : %s\n å��ȣ : %d\n �뿩 ���� : %c\n", book[i].title, book[i].author, book[i].num, book[i].rental);

				return;
			}
		}
		printf("���������ʽ��ϴ�");
		break;
	default:
		printf("�߸��� �Է��Դϴ�\n");
		break;
	}
	return;
	
};
void insert_book(struct Book* book, int c) {
	printf("å ����: ");
	scanf("%s", &book[c].title);
	printf("�۰� : ");
	scanf("%s", &book[c].author);
	printf("å ��ȣ: ");
	scanf("%d", &book[c].num);
	book[c].rental = 'X';

	/*
	int num;
	do {
		printf("å ��ȣ: ");
		scanf("%d",&num);
		num_check(book, num);
	} while (num_check == 1);
	book.num = num;
	*/
};

/*
//insert_book ����� num �ߺ��˻� �Լ�
int num_check(struct Book book, int num) {
	for (int i = 0; book.book_list[i] != NULL; i++) {
		if (num == book.book_list[i]) {
			printf("�̹� �����ϴ� å ��ȣ�Դϴ�");
			return 1;
		}
	}
	return 0;
}
*/

void insert_stud(struct Student* stud, int c) {
	printf("�̸� : ");
	scanf("%s", &stud[c].name);
	printf("�й� : ");
	scanf("%d", &stud[c].num);
	/* for ��
	printf("�뿩���� å: ");
	scanf("%s", &stud[c].r_book);
	*/
	
};

void print_menu() {
	printf("\n---���� ���� �ý���---\n");
	printf("1. ����ã��\n");
	printf("2. ���� ������Ʈ\n");
	printf("3. �л� ���� ������Ʈ\n");
	printf("4. ����\n");
	printf("���ϴ� ����� ��ȣ�� �Է��ϼ��� : ");
}
void menu() {
	struct Book B[10];
	struct Student S[10];
	int b_count = 0;
	int s_count = 0;
	
	int cmd;
	print_menu();
	scanf("%d", &cmd);

	while (cmd != 4) {
		switch (cmd) {
		case 1:
			search_book(B,b_count);
			break;
		case 2:
			insert_book(B, b_count);
			b_count++;
			break;
		case 3:
			insert_stud(S, s_count);
			s_count++;
			break;

		}
		//system("cls");
		print_menu();
		scanf("%d", &cmd);

	};
};