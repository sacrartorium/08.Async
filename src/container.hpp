#pragma once

/**
 @file
 Заголовочный файл, содержащий описание контейнера, для хранения команд.
 */

#include <string>
#include <vector>

using handle_t = void *;

struct Container {
  Container() = default;
  Container(size_t size);

  /**
   Добавление новой команды.
   @param command Текстовое представление команды.
   */
  void add(const std::string &command);

  /**
    Получение команды по индексу.
    @param index
   */
  const std::string &getCommand(const int index) const;

  /**
    Очистка контейнера.
   */
  void clear();

  /**
    Количество команд в контейере.
   */
  size_t size() const;

  /**
    Проверка на пустоту.
   */
  bool isEmpty() const;

  /**
    Вернуть итератор начала контейнера.
   */
  std::vector<std::string>::const_iterator begin() const;
  /**
    Вернуть итератор конца контейнера.
   */
  std::vector<std::string>::const_iterator end() const;

private:
  std::vector<std::string> mElements;
};
