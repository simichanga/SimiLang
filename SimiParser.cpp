//
// Created by simi on 31.01.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <source_location>
#include <string_view>

class SimiParser {
private:
    std::ifstream file;
    std::string fileName;
    std::vector<std::string> keyVector;
    std::map<std::string, size_t> variableMap;

public:
    SimiParser(const std::string& newFileName) : fileName(newFileName) {
        // I hate having to do this because file standards differ so much from os to os
        // I hate this. I hate this so much.
        const std::source_location location = std::source_location::current();
        std::string path = location.file_name();

        const size_t position = path.find_last_of("/");
        const size_t end = path.size() - position;

        path.erase(position, end);
        path += "/" + fileName;

        file.open(path);

        getData();
        comprehenser();
    }

    ~SimiParser() {
        file.close();
    }

    void getData() {
        for (std::string word; file >> word;)
            keyVector.push_back(word);
    }

    // Has no syntax checking, basically just be good
    void comprehenser() {
        for (size_t pos = 0; pos < keyVector.size(); pos++) {
            if (keyVector[pos] == "INT")
            {
                pos++;

                std::string variableName = keyVector[pos];
                size_t variableValue = std::stoi(keyVector[pos + 1]);

                variableMap[variableName] = variableValue;
            }

            if (keyVector[pos] == "STRING") {
                pos++;

                std::string stringName = keyVector[pos++];
                std::string stringContents;

                // Sorcery
                for (stringContents;
                    stringContents[stringContents.size() - 1] != '"';
                    stringContents += keyVector[pos++]) {}

                pos--;

                // TODO
            }

            if (keyVector[pos] == "ADD")
            {
                pos++;

                std::string variableName = keyVector[pos];

                size_t prevValue = variableMap[keyVector[pos]];
                size_t inputValue = variableMap[keyVector[pos + 1]];

                variableMap[variableName] = (prevValue + inputValue);
            }

            // Only prints out variables
            if (keyVector[pos] == "PRINT")
            {
                pos++;

                std::string parameter = keyVector[pos];

                std::cout << variableMap[keyVector[pos]];
            }
        }
    }

};