#include "async.hpp"
#include "controller.hpp"
#include "multiple_worker.hpp"
#include "single_worker.hpp"

int main() {

  std::string a = "cmd-1";

  std::string b = "cmd-1\n"
                  "cmd-2\n"
                  "cmd-3\n"
                  "cmd-4\n";

  std::string c = "\n"
                  "cmd-2\n"
                  "cmd-3\n"
                  "cmd-4\n"
                  "cmd-5\n"
                  "cmd-6\n"
                  "{\n"
                  "a\n";

  std::string d = "b\n"
                  "c\n"
                  "d\n"
                  "}\n"
                  "xx\n";

  std::size_t bulk = 5;
  auto h = async::connect(bulk);
  auto h2 = async::connect(bulk);
  async::receive(h, a.c_str(), a.size());
  async::receive(h2, b.c_str(), b.size());
  async::receive(h, c.c_str(), c.size());
  async::receive(h, d.c_str(), d.size());
  async::disconnect(h);
  async::disconnect(h2);

  return 0;
}
