#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace ariel;
using namespace std;
using ariel::Direction;


namespace ariel{

    static const int page_width = 100;
    unordered_map<int, unordered_map<int, unordered_map<int, char>>> nbook;

    void Notebook::write(int page, int row, int column, Direction direction, string text) {
        if(page < 0 || column < 0 || row < 0 || column + text.length() >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
        for(int i = 0; i < text.length(); i++) {
            if(text.at(i) < 33 || text.at(i) > 126) {
                throw invalid_argument("illegal arguments!");
            }
        }
        
    }

    string Notebook::read(int page, int row, int column, Direction direction, int length) {
        if(column + length >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
        return " ";
    }

    void Notebook::erase(int page, int row, int column, Direction direction, int length) {
        if(column + length >= page_width) {
            throw invalid_argument("illegal arguments!");
        }
    }

    void Notebook::show(int page) {

    }
}