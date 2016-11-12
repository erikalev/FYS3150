#include "solarsystem.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Class for the entire solar system. Has properties like total energy and total angular momentum. This is where the force on each celestial body is calculated.
 */

SolarSystem::SolarSystem() :
    m_kineticEnergy(0),
    m_potentialEnergy(0)
{
}

CelestialBody& SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass) {
    m_bodies.push_back( CelestialBody(position, velocity, mass) );
    return m_bodies.back(); // Return reference to the newest added celstial body
}


void SolarSystem::calculateForcesAndEnergy()
{
    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_angularMomentum.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force.zeros();
    }

    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = m_bodies[i];
        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = m_bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();
            vec3 force = -G*body1.mass*body2.mass/(dr*dr*dr)*deltaRVector;
            body1.force += force;
            body2.force -= force;
            m_potentialEnergy += G*body1.mass*body2.mass/dr;
        }
        m_angularMomentum += body1.mass*body1.position.cross(body1.velocity);
        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();
    }
    // Uncomment these lines for a stationary star
    //vec3 force_sun = vec3(0, 0, 0);
    //m_bodies[0].force = force_sun;
}
void SolarSystem::calculateForcesGR(){

        for(CelestialBody &body : m_bodies) {
            // Reset forces on all bodies
            body.force.zeros();
        }

        for(int i=0; i<numberOfBodies(); i++) {
            CelestialBody &body1 = m_bodies[i];
            for(int j=i+1; j<numberOfBodies(); j++) {
                CelestialBody &body2 = m_bodies[j];
                vec3 deltaRVector = body1.position - body2.position;
                double dr = deltaRVector.length();
                vec3 l_vec = body1.position.cross(body1.velocity);
                double l = l_vec.length();
                double c = 63239.7263;
                vec3 force = - G*body1.mass/(dr*dr*dr)*deltaRVector*(1 + 3*l*l/(dr*dr*c*c));//- G*body1.mass*body2.mass/(dr*dr*dr)*deltaRVector*3*l*l/(dr*dr*c*c);
                body1.force += force;
                body2.force -= force;
            }
        }
}

void SolarSystem::calculateAccelerationCircleOnePlanet(int planet_number)
{
    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_angularMomentum.zeros();

    double v = m_bodies[planet_number].velocity.length();
    double r = m_bodies[planet_number].position.length();

    m_bodies[planet_number].force = -v*v/(r*r)*m_bodies[planet_number].position;

    m_kineticEnergy = 0.5*m_bodies[planet_number].mass*m_bodies[planet_number].velocity.lengthSquared();
    m_potentialEnergy = G*m_bodies[planet_number].mass/m_bodies[planet_number].position.length();
    m_angularMomentum = m_bodies[planet_number].mass*m_bodies[planet_number].position.cross(m_bodies[planet_number].velocity);
}

void SolarSystem::calculateForcesOnePlanet(int planet_number)
{
    m_bodies[planet_number].force.zeros();
    int numbodies = numberOfBodies();
    for (int i = 0; i < numbodies; i++){
        CelestialBody &body2 = m_bodies[i];
        if (m_bodies[planet_number].mass == body2.mass){
            continue;
        }
        else{
            double dx = m_bodies[planet_number].position[0] - body2.position[0];
            double dy = m_bodies[planet_number].position[1] - body2.position[1];
            double dz = m_bodies[planet_number].position[2] - body2.position[2];
            double dr2 = dx*dx + dy*dy + dz*dz;
            double dr = sqrt(dr2);
            double force = -G*m_bodies[planet_number].mass*body2.mass/(dr*dr*dr);

            m_bodies[planet_number].force[0] += force*dx;
            m_bodies[planet_number].force[1] += force*dy;
            m_bodies[planet_number].force[2] += force*dz;
        }
    }
}

int SolarSystem::numberOfBodies() const
{
    return m_bodies.size();
}

double SolarSystem::totalEnergy() const
{
    return m_kineticEnergy + m_potentialEnergy;
}

double SolarSystem::potentialEnergy() const
{

    return m_potentialEnergy;
}

double SolarSystem::kineticEnergy() const
{
    return m_kineticEnergy;
}

void SolarSystem::writeToFile(string filename)
{
    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    m_file << numberOfBodies() << endl;
    for(CelestialBody &body : m_bodies) {
        m_file << "1 " << setprecision(15) <<  body.position.x() << " " << body.position.y() << " " << body.position.z() << "\n";
    }
}

vec3 SolarSystem::angularMomentum() const
{
    return m_angularMomentum;
}

std::vector<CelestialBody> &SolarSystem::bodies()
{
    return m_bodies;
}
