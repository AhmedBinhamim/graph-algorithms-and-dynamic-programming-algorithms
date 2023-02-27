#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Planet.cpp"

using namespace std;

// split planet infor read for file
vector<string> splitPlanetInfo(string planetInfo) 
{   
    vector<string> pInfo;
    string info = "";
    for (auto f : planetInfo) {
        if (f == ' ') {
            pInfo.push_back(info);
            info = "";
        }
        else
            info += f;
    }
    
    pInfo.push_back(info);

    return pInfo;
}

// find optimal solution for 0/1 knapsack
void knapSack(Planet planets[], int shipSize, int n)
{
    int totalProfit;    // knapsack solution
    int matrix[n+1][shipSize+1];    // knapsack matrix

    // fill the knapsack matrix with appropriate values
    for (int i = 0; i <= n; i++) {
        // line (Planet index) number
        cout << "Line " << setw(2) << i << ": ";
        for (int w = 0; w <= shipSize; w++) {
            // if no items or no weight
            if (i == 0 || w == 0)
                matrix[i][w] = 0;
            // if current planet weight is less than or equal to current weight
            else if (planets[i-1].weight <= w) {
                // find optimal value (include current planet or no)
                matrix[i][w] = max(matrix[i-1][w], matrix[i-1][w-planets[i-1].weight] + planets[i-1].profit);
            }
            // if current planet weight exceeds current weight
            else
                matrix[i][w] = matrix[i-1][w];

            cout << setw(3) << matrix[i][w] << " ";
        }
        cout << endl << endl;
    }    

    // traceback the matrix from bottom to up
    // to find out which planets got selected
    // and their respective weight
    int remW = shipSize;
    totalProfit = matrix[n][shipSize];
    for (int i = n; i > 0 && totalProfit > 0; i--) {
        if (matrix[i-1][remW] == totalProfit) {
            continue;
        }
        else {
            cout << "Planet " << planets[i-1].planet_num  << " Selected: Weight = " << planets[i-1].weight << " Profit = " << planets[i-1].profit << endl;
            remW -= planets[i-1].weight;
            totalProfit -= planets[i-1].profit;
        }
    }

    // print final solution
    cout << "\nTotal Weight: " << shipSize - remW;
    cout << "\nTotla Profit: " << matrix[n][shipSize];
}

int main() 
{
    string data;    // data line read from text file
    vector<string> p_info; // planet information
    const int n = 10; 
    Planet ps[n];
    ifstream file;
    int count = 0, shipSize = 80;

    file.open("A2planets.txt");
    while(getline(file, data)) {
        // seperate planet information
        p_info = splitPlanetInfo(data);
        // create planet
        Planet p(p_info.at(0), count,  stoi(p_info.at(1)), stoi(p_info.at(2)), stoi(p_info.at(3)), stoi(p_info.at(4)), stoi(p_info.at(5)));
        ps[count] = p;
        count++;
    }
    file.close();

    // find optimal solution for 0/1 knapsack
    cout << "List of planets: " << endl;
    cout << ps << endl;
    knapSack(ps, shipSize, n);
}