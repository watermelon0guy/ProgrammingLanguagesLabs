#include <iostream>
#include "lib.h"

int main() {
    string name = "test.txt";
    string temp = "";
    cout << "Count chars:" << endl;
    CountChars(name);
    cout << "Press any char button + enter to continue..." << endl;
    cin >> temp; // возможность проверить файл

    cout << "Longest string:" << endl;
    LongestString(name);
    cout << "Press any char button + enter to continue..." << endl;
    cin >> temp; // возможность проверить файл

    cout << "Word count:" << endl;
    WordCountInStrings(name);
    cout << "Press any char button + enter to continue..." << endl;
    cin >> temp; // возможность проверить файл

    cout << "Delete word \"BIG_WORD\":" << endl;
    DeleteWords(name, "BIG_WORD");
    cout << "Check file, then press any char button + enter to continue..." << endl;
    cin >> temp; // возможность проверить файл

    cout << "Number lines:" << endl;
    NumberLines(name);
    cout << "Check file, then press any char button + enter to continue..." << endl;
    cin >> temp; // возможность проверить файл

    cout << "Replace words(hmm) with their numbers:" << endl;
    ReplaceWithCount(name, "hmm");

}


// Исходный текст. Уже в файле
/*word wow BIG_WORD word heh word BIG_WORD word
word word hmm word word maybe word
word BIG_WORD word word word hmm word word word
word watermelon word BIG_WORD math check hmm
word word hmm math word word
keith watermelon word small word big word word
word word word hmm word space word
BIG_WORD word rus BIG_WORD word BIG_WORD BIG_WORD BIG_WORD word*/