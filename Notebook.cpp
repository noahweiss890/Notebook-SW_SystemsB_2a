#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;
using ariel::Direction;


namespace ariel{
    Notebook::Notebook() {

    }

    void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string text) {
        if(column + text.length() >= 100) {
            throw invalid_argument("illegal arguments!");
        }
    }

    string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        if(column + length >= 100) {
            throw invalid_argument("illegal arguments!");
        }
        return " ";
    }

    void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        if(column + length >= 100) {
            throw invalid_argument("illegal arguments!");
        }
    }

    void Notebook::show(unsigned int page) {

    }
}