#include <string>
#include "Direction.hpp"
#include <climits>

namespace ariel
{
    class Notebook
    {
        private:
        int num_pages;
        int num_rows;
        int line_len;

        public:
        Notebook(){
            num_pages = INT_MAX;
            num_rows = INT_MAX;
            line_len = 100;
        }
    void write(int page, int row, int col, Direction way, std::string s_write );
    std::string read(int page, int row, int col, Direction way, int lentgh);
    void erase(int page, int row, int col, Direction way, int lentgh);
    void show(int page);
    };
}