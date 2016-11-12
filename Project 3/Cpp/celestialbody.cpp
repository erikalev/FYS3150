#include "celestialbody.h"

/*
 * Class for storing Celestial bodies. All bodies has four properties: position, velocity, mass and force.
 * Each object is stored in the class solarsystem
 */

CelestialBody::CelestialBody(vec3 pos, vec3 vel, double mass_) {
    position = pos;
    velocity = vel;
    mass = mass_;
}

CelestialBody::CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_) {
    position = vec3(x,y,z);
    velocity = vec3(vx,vy,vz);
    mass = mass_;
}

void CelestialBody::resetForce() {
    force.zeros();
}

