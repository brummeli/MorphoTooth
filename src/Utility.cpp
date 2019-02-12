//
// Created by Stefanie on 23.01.2019.
//

#include <algorithm>
#include <cctype>
#include "Utility.h"
#include "Cell.h"
#include <string>
#include <sstream>
#include <iostream>

void Utility::resetNonConstantParameters(Parameters &params) {
    params.error = false;
    params.currentIteration = 0;
}

void Utility::trimString(std::string &str) {
    Utility::leftTrim(str);
    Utility::rightTrim(str);
}

void Utility::leftTrim(std::string &str) {
    // trim from start to first occurence that is not a space
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

void Utility::rightTrim(std::string &str) {
    // trim from last occurence that is not a space to end
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

std::string Utility::doubleToString(double value) {
    std::ostringstream strs;
    strs << value;
    std::string str = strs.str();
    return str;
}

bool Utility::NanIsPresent(double x, double y, double z) {
    if (x != x) {
        std::cout << "x value is Nan" << std::endl;
        return true;
    } else if (y != y) {
        std::cout << "y value is Nan" << std::endl;
        return true;
    } else if (z != z) {
        std::cout << "z value is Nan" << std::endl;
        return true;
    }
    return false;
}


bool Utility::errorTesting(Cell *cells, Parameters &params) {
    if (params.nrCellsInSimulation > totalNrOfCells) {
        params.error = true;
        std::cout << "There are too many cells in the simulation" << std::endl;
        std::cout.flush();
    }

    for (int cell = 0; cell < params.nrCellsInSimulation; ++cell) {
        double x = cells[cell].getX();
        double y = cells[cell].getY();
        double z = cells[cell].getZ();

        if (Utility::NanIsPresent(x, y, z)) {
            params.error = true;
            std::cout << "There is a Nan in iteration " << params.currentIteration << std::endl;
        }
    }

    return params.error;

}

int Utility::endOfSimulation(Parameters &params, int iterationStep, int oldSuccess) {
    // if the maxNrOfIterations is reached the simulation gets ended
    if (params.currentIteration == params.maxNrOfIterations) {
        std::cout << "The simulation was was stopped because the maxNrOfIterations was reached."
                  << std::endl;
        std::cout << "This was at iteration " << iterationStep << std::endl;
        return 1;
    }

    // if a multiple of minNrOfCells is reached, the simulation was a success -> do an output and continue simulation
    for (int multiple = 1; multiple < 6; ++multiple) {
        if (params.nrCellsInSimulation == (params.minNrOfCells * multiple)) {
            // if this success number was already achieved once do return 0 -> simulation is normally continued
            if (oldSuccess != (1 + multiple)) {
                std::cout << "A multiple of minNrOfCells was reached :)" << std::endl;
                std::cout << "This was at iteration " << iterationStep << std::endl;
                return (1 + multiple);
            } else {
                return oldSuccess;
            }
        }
    }

    // if no end determing value is reached, set success to 0 -> simulation is continued
    return 0;
}
