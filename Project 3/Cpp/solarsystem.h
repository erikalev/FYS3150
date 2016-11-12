#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "celestialbody.h"
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

class SolarSystem
{
public:
    double G = 4*M_PI*M_PI;
    SolarSystem();
    CelestialBody &createCelestialBody(vec3 position, vec3 velocity, double mass);
    void calculateForcesAndEnergy();
    //void calculateForcesAndEnergyEarthSun();
    void calculateForcesOnePlanet(int planet_number);
    int numberOfBodies() const;
    void calculateAccelerationCircleOnePlanet(int planet_number);
    void calculateForcesGR();

    double totalEnergy() const;
    double potentialEnergy() const;
    double kineticEnergy() const;
    void writeToFile(std::string filename);

    vec3 angularMomentum() const;
    std::vector<CelestialBody> &bodies();

private:
    std::vector<CelestialBody> m_bodies;
    vec3 m_angularMomentum;
    std::ofstream m_file;
    double m_kineticEnergy;
    double m_potentialEnergy;
};

#endif // SOLARSYSTEM_H
