#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "Genome.h"

using namespace std;

class Animal : public Cell
{
private:
    Animal *Radomize_with_inputed_similarity(Animal *parent, double Max_len, double Sim_per)
    {
        vector<Cell> tmp;
        Animal *new_child = new Animal;
        int m = my_ceil(Max_len / 100.0 * Sim_per);
        for (int i = 0; i < m; i++)
        {
            new_child->cells_vector.push_back(parent->cells_vector[i]);
            tmp.push_back(parent->cells_vector[i]);
        }
        for (int i = m; i < parent->cells_vector.size(); i++)
        {
            tmp.push_back(parent->cells_vector[i]);
            tmp.push_back(parent->cells_vector[i]);
        }
        int F = tmp.size();
        for (int i = m; i < Max_len; i++)
        {
            int random = rand() % F;
            new_child->cells_vector.push_back(tmp[random]);
            tmp.erase(tmp.begin() + random);
        }
        return new_child;
    }
    int my_ceil(double f)
    {
        if (f <= int(f))
            return f;
        else
            return int(f) + 1;
    }

public:
    vector<Cell> cells_vector;

    vector<Animal *> childs_vector;
    Animal() : Cell()
    {
    }
    // finding distance between two strings using DP
    int Get_distance(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        int T[m + 1][n + 1];
        for (int i = 1; i <= m; i++)
        {
            T[i][0] = i;
        }

        for (int j = 1; j <= n; j++)
        {
            T[0][j] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int weight = s1[i - 1] == s2[j - 1] ? 0 : 1;
                T[i][j] = min(min(T[i - 1][j] + 1, T[i][j - 1] + 1), T[i - 1][j - 1] + weight);
            }
        }

        return T[m][n];
    }
    // getting percentage of similarity between two strings
    double Find_string_similarity_percent(string s1, string s2)
    {
        double max_length = max(s1.length(), s2.length());
        if (max_length > 0)
        {
            return (max_length - Get_distance(s1, s2)) / max_length;
        }
        return 1.0;
    }
    // finding Similarity between two cells
    // comparing all cromozoms in cells
    double Similarity_cells(Animal a)
    {
        int n = a.cells_vector.size();
        int m = this->cells_vector.size();
        int min_size = min(n, m);
        int max_size = max(n, m);
        vector<double> result_maker;
        for (int i = 0; i < min_size; i++)
        {
            double p1 = Find_string_similarity_percent(a.cromozom_vector[i].DNA[0], this->cromozom_vector[i].DNA[0]);
            double p2 = Find_string_similarity_percent(a.cromozom_vector[i].DNA[1], this->cromozom_vector[i].DNA[1]);
            result_maker.push_back(p1);
            result_maker.push_back(p2);
        }
        for (int i = min_size; i < max_size; i++)
        {
            result_maker.push_back(0);
            result_maker.push_back(0);
        }
        int N = result_maker.size();
        double cal = 0;
        for (int i = 0; i < N; i++)
        {
            cal += result_maker[i];
        }
        return (cal / N);
    }
    // return true if Animals are enough similar
    bool operator==(const Animal a)
    {
        if (cells_vector.size() != a.cells_vector.size())
            return false;
        if (Similarity_cells(a) < 0.70)
            return false;
        return true;
    }
    // new child object from what we already have
    Animal *Make_asexual_reproduction(bool add)
    {
        Animal *new_child = new Animal;
        new_child = Radomize_with_inputed_similarity(this, this->cells_vector.size(), 72);
        if (add)
            this->childs_vector.push_back(new_child);
        return new_child;
    }
    // make sexual representation of tow animals and returning the children
    // if they are enough similar
    Animal *operator+(Animal M)
    {
        if (M.cells_vector.size() != this->cells_vector.size())
        {
            cout << "diffrent cromozoms... cant make sexual reproduction\n";
            return;
        }
        Animal *tmp1 = this->Make_asexual_reproduction(false);
        Animal *tmp2 = M.Make_asexual_reproduction(false);
        if (tmp1->cells_vector.size() % 2 != 0)
        {
            cout << "cromozoms number should be ODD\n";
            return;
        }
        tmp1 = tmp1->Radomize_with_inputed_similarity(tmp1, tmp1->cells_vector.size() / 2, 72);
        if (tmp2->cells_vector.size() % 2 != 0)
        {
            cout << "cromozoms number should be ODD\n";
            return;
        }
        tmp2 = tmp2->Radomize_with_inputed_similarity(tmp1, tmp1->cells_vector.size() / 2, 72);
        Animal *tmp3 = new Animal;
        for (int i = 0; i < tmp1->cells_vector.size(); i++)
        {
            tmp3->cells_vector.push_back(tmp1->cells_vector[i]);
        }
        for (int i = 0; i < tmp2->cells_vector.size(); i++)
        {
            tmp3->cells_vector.push_back(tmp2->cells_vector[i]);
        }
    }
    void AddCell(Cell cell)
    {
        this->cells_vector.push_back(cell);
    }
};

