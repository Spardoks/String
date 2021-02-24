#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String
{
  public:

    String();

    String(const String& other);

    String(String&& other);

    String(const char* c_str);

    ~String();

    size_t size() const;

    bool empty() const;

    size_t substr(const String& other) const;

    void replace(char source, char dest);

    String& operator=(const String& other);

    String& operator=(String&& other);

    bool operator==(const String& other) const;

    char& operator[](size_t index);

    const char& operator[](size_t index) const;

    String operator+(const String& other) const;

    friend std::ostream&  operator<<(std::ostream& out, const String& str);

  private:

    void swap(String& other);

    char* data_;

    size_t length_;
};

std::istream& operator>>(std::istream& in, String& str);

#endif // STRING_HPP
