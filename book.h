#pragma once
#pragma warning(disable : 4996)
/*
	함수목록

	메뉴 출력
	도서 찾기
	도서 업데이트
	학생 정보 업데이트
*/

struct Book {
	char title[20];
	char author[10];
	int num;
	int rental; //1이면 대여중
};
struct Student {
	char name[20];
	int num;
	char* r_book[10];//대여중인 책 목록
	int rental; // x = 1이면 대여중
};
void menu();
void search_book(struct Book* book);
void insert_book(struct Book* book);
void insert_stud(struct Student* stud);