#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>

namespace license
{
    unsigned int current_year();
    std::string current_year_string();

    class License
    {
        std::string name;
        std::string year;
        std::string text;

    public:
        virtual std::string string();
    };

    void add_prefix(std::string &in, const std::string &prefix);
    void add_sufix(std::string &in, const std::string &sufix);

    void write_out(License &license, const std::filesystem::path &infile, const std::filesystem::path &outfile, const std::string &prefix = "", const std::string &sufix = "");

    class MIT : public License
    {
    public:
        std::string name;
        std::string year;
        std::string text;

        MIT(std::string name = std::getenv("USER"), std::string year = "");

        std::string string();
    };

    class Apache2 : public License
    {
    public:
        std::string name;
        std::string year;
        std::string text;

        Apache2(std::string name = std::getenv("USER"), std::string year = "");
        std::string string();
    };

} // namespace license
