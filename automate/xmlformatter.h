//
// Created by Patryk on 12.07.2023.
//

#ifndef AUTOMATE_XMLFORMATTER_H
#define AUTOMATE_XMLFORMATTER_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct line_t {
    std::string text;
    int level;
};

class tag_t {
public:
    std::string content;
    struct tag_t* prev{};
};


class xmlformatter {
public:


    explicit xmlformatter(std::string filename)
    {
        this->filename = std::move(filename);
        this->lines = *new std::vector<struct line_t>();
        current_lvl = 0;
        file = open_file();
        this->tag_started = new tag_t;
        this->is_tag_started = false;
    }

    int format_file();

    int write_to_file();
private:
    std::string filename;
    std::fstream file;
    std::vector<struct line_t> lines;
    int current_lvl;
    tag_t* tag_started;
    bool is_tag_started;

    [[nodiscard]] std::fstream open_file() const;


};


#endif //AUTOMATE_XMLFORMATTER_H
