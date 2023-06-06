#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// MagicalContainer implementation

// Default constructor
MagicalContainer::MagicalContainer() {}

// Copy constructor
MagicalContainer::MagicalContainer(const MagicalContainer& other) : elements(other.elements){}

// Destructor
MagicalContainer::~MagicalContainer() {
    // Deallocate memory for each prime element in the 'primeElements' vector
    for(int* element : primeElements){
        delete element;
    }
}


void MagicalContainer::addElement(int element) {
    // Insert the element into the 'elements' vector in ascending order
    auto it = std::lower_bound(elements.begin(), elements.end(), element); // for inserts elements in ascending order
    elements.insert(it, element);

    // Check if the element is prime for insert hin to the prime vector
    if(isPrime(element)){
        int* find_element = new int(element);
        // Insert the new prime element into the 'primeElements' vector in ascending order
        auto it = std::lower_bound(primeElements.begin(), primeElements.end(), find_element, [](const int *x,const int *y) { return ((*x) < (*y)); });
        getPrimeElements().insert(it, find_element);
    }
    //For this question I used the link: https://stackoverflow.com/questions/49581998/using-lower-bound-with-vector-of-object-pointers
}

//remove the element from the container
void MagicalContainer::removeElement(int element) {
    // Find the iterator pointing to the element in the 'elements' vector
    auto it = std::find(elements.begin(), elements.end(), element);

    if (it == elements.end()) {     // Check if the element was found
        throw runtime_error("Element not found");
    }
    elements.erase(it);     // Erase the element from the 'elements' vector

    if(isPrime(element)){     // Check if the element is prime

        int* PrimeElement= new int(element);
        // Find the iterator pointing to the prime element in the 'primeElements' vector
        auto it = std::find(primeElements.begin(), primeElements.end(), PrimeElement);
        // Erase the prime element from the 'primeElements' vector
        primeElements.erase(it);
        // Deallocate the memory for the prime element that erased
        delete PrimeElement;
    }
}

//return the size of the vector
int MagicalContainer::size() const {
    return elements.size();
}

//helper function to check if number is prime
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

//getters & setters
std::vector<int>& MagicalContainer::getElements() {
    return elements;
}

void MagicalContainer::setElements(std::vector<int>& elements) {
    this->elements = std::move(elements);
}

std::vector<int*>& MagicalContainer::getPrimeElements(){
    return this->primeElements;
}