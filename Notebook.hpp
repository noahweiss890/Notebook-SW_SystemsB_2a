#include <iostream>
using namespace std;
using ariel::Direction;


namespace ariel {
    class Notebook {
        public:
            Notebook();
            void write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string text);
            string read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void show(unsigned int page);
    };
}