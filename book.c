#include <stdio.h>
#include <string.h>
#include "book.h"
#pragma warning(disable : 4996)
/*
	함수목록

	메뉴 출력
	도서 찾기
	도서 업데이트
	학생 정보 업데이트
*/


void search_book(struct Book* book,int c) {
	/*printf("책 제목을 입력하세요 : ");
	char s_title[20];
	scanf("%s", &s_title);
	
	for (int i = 0;i<c; i++) {
		if (s_title==book[i].title) {
			printf("%s %s %n %n\n", &book[i].title, &book[i].author, &book[i].num, &book[i].rental);
			return;
		}
	}
	printf("존재하지않습니다");
	*/
	printf("책 번호를 입력하세요 : ");
	int n;
	scanf("%d", &n);

	for (int i = 0; i < c; i++) {
		if (n== &book[i].num) {
			printf("%s %s %n %n\n", &book[i].title, &book[i].author, &book[i].num, &book[i].rental);
			return;
		}
	}
	printf("존재하지않습니다");
	return;
};
void insert_book(struct Book* book, int c) {
	printf("책 제목: ");
	scanf("%s", &book[c].title);
	printf("작가 : ");
	scanf("%s", &book[c].author);
	printf("책 번호: ");
	scanf("%d", &book[c].num);
	printf("입력되었습니다. %s %s %d\n", &book[c].title, &book[c].author, book[c].num);

	/*
	int num;
	do {
		printf("책 번호: ");
		scanf("%d", num);
		num_check(book, num);
	} while (num_check == 1);
	book.num = num;
	*/
};

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
	scanf("%s", stud[c].name);
	printf("학번 : ");
	scanf("%d", stud[c].num);
	printf("대여중인 책: ");
	scanf("%s", stud[c].r_book);
	
};

void print_menu() {
	printf("\n---도서 관리 시스템---\n");
	printf("1. 도서찾기\n");
	printf("2. 도서 업데이트\n");
	printf("3. 학생 정보 업데이트\n");
	printf("4. 종료\n");
	printf("원하는 기능의 번호를 입력하세요 : ");
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