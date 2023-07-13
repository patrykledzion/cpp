#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include <iostream>
#include <filesystem>
#include <unistd.h>
#include "xmlformatter.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

namespace fs = std::filesystem;


void copy_all(const fs::path &from, const fs::path &to)
{
    fs::path from_rel = fs::relative(from, from.parent_path());
    if(!fs::exists(to))
    {
        fs::create_directory(to);
    }

    if(!is_empty(from)) {
        for (const auto &entry: fs::directory_iterator(from)) {
            fs::path entry_rel = fs::relative(entry.path(), entry.path().parent_path());
            fs::file_status s = fs::status(entry.path());
            if (fs::is_directory(s)) {
                copy_all(entry.path(), to/entry_rel);
                fs::remove(entry.path());
            } else {
                fs::copy_file(entry.path(), to/entry_rel);
                fs::remove(entry.path());
            }
        }
    }
}

void map(const fs::path& p, int lvl){
    for(int i=0;i<lvl;i++)std::cout<<"  ";
    //fs::path rel_path= fs::relative(p,p.parent_path());
    //std::cout<<"["<<rel_path<<"]"<<std::endl;

    if(!is_empty(p)) {
        for (const auto &entry: fs::directory_iterator(p)) {
            fs::file_status s = fs::status(entry.path());
            if (fs::is_directory(s)) {
                for (int i = 0; i < lvl + 1; i++)std::cout << "  ";
                std::cout << "["<<fs::relative(entry.path(),p)<< "]" << std::endl;
                map(entry.path(), lvl+1);
            } else {
                for (int i = 0; i < lvl + 1; i++)std::cout << "  ";
                std::cout << fs::relative(entry.path(),p) << std::endl;
            }
        }
    }
}



int main()
{
    const fs::path p = R"(D:\tmp\test)";
    const fs::path p2 = R"(D:\tmp\copy_to)";

    /*while(true)
    {*/
        map(p,0);
        copy_all(p,p2);
        sleep(1);

   /* }*/

    std::string path_xml = "D:/tmp/xml/a.xml";
    auto *formatter = new xmlformatter(path_xml);
    formatter->format_file();
    formatter->write_to_file();
}
#pragma clang diagnostic pop
#pragma clang diagnostic pop