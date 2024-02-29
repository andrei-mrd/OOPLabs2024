#include <stdio.h>

struct Word {
    int size;
    char word[100];
};

int main()
{
    char s[100]; //sentence
    scanf("%[^\n]s", s);
    char prop[100][100]; //prop separate

    Word cuvant[100];
    int c = 0; //pt parcurgerea propozitiei
    int cnt = 0; //contor de lungime cuvinte
    int cnt_cuv = 0; //cnt cuvinte
    while (1)
    {
        if (s[c] != ' ' && s[c])
        {
            cnt++;
        }
        else {
            cuvant[cnt_cuv].size = cnt;
            cnt = 0;
            for (int j = 0; j < cuvant[cnt_cuv].size; j++) {
                cuvant[cnt_cuv].word[j] = s[c - cuvant[cnt_cuv].size + j];
            }
            cnt_cuv++;
            if (s[c] == '\0')
                break;
        }
        c++;
    }

    for (int j = 0; j < cnt_cuv; j++) {
        //printf("%i ", cuvant[j].size);
        printf("%s ", cuvant[j].word);
    }


    return 0;
}
