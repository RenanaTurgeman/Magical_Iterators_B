#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// PrimeIterator implementation

//MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other_iterator)
//        : container(other_iterator.container), index(other_iterator.index) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : MyIterator(container) {}

int MagicalContainer::PrimeIterator::operator*() const {
    return this->getMyContainer().getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    // Move to the next prime element
    if (this->getIndex() >= this->getContainer().size()) {
        throw std::runtime_error("Iterator has reached the end.");
    }

    this->setIndex(++this->getIndex());
    return *this;
}

/*bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_iterator) const {
    return index == other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other_iterator) const {
    return index != other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other_iterator) const {
    return index > other_iterator.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other_iterator) const {
    return index < other_iterator.index;
}*/

//MagicalContainer& MagicalContainer::PrimeIterator::getContainer() const {
//    return container;
//}

//int MagicalContainer::PrimeIterator::getCurrentIndex() const {
//    return index;
//}

/*MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (&container != &other.container) {
        throw std::runtime_error("Iterators are pointing to different containers.");
    }
    index = other.index;
    return *this;
}*/

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() const {
    this->setIndex(0);
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() const {
    this->setIndex(this->getMyContainer().getElements().size());
    return it;
}
