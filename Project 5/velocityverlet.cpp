#include "velocityverlet.h"
#include "system.h"
#include "atom.h"

void VelocityVerlet::integrate(System &system, double dt, int N)
{

    if(m_firstStep) {
        system.calculateForces(N);
        m_firstStep = false;
    }

    for(Atom *atom : system.atoms()) {
        atom->velocity += atom->force*0.5*dt/atom->mass();
        atom->position += atom->velocity*dt;
    }

    system.applyPeriodicBoundaryConditions(N);
    system.calculateForces(N); // New positions, recompute forces

    for(Atom *atom : system.atoms()) {
        atom->velocity += atom->force*0.5*dt/atom->mass();
    }
}
