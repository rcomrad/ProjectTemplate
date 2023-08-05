#include "parser.hpp"

#include "domain/log.hpp"

#include "file.hpp"

std::optional<file::Variable>
file::Parser::makeVariable(const std::string& aStr) noexcept
{
    std::optional<Variable> result;

    int num = aStr.find('=');
    if (num != std::string::npos)
    {
        Variable temp;

        for (size_t i = 0; i < num; ++i)
        {
            if (std::islower(aStr[i]) || std::isupper(aStr[i]) ||
                aStr[i] == '_')
            {
                temp.name += aStr[i];
            }
        }

        temp.value.str = aStr.substr(num + 2, aStr.size());
        normalize(temp.name, Type::Lower);
        result = std::move(temp);
    }

    return result;
}

std::vector<file::Variable>
file::Parser::getVariablesFromFile(const std::string aFilename,
                                   bool aIsCritical) noexcept
{
    std::vector<Variable> result;

    auto lines = file::File::getLines(aFilename, aIsCritical);
    for (auto& str : lines)
    {
        auto temp = file::Parser::makeVariable(str);
        if (temp.has_value())
        {
            result.emplace_back(std::move(temp.value()));
        }
        else
        {
            dom::writeError("Line '", str, "' from ", aFilename,
                            " doesn't contain variable");
            continue;
        }
    }

    return result;
}

std::vector<std::string>
file::Parser::slice(const std::string& aStr, char delimiter) noexcept
{
    std::vector<std::string> result(1);

    for (auto& i : aStr)
    {
        if (std::isalpha(i) || i == '_' || i == '~')
        {
            result.back().push_back(i);
        }
        if (i == ',')
        {
            result.emplace_back();
        }
    }

    return result;
}

void
file::Parser::normalize(std::string& aStr, Type aType) noexcept
{
    if (aType == Type::Upper)
    {
        for (auto& i : aStr)
            if (std::islower(i)) i = std::toupper(i);
    }
    else if (aType == Type::Lower)
    {
        for (auto& i : aStr)
            if (std::isupper(i)) i = std::tolower(i);
    }
}

std::string
file::Parser::normalize(const std::string& aStr, Type aType) noexcept
{
    std::string result = aStr;
    normalize(result, aType);
    return result;
}
