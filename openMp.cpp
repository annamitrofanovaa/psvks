#include <iostream>
#include <omp.h>

int main() {
    // ���������, ��� ��������� ���� ���� ������ ����������� �����������
//#pragma omp parallel
#pragma omp parallel num_threads(4)
    {
        // �������� ����� ���������� �������
        int num_threads = omp_get_num_threads();

        // �������� ����� �������� ������
        int thread_num = omp_get_thread_num();

        // ������� ��������� � �������������� ������ ������
#pragma omp critical
        {
            std::cout << "Heello world from thread " << thread_num + 1 << " of " << num_threads << std::endl;
        }
    }

    return 0;
}
