#include <vector>
#include <sstream>
#include <string>
#include <iostream>

std::size_t AVG_LENGTH = 3; // Length over which to average

int predict(std::vector<float> v)
{
    float sum = 0.0;
    for (std::vector<float>::iterator j = v.end() - AVG_LENGTH; j < v.end(); j++)
    {
        sum += *j;
    }
    if (sum < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    std::string s;
    std::vector<float> v;

    while (std::cin >> s)
    {
        // Parse string to vector
        std::stringstream stream(s);
        for (float i; stream >> i;)
        {
            v.push_back(i);
            if (stream.peek() == ',')
            {
                stream.ignore();
            }
        }
        // Print prediction
        std::cout << predict(v) << std::endl;
    }
    return 0;
}
