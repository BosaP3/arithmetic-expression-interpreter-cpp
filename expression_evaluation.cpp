//*****test****
#include <sstream>

bool isNumber(const std::string &s)
{
    std::istringstream iss(s);
    double value;
    return iss >> value >> std::ws && iss.eof();
}
