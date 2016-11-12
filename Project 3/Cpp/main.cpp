#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include <fstream>
#include <iomanip>
#include "solvers.h"

using namespace std;

int find_StepsPrYear(){
    //Supplies for the amount of time steps pr. year for the simulation
    int StepsPrYear;
    cout << "How many steps pr. year would you like?";
    cout << "\n";
    cin >> StepsPrYear;
    return StepsPrYear;
}
int find_years(){
    //Supplies for the amount of years for the simulation
    int years;
    cout << "\n";
    cout << "\n";
    cout << "How many years would you like to simulate?";
    cout << "\n";
    cin >> years;
    cout << "\n";
    cout << "\n";
    return years;
}
int find_solver(double dt, int numTimesteps ){
    /*Method for choosing the solver and system. The options are listed in the command line when running the program.
     * Takes variables:
     * dt = the time step
     * numTimsteps = Total number of time steps
     */
    SolarSystem solarSystem;
    double AUPrDayToAUPrYEAR = 365.242199;
    double kgToSolarMasses = 5.02739933e-31;
    vec3 angular_momentum_start, angular_momentum_end;
    double total_kinetic_energy_start, total_kinetic_energy_end, total_potential_energy_start, total_potential_energy_end;

    int number;
    cout << "which solver would you like to use? Solver 1-4 incoorporate all the lanets in our solar system.";
    cout << "\n";
    cout << "For RK4 (including the moon and some comets)   type   1";
    cout << "\n";
    cout << "For Euler Forward                              type   2";
    cout << "\n";
    cout << "For Euler Chromer                              type   3";
    cout << "\n";
    cout << "For Velocity Verlet                            type   4";
    cout << "\n";
    cout << "For Euler-Foreward Earth-Sun                   type   5";
    cout << "\n";
    cout << "For Veclocity-Verlet Earth-Sun                 type   6";
    cout << "\n";
    cout << "For Euler-Foreward Earth-Sun-Jupiter           type   7";
    cout << "\n";
    cout << "For Veclocity-Verlet Earth-Sun-Jupiter         type   8";
    cout << "\n";
    cout << "For Euler Forward Earth-Sun circular orbit     type   9";
    cout << "\n";
    cout << "For Velocity Verlet Earth-Sun circular orbit   type   10";
    cout << "\n";
    cout << "For Velocity Verlet Mercury GR system          type   11";
    cout << "\n";cout << "";
    cin >> number;

    if (number==1){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen RK4.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(-7.497270117482965E-02, 3.051040159347127E-01, 3.170585217131067E-02), vec3(-3.287413355627859E-02, -6.048518092561997E-03, 2.521001103093666E-03)*AUPrDayToAUPrYEAR, 3.302e23*kgToSolarMasses );
        solarSystem.createCelestialBody( vec3(-3.762527076543014E-02, -7.222297667594171E-01, -7.730578709655952E-03), vec3(2.005677918924942E-02, -1.216749544949919E-03, -1.174251392296420E-03)*AUPrDayToAUPrYEAR, 48.685e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.055088903671614, -8.990076602197199E-01, -4.487531177805415E-02), vec3(9.642015309290944E-03, 1.182614726678359E-02, 1.103645507688215E-05)*AUPrDayToAUPrYEAR, 6.4185e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.328547414949876E+00, -9.759277178762529E+00, 2.623618409080613E-01), vec3(5.121367392260793E-03, -1.312591329536972E-03, -1.808535750517112E-04)*AUPrDayToAUPrYEAR, 5.68319e26*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.848140778175129E+01, 7.519928599269791E+00, -2.115010672892306E-01), vec3(-1.511040584724206E-03, 3.459739710284834E-03, 3.258846519965050E-05)*AUPrDayToAUPrYEAR, 86.8103e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(2.824868172672491E+01, -9.958052925289111E+00, -4.459523234277518E-01), vec3(1.022551850050800E-03, 2.979487305245919E-03, -8.451307298482491E-05)*AUPrDayToAUPrYEAR, 102.41e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.386952321033753E+00, -3.182110013246340E+01, 6.897972361639414E-01), vec3(3.081193860165317E-03, 2.357166053135576E-04, -9.279707965939170E-04)*AUPrDayToAUPrYEAR, 1.307e22*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.867388384120823E-01, 1.753807358422285E-01, 1.386465385426813E-05), vec3(-2.976831655184258E-03, 1.641323814155747E-02, 3.260727347268461E-05)*AUPrDayToAUPrYEAR, 734.9e20*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.911831018516783E+00, -6.039627468068883E-01, 3.483157127746035E-01), vec3(1.084676294666545E-03, -1.000229660677933E-02, 7.099566959763434E-04)*AUPrDayToAUPrYEAR, 3.27e19*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.046753647354204E+01, 2.577555799437012E+01, -9.878448510331060E+00), vec3(4.516941972123285E-05, 8.017838081216701E-04, -1.205000216987169E-04)*AUPrDayToAUPrYEAR, 2.2e14*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(3.048303102304126E+00, -1.551152401717859E+01, -3.556067224567644E+01), vec3(4.062547641888652E-04, -1.982441250227234E-03, -3.078364216504917E-03)*AUPrDayToAUPrYEAR, 2.2e14*kgToSolarMasses);
        solarSystem.writeToFile("positions.xyz");

        Solvers solvers(dt);
        //solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            //solarSystem.writeToFile("positions.xyz");
            solvers.Rk4(solarSystem);
        }
    }
    else if (number==2){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Euler Forward.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(-7.497270117482965E-02, 3.051040159347127E-01, 3.170585217131067E-02), vec3(-3.287413355627859E-02, -6.048518092561997E-03, 2.521001103093666E-03)*AUPrDayToAUPrYEAR, 3.302e23*kgToSolarMasses );
        solarSystem.createCelestialBody( vec3(-3.762527076543014E-02, -7.222297667594171E-01, -7.730578709655952E-03), vec3(2.005677918924942E-02, -1.216749544949919E-03, -1.174251392296420E-03)*AUPrDayToAUPrYEAR, 48.685e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.055088903671614, -8.990076602197199E-01, -4.487531177805415E-02), vec3(9.642015309290944E-03, 1.182614726678359E-02, 1.103645507688215E-05)*AUPrDayToAUPrYEAR, 6.4185e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.328547414949876E+00, -9.759277178762529E+00, 2.623618409080613E-01), vec3(5.121367392260793E-03, -1.312591329536972E-03, -1.808535750517112E-04)*AUPrDayToAUPrYEAR, 5.68319e26*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.848140778175129E+01, 7.519928599269791E+00, -2.115010672892306E-01), vec3(-1.511040584724206E-03, 3.459739710284834E-03, 3.258846519965050E-05)*AUPrDayToAUPrYEAR, 86.8103e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(2.824868172672491E+01, -9.958052925289111E+00, -4.459523234277518E-01), vec3(1.022551850050800E-03, 2.979487305245919E-03, -8.451307298482491E-05)*AUPrDayToAUPrYEAR, 102.41e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.386952321033753E+00, -3.182110013246340E+01, 6.897972361639414E-01), vec3(3.081193860165317E-03, 2.357166053135576E-04, -9.279707965939170E-04)*AUPrDayToAUPrYEAR, 1.307e22*kgToSolarMasses);
        //solarSystem.createCelestialBody( vec3(9.867388384120823E-01, 1.753807358422285E-01, 1.386465385426813E-05), vec3(-2.976831655184258E-03, 1.641323814155747E-02, 3.260727347268461E-05)*AUPrDayToAUPrYEAR, 734.9e20*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.EulerForward(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==3){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Euler Chromer.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";


        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(-7.497270117482965E-02, 3.051040159347127E-01, 3.170585217131067E-02), vec3(-3.287413355627859E-02, -6.048518092561997E-03, 2.521001103093666E-03)*AUPrDayToAUPrYEAR, 3.302e23*kgToSolarMasses );
        solarSystem.createCelestialBody( vec3(-3.762527076543014E-02, -7.222297667594171E-01, -7.730578709655952E-03), vec3(2.005677918924942E-02, -1.216749544949919E-03, -1.174251392296420E-03)*AUPrDayToAUPrYEAR, 48.685e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.055088903671614, -8.990076602197199E-01, -4.487531177805415E-02), vec3(9.642015309290944E-03, 1.182614726678359E-02, 1.103645507688215E-05)*AUPrDayToAUPrYEAR, 6.4185e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.328547414949876E+00, -9.759277178762529E+00, 2.623618409080613E-01), vec3(5.121367392260793E-03, -1.312591329536972E-03, -1.808535750517112E-04)*AUPrDayToAUPrYEAR, 5.68319e26*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.848140778175129E+01, 7.519928599269791E+00, -2.115010672892306E-01), vec3(-1.511040584724206E-03, 3.459739710284834E-03, 3.258846519965050E-05)*AUPrDayToAUPrYEAR, 86.8103e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(2.824868172672491E+01, -9.958052925289111E+00, -4.459523234277518E-01), vec3(1.022551850050800E-03, 2.979487305245919E-03, -8.451307298482491E-05)*AUPrDayToAUPrYEAR, 102.41e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.386952321033753E+00, -3.182110013246340E+01, 6.897972361639414E-01), vec3(3.081193860165317E-03, 2.357166053135576E-04, -9.279707965939170E-04)*AUPrDayToAUPrYEAR, 1.307e22*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.EulerChromer(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==4){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen velocity Verlet.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";


        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(-7.497270117482965E-02, 3.051040159347127E-01, 3.170585217131067E-02), vec3(-3.287413355627859E-02, -6.048518092561997E-03, 2.521001103093666E-03)*AUPrDayToAUPrYEAR, 3.302e23*kgToSolarMasses );
        solarSystem.createCelestialBody( vec3(-3.762527076543014E-02, -7.222297667594171E-01, -7.730578709655952E-03), vec3(2.005677918924942E-02, -1.216749544949919E-03, -1.174251392296420E-03)*AUPrDayToAUPrYEAR, 48.685e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.055088903671614, -8.990076602197199E-01, -4.487531177805415E-02), vec3(9.642015309290944E-03, 1.182614726678359E-02, 1.103645507688215E-05)*AUPrDayToAUPrYEAR, 6.4185e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-2.328547414949876E+00, -9.759277178762529E+00, 2.623618409080613E-01), vec3(5.121367392260793E-03, -1.312591329536972E-03, -1.808535750517112E-04)*AUPrDayToAUPrYEAR, 5.68319e26*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(1.848140778175129E+01, 7.519928599269791E+00, -2.115010672892306E-01), vec3(-1.511040584724206E-03, 3.459739710284834E-03, 3.258846519965050E-05)*AUPrDayToAUPrYEAR, 86.8103e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(2.824868172672491E+01, -9.958052925289111E+00, -4.459523234277518E-01), vec3(1.022551850050800E-03, 2.979487305245919E-03, -8.451307298482491E-05)*AUPrDayToAUPrYEAR, 102.41e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(9.386952321033753E+00, -3.182110013246340E+01, 6.897972361639414E-01), vec3(3.081193860165317E-03, 2.357166053135576E-04, -9.279707965939170E-04)*AUPrDayToAUPrYEAR, 1.307e22*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.VelocityVerlet(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==5){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Euler Foreward for the Earth-Sun system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.EulerForward(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==6){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Velocity Verlet for the Earth-Sun system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";
        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.VelocityVerlet(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==7){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Euler Foreward for the Earth-Sun-Jupiter system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.EulerForward(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==8){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Velocity Verlet for the Earth-Sun-Jupiter system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";
        solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
        solarSystem.createCelestialBody( vec3(9.890331046925951E-01, 1.768079890757788E-01, -1.738715302893284E-04), vec3(-3.268395786841218E-03, 1.689265025904021E-02, -9.889230545039174E-07)*AUPrDayToAUPrYEAR, 5.97219e24*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(-5.434331739612955E+00, -3.675616668136252E-01, 1.230601930789849E-01), vec3(4.213116301102531E-04, -7.173329393314243E-03, 2.032479963464221E-05)*AUPrDayToAUPrYEAR, 1898.13e24*kgToSolarMasses);

        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.VelocityVerlet(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number==9){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Euler Forward for the Earth-Sun circular orbit system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";
        solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 5.97219e24*kgToSolarMasses);
        Solvers solvers(dt);
        solarSystem.writeToFile("positions.xyz");

        for(int timestep=0; timestep<numTimesteps; timestep++) {
            solvers.circle_EulerForward(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number == 10){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Velocity Verlet for the Earth-Sun circular orbit system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 5.97219e24*kgToSolarMasses);
        solarSystem.writeToFile("positions.xyz");

        Solvers solvers(dt);
        for(int timestep=0; timestep<numTimesteps; timestep++) {

            solvers.circle_velocityVerlet(solarSystem);
            solarSystem.writeToFile("positions.xyz");
        }
    }
    else if (number == 11){
        cout << "\n";
        cout << "\n";
        cout << "You have choosen Velocity Verlet for the Mercury GR system.";
        cout << "\n";
        cout << "Calculating positions. Please wait...";
        cout << "\n";
        cout << "\n";

        solarSystem.createCelestialBody( vec3(0.3075, 0, 0), vec3(0, -12.44, 0), 3.285e23*kgToSolarMasses);
        solarSystem.createCelestialBody( vec3(0, 0, 0), vec3(0, 0, 0), 1);
        Solvers solvers(dt);
        ofstream outputFile;    //create new file
        outputFile.open("perihelionGR_1mill.txt");

        //solarSystem.writeToFile("positions1.xyz");
        double x = solarSystem.bodies().at(0).position.x() - solarSystem.bodies().at(1).position.x();
        double y = solarSystem.bodies().at(0).position.y() - solarSystem.bodies().at(1).position.y();
        double r = solarSystem.bodies().at(0).position.length() - solarSystem.bodies().at(1).position.length();
        //cout << r << endl;

        double thetaPrev = 0;
        double theta = 0;

        double rPrevPrev = 0;
        double rPrev = 0.1;
        int i= 0;
        for(int timestep=0; timestep<numTimesteps; timestep++) {
            //solarSystem.writeToFile("positions1.xyz");
            solvers.Mercury_velocityVerlet(solarSystem);
            x = solarSystem.bodies().at(0).position.x() - solarSystem.bodies().at(1).position.x();
            y = solarSystem.bodies().at(0).position.y() - solarSystem.bodies().at(1).position.y();
            theta = atan2(y,x);
            r = solarSystem.bodies().at(0).position.length() - solarSystem.bodies().at(1).position.length();

            if ( (r > rPrev) && (rPrev < rPrevPrev) ){
                cout << "Perihelion angle = " << thetaPrev*180/M_PI*3600 << endl;
                outputFile << setiosflags(ios::showpoint | ios::uppercase);
                outputFile << setprecision(10) << setw(20) << thetaPrev << endl;
                i = i+1;
                thetaPrev = theta;
                rPrevPrev = rPrev;
                rPrev = r;

            }
            else{
                thetaPrev = theta;
                rPrevPrev = rPrev;
                rPrev = r;
            }

        }
        outputFile.close();
        cout << i << endl;
    }
    else{
        cout << "\n";
        cout << "\n";
        cout << "I only have the 11 solvers stated..."<< endl;
        cout << "\n";
        cout << "\n";
    }

    return solarSystem.bodies().size();
}

int main()
{
    clock_t start, finish; //include timer
    start = clock();   //start the time

    int stepsPrYear = find_StepsPrYear();
    int years = find_years();
    double dt = 1.0/float(stepsPrYear);
    int numTimesteps = years*stepsPrYear;
    int number_of_planets = find_solver(dt, numTimesteps);

    ofstream variables;
    variables.open("variables.txt");
    variables << setiosflags(ios::showpoint | ios::uppercase);
    variables << setprecision(10) << setw(20) << numTimesteps << " " << number_of_planets << endl;
    variables.close();

    finish = clock(); //stop timetaking
    double sec = (finish - start);   //calculate clocks_per_sec used

    cout << "Calculations completed.";
    cout << "\n";
    cout << "\n";
    cout << "The calculation time for your choosen solver was "<< sec/CLOCKS_PER_SEC << " seconds." << endl;
    cout << "\n";
    cout << "Positions are available in file positions.xyz.";
    cout << "\n";
    cout << "\n";


    return 0;
}

