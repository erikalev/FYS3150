#include <iostream>
#include <stdlib.h>
#include <armadillo>
#include <fstream>
#include <iomanip>
#include <mpi.h>

using namespace std;
using namespace arma;

ofstream outputFile1;    //create new file
ofstream outputFile2;    //create new file
ofstream outputFile3;    //create new file
ofstream outputFile4;    //create new file

void flipping_spin(mat &spin, int indexi, int indexj, int N){

    spin(indexi, indexj) = -1*spin(indexi, indexj);
    //Changing the skeleton values belonging to spin(indexi, indexj)

    if (indexi == 1){
        spin(N+1, indexj) = spin(indexi, indexj);
       }

    if (indexi == N){
        spin(0, indexj) = spin(indexi, indexj);
       }
    if (indexj == 1){
        spin(indexi, N+1) = spin(indexi, indexj);
       }
    if (indexj == N){
        spin(indexi, 0) = spin(indexi, indexj);
       }

}
void Metropolis(mat &spin, int N, double &M, double &E, int &success, double *w){
    for (int atoms = 0; atoms < N*N; atoms++){
        int indexi = (rand() % N)+1;
        int indexj = (rand() % N)+1;
        int deltaE = 2.0*spin(indexi, indexj)*(spin(indexi+1, indexj) + spin(indexi, indexj+1) + spin(indexi-1, indexj) + spin(indexi, indexj-1));

        if(deltaE > 0){
            double r = ((double) rand() / (RAND_MAX));
            if (r <= w[deltaE+8]){
                flipping_spin(spin, indexi, indexj, N);
                E += (double) deltaE;
                M += (double) 2*spin(indexi, indexj);
                success += 1;
            }
        }
        else{
            flipping_spin(spin, indexi, indexj, N);
            E += (double) deltaE;
            M += (double) 2*spin(indexi, indexj);
            success += 1;
        }
    }
}
void initialize_random(mat &spin, double &E, double &M, int N){

    for (int i = 0; i < N+2; i++){
        for (int j = 0; j < N+2; j++){
            int value = (rand() % 2)+1;
            if (value == 1){
                spin(i, j) = 1.0;
            }
            else{
                spin(i, j) = -1.0;
            }
        }
    }

    for (int i = 0; i < N+2; i++){
        spin(i, 0) = spin(i, N);
        spin(i, N+1) = spin(i, 1);
        spin(0, i) = spin(N, i);
        spin(N+1, i) = spin(1, i);
    }

    for (int i = 1;i<N+1;i++){
        for (int j = 1;j<N+1;j++){
            E -= spin(i, j)*(spin(i, j+1) + spin(i+1, j));
            M += (double) spin(i, j);
        }
    }
}
void dump_to_file(int max_cycles, double T, int N, double *total_average);

int main(int argc, char* argv[])
{
    outputFile1.open("E_values20.txt");
    outputFile2.open("M_values20.txt");
    outputFile3.open("Cv_values20.txt");
    outputFile4.open("chi_values20.txt");

    //int my_rank, numprocs;
    int max_cycles = 1e6;
    int N = 40;
    /*
    MPI_Init(&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

    int no_intervalls = max_cycles/numprocs;
    int myloop_begin = my_rank*no_intervalls + 1;
    int myloop_end = (my_rank+1)*no_intervalls;
    if ( (my_rank == numprocs-1) &&( myloop_end < max_cycles) ) myloop_end = max_cycles;
    */
    double initial_temp, final_temp, temp_step;
    initial_temp = 2.2; final_temp = 2.3; temp_step =0.01;

            // broadcast to all nodes common variables
    //MPI_Bcast (&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    //MPI_Bcast (&initial_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    //MPI_Bcast (&final_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    //MPI_Bcast (&temp_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);


    for ( double T = initial_temp; T <= final_temp; T+=temp_step){
        cout << T << endl;
        srand(time(NULL));
        double beta = 1.0/(T);
        double M = 0.0; double E = 0.0;
        double average[5];
        for( int i = 0; i < 5; i++) average[i] = 0.;

        // Matrix consists of an external skeleton to make periodic boundary condition easier
        mat spin = zeros<mat>(N+2, N+2);

        //setting random initial values
        initialize_random(spin, E, M, N);

        // precalculating the w value since we only have a set number of energy changes
        double w[17];
        for( int de =-8; de <= 8; de++) w[de+8] = 0;
        for( int de =-8; de <= 8; de+=4) w[de+8] = exp(-beta*de);

        double total_average[4];
        for( int i = 0; i <= 4; i++){
            total_average[i] = 0.0;
        }
        for (int cycles = 1; cycles <= max_cycles; cycles ++){
            int success = 0;
            Metropolis(spin, N, M, E, success, w);
            average[0] += E; average[1] += E*E;
            average[2] += M; average[3] += M*M; average[4] += fabs(M);
        }
        /*
        for( int i =0; i < 5; i++){
          MPI_Reduce(&average[i], &total_average[i], 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        }
        if(my_rank == 0) {
           dump_to_file(max_cycles, T, N, total_average);
        }*/
        dump_to_file(max_cycles, T, N, total_average);
    }
    //MPI_Finalize();
    return 0;
}
void dump_to_file(int max_cycles, double T, int N, double *total_average){
    double norm = 1/((double) (max_cycles));//  *4);  // divided by total number of cycles in addition to averaging the MPI total
    double Etotal_average = total_average[0]*norm;
    double E2total_average = total_average[1]*norm;
    double Mtotal_average = total_average[2]*norm;
    double M2total_average = total_average[3]*norm;
    double Mabstotal_average = total_average[4]*norm;
    // all expectation values are per spin, divide by 1/n_spins/n_spins
    double Evariance = (E2total_average- Etotal_average*Etotal_average)/N/N;
    double Mabsvariance = (M2total_average - Mabstotal_average*Mabstotal_average)/N/N;
    //double Mvariance = (M2total_average - Mtotal_average*Mtotal_average)/N/N;
    double Cv = Evariance/(T*T);
    cout << sqrt(Evariance*N*N) << endl;
    double chi = Mabsvariance/T;
    outputFile1 << setiosflags(ios::showpoint | ios::uppercase);
    outputFile2 << setiosflags(ios::showpoint | ios::uppercase);
    outputFile3 << setiosflags(ios::showpoint | ios::uppercase);
    outputFile4 << setiosflags(ios::showpoint | ios::uppercase);
    outputFile1 << setprecision(10) << setw(20) << Etotal_average/N/N << endl;
    outputFile2 << setprecision(10) << setw(20) << Mabstotal_average/N/N << endl;
    outputFile3 << setprecision(10) << setw(20) << Cv << endl;
    outputFile4 << setprecision(10) << setw(20) << chi << endl;
}
