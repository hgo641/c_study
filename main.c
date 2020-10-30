#include <stdio.h>
#include <string.h>

char* Strcpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return dest;
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
	
	char str1[10] = { "hel" };
	char str2[10] = { "hello" };
	printf(Strcmp(str1, str2));

}