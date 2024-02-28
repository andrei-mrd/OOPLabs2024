#include <iostream>

int num(char* s) {
	int i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return i;
}

int function(char *c) {
	int x = 0;
	int i = 0;
	while (i != num(c)) {
		if (c[i] >= '0' && c[i] <= '9')
			x = x * 10 + (c[i] - '0');
		i++;
	}
	return x;
}

int main()
{
	char myString[100];
	FILE* pFile;
	fopen_s(&pFile, "in.txt", "r");
	if (fopen_s(&pFile, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	while (fopen_s(&pFile, "in.txt", "r") != NULL) {
		fgets(myString, 100, pFile);
		printf("%s", myString);
		printf("%i", function(myString));
	}
}
