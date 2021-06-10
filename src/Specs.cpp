#include "Specs.h"

int Specs::getMaxWidth() const
{
    int maxWidth = 0;

    for (int i : m_widths)
    {
        if (i > maxWidth)
        {
            maxWidth = i;
        }
    }
    return maxWidth;
}
int Specs::getMaxHeight() const
{
    int maxHeight = 0;

    for (int i : m_heigths)
    {
        if (i > maxHeight)
        {
            maxHeight = i;
        }
    }
    return maxHeight;
}
int Specs::getAvgWidth() const
{
    int sumWidth = 0;
    for(int i=0; i<m_widths.size(); i++){
        sumWidth+=m_widths[i];
    }

    return sumWidth/m_widths.size();
}
int Specs::getAvgHeight() const
{
    int sumHeight = 0;
    for(int i=0; i<m_heigths.size(); i++){
        sumHeight+=m_heigths[i];
    }

    return sumHeight/m_heigths.size();
    
}

void Specs::parseFromFile(const std::string file_path)
{
    std::ifstream myfile;
    std::string str; // file line iterator

    myfile.open(file_path, std::ios::in);

    const std::string startfileseq = "begin"; //from requirements file
    const std::string endfileseq = "end";     //from requirements file
    const std::string beginseq = "~~";        //from requirements file
    const std::string endseq = "??";          //from requirements file
    const std::string delimiter = "!-!";      //from requirements file

    std::string parsedata;
    bool doiter = false;

    std::cout<<"Started parsing file.."<< std::endl;

    if (myfile.is_open())
    {
        for (std::string line = ""; std::getline(myfile, str);)

        {
            if (str == startfileseq)
            {
                doiter = true; // setting the flag to be true for first found instance of 'begin'
            }
            if (doiter)
            {

                if (str.rfind(" ~~ ", 0) == 0) // parse line only for found pattern match
                {
                    std::string::size_type i = str.find(beginseq);
                    if (i != std::string::npos)
                    {
                        str.erase(i, beginseq.length()); // erase the ~~ from the beginning
                    }

                    std::string widthParsed = str.substr(0, str.find(delimiter));

                    std::string heightParsed = str.substr(str.find(delimiter) + 3).erase(str.length() - str.find("??") + 1, 2);

                    // std::cout << heightParsed << std::endl;

                    m_widths.push_back(stoi(widthParsed));
                    m_heigths.push_back(stoi(heightParsed));
                }
            }

            if (str == "end")
            {
                doiter = false; // setting the flag to be false for first found instance of 'end'

                std::cout << "Reached end, exiting parsing file." << std::endl;
            }
        }
        
        //close the file
        myfile.close();

    }
    else
        std::cerr << "Unable to open file" << std::endl; // file opening error

}
