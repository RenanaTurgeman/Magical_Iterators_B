#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H

#include <vector>
#include <algorithm>
#include <cstddef>

namespace ariel{

    class MagicalContainer {

    private:
        std::vector<int> elements;
        std::vector<int*> primeElements;
        bool static isPrime(int n);

    public:
        MagicalContainer(); // Default constructor
        MagicalContainer(const MagicalContainer& other); // Copy constructor
        ~MagicalContainer(); // Destructor

        std::vector<int>& getElements();
        void setElements(std::vector<int>& elements);
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        std::vector<int*>& getPrimeElements();

        class MyIterator {
        private:
            MagicalContainer& container;
            int index;
            bool move;

        public:
            MyIterator(MagicalContainer& container); //constructor
            MyIterator(const MyIterator& other); //copy constructor
            virtual ~MyIterator() = default;

            int getIndex() const;
            void setIndex(int other);
            MagicalContainer& getMyContainer() const;
            bool getMove() const;
            void setMove(bool move);

            virtual int& operator*() const = 0; //Dereference operator
            virtual MyIterator& operator++() = 0; // Pre-increment operator
            virtual MyIterator& begin() =0;
            virtual MyIterator& end() = 0;
            bool operator==(const MyIterator& other_iterator) const; //Equality comparison
            bool operator!=(const MyIterator& other_iterator) const; // Inequality comparison
            MyIterator &operator=(const MyIterator &other);   // Assignment operator
            // GT, LT comparison:
            bool operator>(const MyIterator& other) const ;
            bool operator<(const MyIterator& other) const ;

            MyIterator &operator=(MyIterator &&other) noexcept;  // Move assignment operator
            MyIterator(MyIterator&& other) noexcept; //move constructor
        };

        class AscendingIterator : public MyIterator{

        public:

            AscendingIterator(const AscendingIterator& copy_container);  // Copy constructor
            AscendingIterator() = delete;     // Default constructor (deleted)
            ~AscendingIterator();     // Destructor

            AscendingIterator(MagicalContainer& container);     // Constructor
            int& operator*() const override;
            AscendingIterator& operator++() override; // Pre-increment operator

            AscendingIterator& begin()  override;
            AscendingIterator& end()  override;
            int getCurrentIndex() const;

        };

        class SideCrossIterator : public MyIterator{

        public:

            SideCrossIterator(const SideCrossIterator& other_container); // Copy constructor
            SideCrossIterator(const SideCrossIterator&& other_container) noexcept; // Move constructor
            SideCrossIterator() : MyIterator(this->getMyContainer()) {} // Constructor
            ~SideCrossIterator(); // Destructor
            SideCrossIterator(MagicalContainer& container); // Constructor

            int& operator*() const override; //Dereference operator
            SideCrossIterator& operator++() override; // Pre-increment operator

            SideCrossIterator& begin() override;
            SideCrossIterator& end() override;

        };

        class PrimeIterator : public MyIterator{

        public:

            PrimeIterator(const PrimeIterator& other_container); // Copy constructor //todo: why he dont get from the base class
            ~PrimeIterator(); // Destructor
            PrimeIterator(MagicalContainer& container); // Constructor
            PrimeIterator(PrimeIterator &&other) noexcept; // Move constructor

            int& operator*() const override; //Dereference operator
            PrimeIterator& operator++() override; // Pre-increment operator

            PrimeIterator &operator=(PrimeIterator &&other) ; // Move assignment operator
            PrimeIterator& begin() override;
            PrimeIterator& end() override;

        };
    };//magical

}



#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H