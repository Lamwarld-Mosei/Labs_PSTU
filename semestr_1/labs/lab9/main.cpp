#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string F1 = "F1.txt";
const string F2 = "F2.txt";

void createFile()
{
    ofstream f1(F1);

    if (!f1.is_open())
    {
        cout << "Error!";
        return;
    }

    f1 << "Anna likes to read a book in the evening A\n";
    f1 << "Today is a beautiful day\n";
    f1 << "Bob has a small dog B\n";
    f1 << "I enjoy learning programming\n";
    f1 << "Elephants are very intelligent E\n";
    f1 << "My brother plays football\n";
    f1 << "Never say never N\n";
    f1 << "We study English at school\n";
    f1 << "Madam speaks very quietly M\n";
    f1 << "Technology changes our world\n";

    f1.close();
}


void printFile(const string& path)
{
    ifstream f(path);

    if (!f.is_open())
    {
        cout << "Error!";
        return;
    }

    string str;

    while (getline(f, str))
    {
        cout << str << '\n';
    }

    f.close();

    return;
}


void copyFile()
{
    ifstream f1(F1);
    ofstream f2(F2);

    if (!f1.is_open())
    {
        cout << "Error!";
        return;
    }

    else if (!f2.is_open())
    {
        cout << "Error!";
        f1.close();
        return;
    }

    string str;

    while (getline(f1, str))
    {
        if (!str.empty() && str[0] == str[str.length() - 1])
            f2 << str << '\n';
    }

    f1.close();
    f2.close();

    return;
}


void countingSuitable()
{
    ifstream f2(F2);

    if (!f2.is_open())
    {
        cout << "Error!";
        return;
    }

    string str;
    size_t count = 0;

    while (getline(f2, str))
    {
        count += str.length();
    }

    f2.close();

    cout << "Count of characters in file 2: " << count << '\n';

    return;
}


int main()
{
    cout << "=========FILE FORMATION=========\n";
    createFile();

    cout << "\n=========OUTPUT FILE 1=========\n";
    printFile(F1);

    cout << "\n=========COPYING CONDITIONAL STRINGS TO FILE 2=========\n";
    copyFile();

    cout << "\n=========OUTPUT FILE 2=========\n";
    printFile(F2);

    cout << "\n=========COUNTING CHARACTERS IN FILE 2=========\n";
    countingSuitable();

    return 0;
}