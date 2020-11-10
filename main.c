#include <studio.h>
#include <string.h>
//strcpy strcat strcmp

int strcmp(char* dest, char* src) {
	if (strlen(dest))
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
	
	char str1[10] = { "hel" };
	char str2[10] = { "hello" };
	printf(Strcmp(str1, str2));

}