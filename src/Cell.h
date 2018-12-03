//
// Created by Stefanie on 30.07.2018.
//

#ifndef TOOTHMAKER_CELL_H
#define TOOTHMAKER_CELL_H

#include <vector>

/**
 * Object that contains all information and features about a cell
 */
class Cell {
private:
    /**
     * position on the x-axis
     */
    double x;

    /**
     * temp coordinates are used to cache the position changes resulting from the different forces
     * and are applied on the position after all forces are calculated
     */
    double tempX;

    /**
     * position on the y-axis
     */
    double y;

    /**
     * temp coordinates are used to cache the position changes resulting from the diffferent forces
     * and are applied on the position after all forces are calculated
     */
    double tempY;

    /**
     * position on the z-axis
     */
    double z;

    /**
     * temp coordinates are used to cache the position changes resulting from the diffferent forces
     * and are applied on the position after all forces are calculated
     */
    double tempZ;

    /**
     * This are the distances the cell has to its neighbours when it (or a new neighbour) is inserted into the grid
     */
    std::vector<double> originalDistances;

    /**
     * The ID of a cell is identical with their index in the vector containing all cells
     */
    int ID;

    /**
     * contains all neighbours (their ID). The order is relevant (clockwise order)
     */
    std::vector<int> neighbours;

    int nrOfNeighbours;

    /**
     * the differentiation state is a variable indicating the "age" of a cell
     */
    double diffState;

    /**
     * proteinConcentrations[protein][layer]
     * Proteins: Act, Inh, Sec1, Sec2
     * Layers: Epithelium, Mesenchyme1, Mesenchyme2,.. MesenchymeThickness
     */
    std::vector<std::vector<double>> proteinConcentrations;

    /**
     * tempProteinConcentrations[protein][layer]
     *
     * contains the resulting concentration changes based on concentration differences
     */
    std::vector<std::vector<double>> tempProteinConcentrations;

    /**
     * If this cell is an enamel knot cell
     */
    bool knot;

    /**
     * A cell is within simulation if it has neighbours on all sides i.e. if it is not at the border
     */
    bool inSimulation;

    /**
     * is true if the cell is in the center of the cell compound.
     * The radius of "center" is defined by the parameter initialRadius
     */
    bool inCentre;

    /**
     * MesenchymeThickness indicates how many mesenchyme cells lay under the epithelium cell
     */
    int mesenchymeThickness;

    /**
         * This vector contains the x coordinates of all voronoi vertices around the cell centre
         */
    std::vector<std::vector<double>> borderPoints;

    /**
     * marginPoints contains these two points that make the edge of the cell which is part of the border of the
     * whole tissue. They are the result, in contrast to the other cell border points, of the midpoint of only two
     * instead of three points.
     * Obviously only cells on the tissue border have such points.
     */
    std::vector<std::vector<double>> marginPoints;

    /**
     * margin is the length of the cell border that is part of the tissue border (length between the two marginPoints
     * Obviously only cells on the tissue border have such a margin length
     */
    double margin;

    /**
     * This is the area of the triangle centre-marginPoint1-marginPoint2. It represents the area made of the part of the
     * cell that is next to the tissue border.
     * It is part of the whole cellArea and is used for horizontal diffusion when there is a sink at the tissue border
     * Obviously only cells on the tissue border have such a marginArea.
     */
    double marginArea;

    /**
     * Contains the lengths of the polygon sides. Their sum (together with the margin, if the cell is at the tissue
     * border) is the perimeter of the polygon
     */
    std::vector<double> perimeterParts;

    /**
     * Contains the triangles of the polygon area. Their sum is the area of the polygon
     */
    std::vector<double> areaParts;

    /**
     * Perimeter of the polygon (cell)
     */
    double perimeter;

    /**
     * Area of the polygon (cell)
     */
    double cellArea;

public:
    //Getter
    double getX() const;

    double getTempX() const;

    double getY() const;

    double getTempY() const;

    double getZ() const;

    double getTempZ() const;

    const std::vector<double> &getOriginalDistances() const;

    int getID() const;

    double getDiffState() const;

    bool isKnotCell() const;

    std::vector<int> getNeighbours() const;

    int getNrOfNeighbours() const;

    int getMesenchymeThickness() const;

    bool isInSimulation() const;

    bool isInCentre() const;

    std::vector<std::vector<double>> getBorderPoints() const;

    std::vector<std::vector<double>> getMarginPoints() const;

    const std::vector<double> &getPerimeterParts() const;

    const std::vector<double> &getAreaParts() const;

    double getPerimeter() const;

    double getCellArea() const;

    double getMargin() const;

    std::vector<std::vector<double>> &getProteinConcentrations();

    const std::vector<std::vector<double>> &getTempProteinConcentrations() const;


    //Setter

    void addX(double newX);

    void addY(double newY);

    void addZ(double newZ);

    void setID(int newID);

    /**
     * Increments the variable tempX by a certain amount
     * @param tempX
     */
    void addTempX(double tempX);

    /**
     * Multiplies the variable tempX by a certain amount
     * @param tempX
     */
    void multiplyTempX(double tempX);

