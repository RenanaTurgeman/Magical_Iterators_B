//
// Created by renana on 6/5/23.
//

#include "MagicalContainer.hpp"
using namespace ariel;
using namespace std;

MagicalContainer::MyIterator::MyIterator(MagicalContainer& container) : container(container), index(0), move(true){}

MagicalContainer::MyIterator::MyIterator(const MyIterator& other) : container(other.container), index(other.index), move(other.move) {}

//Equality comparison
bool MagicalContainer::MyIterator::operator==(const MyIterator& other_iterator) const{
    if (typeid(*this) != typeid(other_iterator)) {
        throw std::runtime_error("Cannot compare iterators of different types");
    }

    return this->getIndex() == other_iterator.getIndex();
}

// Inequality comparison
bool MagicalContainer::MyIterator::operator!=(const MyIterator& other_iterator) const{
    return !(*this == other_iterator);
}

// Assignment operator
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator=(const MyIterator &other){
    if (&container != &other.container) {
        throw std::runtime_error("Iterators are pointing to different containers.");
    }
    index = other.index;
    return *this;
}

// GT, LT comparison:
bool MagicalContainer::MyIterator::operator>(const MyIterator& other) const {
    return index > other.index;
}
bool MagicalContainer::MyIterator::operator<(const MyIterator& other) const{
    return index < other.index;
}

// Move assignment operator
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator=(MyIterator &&other) noexcept {
    if(this != &other) {
        this->container = std::move(other.container);
        this->index = other.index;
        this->move = other.move;
    }
    return *this;
}

//move constructor
MagicalContainer::MyIterator::MyIterator(MyIterator&& other) noexcept
    : container(other.container), index(other.index), move(other.move) {}

//getters and setters
int MagicalContainer::MyIterator::getIndex() const{
    return index;
}

void MagicalContainer::MyIterator::setIndex(int other){
    this->index = other;
}
MagicalContainer& MagicalContainer::MyIterator::getMyContainer() const{
    return this->container;
}
bool MagicalContainer::MyIterator::getMove() const{
    return this->move;
}
void MagicalContainer::MyIterator::setMove(bool move){
    this->move = move;
}
