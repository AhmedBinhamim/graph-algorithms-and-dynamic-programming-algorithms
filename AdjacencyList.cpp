// AdjacencyList.cpp -- graph actual implementation in memory using adjacency list

#ifndef ADJACENCYLIST_CPP
#define ADJACENCYLIST_CPP

#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
#include "Planet.cpp"

using namespace std;

template <typename>
class AdjacencyList
{
    public:
        vector<Edge> edges;     // list of edges the graph contains
        vector<Planet> planets; // list of planets the graph contains
    
    // initialise adjacency list by adding planets(vertices) to the graph
    // and adding edges to connect planets
    void initAdjList(Planet p[])
    {
        for (int i = 0; i < 10; i++)
            addPlanet(p[i]);

        addEdge(p[0].planet_num, p[5].planet_num);
        addEdge(p[0].planet_num, p[6].planet_num);
        addEdge(p[0].planet_num, p[9].planet_num);
        addEdge(p[5].planet_num, p[2].planet_num);
        addEdge(p[5].planet_num, p[7].planet_num);
        addEdge(p[6].planet_num, p[2].planet_num);
        addEdge(p[6].planet_num, p[7].planet_num);
        addEdge(p[6].planet_num, p[4].planet_num);
        addEdge(p[9].planet_num, p[7].planet_num);
        addEdge(p[9].planet_num, p[4].planet_num);
        addEdge(p[2].planet_num, p[8].planet_num);
        addEdge(p[7].planet_num, p[8].planet_num);
        addEdge(p[7].planet_num, p[1].planet_num);
        addEdge(p[4].planet_num, p[1].planet_num);
        addEdge(p[1].planet_num, p[3].planet_num);
        addEdge(p[8].planet_num, p[3].planet_num);
    }

    // to add planet to the graph
    void addPlanet(Planet planet)
    {
        planets.push_back(planet);
    }

    // to add edge to the graph
    void addEdge(int fromPlanet, int toPlanet)
    {
        Edge newEdge(fromPlanet, toPlanet); // create the new edge to be added
        newEdge.setDistance(calculateDistance(fromPlanet, toPlanet));
        edges.push_back(newEdge); // add edge to egdes list
        for (int i = 0; i < planets.size(); i++) {
            // if current planet is source planet
            if (planets.at(i).planet_num == fromPlanet) {
                Edge e(fromPlanet, toPlanet);
                e.distance = newEdge.distance;
                planets.at(i).edgeList.push_back(e);
            }
            // if current planet is destination planet
            else if (planets.at(i).planet_num == toPlanet) {
                Edge e(toPlanet, fromPlanet);
                e.distance = newEdge.distance;
                planets.at(i).edgeList.push_back(e);
            }
        }
    }

    // print adjacency list
    void printGraph()
    {
        for (int i = 0; i < planets.size(); i++) {
            Planet temp;
            temp = planets.at(i);
            cout << i << ": " << temp.planet_name << "  ";
            temp.printEdgeList();
        }
    }

    // to get a planet from planets list by its number
    Planet getPlanetByPNum(int p_num)
    {
        Planet temp;
        for (int i = 0; i < planets.size(); i++) {
            temp = planets.at(i);
            if (temp.planet_num == p_num)
                return temp;
        }
        
        return temp;
    }

    // to calculate distance (edge weight) between two planets
    int calculateDistance(int source, int destination)
    {
        Planet p1 = getPlanetByPNum(source);
        Planet p2 = getPlanetByPNum(destination);
        int x = pow((p2.x - p1.x), 2);
        int y = pow((p2.y - p1.y), 2);
        int z = pow((p2.z - p1.z), 2);
        int d = sqrt(x + y + z);

        return d;
    }
};

#endif