#include "license.hpp"
#include <ctime>
#include <sstream>
#include <vector>

uint license::current_year()
{
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    return 1900 + pTInfo->tm_year;
}

std::string license::current_year_string()
{
    std::ostringstream os;
    os << license::current_year();
    return os.str();
}

std::string license::License::string()
{
    return this->text;
}

void license::add_prefix(std::string &in, const std::string &prefix)
{
    std::stringstream ss(in);
    std::string to;
    std::vector<std::string> out;

    if (!in.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            out.push_back(to);
        }
    }

    in.clear();
    for (const auto i : out)
    {
        if (!i.empty())
        {
            in.append(prefix);
        }
        in.append(i);
        in.append("\n");
    }
}

void license::add_sufix(std::string &in, const std::string &sufix)
{
    std::stringstream ss(in);
    std::string to;
    std::vector<std::string> out;

    if (!in.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            out.push_back(to);
        }
    }

    in.clear();
    for (const auto i : out)
    {

        in.append(i);
        if (!i.empty())
        {
            in.append(sufix);
        }
        in.append("\n");
    }
}

void license::write_out(license::License &license, const std::filesystem::path &infile, const std::filesystem::path &outfile, const std::string &prefix, const std::string &sufix)
{
    std::string out = license.string();
    license::add_prefix(out, prefix);
    license::add_sufix(out, sufix);
    std::ifstream ifs{infile};
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    out.append("\n").append(content);

    std::ofstream of;
    of.open(outfile);
    if (!of)
    {
        throw std::string{"unable to open "}.append(outfile);
        return;
    }
    of.clear();
    of << out;
    of.close();
}