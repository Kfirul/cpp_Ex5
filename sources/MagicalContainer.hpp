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
    MagicalContainer() = default;
    ~MagicalContainer() = default;

    void addElement(int element);
    void removeElement(int element);

    int size() const;
    vector<int> getElements() const;
};

class AscendingIterator {
    const MagicalContainer *container;
    size_t index;

public:
    AscendingIterator(const MagicalContainer *container, size_t index);
    AscendingIterator(const AscendingIterator &other);
    ~AscendingIterator();

    AscendingIterator &operator=(const AscendingIterator &other);
    bool operator==(const AscendingIterator &other) const;
    bool operator!=(const AscendingIterator &other) const;
    bool operator>(const AscendingIterator &other) const;
    bool operator<(const AscendingIterator &other) const;

    int operator*() const;
    AscendingIterator &operator++();

    static AscendingIterator begin(const MagicalContainer &container);
    static AscendingIterator end(const MagicalContainer &container);
};

class SideCrossIterator {
    const MagicalContainer *container;
    size_t index;

public:
    SideCrossIterator(const MagicalContainer *container, size_t index);
    SideCrossIterator(const SideCrossIterator &other);
    ~SideCrossIterator();

    SideCrossIterator &operator=(const SideCrossIterator &other);
    bool operator==(const SideCrossIterator &other) const;
    bool operator!=(const SideCrossIterator &other) const;
    bool operator>(const SideCrossIterator &other) const;
    bool operator<(const SideCrossIterator &other) const;

    int operator*() const;
    SideCrossIterator &operator++();

    static SideCrossIterator begin(const MagicalContainer &container);
    static SideCrossIterator end(const MagicalContainer &container);
};

class PrimeIterator {
    const MagicalContainer *container;
    size_t index;

public:
    PrimeIterator(const MagicalContainer *container, size_t index);
    PrimeIterator(const PrimeIterator &other);
    ~PrimeIterator();

    PrimeIterator &operator=(const PrimeIterator &other);
    bool operator==(const PrimeIterator &other) const;
    bool operator!=(const PrimeIterator &other) const;
    bool operator>(const PrimeIterator &other) const;
    bool operator<(const PrimeIterator &other) const;

    int operator*() const;
    PrimeIterator &operator++();

    static PrimeIterator begin(const MagicalContainer &container);
    static PrimeIterator end(const MagicalContainer &container);
};

} // namespace ariel

#endif // MAGICALCONTAINER_HPP
