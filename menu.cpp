#include <iostream>
#include <string>
#include <vector>
#include "Genome.h"
#include "Cell.h"
#include "Animal.h"

vector<Animal> All_Animals;
vector<Genome> All_Genomes;
vector<Cell> All_Cells;

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

void Work_with_cell()
{
    if (All_Cells.size() == 0)
    {
        cout << "First create some cells!!!\n";
        return;
    }
    cout << "select one cell\n(cells are represented by first cromozom)" << endl;
    for (int i = 0; i < All_Cells.size(); i++)
    {
        cout << i + 1 << ".{ " << All_Cells[i].cromozom_vector[0].DNA[0] << endl
             << All_Cells[i].cromozom_vector[0].DNA[1] << "}\n";
    }
    int iter = correct_number_cin(1, All_Cells.size()) - 1;
    cout << "What do you want to do with this cell?\n"
         << "1. Add genome to cromozom vector\n"
         << "2. Check all cromozoms for killing\n"
         << "3. Create small mutation\n"
         << "4. Create big mutation\n"
         << "5. Create reverse mutation\n"
         << "6. Find all complete palindrome\n"
         << "7. Cancel";
    int c = correct_number_cin(1, 7);
    switch (c)
    {
    case 1:
    {
        cout << "enter DNA:\nfirst enter first string then enter secone one\n";
        string s1 = correct_RNA_cin();
        string s2 = correct_RNA_cin();
        Genome gen;
        gen.RNA = "";
        gen.DNA[0] = s1;
        gen.DNA[1] = s2;
        All_Cells[iter].cromozom_vector.push_back(gen);
        cout << "Cromozom added!..\n";
        break;
    }
    case 2:
    {
        cout << "Checking cromozoms for killing...\n";
        cout << "--------------------------------\n";
        cout << "Before delting we have this cromozoms:\n";
        for (int i = 0; i < All_Cells[iter].cromozom_vector.size(); i++)
        {
            cout << i + 1 << ".{ " << All_Cells[i].cromozom_vector[i].DNA[0] << endl
                 << All_Cells[i].cromozom_vector[i].DNA[1] << "}\n";
        }
        All_Cells[iter].Killing_cell();
    }
    case 3:
    {
        cout << "First enter the substring to be changed"
             << "Then enter the new substring ";
        string s1 = correct_RNA_cin();
        string s2 = correct_RNA_cin();
        All_Genomes[iter].Create_big_mutation(s1, s2);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 4:
    {
        cout << "enter substring you want to reverse\n";
        string s1 = correct_RNA_cin();
        All_Genomes[iter].create_reverse_mutation(s1);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 5:
    {
        cout << "Enter the RNA you want crete DNA from:\n";
        string s1 = correct_RNA_cin();
        All_Genomes[iter].Create_DNA(s1);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 6:
    {
        cout << "returning to main menu..." << endl;
        break;
    }
    default:
    {
        cout << "Not a Valid Choice. \n";
        break;
    }
    }
}

// Create a new cell and adding it to the vector
void Create_new_cell()
{
    cout << "Enter first cromozom's DNA\n"
         << "first enter first string of DNA\n"
         << "then enter second string of DNA\n";
    string s1 = correct_RNA_cin();
    string s2 = correct_RNA_cin();
    Cell new_cell(s1, s2);
    All_Cells.push_back(new_cell);
    cout << "Successfully created!\n";
}

// functions wirted in Genome are now accessible!
void Work_with_genome()
{
    if (All_Genomes.size() == 0)
    {
        cout << "First create some genomes!!!\n";
        return;
    }
    cout << "Selcet one Genome\n";
    for (int i = 0; i < All_Genomes.size(); i++)
    {
        cout << i + 1 << ". " << All_Genomes[i].RNA << endl;
    }
    int iter = correct_number_cin(1, All_Genomes.size()) - 1;
    cout << "What do you want to do with this Genome?\n"
         << "1. Print DNA\n"
         << "2. Create small mutation\n"
         << "3. Create_big_mutation\n"
         << "4. Create_reverse_mutation\n"
         << "5. Create a DNA from a RNA\n"
         << "6. Cancel";
    int c = correct_number_cin(1, 6);
    switch (c)
    {
    case 1:
    {
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 2:
    {
        cout << "Which two things do you want to exchange?"
             << "(First, what is now in RNA\n"
             << "Second, what is to be replaced)";
        string A = correct_RNA_cin();
        string C = correct_RNA_cin();
        cout << "How many times should this change be done?\n";
        int n;
        cin >> n;
        All_Genomes[iter].Create_small_mutation(A[0], C[0], n);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 3:
    {
        cout << "First enter the substring to be changed"
             << "Then enter the new substring ";
        string s1 = correct_RNA_cin();
        string s2 = correct_RNA_cin();
        All_Genomes[iter].Create_big_mutation(s1, s2);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 4:
    {
        cout << "enter substring you want to reverse\n";
        string s1 = correct_RNA_cin();
        All_Genomes[iter].create_reverse_mutation(s1);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 5:
    {
        cout << "Enter the RNA you want crete DNA from:\n";
        string s1 = correct_RNA_cin();
        All_Genomes[iter].Create_DNA(s1);
        cout << "Done!\n"
             << "new RNA is:";
        All_Genomes[iter].Print_RNA();
        cout << "\nnew DNA is:";
        All_Genomes[iter].Print_DNA();
        break;
    }
    case 6:
    {
        cout << "returning to main menu..." << endl;
        break;
    }
    default:
    {
        cout << "Not a Valid Choice. \n";
        break;
    }
    }
}

// getting inputs and add a new genome to our genoms!
void Create_new_genome()
{
    string RNA;
    string DNA1, DNA2;
    cout << "input RNA...\n";
    RNA = correct_RNA_cin();
    cout << "input first string of DNA...\n";
    DNA1 = correct_RNA_cin();
    cout << "input second string of DNA...\n";
    DNA2 = correct_RNA_cin();
    Genome my_gen(RNA, DNA1, DNA2);
    All_Genomes.push_back(my_gen);
    cout << "Successfully created!\n";
}

int main()
{
    bool gameOn = true;
    cout << "wellcome to the application\n";
    int choice;
    while (gameOn != false)
    {
        cout << "--------------------------------\n";
        cout << "1-Create a new Genome\n";
        cout << "2-Work with a Genome\n";
        cout << "3-Create a new Cell\n";
        cout << "4-Work with a Cell\n";
        cout << "5-Craete a new Animal\n";
        cout << "6-Work with a Animal\n";
        cout << "--------------------------------\n";
        cout << "Input one number between 1 and 6...\n";
        choice = correct_number_cin(1, 6);
        switch (choice)
        {
        case 1:
            Create_new_genome();
            break;
        case 2:
            Work_with_genome();
            break;
        case 3:
            Create_new_cell();
            break;
        case 4:
            cout << "End of Program.\n";
            gameOn = false;
            break;
        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
        }
    }
}
