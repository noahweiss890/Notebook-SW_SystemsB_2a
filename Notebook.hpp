#include <iostream>
#include <unordered_map>
#include <iterator>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;


namespace ariel {
    class Notebook {
        int bla = 0;
        unordered_map<int, unordered_map<int, unordered_map<int, char>>> nbook;
        public:
            void write(int page, int row, int column, Direction direction, string text);
            string read(int page, int row, int column, Direction direction, int length);
            void erase(int page, int row, int column, Direction direction, int length);
            void show(int page);
    };
}