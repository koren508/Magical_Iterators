#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace ariel {}

class MagicalContainer {
private:
    std::vector<int> container;

public:
    MagicalContainer(std::vector<int> cont);
    MagicalContainer();
    void addElement(int number);
    void removeElement(int number);
    int size();
    std::vector<int> getContainer();

    class AscendingIterator {
    private:
        MagicalContainer& container_;
        size_t index_;

    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator& operator=(AscendingIterator& other);
        bool operator==( AscendingIterator& other);
        bool operator!=( AscendingIterator& other);
        bool operator>( AscendingIterator& other);
        bool operator<( AscendingIterator& other);
        int operator*();
        AscendingIterator& operator++();
        AscendingIterator begin();
        AscendingIterator end();
        size_t getIndex();
    };

        class SideCrossIterator {
    private:
        MagicalContainer& container_;
        size_t frontIndex_;
        size_t backIndex_;
        bool frontTurn_;

    public:
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(SideCrossIterator& other);
        ~SideCrossIterator();
        SideCrossIterator& operator=(SideCrossIterator& other);
        bool operator==( SideCrossIterator& other);
        bool operator!=( SideCrossIterator& other);
        bool operator>( SideCrossIterator& other);
        bool operator<( SideCrossIterator& other);
        int operator*();
        SideCrossIterator& operator++();   
        SideCrossIterator begin();
        SideCrossIterator end();
    };
        class PrimeIterator {
    private:
        MagicalContainer& container_;
        size_t index_;

    public:
        PrimeIterator( MagicalContainer& container);
        PrimeIterator( PrimeIterator& other);
        ~PrimeIterator();
        PrimeIterator& operator=( PrimeIterator& other);
        bool operator==( PrimeIterator& other);
        bool operator!=( PrimeIterator& other);
        bool operator>( PrimeIterator& other);
        bool operator<( PrimeIterator& other);
        int operator*();
        PrimeIterator& operator++();
        PrimeIterator begin();
        PrimeIterator end();

    private:
        bool isPrime(int number)  {
            if (number < 2)
                return false;

            for (int i = 2; i <= sqrt(number); ++i) {
                if (number % i == 0)
                    return false;
            }

            return true;
        }

        void findNextPrime() {
            while (index_ < container_.container.size() && !isPrime(container_.container[index_]))
                ++index_;
        }
    };
};
        
#endif