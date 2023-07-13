//
// Created by Patryk on 12.07.2023.
//

#include "xmlformatter.h"

std::fstream xmlformatter::open_file() const
{
    if (filename.substr(filename.size() - 4, 4)!=".xml")
    {
        return nullptr;
    }
    std::fstream f;
    f.open(filename);

    return f;
}

int xmlformatter::format_file() {

    char c;
    std::string tmp;
    while (file >> c)
    {
        if(c=='<')
        {
            if(tmp.size()>1)
            {

                this->lines.push_back({tmp,this->current_lvl});

            }
            tmp = "";
        }

        tmp+=c;

        if(tmp.size()>=3 && tmp[0]=='<' && tmp[tmp.size()-1]=='>' && tmp[1]=='?' && tmp[tmp.size()-2]=='?')
        {
            this->lines.push_back({tmp,this->current_lvl});

            tag_t* prev_tag = tag_started;
            tag_started = new tag_t;
            tag_started->content = tmp;
            tag_started->prev = prev_tag;

            tmp = "";
            //this->current_lvl--;
        }
        else if(tmp.size()>=3 && tmp[0]=='<' && tmp[tmp.size()-1]=='>' && tmp[1]!='/' && tmp[tmp.size()-2]!='/')
        {
            this->lines.push_back({tmp,this->current_lvl});

            tag_t* prev_tag = tag_started;
            tag_started = new tag_t;
            tag_started->content = tmp;
            tag_started->prev = prev_tag;

            tmp = "";
            this->current_lvl++;
        }
        else if(tmp.size()>=4 &&tmp[0]=='<' && tmp[tmp.size()-1]=='>' && tmp[1]=='/')
        {
            this->current_lvl--;
            this->lines.push_back({tmp,this->current_lvl});

            tmp = "";
            tag_started = tag_started->prev;
        }

        else if(tmp.size()>=4 &&tmp[0]=='<' && tmp[tmp.size()-1]=='>'  && tmp[1]!='/' && tmp[tmp.size()-2]=='/')
        {
            this->lines.push_back({tmp,this->current_lvl});
            tmp = "";
        }
    }

    return 0;
}

int xmlformatter::write_to_file() {

    fs::path new_path =  fs::path(fs::path(this->filename).parent_path()/"out.xml");
    std::ofstream out_file (new_path);
    std::cout<<new_path<<'\n';
    for(const auto& line : lines)
    {
        for(int i=0;i<line.level;i++)
        {
            out_file<<"  ";
        }
        out_file<<line.text<<'\n';
    }

    return 0;
}




