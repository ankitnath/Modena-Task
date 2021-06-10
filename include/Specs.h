#ifndef SPECS_H
#define SPECS_H

#include <vector>
#include <numeric>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

#include "utils.h"


class Specs{

    private:

    std::vector<int> m_widths;
    std::vector<int> m_heigths;

    public:


    int getMaxWidth() const;
    int getMaxHeight() const;
    int getAvgWidth() const;
    int getAvgHeight() const;

    void parseFromFile(const std::string file_path);

};

#endif /*SPECS_H*/
