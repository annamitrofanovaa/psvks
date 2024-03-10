//D:\algos\pr\HelloMPI\Debug>mpiexec -n 4 HelloMPI.exe
#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    // ������������� MPI
    MPI_Init(&argc, &argv);

    // ��������� ������ ����� ��������� � ����� �������� ��������
    int numProcesses, rank;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
    

    // ����� "Hello world" �� ������� ��������
    std::cout << "Hello world from process " << rank << " of " << numProcesses << std::endl;
   // printf("Hello world from process = %d, total munder of processes: %d\n", rank, numProcesses);
    // ����������� MPI
    MPI_Finalize();

    return 0;
}
