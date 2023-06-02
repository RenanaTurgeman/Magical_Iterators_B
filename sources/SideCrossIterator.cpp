//
// Created by renana on 6/1/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


// SideCrossIterator implementation

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other_iterator)
        : container(other_iterator.container), index(other_iterator.index) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : container(container), index(0) {
    std::vector<int> sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());

    std::vector<int> crossElements(sortedElements.size());
    size_t start = 0;
    size_t end = sortedElements.size() - 1;
    for (size_t i = 0; i < crossElements.size(); i += 2) {
        crossElements[i] = sortedElements[start];
        crossElements[i + 1] = sortedElements[end];
        start++;
        end--;
    }

    container.setElements(crossElements);
}

int& MagicalContainer::SideCrossIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    ++index;
    return *this;
}

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

MagicalContainer& MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}

int MagicalContainer::SideCrossIterator::getCurrentIndex() const {
    return index;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(container);
    it.index = container.size();
    return it;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator&& other) noexcept {
if (this != &other) {
container = other.container;
index = other.index;
}
return *this;
}