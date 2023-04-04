#include <iostream>
#include "Genome.h"

using namespace std;
// checking input RNA if it is correct or not
string correct_RNA_cin()
{
    string s;
    bool is_correct = true;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'T' || s[i] == 'A' || s[i] == 'C' || s[i] == 'G')
            continue;
        else
        {
            is_correct = false;
            break;
        }

    if (is_correct)
        return s;
    else
    {
        cout << "Invalid input\ninput a string with A,T,C,G\n";
        return (correct_RNA_cin());
    }
}
// checking the input number to be sure its correct
int correct_number_cin(int a, int b)
{
    string s;
    cin >> s;
    int n = stoi(s);
    if (n <= b && n >= a)
        return n;
    else
    {
        cout << "invalid input\n"
             << "input a number between " << a << " and " << b << endl;
        return (correct_number_cin(a, b));
    }
}

void Create_new_Genome()
{
    string RNA;
    string DNA1, DNA2;
    cout << "input RNA...\n";
    RNA = correct_RNA_cin();
    cout << "input first string of DNA...\n";
    DNA1 = correct_RNA_cin();
    cout << "input second string of DNA...\n";
    DNA2 = correct_RNA_cin();
    Genome my_obj(RNA, DNA1, DNA2);
}

int main()
{ 
    bool gameOn = true;
    cout << "wellcome to the application\n";
    int choise;
   while (gameOn!=false)
   { 
    cout<< "--------------------------------\n";
    cout << "1-Create a new Genome\n";
    cout << "2-Work with a Genome\n";
    cout << "3-Create a new Cell\n";
    cout << "4-Work with a Cell\n";
    cout << "5-Craete a new Animal\n";
    cout << "6-Work with a Animal\n";
    cout << "--------------------------------\n";
    cout << "Input one number between 1 and 6...\n";
    choise = correct_number_cin(1, 6);
    if (choise == 1)
        Create_new_Genome();
    else 




   }
}