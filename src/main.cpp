#include <iostream>
#include "./license/license.hpp"

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        return 1;
    }

    std::string name = getenv("USER");
    std::string year = license::current_year_string();
    std::string license = "MIT";
    std::string infile;
    std::string outfile;
    std::string prefix{""}, sufix{""};

    for (int i = 1; i < argc; i++)
    {
        bool bigger = false;
        std::string arg{argv[i]};
        if (argc >= i + 1)
        {
            bigger = true;
        }

        if (arg == "help" || arg == "-h")
        {
            
        }
        else if (arg == "-n" && bigger)
        {
            name = std::string{argv[i + 1]};
        }
        else if (arg == "-y" && bigger)
        {
            year = std::string{argv[i + 1]};
        }
        else if (arg == "-l" && bigger)
        {
            license = std::string{argv[i + 1]};
        }
        else if (arg == "-i" && bigger)
        {
            infile = std::string{argv[i + 1]};
        }
        else if (arg == "-o" && bigger)
        {
            outfile = std::string{argv[i + 1]};
        }
        else if (arg == "-pl" && bigger)
        {
            prefix = std::string{argv[i + 1]};
        }
        else if (arg == "-sl" && bigger)
        {
            sufix = std::string{argv[i + 1]};
        }
    }

    if (infile.empty())
    {
        std::cerr << "rt requires an input file (use -i <./filepath>)" << std::endl;
        return 1;
    }
    else if (outfile.empty())
    {
        outfile = infile;
    }

    if (license == "MIT")
    {
        auto copy = license::MIT{name, year};
        try
        {
            license::write_out(copy, infile, outfile, prefix, sufix);
        }
        catch (std::string err)
        {
            std::cerr << err << std::endl;
            return 1;
        }
    }
    return 0;
}
