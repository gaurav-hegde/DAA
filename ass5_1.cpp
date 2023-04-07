//Given a weighted graph with the source city '0', write a C++ program to find the approximate shortest tour using approximation algorithm for the train running across various cities marked by the vertices in the graph. Note that, first you have to check whether the graph meets the triangle inequality property or not. For example, for the following graph with the cost adjacency matrix shown, the shortest tour the train has to travel to visit all the cities exactly once starting from 0 and back again to 0 will be 0-1->3->4->2->0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function prototypes
void readGraph(string filename, vector<vector<int> > &graph);
void printGraph(vector<vector<int> > &graph);
void printTour(vector<int> &tour);
bool checkTriangleInequality(vector<vector<int> > &graph);
void findTour(vector<vector<int> > &graph, vector<int> &tour);

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Read graph from file
    vector<vector<int> > graph;
    readGraph(argv[1], graph);

    // Print graph
    cout << "Graph:" << endl;
    printGraph(graph);

    // Check triangle inequality
    if (!checkTriangleInequality(graph))
    {
        cout << "Graph does not meet triangle inequality property." << endl;
        return 1;
    }

    // Find tour
    vector<int> tour;
    findTour(graph, tour);

    // Print tour
    cout << "Tour:" << endl;
    printTour(tour);

    return 0;
}

// Read graph from file

void readGraph(string filename, vector<vector<int> > &graph)
{
    // Open file
    ifstream file(filename.c_str());
    if (!file.is_open())
    {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    // Read graph
    string line;
    while (getline(file, line))
    {
        // Create row
        vector<int> row;

        // Read row
        istringstream iss(line);
        int value;
        while (iss >> value)
        {
            row.push_back(value);
        }

        // Add row to graph
        graph.push_back(row);
    }

    // Close file
    file.close();
}

// Print graph

void printGraph(vector<vector<int> > &graph)
{
    // Print graph
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << setw(3) << graph[i][j];
        }
        cout << endl;
    }
}

// Print tour

void printTour(vector<int> &tour)
{
    // Print tour
    for (int i = 0; i < tour.size(); i++)
    {
        cout << tour[i];
        if (i < tour.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

// Check triangle inequality

bool checkTriangleInequality(vector<vector<int>>)

// Find tour

void findTour(vector<vector<int> > &graph, vector<int> &tour)
{
    // Initialize tour
    tour.push_back(0);

    // Find tour
    while (tour.size() < graph.size())
    {
        // Find next city
        int nextCity = -1;
        int minCost = numeric_limits<int>::max();
        for (int i = 0; i < graph.size(); i++)
        {
            if (find(tour.begin(), tour.end(), i) == tour.end())
            {
                int cost = graph[tour.back()][i];
                if (cost < minCost)
                {
                    nextCity = i;
                    minCost = cost;
                }
            }
        }

        // Add next city to tour
        tour.push_back(nextCity);
    }

    // Add source city to tour
    tour.push_back(0);
}

// Output
