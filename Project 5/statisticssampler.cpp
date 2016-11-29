#include "system.h"
#include "statisticssampler.h"
#include "lennardjones.h"
#include <iostream>
#include "unitconverter.h"
using std::ofstream; using std::cout; using std::endl;

StatisticsSampler::StatisticsSampler()
{

}

void StatisticsSampler::saveToFile(System &system, int temperature)
{
    // Save the statistical properties for each timestep for plotting etc.
    // First, open the file if it's not open already
    if(!m_file.is_open()) {
        m_file.open("statistics_" + std::to_string(temperature) + ".txt", ofstream::out);
        // If it's still not open, something bad happened...

        if(!m_file.is_open()) {
            cout << "Error, could not open statistics.txt" << endl;
            exit(1);
        }
    }
    m_file << system.time() << " "<< m_density << " " << m_r2 << " " << totalEnergy()<< " " << kineticEnergy() << " " << potentialEnergy()<< " " << StatisticsSampler::temperature() << endl;
}

void StatisticsSampler::sample(System &system)
{
    // Here you should measure different kinds of statistical properties and save it to a file.
    sampleKineticEnergy(system);
    samplePotentialEnergy(system);
    sampleTemperature(system);
    sampleDensity(system);
    sampleDiffusion(system);
    saveToFile(system, system.samlpe_initialTindex());
}

void StatisticsSampler::sampleKineticEnergy(System &system)
{
    m_kineticEnergy = 0; // Remember to reset the value from the previous timestep
    for(Atom *atom : system.atoms()) {
        m_kineticEnergy += 0.5*atom->mass()*atom->velocity.lengthSquared();
    }
}

void StatisticsSampler::samplePotentialEnergy(System &system)
{
    for (Atom *atom : system.atoms()) {

    }
    m_potentialEnergy = system.potential().potentialEnergy();
}

void StatisticsSampler::sampleTemperature(System &system)
{
    m_temperature = 2.0/3.0*m_kineticEnergy/(system.atoms().size());
}

void StatisticsSampler::sampleDiffusion(System &system){
    m_D= 0;
    m_r2 = 0;
    for (Atom *atom : system.atoms()){
        m_r2 += (atom->position - atom->initial_position).lengthSquared();
    }
    m_r2 /= system.atoms().size();
    m_D = m_r2/6.0/system.time();

}

void StatisticsSampler::sampleDensity(System &system)
{


}
