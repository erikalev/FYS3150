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

    double boxLength = system.systemSize().x();
    double sigma = m_sigma;
    double rCut = 2.5*m_sigma;
    double rCut2 = rCut*rCut;
    double sigma6 = m_sigma*m_sigma*m_sigma*m_sigma*m_sigma*m_sigma;
    double sigma12 = sigma6*sigma6;
    double potentialEnergyAtRcut = 4*m_epsilon*(sigma12*pow(rCut,-12) - sigma6*pow(rCut, -6));
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

            double dr2 = dx*dx + dy*dy + dz*dz;
            if(dr2 < rCut2) {
                double oneOverDr2 = 1.0 / dr2;
                double oneOverDr6 = oneOverDr2*oneOverDr2*oneOverDr2;
                double oneOverDr12 = oneOverDr6*oneOverDr6;
                double force_scalar = 24*m_epsilon*oneOverDr2*(2*sigma12*oneOverDr12 - sigma6*oneOverDr6);

                atom1->force[0] += force_scalar*dx;
                atom1->force[1] += force_scalar*dy;
                atom1->force[2] += force_scalar*dz;

                atom2->force[0] -= force_scalar*dx;
                atom2->force[1] -= force_scalar*dy;
                atom2->force[2] -= force_scalar*dz;

                m_potentialEnergy += 4*m_epsilon*(sigma12*oneOverDr12 - sigma6*oneOverDr6) - potentialEnergyAtRcut;
            }
        }
    }
}
