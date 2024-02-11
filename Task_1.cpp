#include <iostream>
#include <fstream>
#include <string>

bool checkUpper(std::string word)
{
    if (word[0] >= 65 && word[0] <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool end_letter(std::string word)
{
    int size = word.size();
    if ((word[size - 1] >= 97 && word[size - 1] <= 122) || (word[size - 1] >= 65 && word[size - 1] <= 90))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string size_1(std::string word)
{
    return word.substr(0, word.length() - 1);
}

int main()
{
    int index = 0;
    std::string db[2000]; // Հայկը ասելա նավսյակի շատ վերցրեք եթե չգիտեք հաստատ չափը 😂
    std::ifstream file("input.txt");
    std::ofstream ofile("output.txt");
    std::ifstream dbfile("db.txt");
    std::string word;
    if (!file.is_open())
    {
        std::cout << "Error in open file";
    }
    if (!ofile.is_open())
    {
        std::cout << "Error in open file";
    }

    while (dbfile >> db[index])
    {
        ++index;
    }

    while (file >> word)
    {
        if (checkUpper(word))
        {
            if (!end_letter(word))
            {
                word = size_1(word);
                std::cout << word << std::endl;
            }
            for (int i = 0; i < index; ++i)
            {
                if (word == db[i])
                {
                    word = "X";
                }
            }
        }
        ofile << word << ' ';
    }

 
    ofile.close();
    file.close();
    dbfile.close();
    return 0;
}
