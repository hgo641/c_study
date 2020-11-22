#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	�迭 -> ���Ḯ��Ʈ�� ����
	���Ϸ� �Է�
*/

void search_print() {
	printf("----------------------\n");
	printf("1. å �������� �˻�\n");
	printf("2. ���ڷ� �˻�\n");
	printf("3. å ��ȣ�� �˻�\n");
	printf("���ڸ� �Է����ּ���\n");
};
void search_book_title(struct Book* book, const char s_title) {
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

void search_book(struct Book_list* book_list,int c) {
	search_print();
	int cmd_s;
	scanf("%d",&cmd_s);
	switch (cmd_s){
	case 1:
		printf("å ������ �Է��ϼ��� : ");
		const char s_title[20];
		scanf("%s", &s_title);
		search_book_title(book_list->head, s_title);
		break;
		/*
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
		break;*/
	default:
		printf("�߸��� �Է��Դϴ�\n");
		break;
	}
	return;
	
};
void insert_book2(struct Book_list* book_list, struct Book* book) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("å ����: ");
	scanf("%s", new_book->title);
	printf("�۰� : ");
	scanf("%s", new_book->author);
	printf("å ��ȣ: ");
	scanf("%d", new_book->num);
	new_book->rental = 'X';
	new_book->next = NULL; //�ڿ������� ����
	if (book_list->head == NULL) {
		book_list->head = new_book;
		book_list->head->prev = NULL;
		book_list->tail = NULL;
	}
	else {
		book_list->tail->next = new_book;
		new_book->prev = book_list->tail;
		book_list->tail = new_book;
	}
};

/*
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
	
};*/
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
	memset(stud[c].r_book, 0, sizeof(stud[c].r_book)); // �뿩���� å 0���� �ʱ�ȭ
	//stud[c].r_book = { 0, };
	/* for ��
	printf("�뿩���� å: ");
	scanf("%s", &stud[c].r_book);
	*/
	
};
void search_stud(struct Student* stud, int s_count,struct Book* book,int b_count) {
	printf("�й��� �Է��ϼ��� : ");
	int s_num;
	scanf("%d", &s_num);
	for (int i = 0; i < s_count; i++) {
		
		if (s_num == stud[i].num) {
			printf("�˻��Ͻ� �л��� �����Դϴ�\n");
			printf(" �̸� : %s\n �й� : %d\n",stud[i].name, stud[i].num);
			printf("�뿩���� å ��ȣ : ");
			if (stud[i].r_book[0] == 0)
				printf("�뿩���� å�� ���������ʽ��ϴ�.\n");
			for (int l = 0; stud[i].r_book[l] != 0; l++)
				printf("%d ", stud[i].r_book[l]);
			/*
			printf("�뿩���� å ��� : ");
			for (int j = 0; stud[i].r_book[j] != 0; j++) {
				
				for (int k = 0; k < b_count; k++) {
					if (stud[i].r_book[j] == book[k].num) {
						printf("%s", book[k].title);
					}
				}
			}*/
			
		}
	}
	return;
};
int r_book_size(struct Student stud) {
	int i = 0;
	while (stud.r_book[i] != 0) {
		i++;
	}
	return i;
}
void rental(struct Student* stud, struct Book* book,int s_count,int b_count) {
	printf("�뿩�ϴ� �л��� �й��� �Է��ϼ��� : ");
	int s_num;
	scanf("%d", &s_num);
	printf("\n�뿩�ϴ� å�� ��ȣ�� �Է��ϼ��� : ");
	int b_num;
	scanf("%d", &b_num);
	for (int i = 0; i < s_count; i++) {
		if (s_num == stud[i].num) {
			stud[i].r_book[r_book_size(stud[i])]=b_num;
		}
	}
	for (int j = 0; j < b_count; j++) {
		if (b_num == book[j].num)
			book[j].rental = 'O';
	}
	printf("\n�뿩�Ǿ����ϴ�.\n");
	return;
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
	struct Book B[10];
	struct Student S[10];
	int b_count = 0;
	int s_count = 0;
	
	int cmd;
	print_menu();
	scanf("%d", &cmd);

	while (cmd != 6) {
		switch (cmd) {
		case 1:
			search_book(B,b_count);
			break;
		case 2:
			insert_book2(B, b_count);
			b_count++;
			break;
		case 3:
			search_stud(S, s_count, B, b_count);
			break;
		case 4:
			insert_stud(S, s_count);
			s_count++;
			break;
		case 5:
			rental(S, B, s_count, b_count);
			break;
		}
		//system("cls");
		print_menu();
		scanf("%d", &cmd);

	};
};