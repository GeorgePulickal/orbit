#include <iostream>
#include <cmath>
#include <fstream> 

//define number of dimensions = 3
#define D 3

using namespace std;

// make struct with information about orbiting object
struct planet{
    double mass;
    double position[D];
    double velocity[D];
    double force[D];
    double kinetic;
    double potential;
};

// function headers
void initial_position_impulse(planet& earth);
void initial_velocity_impulse( planet& earth);
void initial_position_circular (planet& earth);
void initial_velocity_circular (planet& earth);
float distance(planet earth);
double kineticE(planet earth);
double potentialE(planet earth, double g_constantM, float d);



int main(){

    //assign filenames for data files to store positions
    char filename1[30] = "positive_x_impulse.dat";
    char filename2[30] = "positive_x_circle.dat";

    // determine the constants
    double g_constantM = 1000; 
    double dt = 0.001;
    int t = 0;
    int iterations = 10000;
    planet earth; 
    earth.mass = 10;


    //initial conditions of the impulsed planet
    initial_position_impulse(earth);
    initial_velocity_impulse(earth);
    

    //open first file to store impulse results
    ofstream fout; 
    fout.open(filename1);


    //perform leapfrog method
    for( int i = 0; i < iterations; i++)
    {
        float d = distance(earth);
        for( int j = 0; j < D; j++)
        {
            earth.position[j] += (dt / 2) * earth.velocity[j];
            earth.force[j] = - (g_constantM * earth.mass * earth.position[j]) / pow(d , 3);
            earth.velocity[j] += dt * (earth.force[j] / earth.mass);
            earth.position[j] += (dt / 2) * earth.velocity[j];
        
            //write the positions of the planet
            fout << earth.position[j] << "\t";
        } 

            t++;

        //write kinetic energy, potential energy, total energy and t counter in datafile
        fout << kineticE(earth) << "\t" << potentialE(earth, g_constantM, d) << "\t" << (kineticE(earth) + potentialE(earth, g_constantM, d))<< "\t" << t << endl;
    }


    //close the file
    fout.close();


    // initial conditions of the circular orbit
    initial_position_circular(earth);
    initial_velocity_circular(earth);

    //repeat process for circular motion
    fout.open(filename2);
    t = 0;

    //leapfrog method
    for( int i = 0; i < iterations; i++)
    {
        float d = distance(earth);
        for( int j = 0; j < D; j++)
        {
            
            earth.position[j] += (dt / 2) * earth.velocity[j];
            earth.force[j] = - (g_constantM * earth.mass * earth.position[j]) / pow(d , 3);
            earth.velocity[j] += dt * (earth.force[j] / earth.mass);
            earth.position[j] += (dt / 2) * earth.velocity[j];
        

            fout << earth.position[j] << "\t";
        }   

            t++;
        fout << kineticE(earth) << "\t" << potentialE(earth, g_constantM, d) << "\t" << (kineticE(earth) + potentialE(earth, g_constantM, d)) << "\t" << t << endl;
    }
    fout.close();



}

void initial_position_impulse ( planet& earth){
    earth.position[0] = 0;
    earth.position[1] = 10;
    earth.position[2] = 0;
}

void initial_velocity_impulse ( planet& earth)
{
    earth.velocity[0] = 11;
    earth.velocity[1] = 0;
    earth.velocity[2] = 0;
}   

void initial_position_circular ( planet& earth)
{
    earth.position[0] = 0;
    earth.position[1] = 10;
    earth.position[2] = 0;
}

void initial_velocity_circular ( planet& earth)
{
    earth.velocity[0] = 10;
    earth.velocity[1] = 0;
    earth.velocity[2] = 0;
}

float distance(planet earth)
{
    float distance1 = sqrt( pow(earth.position[0], 2) + pow(earth.position[1], 2) + pow(earth.position[2], 2));
    return distance1;
}

double kineticE(planet earth)
{
    earth.kinetic = (earth.mass / 2) * (pow(earth.velocity[0], 2) + pow(earth.velocity[1], 2) + pow(earth.velocity[2], 2));
    return earth.kinetic;
}

double potentialE(planet earth, double g_constantM, float d)
{
    earth.potential = - (g_constantM * earth.mass) / d;
    return earth.potential;
}




