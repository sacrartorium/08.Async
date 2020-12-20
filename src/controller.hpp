#pragma once

/**
 @file
 Заголовочный файл, содержащий описание подсистемы, управляющей подписчиками.
 */

#include "publisher.hpp"
#include <mutex>

struct Controller {
  using lock_guard = std::lock_guard<std::mutex>;

  Controller(size_t bulkSize);

  void push(PublisherPtr subscriber);

  void add(const char *buffer, const size_t size);

private:
  std::mutex m;
  std::string mSource;
  std::vector<PublisherPtr> mSubscribers;
};
