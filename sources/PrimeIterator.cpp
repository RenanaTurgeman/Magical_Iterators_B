#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// PrimeIterator implementation

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other_iterator)
        : container(other_iterator.container), index(other_iterator.index) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(container), index(0) {
    // Skip non-prime elements
    while (index < container.size() && !isPrime(container.getElements()[static_cast<std::vector<int>::size_type>(index)])) {
        ++index;
    }
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    // Move to the next prime element
    if (index >= container.size()) {
        throw std::runtime_error("Iterator has reached the end.");
    }

    do {
        ++index;
    } while (index < container.size() && !isPrime(container.getElements()[static_cast<std::vector<int>::size_type>(index)]));

    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_iterator) const {
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
}

MagicalContainer& MagicalContainer::PrimeIterator::getContainer() const {
    return container;
}

int MagicalContainer::PrimeIterator::getCurrentIndex() const {
    return index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (&container != &other.container) {
        throw std::runtime_error("Iterators are pointing to different containers.");
    }
    index = other.index;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(container);
    it.index = container.size();
    return it;
}

bool MagicalContainer::PrimeIterator::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}