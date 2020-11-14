#include <stdio.h>


char* Strcpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return dest;
}
int Strcmp(char* a, char* b) {
	int i = 0;
	do {
		if (a[i] != b[i])
			return a[i] > b[i] ? -1 : 1;
		i++;
	} while (a[i - 1] != NULL);
	return 0;
}

char* Strcat(char* dest, char* src)
{
	int i = 0;
	while (dest[i] != NULL) {
		i++;
	}
	for (int j = 0; src[j] != NULL; j++) {
		dest[i++] = src[j];
	}
	return dest;


}
/*
void main() {

	char str1[10] = "hel";
	char str2[6] = "hello";


	printf("%s", Strcat(str1, str2));

}*/