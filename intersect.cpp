#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<int> cover(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cover[i];
    }

    bool is_vertex_cover = true;
    for (int i = 0; i < n; i++)
    {
        if (cover[i] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == 1 && cover[j] == 0)
                {
                    is_vertex_cover = false;
                    break;
                }
            }
        }
    }

    if (is_vertex_cover)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
