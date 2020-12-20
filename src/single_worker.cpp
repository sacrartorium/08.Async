#include "single_worker.hpp"

SingleWorker::SingleWorker(handle_t id, size_t bulkSize)
    : Publisher(id), mBulkSize(bulkSize) {
  mTime = std::time(nullptr);
  mCommands = Container(bulkSize);
}

SingleWorker::~SingleWorker() {
  if (!mCommands.isEmpty())
    dump();
}

void SingleWorker::addCommand(const std::string &command) {
  if (mCommands.isEmpty())
    mTime = std::time(nullptr);

  mCommands.add(command);
}

void SingleWorker::openBrace() {
  if (!mBlockCount && !mCommands.isEmpty())
    dump();

  mBlockCount++;
}

void SingleWorker::closeBrace() {
  if (mBlockCount)
    mBlockCount--;
}

void SingleWorker::job(const std::string &command) {
  if (!mBlockCount) {
    addCommand(command);

    // The limit has been reached.
    if (mBulkSize == mCommands.size())
      dump();
  }
}

PublisherPtr SingleWorker::createWorker(handle_t id, int bulkSize) {
  return std::make_shared<SingleWorker>(id, bulkSize);
}
