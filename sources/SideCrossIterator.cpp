//
// Created by renana on 6/1/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


// SideCrossIterator implementation

// Copy constructor
//MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other_iterator)
//        : container(other_iterator.container), index(other_iterator.index) {}

// Destructor
MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): MyIterator(container) {}

int& MagicalContainer::SideCrossIterator::operator*() const {
    if (this->getMove()) {
        return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(getIndex())];
    }
    return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(static_cast<int>(this->getMyContainer().getElements().size()) - static_cast<int>(getIndex()))];
}



MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (this->getIndex() >= this->getMyContainer().size()) {
        throw std::runtime_error("Iterator is already at the end");
    }
    this ->setMove(true);
   if(this->getMove()){ //move = true
       this ->setMove(false);
       if(getIndex() == getMyContainer().getElements().size() /2){
           setIndex(getMyContainer().getElements().size());
       }else{
           setIndex(getIndex()+1);
       }
   }
    return *this;
}

/*
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other_iterator) const {
    return index == other_iterator.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other_iterator) const {
    return index != other_iterator.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other_iterator) const {
    return index > other_iterator.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other_iterator) const {
    return index < other_iterator.index;
}
*/

//MagicalContainer& MagicalContainer::SideCrossIterator::getContainer() const {
//    return container;
//}

//int MagicalContainer::SideCrossIterator::getCurrentIndex() const {
//    return index;
//}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin()  {
    this->setMove(true);
    this->setIndex(0);
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    this->setIndex(false);
    this->setIndex(this->getMyContainer().getElements().size());
    return *this;
}

/*MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (&container != &other.container) {
        throw std::runtime_error("Iterators are pointing to different containers.");
    }
    index = other.index;
    return *this;
}*/
