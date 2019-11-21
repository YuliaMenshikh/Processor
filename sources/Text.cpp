#include "../headers/Text.h"

#include <sys/stat.h>

Text::Text() : _text(nullptr), _textSize(0) {}

Text::Text(const char* fileName) : _textSize(0), _text(nullptr)
{
    _textSize = SizeOfText(fileName);

    FILE* file = nullptr;
    OpenFile(&file, fileName);

    ++_textSize;
    _text = new char[_textSize];
    fread(_text, sizeof(char), _textSize, file);
    _text[_textSize - 1] = '\0';

    fclose(file);


    int string_count = 0;

    for (size_t i = 0; i < _textSize; ++i)
    {
        if (_text[i] == '\0' || _text[i] == '\n')
        {
            string_count++;
        }
    }
    _numberOfStrings = string_count;
    _arrayOfStringviews = new std::string_view[string_count];

    size_t j = 0;
    for (size_t i = 1; i < _textSize; ++i)
    {
        if (_text[i] == '\n' || _text[i] == '\0')
        {
            if (!j)
            {
                _arrayOfStringviews[j] = std::string_view(&_text[0], i);
            }
            else
            {
                const char* temp = &_arrayOfStringviews[j - 1][0] + _arrayOfStringviews[j - 1].length() + 1;
                _arrayOfStringviews[j] = std::string_view(temp, &_text[i] - temp);
            }
            j++;
        }
    }
}

Text::~Text()
{
    /*for (int i = 0; i < _numberOfStrings; ++i)
    {
        for(int j = 0; j < _arrayOfStringviews[i].length(); ++j)
        {
            std::cout << _arrayOfStringviews[i][j];
        }
    }*/
    delete[] _text;
}

void Text::CopyText(char **buf)
{
    char c;
    for (int i = 0; i < _textSize; ++i)
    {
        c = _text[i];
        (*buf)[i] = c;
    }
}

std::string_view Text::operator[](size_t ind)
{
    return _arrayOfStringviews[ind];
}

size_t Text::Size() const
{
    return _textSize;
}
size_t Text::StringsCount() const
{
    return _numberOfStrings;
}

void Text::OpenFile(FILE **file, const char *fileName)
{
    while (*file == nullptr) {
        *file = fopen(fileName, "r");
        if (*file == nullptr) {
            printf("Wrong name of file");
        }
    }
}

int Text::SizeOfText(const char *fileName)
{
    struct stat file_stats;
    stat(fileName, &file_stats);
    return file_stats.st_size;
}

void Text::WriteToFile(const char* fileName, const char* text, int size)
{
    FILE* file = nullptr;
    file = fopen(fileName, "w");
    for (int i = 0; i < size; ++i)
    {
        fputc(*(text + i), file);
    }
    fclose(file);
}