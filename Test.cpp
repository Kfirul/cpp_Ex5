#include "doctest.h"
#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Check the addElement, removeElement, and size function") {
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);
    CHECK(container.size() == 1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);
    container.addElement(6);
    CHECK(container.size() == 6);
    container.removeElement(4);
    CHECK(container.size() == 5);
    container.removeElement(4);
    CHECK(container.size() == 5);
    container.removeElement(1);
    CHECK(container.size() == 4);
}

TEST_CASE("Check the ascendingIterator") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(3);
    container.addElement(1);
    container.addElement(11);
    container.addElement(8);

    MagicalContainer::AscendingIterator ascending(container);

    auto current = ascending.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 3);
    ++current;
    CHECK(*current == 7);
    ++current;
    CHECK(*current == 8);
    ++current;
    CHECK(*current == 11);
}

TEST_CASE("Check the PrimeIterator") {
    MagicalContainer container;
    container.addElement(6);
    container.addElement(3);
    container.addElement(1);
    container.addElement(11);
    container.addElement(8);

    MagicalContainer::PrimeIterator prime(container);

    auto current = prime.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 3);
    ++current;
    CHECK(*current == 11);
}

TEST_CASE("Check the SideCrossIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(1);
    container.addElement(10);
    container.addElement(9);

    MagicalContainer::SideCrossIterator side(container);

    auto current = side.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 9);
    ++current;
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 10);
    ++current;
    CHECK(*current == 5);
}

TEST_CASE("Check iterator comparisons") {
    MagicalContainer container1;
    container1.addElement(5);
    container1.addElement(2);
    container1.addElement(1);
    container1.addElement(10);
    container1.addElement(9);

    MagicalContainer container2;
    container2.addElement(5);
    container2.addElement(2);
    container2.addElement(1);
    container2.addElement(10);
    container2.addElement(9);

    MagicalContainer::AscendingIterator ascending1(container1);
    MagicalContainer::AscendingIterator ascending2(container2);

    CHECK(ascending1 == ascending2);
    container1.addElement(19);

    MagicalContainer container3;
    container3.addElement(5);
    container3.addElement(2);
    container3.addElement(1);
    container3.addElement(10);
    container3.addElement(9);
    container3.addElement(19);
    MagicalContainer::AscendingIterator ascending3(container3);

    CHECK(ascending1 != ascending3);
}
