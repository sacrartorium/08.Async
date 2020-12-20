#include "publisher.hpp"

#include <fstream>
#include <sstream>

Publisher::Publisher(handle_t id) : mId(id) {}

void Publisher::parse(const std::string &line) {
  auto beginLine = ((!line.empty()) ? line.substr(0) : "");

  if (beginLine == "{")
    openBrace();
  else if (beginLine == "}")
    closeBrace();
  else
    job(line);
}

void Publisher::printBulk(std::ostream &stream) const {
  if (!mCommands.isEmpty()) {
    std::stringstream buffer;
    auto butlast = mCommands.end() - 1;
    buffer << "bulk: ";

    {
      for (auto cmd = mCommands.begin(); cmd != butlast; cmd++) {
        buffer << *cmd << ", ";
      }
      buffer << *butlast;
    }

    stream << buffer.str() << std::endl;
  };
}

void Publisher::dump() {
  dumpConsole();
  dumpFile();

  mCommands.clear();
}

void Publisher::dumpConsole() { printBulk(); }

void Publisher::dumpFile() {
  auto fileName = "bulk" + std::to_string(mTime) + "_" +
                  std::to_string((unsigned long)mId) + "_" +
                  std::to_string(rand()) + ".log";
  std::ofstream file(fileName);
  printBulk(file);
}
