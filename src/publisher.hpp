#pragma once

/**
 @file
 Заголовочный файл, описывающий часть работы паттерна наблюдатель.
 */

#include "container.hpp"

#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Publisher {

  Publisher(handle_t id);

  /**
   Разбор строки.
   @param line Обрабатываемая строка.
   */
  void parse(const std::string &line);

  /**
   Выполнить обработку команды.
   @param command Обрабатываемая команда.
   */
  virtual void job(const std::string &command) = 0;

  /**
    Открыть блок.
   */
  virtual void openBrace() = 0;

  /**
    Закрыть блок.
   */
  virtual void closeBrace() = 0;

  /**
    Вывести команды.
   */
  void dump();

  /**
    Сброс команд в файл.
   */
  void dumpFile();

  /**
    Сброс команд в консоль.
   */
  void dumpConsole();

  /**
    Вывод списка комманд в указанный поток.
    @param stream Поток для вывода.
   */
  void printBulk(std::ostream &stream = std::cout) const;

protected:
  handle_t mId;
  std::time_t mTime = 0;
  size_t mBlockCount = 0;
  Container mCommands;
};

using PublisherPtr = std::shared_ptr<Publisher>;
