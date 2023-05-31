#include "MagicalContainer.hpp"

//MagicalContainer functions
MagicalContainer::MagicalContainer(std::vector<int> cont): container(cont){}
MagicalContainer::MagicalContainer(){}
void MagicalContainer::addElement(int number){
    auto it = std::upper_bound(container.begin(), container.end(), number);
        container.insert(it, number);
}
void MagicalContainer::removeElement(int number){
    auto it = std::find(container.begin(), container.end(), number);
    if (it != container.end()) {    //find method return iterator for end if number is not found.
        container.erase(it);
    }
}
int MagicalContainer::size(){
    return container.size();
}
std::vector<int> MagicalContainer::getContainer(){return container;}

//AscendingIterator functions
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container):container_(container), index_(0){}
MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator& other): container_(other.container_),
index_(other.index_){}
MagicalContainer::AscendingIterator::~AscendingIterator(){}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator& other){
    if (this != &other) {
                container_ = other.container_;
                index_ = other.index_;
            }
            return *this;
    }
bool MagicalContainer::AscendingIterator::operator==( AscendingIterator& other){
    return &container_ == &other.container_ && index_ == other.index_;
}
bool MagicalContainer::AscendingIterator::operator!=( AscendingIterator& other){
    return !(*this == other);
    }
bool MagicalContainer::AscendingIterator::operator>( AscendingIterator& other){
    return index_ > other.index_;
    }
bool MagicalContainer::AscendingIterator::operator<( AscendingIterator& other){
    return index_ < other.index_;
}
int MagicalContainer::AscendingIterator::operator*(){
    return container_.container[index_];
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    ++index_;
    return *this;
    }
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
    index_ = 0;
    return *this;
    }
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
    index_ = container_.container.size();
    return *this;
    }
size_t MagicalContainer::AscendingIterator::getIndex(){return index_;}

//SideCrossIterator functions

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): container_(container),
frontIndex_(0), backIndex_(container.container.size()-1), frontTurn_(true){}
MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator& other): container_(other.container_),
frontIndex_(other.frontIndex_), backIndex_(other.backIndex_), frontTurn_(other.frontTurn_){}
MagicalContainer::SideCrossIterator::~SideCrossIterator(){}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator& other){
    if (this != &other) {
                container_ = other.container_;
                frontIndex_ = other.frontIndex_;
                backIndex_ = other.backIndex_;
                frontTurn_ = other.frontTurn_;
            }
            return *this;
    }
bool MagicalContainer::SideCrossIterator::operator==( SideCrossIterator& other){
    return &container_ == &other.container_ && frontIndex_ == other.frontIndex_ 
    && backIndex_ == other.backIndex_ && frontTurn_ == other.frontTurn_;
}
bool MagicalContainer::SideCrossIterator::operator!=( SideCrossIterator& other){
    return !(*this == other);
}
bool MagicalContainer::SideCrossIterator::operator>( SideCrossIterator& other){
    return frontTurn_ ? frontIndex_ > other.frontIndex_ : backIndex_ > other.backIndex_;
}
bool MagicalContainer::SideCrossIterator::operator<( SideCrossIterator& other){
    return frontTurn_ ? frontIndex_ < other.frontIndex_ : backIndex_ < other.backIndex_;
}
int MagicalContainer::SideCrossIterator::operator*(){
    return frontTurn_ ? container_.container[frontIndex_] : container_.container[backIndex_];
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){

    if (frontTurn_) {
            ++frontIndex_;
            frontTurn_ = false;
        }
        else {
            --backIndex_;
            frontTurn_ = true;
        }
    if(frontIndex_ > backIndex_){
    this->end();
    return *this;
    }
        return *this;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    frontIndex_ = 0;
    backIndex_ = container_.container.size() - 1;
    frontTurn_ = true;
    return *this;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    frontIndex_ = container_.container.size();
    backIndex_ = 0;
    frontTurn_ = true;
    return *this;
}

//PrimeIterator functions

MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer& container): container_(container), index_(0){}
MagicalContainer::PrimeIterator::PrimeIterator( PrimeIterator& other):container_(other.container_), index_(other.index_){}
MagicalContainer::PrimeIterator::~PrimeIterator(){}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=( PrimeIterator& other){
    if(this != &other){
        container_ = other.container_;
        index_ = other.index_;
    }
    return *this;
}
bool MagicalContainer::PrimeIterator::operator==( PrimeIterator& other){
    return &container_ == &other.container_ && index_ == other.index_;
}
bool MagicalContainer::PrimeIterator::operator!=( PrimeIterator& other){
    return !(*this == other);
}
bool MagicalContainer::PrimeIterator::operator>( PrimeIterator& other){
    return index_ > other.index_;
}
bool MagicalContainer::PrimeIterator::operator<( PrimeIterator& other){
    return index_ < other.index_;
}
int MagicalContainer::PrimeIterator::operator*(){
    return container_.container[index_];
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
    ++index_;
    findNextPrime(); //increase the index_ to point the next prime number , if not exist , return end pointer;
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    index_ = 0;
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    index_ = container_.container.size(); //last number
    return *this;
}
