#pragma once

#include <mutex>

namespace async {

using handle_t = void *;
using lock_guard = std::lock_guard<std::mutex>;

handle_t connect(std::size_t bulk);
void receive(handle_t handle, const char *data, std::size_t size);
void disconnect(handle_t handle);

std::mutex m;

} // namespace async
