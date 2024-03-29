#pragma once

class Size
{
private:
    unsigned int width;
    unsigned int height;
public:
    Size();
    Size(unsigned int width, unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setWidth(unsigned int newWidth);
    void setHeight(unsigned int newHeight);

    bool operator==(const Size &other) const;
    bool operator<(const Size &other) const;
    bool operator<=(const Size &other) const;
    bool operator>(const Size &other) const;
    bool operator>=(const Size &other) const;

};