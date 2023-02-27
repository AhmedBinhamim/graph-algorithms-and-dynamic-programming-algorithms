#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "AdjacencyList.cpp"
#include "AdjacencyMatrix.cpp"

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

// print passed vector of elements (planets/edges)
template <typename T>
void printVector (vector<T> elements) 
{
    for (int i = 0; i < elements.size(); i++)
        cout << elements.at(i);

    cout << endl;
}

//  merge passed array of elements (planets/edges)
template <typename T>
void merge (T A[], T Temp[], int p, int m, int r) 
{
    int i, j;
    for (i = m + 1; i > p; i--)
        Temp[i - 1] = A[i - 1];
    for (j = m; j < r; j++)
        Temp [r + m - j] = A[j + 1];
    
    for (int k = p; k <= r; k++)
        if (Temp[j] < Temp [i])
            A[k] = Temp[j--];
        else
            A[k] = Temp[i++];
}

//  merge sort passed array of elements (planets/edges)
template <typename T>
void mergesort (T A[], T Temp[], int p, int r) 
{
    if (p < r) {
        int m = (p + r) / 2;
        mergesort(A, Temp, p , m);
        mergesort(A, Temp, m+1 , r);
        merge(A, Temp, p, m, r);
    }
}

//  start merge sort on passed vector of elements (planets/edges)
template <typename T>
void startMergeSort (vector<T> elements)
{
    int size = elements.size();
    T A[size];
    T* Temp = new T[size];
    
    // make an array of the passed vector
    for (int i = 0; i < size; i++)
        A[i] = elements.at(i);

    mergesort (A, Temp, 0, size-1);
    
    // convert back the array to vector after sorted
    for (int i = 0; i < size; i++)
        elements.at(i) = A[i];

    printVector(elements);

    delete [] Temp;
}

int main() 
{
    AdjacencyMatrix<Planet> matrix; // Graph with adjacency matrix implementation
    AdjacencyList<Planet> map;      // Graph with adjacency list implementation
    string data;    // data line read from text file
    vector<string> p_info;  // planet information
    const int n = 10; 
    Planet ps[n];
    ifstream file;
    int count = 0;

    // reading planets from text file
    file.open("A2planets.txt");
    while(getline(file, data)) {
        // seperate planet information
        p_info = splitPlanetInfo(data);
        // create planet
        Planet p(p_info.at(0), count, stoi(p_info.at(1)), stoi(p_info.at(2)), stoi(p_info.at(3)), stoi(p_info.at(4)), stoi(p_info.at(5)));
        ps[count] = p;
        count++;
    }
    file.close();
    
    // initialise adjacency list
    map.initAdjList(ps);
    // print adjacency list
    map.printGraph();
    cout << endl << endl;
    
    // initialise adjacency matrix
    matrix.initAdjMatrix(ps);
    // print adjacency list
    matrix.printGraph();
    cout << endl;

    // sort graph edges
    cout << "List of Edges Sorted: " << endl;
    startMergeSort(map.edges);
    
    // sort graph planets
    cout << "List of Planets Sorted: " << endl;
    startMergeSort(map.planets);

    return 0;
}