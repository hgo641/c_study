#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	배열 -> 연결리스트로 변경 o
	파일로 입력 x
*/

void insert_firstlist(FILE* fp,Book_list* book_list,Book* book) {
	
	/*
	char s_title[20] = { 0, };
	char s_author[10] = { 0, };

	char s_render;
	*/
	
	while (1) {
		//fseek(fp, sum, SEEK_SET);
		char sc_num[10] = { 0, };
		if (fp == NULL) {
			printf("error\n");
			exit(1);
		}
		int i = 0;
		while ((book->title[i] = fgetc(fp)) != '\t') {
			putchar(book->title[i]);
			i++;
		}
		book->title[i] = '\0';
		int j = 0;
		while ((book->author[j] = fgetc(fp)) != '\t') {
			putchar(book->author[j]);
			j++;
		}
		book->author[j] = '\0';
		int m = 0;
		while ((sc_num[m] = fgetc(fp)) != '\t') {
			putchar(sc_num[m]);
			m++;
		}
		sc_num[m] = '\0';
		book->num = atoi(sc_num);
		book->rental = fgetc(fp);
		putchar(book->rental);
		printf("\n");
		if (fgetc(fp) != '\n') {
			Book* temp = (Book*)malloc(sizeof(Book));
			temp->next = book;
			book_list->head = temp;
			insert_firstlist(fp,book_list, temp);
		}
		/*
		printf("%s\n", &book_list->head->title);
		printf("%s\n", &book_list->head->author);
		printf("%d", &book_list->head->num);
		*/
		return;
		

		//printf("\n%s\n",s_title);
	}
	book_list->tail->next = NULL;
	


};
void search_book(Book_list* book_list) {
	
	printf("책 제목을 입력하세요 : ");
	char s_title[20];
	scanf("%s", &s_title);
	search_book_title(book_list->head, s_title);
		
	return;
};
void search_book_title(Book* book, char* s_title) {
	if (book == NULL) {
		printf("존재하지않습니다");
		return;
	}
	int a = strcmp(s_title, book->title);
	if (a == 0) {
		printf(" 제목 : %s\n 작가 : %s\n 책번호 : %d\n 대여 여부 : %c\n", book->title, book->author, book->num, book->rental);
		return;
	}
	else search_book_title(book->next, s_title);
};

void insert_totalbook (Book_list* book_list) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("책 제목: ");
	scanf("%s", new_book->title);
	printf("작가 : ");
	scanf("%s", new_book->author);
	printf("책 번호: ");
	scanf("%d", &new_book->num);
	new_book->rental = 'X';
	 //앞에서부터 삽입
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
	printf("학생 이름: ");
	scanf("%s", &new_stud->name);
	printf("학번 : ");
	scanf("%d", &new_stud->num);
	
	new_stud->r_book.head = NULL;
	new_stud->r_book.tail = NULL;
	//앞에서부터 삽입
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

	printf("학번을 입력하세요 : ");
	int s_num;
	scanf("%d", &s_num);
	search_stud_num(stud_list->head, s_num);
	if (search_stud_num(stud_list->head, s_num) != NULL) {
		Student* s_stud = (Student*)malloc(sizeof(Student));
		s_stud = search_stud_num(stud_list->head, s_num);
		printf("검색하신 학생입니다\n");
		printf(" 이름 : %s\n 번호 : %d\n", s_stud->name, s_stud->num);
		if (s_stud->r_book.head == NULL) {
			printf("대여중인 책이 없습니다");
		}
		else {
			printf("대여중인 책 목록입니다.\n");
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
		printf("해당 번호의 도서가 존재하지않습니다.\n");
		return NULL; }
	if (book->num == r_num) {
		printf(" 제목 : %s\n 작가 : %s\n 책번호 : %d\n 대여 여부 : %c\n", book->title, book->author, book->num, book->rental);
		return book;
	}
	else search_book_num(r_num, book->next);
};
void rental(Book_list* book_list, Stud_list* stud_list) {
	int r_bnum, r_snum;
	Book* r_book = (Book*)malloc(sizeof(Book));
	printf("대여하는 도서의 번호를 입력하세요: ");
	scanf("%d", &r_bnum);
	if (search_book_num != NULL) {
		if (book_list->head == NULL) {
			printf("도서리스트가 존재하지않습니다.\n");
			return;
		}
		
		r_book = search_book_num(r_bnum, book_list->head);
		if (r_book->rental != 'X') {
			printf("이미 대여중인 책입니다.\n");
			return;
		}
		r_book->rental = 'O';
	}
	printf("대여하는 학생의 번호를 입력하세요: ");
	scanf("%d", &r_snum);
	Student* r_stud = (Student*)malloc(sizeof(Student));
	
	if (search_stud_num(stud_list->head, r_snum) != NULL) {
		
		r_stud = (search_stud_num(stud_list->head, r_snum));
		insert_book(&r_stud->r_book, r_book);
		printf("대여 완료되었습니다.\n");
	}
	return;

};

Student* search_stud_num(Student* stud, int s_num) {
	if (stud == NULL) {
		printf("해당 학생은 존재하지않습니다");
		return NULL;
	}

	if (s_num == stud->num) {
		return stud;
	}
	else search_stud_num(stud->next, s_num);
};
void print_menu() {
	printf("\n---도서 관리 시스템---\n");
	printf("1. 도서찾기\n");
	printf("2. 도서 업데이트\n");
	printf("3. 학생 찾기\n");
	printf("4. 학생 업데이트\n");
	printf("5. 도서 대여\n");
	printf("6. 최초 북리스트 삽입\n");
	printf("7. 종료\n");
	printf("원하는 기능의 번호를 입력하세요 : ");
}
void menu() {
	
	Book_list* book_list = (Book_list*)malloc(sizeof(Book_list));
	Book* temp = (Book*)malloc(sizeof(Book));
	temp->next = NULL;
	book_list->tail = temp;
	book_list->head = temp;
	FILE* fp = fopen("book_list.txt", "r");
	
	Stud_list* stud_list = (Stud_list*)malloc(sizeof(Stud_list));
	stud_list->head = NULL;
	stud_list->tail = NULL;
	int cmd;
	print_menu();
	scanf("%d", &cmd);

	while (cmd != 7) {
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
		case 6:
			
			insert_firstlist(fp,book_list,book_list->tail);
			fclose(fp);
			break;
			
		};
		
		print_menu();
		scanf("%d", &cmd);
	};
};
