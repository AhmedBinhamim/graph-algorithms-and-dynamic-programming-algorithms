// Planet.cpp -- class for planet in map

#ifndef PLANET_CPP
#define PLANET_CPP

#include <iostream>
#include <list>
#include "Edge.cpp"

using namespace std;

class Planet
{
    public:
        int planet_num;         // Unique planet identifier
        string planet_name;     // planet name
        int x,y,z;              // planet (x,y,x) cooridnates
        int weight, profit;     // planet weight and profit
        float value;            // planet value (profit / weight)
        list<Edge> edgeList;    // list of edges connected to the planet

    Planet() {}

    Planet(string name, int number, int x, int y, int z, int weight, int profit)
    {
        planet_num = number;
        planet_name = name;
        this->x = x;
        this->y = y;
        this->z = z;
        this->weight = weight;
        this->profit = profit;
        // calculating planet value
        if (weight == 0 || profit == 0)
            value = 0;
        else
            value = (float) profit / weight;
    }

    // get planet name by number
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
    
    // print list of planets connected through edges to current planet
    void printEdgeList()
    {
        for (auto it = edgeList.begin(); it != edgeList.end(); it++)
            cout << getPlanetName(it->planet2) << "  ";

        cout << endl;
    }

    // Overriding < operator to compate planets by value
    bool operator <(Planet p) 
    {
        return value < p.value;
    }

    // Overriding << operator to print planet details
    friend ostream& operator<< (ostream& os, Planet& p)
    {
        cout << p.planet_num << ": " << p.planet_name << " (" << p.x << "," << p.y << "," << p.z << ") " << "Weight = " << p.weight << " Profit = " << p.profit << " Value = " << p.value << endl;
        return os;
    }

    // Overloading overriden << operator to print array of planets details
    friend ostream& operator<< (ostream& os, Planet p[])
    {
        for (int i = 0; i < 10; i++)
        cout << p[i].planet_num << ": " << p[i].planet_name << " (" << p[i].x << "," << p[i].y << "," << p[i].z << ") " << "Weight = " << p[i].weight << " Profit = " << p[i].profit << endl;
        return os;
    }
};

#endif
