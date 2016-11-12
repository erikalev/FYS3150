#ifndef SOLVERS
#define SOLVERS

class Solvers
{
public:
    double m_dt;
    Solvers(double dt);
    void EulerForward(class SolarSystem &system);
    void EulerChromer(class SolarSystem &system);
    void VelocityVerlet(class SolarSystem &system);
    void Rk4(class SolarSystem &system);
    void circle_EulerForward(class SolarSystem &system);
    void circle_velocityVerlet(class SolarSystem &system);
    void Mercury_velocityVerlet(class SolarSystem &system);
};

#endif // SOLVERS

