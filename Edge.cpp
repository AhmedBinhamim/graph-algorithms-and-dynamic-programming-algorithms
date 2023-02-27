// Edge.cpp -- class for edge connecting planets

#ifndef EDGE_CPP
#define EDGE_CPP

#include <iostream>

using namespace std;

class Edge 
{
    public:
        int planet1, planet2, distance; // two planets connected and edge wieght

    Edge() {}
    
    Edge(int p1, int p2) 
    {
        planet1 = p1;
        planet2 = p2;
    }

    void setDistance(int d)
    {
        distance = d;
    }

    // Overriding < operator to compare edges by distance
    bool operator <(Edge e) 
    {
        return distance < e.distance;
    }

    // Overriding > operator to compare edges by distance
    bool operator >(Edge e) 
    {
        return distance > e.distance;
    }

    // Overriding operator << to print edges details
    friend ostream& operator<< (ostream& os, Edge e) 
    {
        cout << e.planet1 << " <---> " << e.planet2 << " Distance = " << e.distance << endl;
        return os;
    }
};

#endif