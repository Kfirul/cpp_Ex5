#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

namespace ariel {

class MagicalContainer {
    vector<int> mysticalElements;

public:
    // MagicalContainer() = default;
    // ~MagicalContainer() = default;

    void addElement(int element);
    void removeElement(int element);

    int size() const;
    vector<int> getElements() const;


class AscendingIterator {
    MagicalContainer& container;
    std::vector<int>::const_iterator iterator;

public:

    AscendingIterator( MagicalContainer &container);
    AscendingIterator(const AscendingIterator &other);
    ~AscendingIterator();

    bool operator==(const AscendingIterator &other) const;
    bool operator!=(const AscendingIterator &other) const;
    bool operator>(const AscendingIterator &other) const;
    bool operator<(const AscendingIterator &other) const;

    int operator*() const;
    AscendingIterator &operator++();

     AscendingIterator &begin() ;
     AscendingIterator &end() ;
};

class SideCrossIterator {
    MagicalContainer& container;
    std::vector<int>::const_iterator forwardIterator;
    std::vector<int>::const_reverse_iterator reverseIterator;
    bool forward;

public:
    SideCrossIterator( MagicalContainer &container);
    SideCrossIterator(const SideCrossIterator &other);
    ~SideCrossIterator();

    bool operator==(const SideCrossIterator &other) const;
    bool operator!=(const SideCrossIterator &other) const;
    bool operator>(const SideCrossIterator &other) const;
    bool operator<(const SideCrossIterator &other) const;

    int operator*() const;
    SideCrossIterator &operator++();

     SideCrossIterator &begin() ;
     SideCrossIterator &end() ;
};

class PrimeIterator {
    MagicalContainer& container;
    std::vector<int>::const_iterator iterator;
public:
    PrimeIterator( MagicalContainer &container);
    PrimeIterator(const PrimeIterator &other);
    ~PrimeIterator();

    bool operator==(const PrimeIterator &other) const;
    bool operator!=(const PrimeIterator &other) const;
    bool operator>(const PrimeIterator &other) const;
    bool operator<(const PrimeIterator &other) const;

    int operator*() const;
    PrimeIterator &operator++();

     PrimeIterator &begin() ;
     PrimeIterator &end() ;
};

};

} // namespace ariel

#endif // MAGICALCONTAINER_HPP
