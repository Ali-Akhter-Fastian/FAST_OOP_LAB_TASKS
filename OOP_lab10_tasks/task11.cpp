//TASK 11 BY ALI AKHTER 24K-0809
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("article.txt");
    char ch;
    int characters = 0, words = 0, lines = 1, punctuations = 0;
    bool inWord = false;
    while (f.get(ch))
    {
        characters++;
        if (ch == '\n')
        {
            lines++;
        }
        if (ch == ' ')
        {
            characters--;
        }
        if (ispunct(ch))
        {
            punctuations++;
        }
        if (isspace(ch))
        {
            if (inWord)
            {
                words++;
                inWord = false;
            }
        }
        else if (isalnum(ch)) 
            inWord = true;
    }
    if (inWord) 
        words++;
    cout << "Words: " << words<< " Lines: " << lines<< " Punctuations: " << punctuations
    << " Characters: " << characters << endl;
    return 0;
}
