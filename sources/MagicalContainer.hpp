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

        void addElement(int element);
        void removeElement(int element);
        int size() const;

        //get and set to the vector
        std::vector<int>& getElements();
        void setElements(std::vector<int>& elements);
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

            //getters and setters
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
            AscendingIterator(MagicalContainer& container);     // Constructor
            AscendingIterator(const AscendingIterator& copy_container);  // Copy constructor
            AscendingIterator() = delete;     // Default constructor (deleted)
            ~AscendingIterator() = default;     // Destructor

            int& operator*() const override; //Dereference operator
            AscendingIterator& operator++() override; // Pre-increment operator

            AscendingIterator& begin()  override;
            AscendingIterator& end()  override;
        };

        class SideCrossIterator : public MyIterator{

        public:

            SideCrossIterator(const SideCrossIterator& other_container); // Copy constructor
            SideCrossIterator(); // Constructor
            ~SideCrossIterator() = default; // Destructor
            SideCrossIterator(MagicalContainer& container); // Constructor

            int& operator*() const override; //Dereference operator
            SideCrossIterator& operator++() override; // Pre-increment operator

            SideCrossIterator& begin() override;
            SideCrossIterator& end() override;

        };

        class PrimeIterator : public MyIterator{

        public:
            PrimeIterator(MagicalContainer& container); // Constructor
            int& operator*() const override; //Dereference operator
            PrimeIterator& operator++() override; // Pre-increment operator

            PrimeIterator& begin() override;
            PrimeIterator& end() override;

        };
    };//magical

}



#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H