    void addTempY(double tempY);

    void addTempZ(double tempZ);

    void multiplyTempZ(double tempZ);

    void addOriginalDistance(double distance, int position);

    void replaceOriginalDistance(double distance, int position);

    /**
     * Increments the variable diffState by a certain amount
     * @param addedDiffState
     */
    void addDiffState(double addedDiffState);

    void setKnotCell(bool knot);

    void addNeighbour(int neighbourID);

    void incrementNrOfNeighbours();

    void setNeighbour(int position, int newNeighbourID);

    void replaceNeighbour(int oldNeighbourID, int newNeighbourID);

    void insertNeighbour(int newNeighbourID, int position);

    void setInSimulation(bool inSimulation);

    void setInCentre(bool inCentre);

    /**
     * Sets a new border point
     */
    void newBorderPoint(double x, double y, double z);

    void newPerimeterPart(double perimeterPart);

    void newAreaPart(double areaPart);

    void setPerimeter(double perimeter);

    void setCellArea(double cellArea);

    void setMargin(double margin);

    void setMarginArea(double area);

    /**
     * Increments the variable proteinConcentration[protein][layer] by newConcentration
     *
     * @param protein
     * @param layer
     * @param newConcentration
     */
    void addProteinConcentration(int protein, int layer, double newConcentration);

    /**
     * Increments the variable tempConcentrations[protein][layer] by addedConcentration
     * @param protein
     * @param layer
     * @param addedConcentration
     */
    void addTempConcentration(int protein, int layer, double addedConcentration);

    void setProteinConcentration(int protein, int layer, double newConcentration);

    void newMarginPoint(double x, double y, double z);

    //Constructor
    Cell(double x, double y, double z, int ID);

    //Editors
    void deleteNeighbour(int neighbour);

    /**
     * sets the vector tempConcentrations to 0
     */
    void resetTempProteinConcentrations();

    /**
     * sets the vector tempCoordinates to 0
     */
    void resetTempCoordinates();

    /**
     * Deletes all the border points
     */
    void deleteBorderPoints();

    /**
     * Deletes all the perimeter parts
     */
    void deletePerimeterParts();

    /**
     * Deletes all the area parts
     */
    void deleteAreaParts();

    void deleteMarginPoints();

    /**
     * Calculates the new position of the cell by adding the temp coordinates multiplied with delta
     * @param delta
     */
    void updateCoordinates(double delta);

};

inline double Cell::getX() const {
    return x;
}

inline double Cell::getY() const {
    return y;
}

inline double Cell::getZ() const {
    return z;
}

inline double Cell::getTempX() const {
    return tempX;
}

inline double Cell::getTempY() const {
    return tempY;
}

inline double Cell::getTempZ() const {
    return tempZ;
}

inline const std::vector<double> &Cell::getOriginalDistances() const {
    return originalDistances;
}

inline int Cell::getID() const {
    return ID;
}

inline double Cell::getDiffState() const {
    return diffState;
}

inline std::vector<int> Cell::getNeighbours() const {
    return neighbours;
}

inline int Cell::getNrOfNeighbours() const {
    return nrOfNeighbours;
}

inline bool Cell::isKnotCell() const {
    return knot;
}

inline bool Cell::isInSimulation() const {
    return inSimulation;
}

inline bool Cell::isInCentre() const {
    return inCentre;
}

inline int Cell::getMesenchymeThickness() const {
    return mesenchymeThickness;
}

inline std::vector<std::vector<double>> Cell::getBorderPoints() const {
    return borderPoints;
}

inline std::vector<std::vector<double>> Cell::getMarginPoints() const {
    return marginPoints;
}

inline const std::vector<double> &Cell::getPerimeterParts() const {
    return perimeterParts;
}

inline const std::vector<double> &Cell::getAreaParts() const {
    return areaParts;
}

inline double Cell::getPerimeter() const {
    return perimeter;
}

inline double Cell::getCellArea() const {
    return cellArea;
}

inline double Cell::getMargin() const {
    return margin;
}

inline std::vector<std::vector<double>> &Cell::getProteinConcentrations() {
    return proteinConcentrations;
}

inline const std::vector<std::vector<double>> &Cell::getTempProteinConcentrations() const {
    return tempProteinConcentrations;
}

//Setter

inline void Cell::addX(double newX) {
    Cell::x += newX;
}

inline void Cell::addY(double newY) {
    Cell::y += newY;
}

inline void Cell::addZ(double newZ) {
    Cell::z += newZ;
}

inline void Cell::setID(int newID) {
    Cell::ID = newID;
}

inline void Cell::addDiffState(double addedDiffState) {
    Cell::diffState += addedDiffState;
    if (diffState > 1) {
        diffState = 1;
    }
}

inline void Cell::setKnotCell(bool knot) {
    Cell::knot = knot;
}

inline void Cell::addNeighbour(int neighbourID) {
    Cell::neighbours.push_back(neighbourID);
    Cell::incrementNrOfNeighbours();
}

inline void Cell::incrementNrOfNeighbours() {
    Cell::nrOfNeighbours += 1;
}

