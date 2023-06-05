//
// Created by renana on 6/1/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// AscendingIterator implementation

// AscendingIterator copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& copy_iterator)
        : container(copy_iterator.container), index(copy_iterator.index) {}

// AscendingIterator destructor
MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : MyIterator(container) {}

// Pre-increment operator (++) overload
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() override{
    if (this->getIndex() >= this->getMyContainer().getElements().size()) {
        throw std::runtime_error("Iterator is already at the end");
    }
    //update he index +1
    this->setIndex(++this->getIndex());
    return *this;
}

// Equality operator (==) overload
/*
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other_iterator) const {
    return index == other_iterator.index;
}
*/

/*// Inequality operator (!=) overload
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other_iterator) const {
    return index != other_iterator.index;
}*/

// Begin function to get the iterator pointing to the beginning of the container
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() const override {
    this->setIndex(0);
    return *this;
}

// End function to get the iterator pointing to the end of the container
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() const override{
    this->setIndex(this->getMyContainer().getElements().size());
    return *this;
}

/*MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (&container != &other.container) {
        throw std::runtime_error("Iterators are pointing to different containers.");
    }
    index = other.index;
    return *this;
}*/

/*bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.index;
}*/
