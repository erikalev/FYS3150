#include "solvers.h"
#include "solarsystem.h"

Solvers::Solvers(double dt) :
    m_dt(dt)
{

}
void Solvers::EulerForward(SolarSystem &system)
{
    system.calculateForcesAndEnergy();
    for(CelestialBody &body : system.bodies()) {
        body.position += body.velocity*m_dt;
        body.velocity += body.force / body.mass * m_dt;
    }
}
void Solvers::Mercury_velocityVerlet(SolarSystem &system)
{
    system.calculateForcesGR();
    for(CelestialBody &body : system.bodies()) {
        body.velocity += m_dt*0.5*body.force/body.mass;
        body.position += m_dt*body.velocity;
     }
    system.calculateForcesGR();

    for(CelestialBody &body : system.bodies()) {
        body.velocity += m_dt*0.5*body.force/body.mass;
   }
}

void Solvers::circle_EulerForward(SolarSystem &system)
{
    for(CelestialBody &body : system.bodies()) {
        system.calculateAccelerationCircleOnePlanet(0);
        body.position +=  m_dt*(body.velocity - m_dt*body.force);
        body.velocity += m_dt*body.force;
    }
}

void Solvers::circle_velocityVerlet(SolarSystem &system)
{
    for(CelestialBody &body : system.bodies()) {
        system.calculateAccelerationCircleOnePlanet(0);
        body.velocity += m_dt/2*body.force;
        body.position += m_dt*body.velocity;
    }

    system.calculateForcesAndEnergy();
    for(CelestialBody &body : system.bodies()) {
        system.calculateAccelerationCircleOnePlanet(0);
        body.velocity += m_dt/2*body.force;
    }
}

void Solvers::Rk4(SolarSystem &system)
{
    vec3 K1, K2, K3, K4, K1r, K2r, K3r, K4r;
    system.calculateForcesAndEnergy();
    int i = 0;
    for(CelestialBody &body : system.bodies()) {
        vec3 original_position = body.position;
        K1 = body.force/body.mass;
        K1r = body.velocity;
        body.position += K1r*m_dt/2;

        system.calculateForcesOnePlanet(i);

        K2 = body.force/body.mass;
        K2r = body.velocity + K1*m_dt/2;
        body.position = original_position + K2r*m_dt/2;

        system.calculateForcesOnePlanet(i);

        K3 = body.force/body.mass;
        K3r = body.velocity + K2*m_dt/2;
        body.position = original_position + K3r*m_dt;

        system.calculateForcesOnePlanet(i);

        K4 = body.force/body.mass;
        K4r = body.velocity + K3*m_dt;
        body.velocity += m_dt/6.0*(K1 + 2*K2 + 2*K3 + K4);
        body.position = original_position + m_dt/6.0*(K1r + 2*K2r + 2*K3r + K4r);
        i += 1;
    }
}

void Solvers::VelocityVerlet(SolarSystem &system)
{
    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()) {
        body.velocity += m_dt/2*body.force/body.mass;
        body.position += m_dt*body.velocity;
     }
    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()) {
        body.velocity += m_dt/2*body.force/body.mass;
    }
}

void Solvers::EulerChromer(SolarSystem &system)
{
    system.calculateForcesAndEnergy();
    for(CelestialBody &body : system.bodies()) {
        body.velocity += body.force / body.mass * m_dt;
        body.position += body.velocity*m_dt;
    }
}
