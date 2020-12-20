#include "async.hpp"

#include "controller.hpp"

#include <map>

namespace async {

using ControllerPtr = std::shared_ptr<Controller>;

std::map<handle_t, ControllerPtr> controllers;

handle_t connect(std::size_t bulk) {
  lock_guard lock(m);

  ControllerPtr controller = std::make_shared<Controller>(bulk);
  handle_t handle = static_cast<handle_t>(controller.get());

  controllers[handle] = controller;
  return handle;
}

void receive(handle_t handle, const char *data, std::size_t size) {
  lock_guard lock(m);

  ControllerPtr controller = controllers.at(handle);
  controller->add(data, size);
}

void disconnect(handle_t handle) {
  lock_guard lock(m);

  controllers.erase(handle);
}
} // namespace async
