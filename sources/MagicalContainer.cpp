#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool isPrime(int num) {
    if (num <= 1)
        return false;
    for(int i=2; i<=sqrt(num); i++){
        if(num % i==0) return false;
    }
    return true;
}


namespace ariel {

    // MagicalContainer

    void MagicalContainer::addAscendingElements() {
        ascendingElements.clear();
        for (auto it = mainElements.begin(); it != mainElements.end(); ++it) {
            ascendingElements.push_back(&(*it));
        }
        // Sort the pointers in ascending order based on their pointed values
        sort(ascendingElements.begin(), ascendingElements.end(), [](int* a, int* b) {return *a < *b;});
        
    }

    // Add the pointers to the first and last elements, then second and second-to-last elements,
    // and so on, forming a "side-cross" pattern.
    void MagicalContainer::addSideCrossElements() {
        sideCrossElements.clear();
        auto start = mainElements.begin();
        auto end = --mainElements.end();

        while (start < end) {
            sideCrossElements.push_back(&(*start));
            sideCrossElements.push_back(&(*end));
            start++;
            end--;
        }
        if (start == end) {
            sideCrossElements.push_back(&(*start));
        }
        
    }

    // Add the pointers to elements that are prime numbers in the mainElements vector.
    void MagicalContainer::addPrimeElements() {
        primeElements.clear();
        for (auto it = mainElements.begin(); it != mainElements.end(); ++it) {
            if (isPrime(*it)) {
                primeElements.push_back(&(*it));
            }
        }   
    }

    void MagicalContainer::addElement(int element) {
        if (find(mainElements.begin(), mainElements.end(), element) != mainElements.end()) {
            cout << "Element already exists, do not add it again" << endl;
            return;
        }
        // Update the auxiliary containers after adding a new element to the mainElements vector.
        mainElements.push_back(element);

        addAscendingElements();
        addSideCrossElements();
        addPrimeElements();
        
    }

    void MagicalContainer::removeElement(int element) {
        auto it = find(mainElements.begin(), mainElements.end(), element);
        if (it == mainElements.end()) {
            throw runtime_error("Invalid argument");
        }
        // Update the auxiliary containers after removing an element from the mainElements vector
        mainElements.erase(it);

        addAscendingElements();
        addSideCrossElements();
        addPrimeElements();
        .
    }
    // Return the size of the mainElements vector.
    int MagicalContainer::size() const {
        return mainElements.size();
        
    }
    // Return a copy of the mainElements vector.
    vector<int> MagicalContainer::getElements() const {
        return mainElements;
        
    }

    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : container(container), ascendingIterator(container.ascendingElements.begin()), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : container(other.container), ascendingIterator(other.ascendingIterator), index(other.index) {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if (ascendingIterator == container.ascendingElements.end()) {
            throw runtime_error("Out of range");
        }
        ++ascendingIterator;
        ++index;
        return *this;
        // Increment the iterator and index by one.
    }

    // Check if two iterators are pointing to the same index.
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Invalid argument");
        }
        return index == other.index;
        
    }

    // Check if two iterators are pointing to different indices.
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index != other.index;
        
    }

    // Check if the iterator is pointing to an index greater than the other iterator's index.
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index > other.index;
        
    }

    // Check if the iterator is pointing to an index less than the other iterator's index.
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index < other.index;
        
    }

    // Assign the iterator and index values from another iterator.
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("Iterators are pointing at different containers");
        }

        ascendingIterator = other.ascendingIterator;
        index = other.index;
        return *this;
        
    }

    // Dereference the iterator and return the pointed value.
    int MagicalContainer::AscendingIterator::operator*() const {
        if (ascendingIterator == container.ascendingElements.end()) {
            throw out_of_range("Out of range");
        }
        return **ascendingIterator;
        
    }

    // Set the iterator to the beginning of the ascendingElements vector and index to 0.
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
        ascendingIterator = container.ascendingElements.begin();
        index = 0;
        return *this;
        
    }

    // Set the iterator to the end of the ascendingElements vector and index to its size.
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
        ascendingIterator = container.ascendingElements.end();
        index = container.ascendingElements.size();
        return *this;
        
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : container(container), sideCrossIterator(container.sideCrossElements.begin()), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : container(other.container), sideCrossIterator(other.sideCrossIterator), index(other.index) {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (sideCrossIterator == container.sideCrossElements.end()) {
            throw runtime_error("Out of range");
        }
        ++sideCrossIterator;
        ++index;
        return *this;
        // Increment the iterator and index by one.
    }

    // Check if two iterators are pointing to the same index.
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index == other.index;
        
    }

    // Check if two iterators are pointing to different indices.
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index != other.index;
        
    }

    // Check if the iterator is pointing to an index greater than the other iterator's index.
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index > other.index;
        
    }

    // Check if the iterator is pointing to an index less than the other iterator's index.
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index < other.index;
        
    }

    // Assign the iterator and index values from another iterator.
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("Iterators are pointing at different containers");
        }

        sideCrossIterator = other.sideCrossIterator;
        index = other.index;
        return *this;
    }
    
    // Dereference the iterator and return the pointed value.
    int MagicalContainer::SideCrossIterator::operator*() const {
        if (sideCrossIterator == container.sideCrossElements.end()) {
            throw out_of_range("Out of range");
        }
        return **sideCrossIterator;
        
    }

    // Set the iterator to the beginning of the sideCrossElements vector and index to 0.
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
        sideCrossIterator = container.sideCrossElements.begin();
        index = 0;
        return *this;
        
    }

    // Set the iterator to the end of the sideCrossElements vector and index to its size.
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
        sideCrossIterator = container.sideCrossElements.end();
        index = container.sideCrossElements.size();
        return *this;
        
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(container), primeIterator(container.primeElements.begin()), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : container(other.container), primeIterator(other.primeIterator), index(other.index) {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if (primeIterator == container.primeElements.end()) {
            throw runtime_error("Out of range");
        }
        ++primeIterator;
        ++index;
        return *this;
        // Increment the iterator and index by one.
    }

    // Check if two iterators are pointing to the same index.
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index == other.index;
        
    }

    // Check if two iterators are pointing to different indices.
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index != other.index;
        
    }

    // Check if the iterator is pointing to an index greater than the other iterator's index.
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index > other.index;
        
    }

    // Check if the iterator is pointing to an index less than the other iterator's index.
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        if (&container != &other.container) {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return index < other.index;
        
    }

    // Assign the iterator and index values from another iterator.
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("Iterators are pointing at different containers");
        }

        primeIterator = other.primeIterator;
        index = other.index;
        return *this;
        
    }

    // Dereference the iterator and return the pointed value.
    int MagicalContainer::PrimeIterator::operator*() const {
        if (primeIterator == container.primeElements.end()) {
            throw out_of_range("Out of range");
        }
        return **primeIterator;
        
    }

    // Set the iterator to the beginning of the primeElements vector and index to 0.
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
        primeIterator = container.primeElements.begin();
        index = 0;
        return *this;
        
    }

    // Set the iterator to the end of the primeElements vector and index to its size.
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
        primeIterator = container.primeElements.end();
        index = container.primeElements.size();
        return *this;
        
    }



} // namespace ariel
