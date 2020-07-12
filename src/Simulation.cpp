//
// Created by bill on 7/11/20.
//

#include <sstream>
#include <fstream>
#include "string"
#include "iostream"
#include "chrono"

#include "Simulation.h"
#include "System.h"

namespace nbody {
    std::string Simulation::generateName() {
        double s_since_epoch = std::chrono::duration_cast<std::chrono::duration<double>>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count();
        std::ostringstream oss;
        oss << s_since_epoch << "-sim.txt";
        return oss.str();
    }

    void Simulation::evolveSystem(int nSteps, float dt) {
        for (int i = 0; i < nSteps; i++) {
            _system->update(dt);
        }
    }

    void Simulation::loadRun(std::istream &input) {
        _system->readState(input);
    }

    void Simulation::saveRun() const {
        std::ofstream outfile{_name};
        _system->writeState(outfile);
    }
}