#include <iostream>
#include <string>
#include <vector>
#include "Genome.h"
using namespace std;

class Cell : Genome
{
public:
    vector<Genome> cromozom_vector;
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
        if(A_T>(G_C*3))
            return true;
        return false;
    }
    void killing_cell()
    {
        for (int i = 0; i < cromozom_vector.size(); i++)
        {
            string DNA0 = cromozom_vector[i].DNA[0];
            string DNA1 = cromozom_vector[i].DNA[1];
        }
    }
};

int main()
{
    Genome gen("AAA", "TTT", "GGG");
}