inline void Cell::setNeighbour(int position, int newNeighbourID) {
    neighbours[position] = newNeighbourID;
}

inline void Cell::replaceNeighbour(int oldNeighbourID, int newNeighbourID) {
    /*for (auto neighbour : Cell::neighbours) {
        if (neighbour == oldNeighbourID) {
            neighbour = newNeighbourID;
            return;
        }
    }*/

    for (int neighbour = 0; neighbour < Cell::neighbours.size(); ++neighbour) {
        if (Cell::neighbours[neighbour] == oldNeighbourID) {
            setNeighbour(neighbour, newNeighbourID);
            return;
        }
    }
}

inline void Cell::insertNeighbour(int newNeighbourID, int position) {
    Cell::neighbours.insert(Cell::neighbours.begin() + position, newNeighbourID);
    Cell::incrementNrOfNeighbours();
}

inline void Cell::setInSimulation(bool inSimulation) {
    Cell::inSimulation = inSimulation;
}

inline void Cell::setInCentre(bool inCentre) {
    Cell::inCentre = inCentre;
}

inline void Cell::newBorderPoint(double x, double y, double z) {
    std::vector<double> newPoint = {x, y, z};
    borderPoints.push_back(newPoint);
}

inline void Cell::newMarginPoint(double x, double y, double z) {
    std::vector<double> newPoint = {x, y, z};
    marginPoints.push_back(newPoint);
}

inline void Cell::newPerimeterPart(double perimeterPart) {
    perimeterParts.push_back(perimeterPart);
}

inline void Cell::newAreaPart(double areaPart) {
    areaParts.push_back(areaPart);
}

inline void Cell::setPerimeter(double perimeter) {
    Cell::perimeter = perimeter;
}

inline void Cell::setCellArea(double cellArea) {
    Cell::cellArea = cellArea;
}

inline void Cell::setMargin(double margin) {
    Cell::margin = margin;
}

inline void Cell::setMarginArea(double area) {
    Cell::marginArea = area;
}

inline void Cell::addProteinConcentration(int protein, int layer, double addedConcentration) {
    proteinConcentrations[protein][layer] += addedConcentration;
}

inline void Cell::addTempConcentration(int protein, int layer, double addedConcentration) {
    tempProteinConcentrations[protein][layer] += addedConcentration;
}

inline void Cell::setProteinConcentration(int protein, int layer, double newConcentration) {
    proteinConcentrations[protein][layer] = newConcentration;
}

inline void Cell::addTempX(double tempX) {
    Cell::tempX += tempX;
}

inline void Cell::addTempY(double tempY) {
    Cell::tempY += tempY;
}

inline void Cell::addTempZ(double tempZ) {
    Cell::tempZ += tempZ;
}

inline void Cell::multiplyTempX(double tempX) {
    Cell::tempX = Cell::tempX * tempX;
}

inline void Cell::multiplyTempZ(double tempZ) {
    Cell::tempZ = Cell::tempZ * tempZ;
}

inline void Cell::addOriginalDistance(double distance, int position) {
    Cell::originalDistances.insert(Cell::originalDistances.begin() + position, distance);
}

inline void Cell::replaceOriginalDistance(double distance, int position) {
    originalDistances[position] = distance;
}

//Constructor
inline Cell::Cell(double x, double y, double z, int ID) : x(x), y(y), z(z), ID(ID) {
    knot = false;
    inSimulation = false;
    inCentre = false;
    mesenchymeThickness = 4;
    diffState = 0;
    tempX = 0;
    tempY = 0;
    tempZ = 0;
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
    margin = 0;
    marginArea = 0;
    nrOfNeighbours = 0;
}

//Editors

inline void Cell::deleteNeighbour(int neighbour) {
    neighbours.erase(neighbours.begin() + neighbour);
}

inline void Cell::resetTempProteinConcentrations() {
    for (int layer = 0; layer < mesenchymeThickness; ++layer) {
        for (int protein = 0; protein < 4; ++protein) {
            tempProteinConcentrations[protein][layer] = 0;
        }
    }
}

inline void Cell::resetTempCoordinates() {
    tempX = 0;
    tempY = 0;
    tempZ = 0;
}

inline void Cell::deleteBorderPoints() {
    Cell::borderPoints.clear();
}

inline void Cell::deletePerimeterParts() {
    Cell::perimeterParts.clear();
}

inline void Cell::deleteAreaParts() {
    Cell::areaParts.clear();
}

inline void Cell::deleteMarginPoints() {
    Cell::marginPoints.clear();
}

inline void Cell::updateCoordinates(double delta) {
    // There cannot be any force in negative z-direction due to the pressure of the stelate
    if (Cell::tempZ < 0) {
        Cell::tempZ = 0;
    }

    //There is no force at all in z-direction, if the cell is an EK-cell
    if (Cell::isKnotCell()) {
        Cell::tempZ = 0;
    }

    //Apply the forces on the positions
    Cell::x += Cell::tempX * delta;
    Cell::y += Cell::tempY * delta;
    Cell::z += Cell::tempZ * delta;
}

#endif //TOOTHMAKER_CELL_H
