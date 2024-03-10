#include <CL/cl.hpp>
#include <iostream>
#include <vector>

int main() {
    // Получаем доступные платформы
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    if (platforms.empty()) {
        std::cerr << "No OpenCL platforms found." << std::endl;
        return 1;
    }

    // Выбираем первую платформу
    cl::Platform platform = platforms.front();

    // Получаем доступные устройства на выбранной платформе
    std::vector<cl::Device> devices;
    platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);

    if (devices.empty()) {
        std::cerr << "No GPU devices found." << std::endl;
        return 1;
    }

    // Выбираем первое устройство
    cl::Device device = devices.front();

    // Создаем контекст
    cl::Context context(device);

    // Создаем очередь команд для устройства
    cl::CommandQueue queue(context, device);

    // Код OpenCL программы
    const char* kernelSource =
        "__kernel void hello_world() {\n"
        "    int globalId = get_global_id(0);\n"
        "    printf(\"Hello world from thread %d\\n\", globalId);\n"
        "}\n";

    // Создаем программу из исходного кода
    cl::Program::Sources sources(1, std::make_pair(kernelSource, strlen(kernelSource)));
    cl::Program program(context, sources);

    // Собираем программу
    program.build("-cl-std=CL1.2");

    // Создаем ядро программы
    cl::Kernel kernel(program, "hello_world");

    // Устанавливаем размер рабочей группы (количество потоков)
    cl::NDRange globalSize(10); // Пример: 10 потоков

    // Запускаем ядро на устройстве
    queue.enqueueNDRangeKernel(kernel, cl::NullRange, globalSize);

    // Ждем завершения выполнения ядра
    queue.finish();

    return 0;
}
