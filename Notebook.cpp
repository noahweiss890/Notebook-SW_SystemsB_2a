#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;
using ariel::Direction;


namespace ariel{
    const int page_width = 100;

    Notebook::Notebook() {

    }

    void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string text) {
        if(column + text.length() >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
    }

    string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        if(column + length >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
        return " ";
    }

    void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        if(column + length >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
    }

    void Notebook::show(unsigned int page) {

    }
}