#include "controller.hpp"

#include "multiple_worker.hpp"
#include "single_worker.hpp"

Controller::Controller(size_t bulkSize) : m(), mSource(""), mSubscribers() {
  mSubscribers.push_back(
      SingleWorker::createWorker(static_cast<handle_t>(this), bulkSize));
  mSubscribers.push_back(MultipleWorker::createWorker(this));
}

void Controller::push(PublisherPtr subscriber) {
  mSubscribers.push_back(subscriber);
}

void Controller::add(const char *buffer, const size_t size) {
  lock_guard guard(m);

  mSource.append(buffer, size);
  auto nextLine = mSource.find("\n");

  while (nextLine != std::string::npos) {
    auto command = mSource.substr(0, nextLine);
    mSource.erase(0, nextLine + 1);

    for (const auto &subscriber : mSubscribers)
      subscriber->parse(command);

    nextLine = mSource.find("\n");
  }
}
