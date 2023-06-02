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
    auto it = std::lower_bound(elements.begin(), elements.end(), element); // for inserts elements in ascending order
    elements.insert(it, element);
}

void MagicalContainer::removeElement(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        throw runtime_error("Element not found");
    }
    elements.erase(it);
}

int MagicalContainer::size() const {
    return elements.size();
}