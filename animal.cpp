#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "Genome.h"

using namespace std;

class Animal : public Cell
{
private:
    int my_ceil(double f)
    {
        if (f <= int(f))
            return f;
        else
            return int(f) + 1;
    }

public:
    vector<Cell> cells_vector;
    vector<*Animal> childs_vector;
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
    //return true if Animals are enough similar 
    bool operator==(const Animal a)
    {
        if (cells_vector.size() != a.cells_vector.size())
            return false;
        if (Similarity_cells(a) < 0.70)
            return false;
        return true;
    }
    //new child object from what we already have
    void make_Asexual_reproduction()
    {
        Animal *new_child = new Animal;
        for (int i = 0; i < this->cells_vector.size(); i++)
        {
            new_child->cells_vector.push_back(this->cells_vector[i]);
            new_child->cells_vector.push_back(this->cells_vector[i]);
        }
        double n = new_child->cells_vector.size();
        int m = my_ceil(n / 100.0 * 72.0);
        for (int i = m; i < n; i++)
        {
            for (int j = 0; j < new_child->cells_vector[i].cromozom_vector.size(); j++)
            {
                new_child->cells_vector[i].cromozom_vector[j].DNA[0] = Create_random_cromozom(new_child->cells_vector[i].cromozom_vector[j].DNA[0].size());
                new_child->cells_vector[i].cromozom_vector[j].DNA[1] = create_second_DNA_from_first_DNA(new_child->cells_vector[i].cromozom_vector[j].DNA[0]);
            }
        }
        this->childs_vector.push_back(new_child);
    }
};

int main()
{
}