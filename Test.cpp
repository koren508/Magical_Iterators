#include "sources/MagicalContainer.hpp"
#include "doctest.h"
using namespace ariel;

TEST_SUITE("MagicalContainer"){
    TEST_CASE("addElement and removeElement"){
    MagicalContainer container;
    CHECK_EQ(container.size(),0);
    container.addElement(1);
    container.addElement(2);
    CHECK_EQ(container.size(),2);
    container.addElement(2);
    CHECK_EQ(container.size(),3);
    container.removeElement(5);
    CHECK_EQ(container.size(),3);
    container.removeElement(2);
    CHECK_EQ(container.size(),2);
    container.removeElement(2);
    CHECK_EQ(container.size(),1);
    container.removeElement(1);
    CHECK_EQ(container.size(),0);
    }      
}
TEST_SUITE("AscendingIterator"){
    TEST_CASE("check iterator"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(1);
        container.addElement(-8);
        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator ascIter_2 = ascIter;
        ++ascIter_2;
        CHECK(ascIter < ascIter_2);
        CHECK_EQ(ascIter.operator*() , -8);
        ++ascIter;
        CHECK_EQ(ascIter.operator*() , 1);
        ++ascIter;
        CHECK_EQ(*ascIter , 5);
        ++ascIter;
        CHECK_EQ(ascIter.getIndex() , container.getContainer().size());
        CHECK(ascIter > ascIter_2);
        ascIter.begin();
        CHECK(ascIter < ascIter_2);
        CHECK_EQ(ascIter.operator*() , -8);
        ascIter.end();
        CHECK(ascIter > ascIter_2);
        CHECK_EQ(ascIter.getIndex() , container.getContainer().size());
    }
}
TEST_SUITE("SideCrossIterator"){
    TEST_CASE("check iterator"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(12);
        container.addElement(8);    //sorted container is 2,5,8,12
        MagicalContainer::SideCrossIterator crossIter(container);
        CHECK_EQ(*crossIter , 2);
        ++crossIter;
        CHECK_EQ(*crossIter , 12);
        ++crossIter;
        CHECK_EQ(*crossIter , 5);
        ++crossIter;
        CHECK_EQ(*crossIter , 8);
    }
}
TEST_SUITE("SideCrossIterator"){
    TEST_CASE("check iterator"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(11);
        container.addElement(8);    //sorted container is 2,5,8,12
        MagicalContainer::PrimeIterator primeIter(container);
        CHECK_EQ(*primeIter , 2);
        ++primeIter;
        CHECK_EQ(*primeIter , 5);
        ++primeIter;
        CHECK_EQ(*primeIter , 11);
    }
}
