//
// Created by Stefanie on 17.12.2018.
//

#include <iostream>
#include "Print.h"

void Print::printStartOfSimulation(ImplementParams params, int repetition) {
    std::cout << "##################################################################################" << std::endl;
    std::cout << "##################################################################################" << std::endl;
    std::cout << "## Simulation " << repetition << " has started                                                 ##"
              << std::endl;
    std::cout << "##################################################################################" << std::endl;

    Print::printParameterToChange(params);
    Print::printParameterWithNoise(params);
}

void Print::printParameterToChange(ImplementParams params) {
    // Print only if the parameter gets changed
    if (params.parameterToChange != "") {
        std::cout << "###########################################################" << std::endl;
        std::cout << "# Parameter to change " << params.parameterToChange << ": "
                  << params.valueOfParameterToChange << " #" << std::endl;
        std::cout << "###########################################################" << std::endl;
        std::cout.flush();
    }
}

void Print::printParameterWithNoise(ImplementParams params) {
    // Print only if a parameter has noise
    if (params.noiseType == 1) {
        std::cout << "#############################################################" << std::endl;
        std::cout << "# Parameter with Noise: " << params.parameterWithNoise << " #" << std::endl;
        std::cout << "#############################################################" << std::endl;
    }
}

void Print::printEndOfSimulation() {
    std::cout << "##################################################################################" << std::endl;
    std::cout << "##################################################################################" << std::endl;
    std::cout << "## Simulation has completed with success                                        ##" << std::endl;
    std::cout << "##################################################################################" << std::endl;
    std::cout << "##################################################################################" << std::endl;
}

void Print::printSimulationStatus(ImplementParams &params) {
    std::cout << params.currentIteration << std::endl;
    std::cout << "Cells in simulation: " << params.nrCellsInSimulation << std::endl;
    if (params.noiseType != 0) {
        if (!(params.currentIteration < params.noiseStart) || !(params.currentIteration <= params.noiseEnd)) {
            std::cout << "Active noise type: " << params.noiseType << std::endl;
        }
    }
    std::cout.flush();
}


