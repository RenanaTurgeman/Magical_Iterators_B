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
            //todo: bool move?
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

            virtual int& operator*() const; //Dereference operator
            virtual MyIterator& operator++(); // Pre-increment operator
            virtual MyIterator& begin() const;
            virtual MyIterator& end() const;
            bool operator==(const MyIterator& other_iterator) const; //Equality comparison
            bool operator!=(const MyIterator& other_iterator) const; // Inequality comparison
            AscendingIterator &operator=(const MyIterator &other);   // Assignment operator
            // GT, LT comparison:
            bool operator>(const MyIterator& other) const ;
            bool operator<(const MyIterator& other) const ;

            MyIterator &operator=(MyIterator &&other) noexcept;  // Move assignment operator
            MyIterator(MyIterator&& other) noexcept; //move constructor
        };

        class AscendingIterator {

        private:
            MagicalContainer& container;
            int index;

        public:

            AscendingIterator(const AscendingIterator& copy_container);     // Copy constructor
            AscendingIterator() = delete;     // Default constructor (deleted)
            ~AscendingIterator();     // Destructor

            AscendingIterator(MagicalContainer& container);     // Constructor

            int& operator*() const; //Dereference operator
            AscendingIterator& operator++(); // Pre-increment operator
            bool operator==(const AscendingIterator& other_iterator) const; //Equality comparison
            bool operator!=(const AscendingIterator& other_iterator) const; // Inequality comparison
            AscendingIterator &operator=(const AscendingIterator &other);   // Assignment operator
            // GT, LT comparison:
            bool operator>(const AscendingIterator& other) const ;
            bool operator<(const AscendingIterator& other) const ;

            AscendingIterator &operator=(AscendingIterator &&other);  // Move assignment operator
            AscendingIterator begin() const;
            AscendingIterator end() const;
            int getCurrentIndex() const;

            MagicalContainer& getContainer() const;
        };

        class SideCrossIterator {

        private:
            MagicalContainer& container;
            int index;

        public:

            SideCrossIterator(const SideCrossIterator& other_container); // Copy constructor
            SideCrossIterator(const SideCrossIterator&& other_container) noexcept; // Move constructor
            SideCrossIterator() =delete; // Constructor
            ~SideCrossIterator(); // Destructor
            SideCrossIterator(MagicalContainer& container); // Constructor

            int& operator*() const; //Dereference operator
            SideCrossIterator& operator++(); // Pre-increment operator
            bool operator==(const SideCrossIterator& other_iterator) const; //Equality comparison
            bool operator!=(const SideCrossIterator& other_iterator) const; // Inequality comparison
            // GT, LT comparison:
            bool operator>(const SideCrossIterator& other_iterator) const;
            bool operator<(const SideCrossIterator& other_iterator) const;
            SideCrossIterator &operator=(const SideCrossIterator &other); // Assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other) ;  // Move assignment operator

            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            MagicalContainer& getContainer() const;
            int getCurrentIndex() const;


        };

        class PrimeIterator  {

        private:

            MagicalContainer& container;
            int index;

        public:

            PrimeIterator(const PrimeIterator& other_container); // Copy constructorbv
            ~PrimeIterator(); // Destructor
            PrimeIterator(MagicalContainer& container); // Constructor
            PrimeIterator(PrimeIterator &&other) noexcept; // Move constructor

            int operator*() const; //Dereference operator
            PrimeIterator& operator++(); // Pre-increment operator
            bool operator==(const PrimeIterator& other_iterator) const; //Equality comparison
            bool operator!=(const PrimeIterator& other_iterator) const;// Inequality comparison
            // GT, LT comparison:
            bool operator>(const PrimeIterator& other_iterator) const;
            bool operator<(const PrimeIterator& other_iterator) const;
            PrimeIterator &operator=(const PrimeIterator &other); // Assignment operator
            MagicalContainer& getContainer() const;
            int getCurrentIndex() const;

            PrimeIterator &operator=(PrimeIterator &&other) ; // Move assignment operator
            PrimeIterator begin() const;
            PrimeIterator end() const;

        };
    };//magical

}



#endif // MAGICAL_ITERATORS_MAGICALCONTAINER_H