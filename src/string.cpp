#include <cstring>

#include "string.hpp"

String::String()
{
    data_ = nullptr;
    length_ = 0;
}



String::String(const String& other)
{
    data_ = nullptr;
    length_ = other.length_;

    if (length_ > 0) {
        data_ = new char[length_];
        std::memcpy(data_, other.data_, length_);
    }
}



String::String(String&& other)
{
    data_ = nullptr;
    length_ = 0;
    swap(other);
}



String::String(const char* c_str)
{
    data_ = nullptr;
    length_ = 0;

    if (c_str != nullptr) {
        while(c_str[length_] != '\0') {
            ++length_;
        }
    }

    if (length_ > 0) {
        data_ = new char[length_];
        std::memcpy(data_, c_str, length_);
    }
}



String::~String()
{
    delete[] data_;
}



String& String::operator=(const String& other)
{
    if (this == &other) {
        return *this;
    }

    if (other.length_ == 0) {
        delete[] data_;
        length_ = 0;
        return *this;
    }

    char* newData = new char[other.length_];
    std::memcpy(newData, other.data_, other.length_);
    length_ = other.length_;
    delete[] data_;
    data_ = newData;

    return *this;
}



String& String::operator=(String&& other)
{
    swap(other);

    return *this;
}



bool String::operator==(const String& other) const
{
    if (length_ != other.length_) {
        return false;
    }

    return (std::memcmp(data_, other.data_, length_) == 0);
}



size_t String::size() const
{
    return length_;
}



bool String::empty() const
{
    return length_ == 0;
}



size_t String::substr(const String& other) const
{
    if ((length_ == 0) || (other.length_ == 0) || (other.length_ > length_)) {
        return -1;
    }

    bool found = false;
    for (size_t i = 0; i < length_; ++i) {
        if ((i + other.length_) > length_) {
            return -1;
        }

        found = true;
        for (size_t j = 0; j < other.length_; ++j) {
            if (data_[i + j] != other.data_[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }

    return -1;
}



void String::replace(char source, char dest)
{
    for (size_t i = 0; i < length_; ++i) {
        if (data_[i] == source) {
            data_[i] = dest;
        }
    }
}



char& String::operator[](size_t index)
{
    return data_[index];
}



const char& String::operator[](size_t index) const
{
    return data_[index];
}



String String::operator+(const String& other) const
{
    size_t newLength = length_ + other.length_;
    if (newLength == 0) {
        return String();
    }

    char* newCstr = new char[newLength + 1];
    if (data_ != nullptr) {
        std::memcpy(newCstr, data_, length_);
    }
    if (other.data_ != nullptr) {
        std::memcpy(newCstr + length_, other.data_, other.length_);
    }

    newCstr[newLength] = '\0';
    String newString(newCstr);
    delete[] newCstr;

    return newString;
}



std::ostream& operator<<(std::ostream& out, const String& str)
{
    if (str.length_ == 0) {
        out << "";
    }
    for (size_t i = 0; i < str.length_; ++i) {
        out << str.data_[i];
    }

    return out;
}



std::istream& operator>>(std::istream& in, String& str)
{
    char buf[256];
    size_t posBuf = 0;
    String newString;

    if (in.peek() == '\n') {
        in.ignore(1);
    }
    char c = in.get();
    while (c != '\n') {
        if (posBuf == 254) {
            buf[255] = '\0';
            newString = (newString + String(buf));
            posBuf = 0;
        }
        buf[posBuf] = c;
        ++posBuf;

        c = in.get();
    }

    if (posBuf != 0) {
        buf[posBuf] = '\0';
        str = (newString + String(buf));
    } else {
        str = newString;
    }

    return in;
}


// Private
void String::swap(String& other)
{
    size_t length = length_;
    char* data = data_;

    data_ = other.data_;
    length_ = other.length_;
    other.data_ = data;
    other.length_ = length;
}
