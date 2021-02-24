/*!
\file
\brief Заголовочный файл с описанием класса String
\author Spardoks
\version 1.0
\date Февраль 2021 года

Файл хранит информацию об интерфейсе класса String
*/
#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>


/*!
\brief Класс аналог std::string
\warning Данный класс создан только в учебных целях

Класс повзоляет не уделать время работе с памятью и проще
взаимодействовать со строками
*/
class String
{
  public:

    /// \brief Стандартный конструктор
    /// \details Устанавливает длину в 0, а указатель на строку в нулевой указатель
    String();

    /// \brief Копирующий конструктор
    /// \details Полностью делает одну строку похожей на другую, выделяя при необходимости память
    String(const String& other);

    /// \brief Перемещающий конструктор
    /// \details Обменивает ресурсами строки
    String(String&& other);

    /*!
    \brief Конструктор с параметрами
    \param[in] c_str Входной массив с символами и нуль-терминатором в конце
    */
    String(const char* c_str);

    /// \brief Стандартный деструктор
    /// \details Очищает память, если она была выделена
    ~String();

    /*!
    \brief Длина строки
    \return Параметр length_
    */
    size_t size() const;

    /*!
    \brief Проверка строки на пустоту
    \return true, если она пуста, и false в противном случае
    */
    bool empty() const;

    /*!
    \brief Первое вхождение подстроки
    \param[in] other Искомая подстрока
    \return Позиция в исходной строке, с которой начинается подсртока, либо -1, если не нашлась
    \todo Можно улучшить алгоритм
    */
    size_t substr(const String& other) const;

    /*!
    \brief Замена символов
    \param[in] source Заменяемый символ
    \param[in] dest Символ, на который произойдёт замена
    */
    void replace(char source, char dest);

    /*!
    \brief Копирующее присваивание
    \param[in] other Строка для копирования
    */
    String& operator=(const String& other);

    /*!
    \brief Перемещающее присваивание
    \param[in] other Строка для обмена ресурсами
    */
    String& operator=(String&& other);

    /*!
    \brief Сравнение строк
    \param[in] other Строка для сравнения
    \return True, если строки полностью идентичны. False в противном случае
    \code
      String s1 = "aaabbb";
      String s2 = "aaabb";
      String s3 = "aaaccc";
      String s4 = "aaabbb";
      s1 == s2; // false
      s1 == s3; // false
      s1 == s4; // true
    \endcode
    */
    bool operator==(const String& other) const;

    /*!
    \brief Получение символа по индексу
    \param[in] index Индекс символа в строке (начинается с 0)
    \return Ссылка на исходный символ для возможности его поменять
    \code
      String s1 = "aaabbb";
      String s2 = "aaabbс";
      s1 == s2; // false
      s1[5] = 'c';
      s1 == s2; // true
    \endcode
    */
    char& operator[](size_t index);

    /*!
    \brief Получение символа по индексу
    \param[in] index Индекс символа в строке (начинается с 0)
    \return Константная сылка на исходный символ
            для вызова в константных методах
    \code
      // str = "aabbcc"
      void foo (const String& str) {
       ...
       str[0] = 'c'; // error
       ...
      }
    \endcode
    */
    const char& operator[](size_t index) const;

    /*!
    \brief Cклейка строк
    \param[in] other Строка, с которй надо склеить исходную
    \return Строка, равная "*this""other"
    \code
      String s1 = "aabb";
      String s2 = "ccdd";
      String s3 = "aabbccdd";
      String s4 = s1 + s2;
      s3 == s4; // true
    \endcode
    */
    String operator+(const String& other) const;

    /// \brief Вывод строки в поток
    /// \details "", если пустая
    friend std::ostream&  operator<<(std::ostream& out, const String& str);

  private:

    void swap(String& other);

    /// Представление строки в памяти
    char* data_;

    /// Информация о длине строки
    size_t length_;
};

/// \brief Получение строки из потока
std::istream& operator>>(std::istream& in, String& str);

#endif // STRING_HPP
