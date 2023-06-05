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
    for(int* element : primeElements){
        delete element;
    }
}

std::vector<int>& MagicalContainer::getElements() {
    return elements;
}

void MagicalContainer::setElements(std::vector<int>& elements) {
    this->elements = std::move(elements);
}

void MagicalContainer::addElement(int element) {
    auto it = std::lower_bound(elements.begin(), elements.end(), element); // for inserts elements in ascending order
    elements.insert(it, element);

    if(isPrime(element)){
        int* find_element = new int(element);
        auto it = std::lower_bound(primeElements.begin(), primeElements.end(), find_element, [](const int *x,const int *y) { return ((*x) < (*y)); });
        getPrimeElements().insert(it, find_element);
    }
}

void MagicalContainer::removeElement(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        throw runtime_error("Element not found");
    }
    elements.erase(it);

    if(isPrime(element)){

        int* PrimeElement= new int(element);
        auto it = std::find(primeElements.begin(), primeElements.end(), PrimeElement);
        primeElements.erase(it);
        delete PrimeElement;
    }
}

int MagicalContainer::size() const {
    return elements.size();
}

bool MagicalContainer::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int*>& MagicalContainer::getPrimeElements(){
    return this->primeElements;
}