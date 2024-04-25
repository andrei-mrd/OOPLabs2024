#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::ifstream fin("in.txt");

int wordCount(std::string str, std::string word) {
    int count = 0, i, aux;
    bool ok;
    for (i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' && word.size() != 1) {
            str[i] += 32;
        }if (word[0] >= 'A' && word[0] <= 'Z' && word.size() != 1) {
            word[0] += 32;
        }
        if (str[i] == word[0]) {
            aux = i;
            ok = true;
            for (int j = 0; j < word.size(); j++) {
                if (str[aux] >= 'A' && str[aux] <= 'Z' && word.size() != 1) {
                    str[aux] += 32;
                }if (word[j] >= 'A' && word[j] <= 'Z' && word.size() != 1) {
                    word[j] += 32;
                }
                if (str[aux] != word[j]) {
                    ok = false;
                    break;
                }
                aux++;
            }
            if (ok == true) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    std::string a;
    std::string b;
    while (std::getline(fin, b)) {
        a += b;
        a += "\n";
    }

    std::map<std::string, int> Elements;

    int first = 0, last = 0, i = 0;
    std::string word, cpy;
    while (i < a.size())
    {
        if ( !((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) || i == a.size() - 1) {
            if ((a[first] >= 'a' && a[first] <= 'z') || (a[first] >= 'A' && a[first] <= 'Z')) {
                word = a.substr(first, last - first);
                int count = wordCount(a, word);
                cpy = word;
                for (int l = 0; l < word.size(); l++) {
                    if (cpy[l] >= 'A' && cpy[l] <= 'Z') {
                        cpy[l] += 32;
                    }
                }
                if (Elements.find(cpy) == Elements.end()) {
                    Elements[cpy] = count;
                }
            }
            first = last + 1;
        }
        last++;
        i++;
    }
    
    int countMax = 0, count = 0;
    std::string toRemove, toCompare;
    while (Elements.empty() == 0) {
        count = 0;
        countMax = 0;
        for (auto it = Elements.begin(); it != Elements.end(); ++it) {
            if (it->second > countMax) {
                countMax = it->second;
                toRemove = it->first;
            }
        }

        for (auto it = Elements.begin(); it != Elements.end(); ++it) {
            if (it->second == countMax) {
                count++;
                if (count > 1) {
                    toCompare = it->first;
                    if (toRemove.compare(toCompare) > 0) {
                        toRemove = toCompare;
                    }
                }
            }
        }
        std::cout << toRemove << " => " << countMax << "\n";

        Elements.erase(toRemove);
    }

    fin.close();

    return 0;
}