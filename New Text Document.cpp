#include<iostream>
#include<string>
using namespace std;

class Genome{
    private:
    string RNA;
    string DNA[2];
    //completed of each NOCLOTID
    char completed(char a){
        if(a=='A') return 'T';
        if(a=='T') return 'A';
        if(a=='C') return 'G';
        if(a == 'G') return 'C';

    }
    public:
    //return RNA
    string Get_RNA() const { return RNA; }
    //return DNA both in a single string 
    string Get_DNA() const {
        return DNA[0] + '/' + DNA[1];
    }
    //creating DNA form RNA
    string Create_DNA(string input_RNA){
        string DNA_maker[2];
        DNA_maker[0] = input_RNA;
        for(int i = 0 ; i < input_RNA.length() ; i++){
            DNA_maker[1][i] = completed(DNA_maker[0][i]);
        }
        cout<<"created DNA is :\n";
        cout<<DNA_maker[0]<<endl<<DNA_maker[1]<<endl;
    }
};
