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


void search_book(struct Book* book,int c) {
	/*printf("å ������ �Է��ϼ��� : ");
	char s_title[20];
	scanf("%s", &s_title);
	
	for (int i = 0;i<c; i++) {
		if (s_title==book[i].title) {
			printf("%s %s %n %n\n", &book[i].title, &book[i].author, &book[i].num, &book[i].rental);
			return;
		}
	}
	printf("���������ʽ��ϴ�");
	*/
	printf("å ��ȣ�� �Է��ϼ��� : ");
	int n;
	scanf("%d", &n);

	for (int i = 0; i < c; i++) {
		if (n== &book[i].num) {
			printf("%s %s %n %n\n", &book[i].title, &book[i].author, &book[i].num, &book[i].rental);
			return;
		}
	}
	printf("���������ʽ��ϴ�");
	return;
};
void insert_book(struct Book* book, int c) {
	printf("å ����: ");
	scanf("%s", &book[c].title);
	printf("�۰� : ");
	scanf("%s", &book[c].author);
	printf("å ��ȣ: ");
	scanf("%d", &book[c].num);
	printf("�ԷµǾ����ϴ�. %s %s %d\n", &book[c].title, &book[c].author, book[c].num);

	/*
	int num;
	do {
		printf("å ��ȣ: ");
		scanf("%d", num);
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
	scanf("%s", stud[c].name);
	printf("�й� : ");
	scanf("%d", stud[c].num);
	printf("�뿩���� å: ");
	scanf("%s", stud[c].r_book);
	
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
	struct Book B[1000] = { 0, };
	struct Student S[1000];
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