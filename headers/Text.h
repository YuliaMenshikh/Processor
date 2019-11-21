#pragma once

#include <stdio.h>
#include <string_view>

class Text
{
public:
    Text();
    Text(const char* fileName);
    ~Text();

    size_t Size() const;
    size_t StringsCount() const;

    std::string_view operator[](size_t ind);
    void CopyText(char** buf);

    void WriteToFile(const char* fileName, const char* text, int size);
private:
    int SizeOfText(const char* fileName);
    void OpenFile(FILE** file, const char* fileName);

    char* _text;
    size_t _textSize;

    std::string_view* _arrayOfStringviews;

    int _numberOfStrings;
};