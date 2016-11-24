#include "lennardjones.h"
#include "system.h"
#include <cmath>
#include <unitconverter.h>
double LennardJones::potentialEnergy() const
{
    return m_potentialEnergy;
}

double LennardJones::sigma() const
{
    return m_sigma;
}

void LennardJones::setSigma(double sigma)
{
    m_sigma = sigma;
}

double LennardJones::epsilon() const
{
    return m_epsilon;
}

void LennardJones::setEpsilon(double epsilon)
{
    m_epsilon = epsilon;
}

void LennardJones::calculateForces(System &system, int N)
{

    m_potentialEnergy = 0; // Remember to compute this in the loop
    int numberOfAtoms = system.atoms().size();
    double boxLength = 5.26*N;
    double sigma = m_sigma;
    double sigma6 = m_sigma*m_sigma*m_sigma*m_sigma*m_sigma*m_sigma;
    double sigma12 = sigma6*sigma6;
    for (int i = 0; i < numberOfAtoms; i++){
        Atom *atom1 = system.atoms()[i];
        for (int j = i+1; j < numberOfAtoms; j++){
            Atom *atom2 = system.atoms()[j];

            double dx = atom1->position(0) - atom2->position(0);
            double dy = atom1->position(1) - atom2->position(1);
            double dz = atom1->position(2) - atom2->position(2);

            if ((dx) <= -boxLength/2.0) dx += boxLength;
            if ((dx) > boxLength/2.0) dx -= boxLength;

            if ((dy) <= -boxLength/2.0) dy += boxLength;
            if ((dy) > boxLength/2.0) dy -= boxLength;

            if ((dz) <= -boxLength/2.0) dz += boxLength;
            if ((dz) > boxLength/2.0) dz -= boxLength;

            double r2 = dx*dx+dy*dy+dz*dz;
            double r1 = sqrt(r2);
            double r6 = r2*r2*r2;
            double r12 = r6*r6;

            double force_scalar = -24*m_epsilon*(2*sigma12/(r12*r1) - sigma6/(r6*r1));
            vec3 force = vec3(force_scalar*dx, force_scalar*dy, force_scalar*dz);

            atom1->force  += (force);
            atom2->force -= (force);

            m_potentialEnergy += 4*m_epsilon*(sigma12/r12 - sigma6/r6);
        }
    }
}
