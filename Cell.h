#include <iostream>
#include <string>
#include <vector>
#include "Genome.h"
using namespace std;

class Cell : Genome
{
public:
    // create string from j to i + j
    // for finging palindrome
    string Str_maker_from_jTojplusi(string str, int j, int i)
    {
        string res;
        for (int z = j; z < j + i; z++)
            res += str[z];
        return res;
    }
    vector<Genome> cromozom_vector;
    // check if this cell should be deleted
    // if A,T 3 times more than G,C or more than 5 misstakes in DNA
    bool check_for_kill(string a, string b)
    {
        int n = 0;
        int A_T, G_C;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == 'A' && b[i] == 'T')
                A_T++;
            else if (a[i] == 'G' && b[i] == 'C')
                G_C++;
            if (a[i] != Calculate_completed(b[i]))
            {
                n++;
                if (n >= 5)
                    return true;
            }
        }
        if (A_T > (G_C * 3))
            return true;
        return false;
    }
    // delete coromozom if it should be removed
    void killing_cell()
    {
        for (int i = 0; i < cromozom_vector.size(); i++)
        {
            string DNA0 = cromozom_vector[i].DNA[0];
            string DNA1 = cromozom_vector[i].DNA[1];
            if (check_for_kill(DNA0, DNA1))
                delete this;
        }
    }
    // change first s2 in coromozom m with s1 in coromozom n
    //  and doing it for second DNA
    void Create_big_mutation(string s1, int n, string s2, int m)
    {
        int iter1 = cromozom_vector[n].DNA[0].find(s1);
        string temp1 = cromozom_vector[n].DNA[1];
        int iter2 = cromozom_vector[m].DNA[0].find(s2);
        string temp2 = cromozom_vector[m].DNA[1];
        for (int i = 0; i < s1.size(); i++)
        {
            cromozom_vector[n].DNA[0][i + iter1] = s2[i];
            cromozom_vector[n].DNA[1][i + iter1] = temp2[i];
            cromozom_vector[m].DNA[0][i + iter2] = s1[i];
            cromozom_vector[m].DNA[1][i + iter2] = temp1[i];
        }
    }
    // change A in mth coromozom with C n times
    void Create_small_mutation(char A, char C, int n, int m)
    {
        int f = n;
        for (int i = 0; i < cromozom_vector[m].DNA[0].size(); i++)
        {
            if (cromozom_vector[m].DNA[0][i] == A)
            {
                cromozom_vector[m].DNA[0][i] = C;
                cromozom_vector[m].DNA[1][i] = Calculate_completed(C);
                f--;
            }
            if (f == 0)
                break;
        }
    }
    // complete the s1 in nth coromozom
    void Create_reverse_mutation(string s1, int n)
    {
        int iter = cromozom_vector[n].DNA[0].find(s1);
        for (int i = iter; i < cromozom_vector[n].DNA[0].length(); i++)
        {
            cromozom_vector[n].DNA[0][i] = Calculate_completed(cromozom_vector[n].DNA[0][i]);
            cromozom_vector[n].DNA[1][i] = Calculate_completed(cromozom_vector[n].DNA[1][i]);
        }
    }
    // find all complete palindrome in a coromozom
    void find_all_complete_palindrome(int m)
    {
        string str1, str2;
        int n = cromozom_vector[m].DNA[0].size();
        string crom = cromozom_vector[m].DNA[0];

        for (int i = 1; i < n; i++)
        {
            bool check;
            for (int j = 0; j < n; j++)
            {
                check = true;
                if (j + i > n)
                    break;
                str1 = Str_maker_from_jTojplusi(crom, j, i);
                if (j + i + i > n)
                    break;
                str2 = Str_maker_from_jTojplusi(crom, j + i, i);
                for (int z = j; z < j + i; z++)
                {
                    if (str1[z] != Calculate_completed(str2[z]))
                        check = false;
                }
            }
            if (check)
            {
                cout << str1 << ":" << str2 << endl;
            }
        }
    }
};

// int main()
// {
//     Genome gen("AAA", "TTT", "GGG");
// }