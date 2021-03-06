#ifndef MEDIS_SERVER_BLOCKING_SERVER_H_
#define MEDIS_SERVER_BLOCKING_SERVER_H_

#include <cstdint>
#include <string>

#include "lib/tcp_socket.h"
#include "medis.h"

class BlockingServer {
 public:
  BlockingServer(const std::string &addr, uint16_t port);
  BlockingServer(const BlockingServer &rhs) = delete;
  BlockingServer(BlockingServer &&rhs) = delete;
  BlockingServer &operator=(const BlockingServer &rhs) = delete;
  BlockingServer &operator=(BlockingServer &&rhs) = delete;
  ~BlockingServer() = default;

  // serve won't return to caller,
  // more specific, control flow will not return to the caller.
  // http://stackoverflow.com/questions/10538291/what-is-the-point-of-noreturn
  [[noreturn]] void serve();

 private:
  TcpSocket _tcp_socket;

  // _medis is shared among multiple threads.
  Medis _medis;
};

#endif  // MEDIS_SERVER_BLOCKING_SERVER_H_
