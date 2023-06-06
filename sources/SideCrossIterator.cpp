//
// Created by renana on 6/1/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator() : MyIterator(this->getMyContainer()) {}
// Copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other_iterator)
        : MyIterator(other_iterator) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): MyIterator(container) {}

int& MagicalContainer::SideCrossIterator::operator*() const {
    // Check if the iterator is in "move" mode
    if (this->getMove()) {
        // Access the element at the current index from the container's elements vector
        return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(getIndex())];
    }
    // Access the element at the mirrored index from the container's elements vector
    // The mirrored index is calculated as (size - index - 1)
    return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(static_cast<int>(this->getMyContainer().getElements().size()) - static_cast<int>(getIndex()))];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    // Check if the current index is at the end of the container
    if (this->getIndex() >= this->getMyContainer().size()) {
        throw std::runtime_error("Iterator is already at the end");
    }

   if(this->getMove()){ //move = true
       this ->setMove(false);
       // Check if the current index is at the middle of the container
       if(getIndex() == getMyContainer().getElements().size() /2){
           setIndex(getMyContainer().getElements().size());
       }else{
           setIndex(getIndex()+1); // Increment the index by 1
       }
   }
   else{
       this->setMove(true);
   }
    return *this;
}

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