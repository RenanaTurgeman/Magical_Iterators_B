#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// MagicalContainer implementation


MagicalContainer::MagicalContainer() {
    // Default constructor
}

MagicalContainer::MagicalContainer(const MagicalContainer& other) {
    // Copy constructor
    elements = other.elements;
}

MagicalContainer::~MagicalContainer() {
    // Destructor
}

std::vector<int>& MagicalContainer::getElements() {
    return elements;
}

void MagicalContainer::setElements(std::vector<int> elements) {
    this->elements = std::move(elements);
}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}