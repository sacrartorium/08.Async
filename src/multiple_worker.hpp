#pragma once

/**
 @file
 Заголовочный файл, описывающий работу с группами команд.
 */

#include "publisher.hpp"

struct MultipleWorker : public Publisher {
  MultipleWorker(handle_t id);

  static PublisherPtr createWorker(handle_t id);

private:
  void openBrace() override;
  void closeBrace() override;

  void job(const std::string &command) override;
};
