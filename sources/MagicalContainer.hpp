#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <algorithm>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> mainElements;
        std::vector<int*> ascendingElements;
        std::vector<int*> sideCrossElements;
        std::vector<int*> primeElements;

    public:
        MagicalContainer() = default;
        ~MagicalContainer() = default;

        void addElement(int element);
        void removeElement(int element);
        int size() const;
        std::vector<int> getElements() const;

        // Helper functions
        void addAscendingElements();
        void addSideCrossElements();
        void addPrimeElements();

        MagicalContainer(const MagicalContainer& other) = default;
        MagicalContainer& operator=(const MagicalContainer& other) = default;
        MagicalContainer(MagicalContainer&& other) = default;
        MagicalContainer& operator=(MagicalContainer&& other) = default;

        class AscendingIterator {
        private:
            MagicalContainer& container;
            std::vector<int*>::iterator ascendingIterator;
            size_t index;

        public:
            AscendingIterator(MagicalContainer& cont);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator() = default;

            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;

            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;

            AscendingIterator& operator=(const AscendingIterator& other);

            int operator*() const;

            AscendingIterator& begin();
            AscendingIterator& end();
        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            std::vector<int*>::iterator sideCrossIterator;
            size_t index;

        public:
            SideCrossIterator(MagicalContainer& cont);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator() = default;

            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;

            SideCrossIterator& operator++();

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;

            SideCrossIterator& operator=(const SideCrossIterator& other);

            int operator*() const;

            SideCrossIterator& begin();
            SideCrossIterator& end();
        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            std::vector<int*>::iterator primeIterator;
            size_t index;

        public:
            PrimeIterator(MagicalContainer& cont);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator() = default;

            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

            PrimeIterator& operator++();

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;

            PrimeIterator& operator=(const PrimeIterator& other);

            int operator*() const;

            PrimeIterator& begin();
            PrimeIterator& end();
        };
    };

}

#endif
