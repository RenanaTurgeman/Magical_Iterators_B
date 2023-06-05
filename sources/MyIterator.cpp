//
// Created by renana on 6/5/23.
//

#include "MagicalContainer.hpp"

MagicalContainer::MyIterator::MyIterator(MagicalContainer& container) : container(container), index(0), move(true){}

MagicalContainer::MyIterator::MyIterator(const MyIterator& other) : container(other.container), index(other.index), move(other.index) {}

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
