#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	배열 -> 연결리스트로 변경
	파일로 입력
*/

void search_print() {
	printf("----------------------\n");
	printf("1. 책 제목으로 검색\n");
	printf("2. 저자로 검색\n");
	printf("3. 책 번호로 검색\n");
	printf("숫자를 입력해주세요\n");
};
void search_book_title(struct Book* book, const char s_title) {
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

void search_book(struct Book_list* book_list,int c) {
	search_print();
	int cmd_s;
	scanf("%d",&cmd_s);
	switch (cmd_s){
	case 1:
		printf("책 제목을 입력하세요 : ");
		const char s_title[20];
		scanf("%s", &s_title);
		search_book_title(book_list->head, s_title);
		break;
		/*
	case 2:
		printf("저자를 입력하세요 : ");
		char s_author[10];
		scanf("%s", &s_author);
		
		for (int i = 0; i < c; i++) {
			int a = strcmp(s_author, book[i].author);
			if (a==0) {
				printf("검색하신 도서입니다\n");
				printf("제목 : %s\n 작가 : %s\n 책번호 : %d\n 대여 여부 : %c\n", book[i].title, book[i].author, book[i].num, book[i].rental);

				return;
			}
		}
		printf("존재하지않습니다");
		break;
	case 3:
		printf("책 번호를 입력하세요 : ");
		int n;
		scanf("%d", &n);

		for (int i = 0; i < c; i++) {
			if (n == book[i].num) {
				printf("검색하신 도서입니다\n");
				printf("제목 : %s\n 작가 : %s\n 책번호 : %d\n 대여 여부 : %c\n", book[i].title, book[i].author, book[i].num, book[i].rental);

				return;
			}
		}
		printf("존재하지않습니다");
		break;*/
	default:
		printf("잘못된 입력입니다\n");
		break;
	}
	return;
	
};
void insert_book2(struct Book_list* book_list, struct Book* book) {
	Book *new_book = (Book*)malloc(sizeof(Book)); 
	printf("책 제목: ");
	scanf("%s", new_book->title);
	printf("작가 : ");
	scanf("%s", new_book->author);
	printf("책 번호: ");
	scanf("%d", new_book->num);
	new_book->rental = 'X';
	new_book->next = NULL; //뒤에서부터 삽입
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
	printf("책 제목: ");
	scanf("%s", &book[c].title);
	printf("작가 : ");
	scanf("%s", &book[c].author);
	printf("책 번호: ");
	scanf("%d", &book[c].num);
	book[c].rental = 'X';

	/*
	int num;
	do {
		printf("책 번호: ");
		scanf("%d",&num);
		num_check(book, num);
	} while (num_check == 1);
	book.num = num;
	
};*/
/*
//insert_book 실행시 num 중복검사 함수
int num_check(struct Book book, int num) {
	for (int i = 0; book.book_list[i] != NULL; i++) {
		if (num == book.book_list[i]) {
			printf("이미 존재하는 책 번호입니다");
			return 1;
		}
	}
	return 0;
}
*/

void insert_stud(struct Student* stud, int c) {
	printf("이름 : ");
	scanf("%s", &stud[c].name);
	printf("학번 : ");
	scanf("%d", &stud[c].num);
	memset(stud[c].r_book, 0, sizeof(stud[c].r_book)); // 대여중인 책 0으로 초기화
	//stud[c].r_book = { 0, };
	/* for 문
	printf("대여중인 책: ");
	scanf("%s", &stud[c].r_book);
	*/
	
};
void search_stud(struct Student* stud, int s_count,struct Book* book,int b_count) {
	printf("학번을 입력하세요 : ");
	int s_num;
	scanf("%d", &s_num);
	for (int i = 0; i < s_count; i++) {
		
		if (s_num == stud[i].num) {
			printf("검색하신 학생의 정보입니다\n");
			printf(" 이름 : %s\n 학번 : %d\n",stud[i].name, stud[i].num);
			printf("대여중인 책 번호 : ");
			if (stud[i].r_book[0] == 0)
				printf("대여중인 책이 존재하지않습니다.\n");
			for (int l = 0; stud[i].r_book[l] != 0; l++)
				printf("%d ", stud[i].r_book[l]);
			/*
			printf("대여중인 책 목록 : ");
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
	printf("대여하는 학생의 학번을 입력하세요 : ");
	int s_num;
	scanf("%d", &s_num);
	printf("\n대여하는 책의 번호를 입력하세요 : ");
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
	printf("\n대여되었습니다.\n");
	return;
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