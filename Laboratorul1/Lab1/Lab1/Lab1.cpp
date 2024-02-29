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
	int sum = 0;
	char myString[100];
	FILE* pFile;
	fopen_s(&pFile, "in.txt", "r");
	if (pFile == NULL)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
		return 1;
	}
	while (fgets(myString, 100, pFile)) {
		
		//printf("%s", myString);
		//printf("%i\n", function(myString));
		sum += function(myString);
	}
	fclose(pFile);
	printf("%i", sum);
	return 0;
}
