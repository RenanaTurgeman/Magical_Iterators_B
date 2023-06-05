#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// PrimeIterator implementation

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other_iterator)
        : MyIterator(other_iterator) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : MyIterator(container) {}

int& MagicalContainer::PrimeIterator::operator*() const {
    return *(this->getMyContainer().getPrimeElements()[(size_t)(this->getIndex())]);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    // Move to the next prime element
    if (this->getIndex() >= this->getMyContainer().getPrimeElements().size()) {
        throw std::runtime_error("Iterator has reached the end.");
    }

    this->setIndex(this->getIndex()+1);
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    this->setIndex(0);
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    this->setIndex(this->getMyContainer().getPrimeElements().size());
    return *this;
}
