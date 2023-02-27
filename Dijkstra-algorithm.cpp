#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "AdjacencyList.cpp"
using namespace std;

typedef pair<int, int> iPair; // Create an Integer Pair

void addEdge(vector<pair<int, int>> adjList[], int u, int v, int wt)
{
    adjList[u].push_back(make_pair(v, wt));
    adjList[v].push_back(make_pair(u, wt));
}

string getPlanetName(int planet_num)
{
    switch (planet_num)
    {
        case 0:
            return "PLANET_A";
        case 1:
            return "PLANET_B";
        case 2:
            return "PLANET_C";
        case 3:
            return "PLANET_D";
        case 4:
            return "PLANET_E";
        case 5:
            return "PLANET_F";
        case 6:
            return "PLANET_G";
        case 7:
            return "PLANET_H";
        case 8:
            return "PLANET_I";
        case 9:
            return "PLANET_J"; 
    }
}
   
void Dijkstra(vector<pair<int,int> > adjList[], int startingPlanet)
{
    // Create Priority Queue that will automatically sort planets
    priority_queue <iPair, vector<iPair>, greater<iPair>> pq;
  
    // Initalize the distances vector to have all distances to be 999999
    vector<int> distances(10, 999999);
  
    // Insert Planet A as the source aswell as its distance as 0
    pq.push(make_pair(0, startingPlanet));
    distances[startingPlanet] = 0;
  
    // Iterate through priority queue until all distances are finalized
    while (!pq.empty()) {
        // First value is minimum distance, second value is the name of the planet
        int u = pq.top().second; 
        pq.pop();

        // Get all adjacents from u
        for (auto x : adjList[u]) {
            int v = x.first;
            int weight = x.second;
            if (distances[v] > distances[u] + weight) {
                // Updating distance of v
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
    
    // Display shortest distances from the Distance array
    printf("Shortest Distances From Planet A\n");
    for (int i = 0; i < 10; ++i)
        cout << getPlanetName(i) << ":\t" << distances[i] << endl;
}

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

void printGraph(char m[10][10])
{
    for (int i = 0; i <10; i++) {
        for (int j = 0; j < 10; j++){
            cout << m[i][j];
        }
        cout << endl;
    }
}

void createMap(char m[10][10])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(i == 0 && j == 4)
                m[i][j] = 'A';
            else if ( i == 2 && j == 1)
                m[i][j] = 'F';
            else if ( i == 2 && j == 4)
                m[i][j] = 'G';
            else if ( i == 2 && j == 7)
                m[i][j] = 'J';
            else if ( i == 5 && j == 1)
                m[i][j] = 'C';
            else if ( i == 5 && j == 4)
                m[i][j] = 'H';
            else if ( i == 5 && j == 7)
                m[i][j] = 'E';
            else if ( i == 8 && j == 1)
                m[i][j] = 'I';
            else if ( i == 8 && j == 4)
                m[i][j] = 'D';
            else if ( i == 8 && j == 7)
                m[i][j] = 'B';
            else
                m[i][j] = ' ';
        }
    }
}

