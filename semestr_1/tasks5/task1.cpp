#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    int length;
    cin >> word;
    length = word.length();

    if (length > 5)
    {
        word[0] = 'X';
    }
    else
    {
        word[length - 1] = 'X';
    }

    cout << word << endl;
}