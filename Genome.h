#include <iostream>
#include <string>
using namespace std;


class Genome
{
public:
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
    //Calculate Completed for every single Noclotid in RNA
    // and then return it as a string
    string create_second_DNA_from_RNA(string input_RNA){
        string make_DNA=input_RNA;
        for (int i = 0; i < input_RNA.length(); i++)
        {
            make_DNA[i] = Calculate_completed(input_RNA[i]);
        }
        return make_DNA;
    }
    //getting a string and returning reverse order of it
    string Create_reverse(string s1){
        string s2 = s1;
        int n = s1.length();
        for (int i =0 ; i < n ; i++){
            s2[n-i-1]=s1[i];
        }
        return s2;
    }

    Genome( string input_RNA,string DNA1,string DNA2){
        RNA = input_RNA;
        string help_split;
        DNA[0] = DNA1;
        DNA[1] = DNA2;
    }
    void Print_RNA()const {cout<<"RNA is:\n"<<RNA<<endl;}
    void Print_DNA()const {cout<<"DNA is:\n"<<DNA[0]<<endl<<DNA[1]<<endl;}
    // return RNA
    string Get_RNA() const { return RNA; }
    // return DNA both in a single string
    string Get_DNA() const
    {
        // we will split it to tow strings when we want to use
        return DNA[0] + DNA[1];
    }
    // creating DNA form RNA
    // 
    void Create_DNA()
    {
        cout<<"creating DNA from RNA\n";
        string DNA_maker[2];
        DNA_maker[0] = RNA;
        DNA_maker[1] = create_second_DNA_from_RNA(RNA);
        cout << "created DNA is:\n"
             << DNA_maker[0] << endl
             << DNA_maker[1] << endl;
    }
    // creatign small mutation in RNA and DNA 
    //changing  char A with Char C n times
    void Create_small_mutation(char A, char C, int n)
    {
        cout<<"creating small mutation\n";
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
        cout<<"creating big mutation\n";
        int i = RNA.find(s1);
        if (i == -1)
            cout << "the string not found in RNA\n"
                 << "Please try again\n";
        else{
            for (int j =i; j < i + s2.length(); j++)
                RNA[j] = s2[j-i];            
        }
        i = DNA[0].find(s1);
        if (i == -1)
            cout << "the string not found in DNA\n"
                 << "Please try again\n";   

    }
    void create_reverse_mutation(string s1){
        cout<<"creating reverse mutation\n";
        int i = RNA.find(s1);
        if (i == -1)
        {
            cout << "we dont have this substring in RNA" << endl
                 << "Please try again" << endl;
        }
        else{
            string s2 = Create_reverse(s1);
            for (int j = i; j < s2.length() + i; j++)
                RNA[j] = s2[j-i];
    }
        DNA[0] = RNA;
        DNA[1] = create_second_DNA_from_RNA(DNA[0]);
    }
};
