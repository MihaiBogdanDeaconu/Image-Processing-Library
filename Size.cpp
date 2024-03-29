#include <iostream>
#include "Size.h"

Size::Size(): width{0}, height{0}{}

Size::Size(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
}

unsigned int Size::getWidth() const
{
    return this->width;
}

unsigned int Size::getHeight() const
{
    return this->height;
}

void Size::setWidth(unsigned int newWidth)
{
    this->width = newWidth;
}

void Size::setHeight(unsigned int newHeight)
{
    this->height = newHeight;
}


bool Size::operator==(const Size& other) const
{
    return this->width == other.getWidth() && this->height == other.getHeight();
}

bool Size::operator<(const Size &other) const
{
    return (this->width * this->height) < (other.getWidth() * other.getHeight());
}

bool Size::operator<=(const Size &other) const
{
    return (this->width * this->height) <= (other.getWidth() * other.getHeight());
}

bool Size::operator>(const Size &other) const
{
    return (this->width * this->height) > (other.getWidth() * other.getHeight());
}

bool Size::operator>=(const Size &other) const
{
    return (this->width * this->height) >= (other.getWidth() * other.getHeight());
}