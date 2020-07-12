#include <nbody/Simulation.h>

#include <iostream>
#include <fstream>

int main() {
    std::ifstream input {"resources/nbody/binary-system-simple.txt"};
    auto *simulation = new nbody::Simulation(input);

    return 0;
}
