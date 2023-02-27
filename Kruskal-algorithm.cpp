// Simple C++ implementation for Kruskal's
// algorithm
#include <bits/stdc++.h>
#include "AdjacencyMatrix.cpp"
#include "PriorityQueue.cpp"
using namespace std;

#define PLANETS 10
int cloud[PLANETS];

// checkCloud of vertex i
int checkCloud(int i)
{
    while (cloud[i] != i)
        i = cloud[i];
    return i;
}

// Merge cloud of i and j if 
// they are not already in same cloud
void mergeCloud(int i, int j)
{
    int a = checkCloud(i);
    int b = checkCloud(j);
    cloud[a] = b;
}

// checkClouds MST using Kruskal's algorithm
void kruskalMST(AdjacencyMatrix<Planet> graph)
{
    int distance = 0; // Cost of min MST.

    // make each Planet (vertex) a cloud itself.
    for (int i = 0; i < PLANETS; i++)
        cloud[i] = i;

    int edgeCount = 0;
    // min heap based PQ storing edges
    PriorityQueue<Edge> edges;

    // add edges to PQ
    for (int i = 0; i < graph.edges.size(); i++)
        edges.enqueue(graph.edges.at(i));   

    // Include the edges with minimum distance to the spanning tree
    // u -- planet 1 connected to current edge
    // v -- planet 2 connected to current edge
    int u,v;    
    Edge currentEdge;
    while (edgeCount < PLANETS - 1) {
        currentEdge = edges.dequeue();  // get edge with lowest distance
        u = currentEdge.planet1;
        v = currentEdge.planet2;
        // if the planets are not in the same cloud, merge them
        if (checkCloud(u) != checkCloud(v)) {
            mergeCloud(u, v);
            printf("Edge %d:(%d, %d) distance:%d \n", edgeCount++, u, v, currentEdge.distance);
            distance += currentEdge.distance;
        }
    }
    printf("\nMinimum distance= %d \n", distance);
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

void connect(char m[10][10], int edge_1, int edge_2)
{
    char planet1;
    if(edge_1 == 0)
        planet1 = 'A';
    else if(edge_1 == 1)
        planet1 = 'B';
    else if(edge_1 == 2)
        planet1 = 'C';
    else if(edge_1 == 3)
        planet1 = 'D';
    else if(edge_1 == 4)
        planet1 = 'E';
    else if(edge_1 == 5)
        planet1 = 'F';
    else if(edge_1 == 6)
        planet1 = 'G';
    else if(edge_1 == 7)
        planet1 = 'H';
    else if(edge_1 == 8)
        planet1 = 'I';
    else if(edge_1 == 9)
        planet1 = 'J';

    char planet2;
    if(edge_2 == 0)
        planet2 = 'A';
    else if(edge_2 == 1)
        planet2 = 'B';
    else if(edge_2 == 2)
        planet2 = 'C';
    else if(edge_2 == 3)
        planet2 = 'D';
    else if(edge_2 == 4)
        planet2 = 'E';
    else if(edge_2 == 5)
        planet2 = 'F';
    else if(edge_2 == 6)
        planet2 = 'G';
    else if(edge_2 == 7)
        planet2 = 'H';
    else if(edge_2 == 8)
        planet2 = 'I';
    else if(edge_2 == 9)
        planet2 = 'J';

    int planet1_index_i = 0;
    int planet1_index_j = 0;
    int planet2_index_i = 0;
    int planet2_index_j = 0;

    // get planet index
    for (int i = 0; i <10; i++) {
        for (int j = 0; j < 10; j++) {
            if (m[i][j] == planet1){
                planet1_index_i = i;
                planet1_index_j = j;
            }
            else if (m[i][j] == planet2) {
                planet2_index_i = i;
                planet2_index_j = j;
            }
        }
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j > planet2_index_j) {
        m[planet2_index_i-1][planet2_index_j+1] = '/';
        m[planet2_index_i-2][planet2_index_j+2] = '/';
    }

    if (planet1_index_i > planet2_index_i && planet1_index_j < planet2_index_j) {
        m[planet1_index_i-1][planet1_index_j+1] = '/';
        m[planet1_index_i-2][planet1_index_j+2] = '/';
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j == planet2_index_j) {
        if(planet2_index_i - planet1_index_i == 3)
            m[planet2_index_i-2][planet2_index_j] = '|';
        
        m[planet2_index_i-1][planet2_index_j] = '|';
    }

    if (planet1_index_i < planet2_index_i && planet1_index_j < planet2_index_j) {
        m[planet2_index_i-1][planet2_index_j-1] = '\\';
        m[planet2_index_i-2][planet2_index_j-2] = '\\';
    }

    if (planet1_index_i > planet2_index_i && planet1_index_j > planet2_index_j){
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
    connect(m, 2, 8);
    connect(m, 1, 4);
    connect(m, 7, 8);
    connect(m, 1, 3);
    connect(m, 4, 6);
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

//driver function
int main()
{
    AdjacencyMatrix<Planet> graph;
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
    
    cout << "------------------------------------------------------------------------------------------------------------------" <<endl;
    graph.initAdjMatrix(ps);
    graph.printGraph();
    cout << "------------------------------------------------------------------------------------------------------------------" <<endl;
    
    // Get the miniumum spanning tree edges
    kruskalMST(graph);
    cout << "------------------------------------------------------------------------------------------------------------------" <<endl;
    
    char m[10][10];
    createMap(m); // create original map with all planets
    edges(m); // connect spanning tree edges
    cout << "Minimum Spanning Tree Using Kruskal Algorithm" << endl;
    
    printGraph(m); // print minimum spanning tree
    return 0;
}

