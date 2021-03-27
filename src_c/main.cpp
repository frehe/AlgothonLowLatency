#include <vector>
#include <sstream>
#include <string>
#include <iostream>

std::size_t AVG_LENGTH = 3; // Length over which to average
std::size_t STRING_LENGTH = 500;

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

float test_predictor(std::vector<float> v)
{
    size_t SIZE = v.size();
    std::vector<int> preds;
    std::vector<int> labels;
    float accuracy = 0;

    for (uint16_t i = 0; i < SIZE - AVG_LENGTH; i++)
    {
        std::vector<float> slice;
        for (uint16_t k = 0; k < AVG_LENGTH; k++) {
            slice.push_back(v.at(i+k));
        }
        preds.push_back(predict(slice));
        if (v.at(i+AVG_LENGTH) < 0)
            labels.push_back(0);
        else
            labels.push_back(1);
        if (preds.back() == labels.back())
            accuracy += 1;
    }

    accuracy /= (SIZE - AVG_LENGTH);
    return accuracy;
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
        // Test predictor on all subsets of size AVG_LENGTH
        // float accuracy = test_predictor(v);
        // std::cout << "Accuracy on test: " << accuracy << std::endl;
        // Print prediction
        std::cout << predict(v) << std::endl;
    }
    return 0;
}
