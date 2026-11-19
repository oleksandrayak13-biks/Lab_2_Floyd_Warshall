#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int N = 7;
const int INF = 1000000000;

int main()
{
    system("chcp 1251 > nul");
    // Граф за варіантом 18 (Додаток 1)
    const int graphSize = 5;

    int adjacencyMatrix[graphSize][graphSize] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };

    cout << "Граф за варіантом 18 (Додаток 1)" << endl;
    cout << "Матриця суміжності:" << endl;

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            cout << adjacencyMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nСписок ребер графа:" << endl;

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << i + 1 << " -> " << j + 1 << endl;
            }
        }
    }

    cout << "\n----------------------------------------\n" << endl;


    vector<vector<int>> dist(N, vector<int>(N));

    cout << "Алгоритм Флойда–Уоршелла " << endl;

    vector<vector<vector<int>>> matrices =
    {
        // Матриця 1
        {
            {0, INF, INF, INF, INF, INF, INF},
            {1, 0, -1, 5, INF, INF, INF},
            {2, 4, 0, 3, INF, -2, 6},
            {7, 8, -4, 0, INF, INF, INF},
            {INF, 10, INF, 11, 0, INF, 9},
            {12, INF, 13, INF, 14, 0, INF},
            {-5, 15, INF, -6, INF, 16, 0}
        },

        // Матриця 2
        {
            {0, INF, 1, INF, 3, INF, 4},
            {INF, 0, INF, 5, INF, INF, INF},
            {2, INF, 0, INF, INF, -2, 6},
            {7, 8, INF, 0, INF, INF, INF},
            {INF, 10, INF, 11, 0, INF, 9},
            {12, INF, 13, INF, INF, 0, INF},
            {-3, 14, INF, -1, INF, INF, 0}
        },

        // Матриця 3
        {
            {0, INF, 1, INF, 15, INF, INF},
            {INF, 0, -1, 3, INF, 4, INF},
            {2, INF, 0, -2, INF, INF, 6},
            {7, 8, 5, 0, INF, INF, INF},
            {INF, 10, INF, 11, 0, INF, 9},
            {12, INF, 13, INF, 14, 0, INF},
            {15, INF, INF, -6, INF, -3, 0}
        },

        // Матриця 4
        {
            {0, INF, 1, INF, 3, INF, 4},
            {2, 0, INF, 5, INF, INF, INF},
            {-2, INF, 0, INF, INF, -2, 6},
            {INF, 8, INF, 0, INF, INF, INF},
            {INF, INF, INF, 7, 0, INF, 9},
            {11, INF, 12, INF, INF, 0, INF},
            {INF, -4, INF, -1, INF, 10, 0}
        },

        // Матриця 5
        {
            {0, 1, 2, 7, INF, 12, INF},
            {INF, 0, -1, 5, INF, INF, INF},
            {INF, INF, 0, 3, INF, 4, 6},
            {INF, 8, -4, 0, INF, INF, INF},
            {INF, 10, INF, 11, 0, INF, 9},
            {INF, INF, 13, INF, 14, 0, INF},
            {-5, 15, INF, -6, INF, 16, 0}
        },

        // Матриця 6
        {
            {0, 2, -5, INF, INF, INF, 4},
            {1, 0, INF, 5, INF, INF, INF},
            {3, INF, 0, INF, INF, -2, 6},
            {7, 8, INF, 0, INF, INF, -4},
            {INF, -1, INF, 11, 0, INF, 9},
            {10, INF, 12, INF, INF, 0, INF},
            {-3, INF, INF, INF, INF, INF, 0}
        },

        // Матриця 7
        {
            {0, INF, INF, INF, INF, INF, INF},
            {INF, 0, 5, INF, INF, INF, INF},
            {2, INF, 0, INF, INF, -2, 6},
            {7, 8, INF, 0, INF, INF, INF},
            {INF, 10, INF, INF, 0, INF, 9},
            {12, INF, 13, INF, INF, 0, INF},
            {-5, 15, INF, -6, INF, INF, 0}
        },

        // Матриця 8
        {
            {0, INF, 1, INF, 3, INF, 4},
            {INF, 0, INF, INF, INF, INF, INF},
            {2, INF, 0, INF, INF, -2, 6},
            {7, 8, INF, 0, INF, INF, INF},
            {INF, 10, INF, 11, 0, INF, 9},
            {INF, INF, INF, INF, INF, 0, INF},
            {-3, 14, INF, -1, INF, INF, 0}
        },

        // Матриця 9
        {
            {0, INF, 1, INF, 3, INF, 4},
            {INF, 0, 2, 5, INF, 7, INF},
            {INF, 12, 0, INF, INF, -2, 6},
            {INF, 8, INF, 0, 13, INF, INF},
            {INF, 10, INF, 11, 0, -3, 9},
            {INF, INF, INF, INF, INF, 0, INF},
            {INF, 14, INF, -1, INF, INF, 0}
        },

        // Матриця 10
        {
            {0, INF, INF, INF, 3, INF, 4},
            {INF, 0, -1, INF, INF, INF, INF},
            {2, 5, 0, INF, 8, -2, 6},
            {7, INF, 12, 0, INF, 11, INF},
            {INF, 1, INF, 10, 0, INF, 9},
            {INF, INF, INF, -4, INF, 0, INF},
            {8, INF, -3, 10, INF, INF, 0}
        }
    };

    while (true)
    {
    cout << "\nОберіть матрицю для обчислення:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " - Тестова матриця " << i + 1 << endl;
    }

    string choiceInput;

    cout << "\nВаш вибір (1-10 або ESC для виходу): ";
    cin >> choiceInput;

    if (choiceInput == "ESC" || choiceInput == "esc" || choiceInput == "Esc")
    {
        cout << "Програму завершено." << endl;
        break;
    }

    int choice;
    stringstream ss(choiceInput);

    if (!(ss >> choice) || !ss.eof() || choice < 1 || choice > 10)
    {
        cout << "Помилка! Введіть число від 1 до 10 або ESC." << endl;
        continue;
    }

    // Завантаження обраної матриці
    dist = matrices[choice - 1];

    cout << "\nОбрано тестову матрицю " << choice << endl;
    cout << "\nВведена матриця відстаней:" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
    // Створення матриці найкоротших шляхів
    vector<vector<int>> nextVertex(N, vector<int>(N, -1));

    // Заповнення початкової матриці шляхів
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                nextVertex[i][j] = i;
            }
            else if (dist[i][j] != INF)
            {
                nextVertex[i][j] = j;
            }
        }
    }

    // Алгоритм Флойда — Воршелла
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        nextVertex[i][j] = nextVertex[i][k];
                    }
                }
            }
        }
    }
    bool hasNegativeCycle = false;

    for (int i = 0; i < N; i++)
    {
        if (dist[i][i] < 0)
        {
            hasNegativeCycle = true;
        }
    }
    vector<vector<bool>> negativeCyclePath(N, vector<bool>(N, false));

    for (int k = 0; k < N; k++) {
        if (dist[k][k] < 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        negativeCyclePath[i][j] = true;
                    }
                }
            }
        }
    }

    if (hasNegativeCycle)
    {
        cout << "\n!У графі є від'ємний цикл!" << endl;
    }
    else
    {
        cout << "\nВід'ємних циклів немає" << endl;
    }
    cout << "\nМатриця мінімальних відстаней:" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (negativeCyclePath[i][j])
            {
                cout << "-INF\t";
            }
            else if (dist[i][j] == INF)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "\nМатриця найкоротших шляхів:" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (nextVertex[i][j] == -1)
                cout << "INF\t";
            else
                cout << nextVertex[i][j] + 1 << "\t";
        }
        cout << endl;
    }
    // Введення вершин для пошуку шляху
    int start, finish;

    cout << "\nВведіть початкову вершину (1-7): ";
    cin >> start;

    cout << "Введіть кінцеву вершину (1-7): ";
    cin >> finish;

    // Перевірка правильності введення
    if (start < 1 || start > N || finish < 1 || finish > N)
    {
        cout << "Помилка! Неправильно введено номер вершин" << endl;
        return 1;
    }

    // Пошук найкоротшого маршруту
    int current = start - 1;
    int target = finish - 1;

    if (negativeCyclePath[current][target])
    {
        cout << "Неможливо визначити скінченну мінімальну відстань через від'ємний цикл" << endl;
    }
    else if (nextVertex[current][target] == -1)
    {
        cout << "Шляху між цими вершинами не існує" << endl;
    }
    else
    {
        cout << "\nНайкоротший шлях: ";

        cout << start;

        int steps = 0;

        while (current != target && steps < N)
        {
            current = nextVertex[current][target];

            if (current == -1)
                break;

            cout << " -> " << current + 1;
            steps++;
        }

        cout << "\nМінімальна відстань: "
            << dist[start - 1][finish - 1] << endl;
    }
       } // Кінець циклу вибору матриці

       return 0;
}