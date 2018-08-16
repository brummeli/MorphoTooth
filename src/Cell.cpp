//
// Created by Stefanie on 30.07.2018.
//

#include <iostream>
#include "Cell.h"


//Getter
double Cell::getX() const {
    return x;
}

double Cell::getY() const {
    return y;
}

double Cell::getZ() const {
    return z;
}

int Cell::getID() const {
    return ID;
}

double Cell::getDiffState() const {
    return diffState;
}

std::vector<int> Cell::getNeighbours() const {
    return neighbours;
}

bool Cell::isKnotCell() const {
    if (knot) {
        return true;
    } else {
        return false;
    }
}

bool Cell::isInSimulation() const {
    return inSimulation;
}

bool Cell::isInCentre() const {
    return inCentre;
}

int Cell::getMesenchymeThickness() const {
    return mesenchymeThickness;
}

const std::vector<double> &Cell::getBorderPointsX() const {
    return borderPointsX;
}

const std::vector<double> &Cell::getBorderPointsY() const {
    return borderPointsY;
}

const std::vector<double> &Cell::getBorderPointsZ() const {
    return borderPointsZ;
}

const std::vector<double> &Cell::getPerimeterParts() const {
    return perimeterParts;
}

const std::vector<double> &Cell::getAreaParts() const {
    return areaParts;
}

double Cell::getPerimeter() const {
    return perimeter;
}

double Cell::getCellArea() const {
    return cellArea;
}

std::vector<std::vector<double>> &Cell::getProteinConcentrations() {
    return proteinConcentrations;
}

const std::vector<std::vector<double>> &Cell::getTempProteinConcentrations() const {
    return tempProteinConcentrations;
}

//Setter
void Cell::setX(double x) {
    Cell::x = x;
}

void Cell::setY(double y) {
    Cell::y = y;
}

void Cell::setZ(double z) {
    Cell::z = z;
}

void Cell::setID(int ID) {
    Cell::ID = ID;
}

void Cell::setDiffState(double diffState) {
    if (diffState > 1) {
        std::cout << "The diff state can maximally be 1" << std::endl;
        diffState = 1;
        return;
    }
    Cell::diffState = diffState;
}

void Cell::addDiffState(double addedDiffState) {
    Cell::diffState += addedDiffState;
    if (diffState > 1) {
        diffState = 1;
    }
}

void Cell::setKnotCell(bool knot) {
    Cell::knot = knot;
}

void Cell::setNeighbour(int neighbourID) {
    Cell::neighbours.push_back(neighbourID);
}

void Cell::setInSimulation(bool inSimulation) {
    Cell::inSimulation = inSimulation;
}

void Cell::setInCentre(bool inCentre) {
    Cell::inCentre = inCentre;
}

void Cell::setMesenchymeThickness(int mesenchymeThickness) {
    Cell::mesenchymeThickness = mesenchymeThickness;
}

void Cell::newBorderPoint(char axis, double point) {
    switch (axis) {
        case 'X': {
            borderPointsX.push_back(point);
            break;
        }
        case 'Y': {
            borderPointsY.push_back(point);
            break;
        }
        case 'Z': {
            borderPointsZ.push_back(point);
            break;
        }
        default:
            std::cout << "The point could not be added" << std::endl;
    }
}

void Cell::replaceBorderPoint(char axis, double point, int position) {
    switch (axis) {
        case 'X': {
            borderPointsX[position] = point;
            break;
        }
        case 'Y': {
            borderPointsY[position] = point;
            break;
        }
        case 'Z': {
            borderPointsZ[position] = point;
            break;
        }
        default:
            std::cout << "The point could not be replaced" << std::endl;
    }
}

void Cell::newPerimeterPart(double perimeterPart) {
    perimeterParts.push_back(perimeterPart);
}

void Cell::newAreaPart(double areaPart) {
    areaParts.push_back(areaPart);
}

void Cell::setPerimeter(double perimeter) {
    Cell::perimeter = perimeter;
}

void Cell::setCellArea(double cellArea) {
    Cell::cellArea = cellArea;
}

void Cell::addProteinConcentration(int protein, int layer, double addedConcentration) {
    proteinConcentrations[protein][layer] += addedConcentration;
}

void Cell::addTempConcentration(int protein, int layer, double addedConcentration) {
    tempProteinConcentrations[protein][layer] += addedConcentration;
}

void Cell::setProteinConcentration(int protein, int layer, double newConcentration) {
    proteinConcentrations[protein][layer] = newConcentration;
}

//Constructor
Cell::Cell(double x, double y, int z, int ID) : x(x), y(y), z(z), ID(ID) {
    knot = false;
    inSimulation = false;
    inCentre = false;
    mesenchymeThickness = 4;
    diffState = 0;
    //Set Concentrations to 0 (in each layer)
    for (int layer = 0; layer < mesenchymeThickness; ++layer) {
        std::vector<double> tempv;
        for (int protein = 0; protein < 4; ++protein) {
            tempv.push_back(0);
        }
        proteinConcentrations.push_back(tempv);
        tempProteinConcentrations.push_back(tempv);
    }
    perimeter = 0;
    cellArea = 0;
}

//Editors

void Cell::deleteNeighbour(int neighbour) {
    neighbours.erase(neighbours.begin() + neighbour);
}

void Cell::resetTempProteinConcentrations() {
    for (int layer = 0; layer < mesenchymeThickness; ++layer) {
        for (int protein = 0; protein < 4; ++protein) {
            tempProteinConcentrations[protein][layer] = 0;
        }
    }
}

//Printer

void Cell::printCellBorders(std::vector<Cell> cells, int cellsInSimulation) {
    for (int cell = 0; cell < cells.size(); ++cell) {
        std::cout << "Cell Nr. " << cell << std::endl;
        for (int point = 0; point < cells[cell].getBorderPointsX().size(); ++point) {
            std::cout << "x: " << cells[cell].getBorderPointsX()[point] << "  ";
            std::cout << "y: " << cells[cell].getBorderPointsY()[point] << "  ";
            std::cout << "z: " << cells[cell].getBorderPointsZ()[point] << "  ";
            std::cout << std::endl;
        }
    }
}