void connect(char m[10][10], int p1_num, int p2_num)
{
    char planet1;
    if(p1_num == 0)
        planet1 = 'A';
    else if(p1_num == 1)
        planet1 = 'B';
    else if(p1_num == 2)
        planet1 = 'C';
    else if(p1_num == 3)
        planet1 = 'D';
    else if(p1_num == 4)
        planet1 = 'E';
    else if(p1_num == 5)
        planet1 = 'F';
    else if(p1_num == 6)
        planet1 = 'G';
    else if(p1_num == 7)
        planet1 = 'H';
    else if(p1_num == 8)
        planet1 = 'I';
    else if(p1_num == 9)
        planet1 = 'J';

    char planet2;
    if(p2_num == 0)
        planet2 = 'A';
    else if(p2_num == 1)
        planet2 = 'B';
    else if(p2_num == 2)
        planet2 = 'C';
    else if(p2_num == 3)
        planet2 = 'D';
    else if(p2_num == 4)
        planet2 = 'E';
    else if(p2_num == 5)
        planet2 = 'F';
    else if(p2_num == 6)
        planet2 = 'G';
    else if(p2_num == 7)
        planet2 = 'H';
    else if(p2_num == 8)
        planet2 = 'I';
    else if(p2_num == 9)
        planet2 = 'J';

    int planet1_index_i = 0;
    int planet1_index_j = 0;
    int planet2_index_i = 0;
    int planet2_index_j = 0;

    // get planet index
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (m[i][j] == planet1) {
                planet1_index_i = i;
                planet1_index_j = j;
            }
            else if (m[i][j] == planet2) {
                planet2_index_i = i;
                planet2_index_j = j;
            }
        }
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j > planet2_index_j ) {
        m[planet2_index_i-1][planet2_index_j+1] = '/';
        m[planet2_index_i-2][planet2_index_j+2] = '/';
    }

    if (planet1_index_i > planet2_index_i && planet1_index_j < planet2_index_j ) {
        m[planet1_index_i-1][planet1_index_j+1] = '/';
        m[planet1_index_i-2][planet1_index_j+2] = '/';
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j == planet2_index_j) {
        if(planet2_index_i - planet1_index_i == 3)
            m[planet2_index_i-2][planet2_index_j] = '|';
        
        m[planet2_index_i-1][planet2_index_j] = '|';
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j < planet2_index_j ) {
        m[planet2_index_i-1][planet2_index_j-1] = '\\';
        m[planet2_index_i-2][planet2_index_j-2] = '\\';
    }

    if (planet1_index_i > planet2_index_i && planet1_index_j > planet2_index_j) {
        m[planet1_index_i-1][planet1_index_j-1] = '\\';
        m[planet1_index_i-2][planet1_index_j-2] = '\\';
    }

    if (planet1_index_i > planet2_index_i && planet1_index_j == planet2_index_j) {
       if(planet1_index_i - planet2_index_i == 3)
            m[planet1_index_i-2][planet1_index_j] = '|';
        
        m[planet1_index_i-1][planet1_index_j] = '|';
    }

    if (planet1_index_i == planet2_index_i && planet1_index_j != planet2_index_j) {
        m[planet1_index_i][planet1_index_j-1] = '-';
        m[planet1_index_i][planet1_index_j-2] = '-';
    }
}

void edges(char m[10][10])
{
    connect(m, 0,5);
    connect(m, 0, 6);
    connect(m, 0, 9);
    connect(m, 6, 7);
    connect(m, 6, 2);
    connect(m, 1, 4);
    connect(m, 7, 8);
    connect(m, 1, 3);
    connect(m, 4, 6);
}  

int main()
{
    AdjacencyList<Planet> map;
    string data;
    vector<string> p_info;
    const int n = 10; 
    Planet ps[n];
    ifstream file;
    int count = 0;

    file.open("A2planets.txt");
    while(getline(file, data)) {
        p_info = splitPlanetInfo(data);
        Planet p(p_info.at(0), count,  stoi(p_info.at(1)), stoi(p_info.at(2)), stoi(p_info.at(3)), stoi(p_info.at(4)), stoi(p_info.at(5)));
        ps[count] = p;
        count++;
    }
    file.close();

    map.initAdjList(ps);

    vector<iPair> adj[10];
    // Adding all edges
    for (int i = 0; i < map.edges.size(); i++)
        addEdge(adj, (map.edges.at(i).planet1), (map.edges.at(i).planet2), map.edges.at(i).distance); 
    
    // passing adjency list and planet A
    Dijkstra(adj, 0);

    char m[10][10];
    createMap(m);
    // Connect edges of the planets 
    edges(m);
    cout << "\nGraph showing shortest distances from planet A to other planets: \n" << endl;
    // Display the graph
    printGraph(m);
    
    return 0;
}