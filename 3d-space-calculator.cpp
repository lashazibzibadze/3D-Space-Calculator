/* 
Author: Lasha Zibzibadze
Course: CSCI-135
Instructor: Genady Maryash

This program calculates the  exact cordinates in the 3d space.
*/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;
class Coord3D {
public:
    double x;
    double y;
    double z;
};



double length(Coord3D *p){
    return sqrt(pow((p -> x), 2) + pow((p->y), 2) + pow((p->z), 2)); // Main Logic
}



Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    // double First_point= sqrt(pow((p1 -> x), 2) + pow((p1->y), 2) + pow((p1->z), 2));
    // double Second_point= sqrt(pow((p2 -> x), 2) + pow((p2->y), 2) + pow((p2->z), 2));

    if(length(p2)> length(p1)){
        return p2;
    }
    else{
        return p1;
    }
    

}

void move(Coord3D *ppos, Coord3D *pvel, double dt){

    ppos->x = ppos->x + pvel->x * dt; //Calculates and stores in class.x

    ppos->y = ppos->y + pvel->y * dt; // Calculates and stores in class.y

    ppos->z = ppos->z + pvel->z * dt; //Calcules and stores in class.z


}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D * object = new Coord3D; //New memory allocation
    object->x = x;
    object->y = y; //Filling with the given double variables
    object->z = z;
    return object; // return new sub class of Coord3D


}

void deleteCoord3D(Coord3D *p){
    delete p;
}
int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z); // Allocate the new cordinates using the new function.
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z); // Allocate the new cordinates using the new function.

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); //call new function to clear Coord3D ppos
    deleteCoord3D(pvel); //call new function to clear Coord3D pvel
    return 0;
}