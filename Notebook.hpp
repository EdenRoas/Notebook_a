#include <string>
#include "Direction.hpp"
#include <climits>
using namespace std;

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
    void write(int page, int row, int col, Direction way,const string &s_write );
    string read(int page, int row, int col, Direction way, int lentgh)const;
    void erase(int page, int row, int col, Direction way, int lentgh);
    void show(int page);
    };
}