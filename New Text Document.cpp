#include <iostream>
#include <string>
using namespace std;

class Genome
{
private:
    string RNA;
    string DNA[2];
    // clculate completed of each NOCLOTID
    char Calculate_completed(char a)
    {
        if (a == 'A')
            return 'T';
        if (a == 'T')
            return 'A';
        if (a == 'C')
            return 'G';
        if (a == 'G')
            return 'C';
    }

public:
    Genome( string input_RNA){
        RNA = input_RNA;
        string help_split;
        DNA[0] = RNA;
        for (int i = 0; i < input_RNA.length(); i++)
        {
            DNA[1][i] = Calculate_completed(DNA[0][i]);
        }

    }
    // return RNA
    string Get_RNA() const { return RNA; }
    // return DNA both in a single string
    string Get_DNA() const
    {
        // we will split it to tow strings when we want to use
        return DNA[0] + '/' + DNA[1];
    }
    // creating DNA form RNA
    string Create_DNA(string input_RNA)
    {
        string DNA_maker[2];
        DNA_maker[0] = input_RNA;
        for (int i = 0; i < input_RNA.length(); i++)
        {
            DNA_maker[1][i] = Calculate_completed(DNA_maker[0][i]);
        }
        cout << "created DNA is :\n"
             << DNA_maker[0] << endl
             << DNA_maker[1] << endl;
    }
    // creatign small mutation in RNA and DNA
    void Create_small_mutation(char A, char C, int n)
    {
        int check = n;
        for (int i = 0; i < RNA.length(); i++)
        {
            if (RNA[i] == A)
            {
                check--;
                RNA[i] = C;
                if (check == 0)
                    break;
            }
        }
        check = n;
        for (int i = 0; i < RNA.length(); i++)
        {
            if (DNA[0][i] == A)
            {
                check--;
                DNA[0][i] = C;
                DNA[1][i] = Calculate_completed(C);
                if (check == 0)
                    break;
            }
        }
    }
    //creating big mutaion in RNA and DNA
    void Create_big_mutation(string s1, string s2)
    {
        int i = RNA.find(s1);
        if (i == RNA[RNA.length() - 1])
        {
            cout << "we dont have this substring in RNA" << endl
                 << "Please try again" << endl;
        }
        else{
            for (int j =i; j < i + s2.length(); j++)
                RNA[j] = s2[j-i];            
        }
    }
};


int main(){


}