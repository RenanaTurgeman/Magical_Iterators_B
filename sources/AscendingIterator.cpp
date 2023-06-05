//
// Created by renana on 6/1/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// AscendingIterator implementation

// AscendingIterator copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& copy_iterator)
        : MyIterator(copy_iterator.getMyContainer()){}

// AscendingIterator destructor
MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : MyIterator(container) {}

int& MagicalContainer::AscendingIterator::operator*() const {
    // Returns a reference to the value at the iterator's current position
    return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(getIndex())];
} //

// Pre-increment operator (++) overload
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if (this->getIndex() >= this->getMyContainer().getElements().size()) {
        throw std::runtime_error("Iterator is already at the end");
    }
    //update he index +1
    this->setIndex(this->getIndex()+1);
    return *this;
}

// Begin function to get the iterator pointing to the beginning of the container
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    this->setIndex(0);
    return *this;
}

// End function to get the iterator pointing to the end of the container
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    this->setIndex(this->getMyContainer().getElements().size());
    return *this;
}