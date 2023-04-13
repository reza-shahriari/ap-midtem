#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "Genome.h"

using namespace std;

class Animal : public Cell
{
public:
    vector<Cell> cells_vector;
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
    double Similarity_cells(int n, int m)
    {
        int min_size = min(cells_vector[n].cromozom_vector.size(), cells_vector[m].cromozom_vector.size());
        int max_size = max(cells_vector[n].cromozom_vector.size(), cells_vector[m].cromozom_vector.size());
        vector<double> result_maker;
        for (int i = 0; i < min_size; i++)
        {
            double p1 = Find_string_similarity_percent(cells_vector[n].cromozom_vector[i].DNA[0], cells_vector[m].cromozom_vector[i].DNA[0]);
            double p2 = Find_string_similarity_percent(cells_vector[n].cromozom_vector[i].DNA[1], cells_vector[m].cromozom_vector[i].DNA[1]);
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
};

int main()
{
}