#include "container.hpp"

Container::Container(size_t size) { mElements.reserve(size); }

void Container::add(const std::string &command) {
  mElements.push_back(command);
}

const std::string &Container::getCommand(const int index) const {
  return mElements.at(index);
}

void Container::clear() { mElements.clear(); }

size_t Container::size() const { return mElements.size(); }

bool Container::isEmpty() const { return mElements.empty(); }

std::vector<std::string>::const_iterator Container::begin() const {
  return mElements.cbegin();
}
std::vector<std::string>::const_iterator Container::end() const {
  return mElements.cend();
}
