#include <iostream>
#include <omp.h>

int main() {
    // Указываем, что следующий блок кода должен выполняться параллельно
//#pragma omp parallel
#pragma omp parallel num_threads(4)
    {
        // Получаем общее количество потоков
        int num_threads = omp_get_num_threads();

        // Получаем номер текущего потока
        int thread_num = omp_get_thread_num();

        // Выводим сообщение с использованием номера потока
#pragma omp critical
        {
            std::cout << "Heello world from thread " << thread_num + 1 << " of " << num_threads << std::endl;
        }
    }

    return 0;
}
