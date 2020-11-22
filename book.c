#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	배열 -> 연결리스트로 변경
	파일로 입력
*/


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
		printf("검색하신 도서입니다\n");
		printf(" 제목 : %s\n 작가 : %s\n 책번호 : %d\n 대여 여부 : %c\n", book->title, book->author, book->num, book->rental);
		return;
	}
	else search_book_title(book->next, s_title);
};

void insert_book (Book_list* book_list) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("책 제목: ");
	scanf("%s", new_book->title);
	printf("작가 : ");
	scanf("%s", new_book->author);
	printf("책 번호: ");
	scanf("%d", &new_book->num);
	new_book->rental = 'X';
	 //앞에서부터 삽입
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

	return;
};

void search_stud_num(Student* stud, int s_num) {
	if (stud == NULL) {
		printf("존재하지않습니다");
		return;
	}
	
	if (s_num == stud->num) {
		printf("검색하신 학생입니다\n");
		printf(" 이름 : %s\n 학번 : %d\n" ,stud->name, stud->num);
		if (stud->r_book.head == NULL) {
			printf("대여중인 책이 없습니다");
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
	printf("\n---도서 관리 시스템---\n");
	printf("1. 도서찾기\n");
	printf("2. 도서 업데이트\n");
	printf("3. 학생 찾기\n");
	printf("4. 학생 업데이트\n");
	printf("5. 도서 대여\n");
	printf("6. 종료\n");
	printf("원하는 기능의 번호를 입력하세요 : ");
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
