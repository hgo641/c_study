#include <stdio.h>
#include <string.h>

/*
	strlng없이 구현
	
	헤더 사용 - 함수 선언
	메뉴 출력
	도서 찾기
	도서 업데이트
*/
char* Strcpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return dest;
}
int str_cmp(char* a , char* b) {
	int i = 0;
	while (i!=NULL) {
		if (a[i] > b[i])
			return -1;
		else if (a[i] < b[i])
			return 1;
		i++;
	}
	return 0;
}

int Strcmp(const char* s1, const char* s2)
{
	unsigned char c1, c2;

	while (1) {
		c1 = *s1++; 
		c2 = *s2++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)
			break;
	}
	return 0;
}

char* Strcat(char* dest, char* src)
{
	int i = strlen(dest);
	int j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	return dest;
}
void main() {
	
	char str1[10] = "hel";
	char str2[10] = "hello";

	
	printf(Strcmp(str1, str2));

}