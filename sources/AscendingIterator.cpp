//
// Created by renana on 6/1/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// AscendingIterator implementation

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& copy_iterator)
        : container(copy_iterator.container), index(copy_iterator.index) {}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : container(container), index(0) {}

int& MagicalContainer::AscendingIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other_iterator) const {
    return index == other_iterator.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other_iterator) const {
    return index != other_iterator.index;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator it(container);
    it.index = container.size();
    return it;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator&& other) noexcept {
if (this != &other) {
container = other.container;
index = other.index;
}
return *this;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.index;
}
