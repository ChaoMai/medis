#ifndef MEDIS_BASE_BASE_H_
#define MEDIS_BASE_BASE_H_

#include <cerrno>   // for errno
#include <cstddef>  // for size_t
#include <cstdio>   // for sprintf
#include <cstring>  // for strerror
#include <string>
#include <vector>

struct Args {
  std::size_t _command_args_count = 0;
  std::string _command;
  std::vector<std::string> _command_args;
};

enum ItemType {
  MEDIS_INT,
  MEDIS_DOUBLE,
  MEDIS_DICT,
  MEDIS_LIST,
  MEDIS_STRING,
  MEDIS_KDTREE,
  MEDIS_ITEM
};

struct Item {
  std::size_t _key_hash;
  std::string _key;
  ItemType _type;
  void* _value_ptr;
};

constexpr int BUF_SIZE = 1024;

constexpr const char* MSG_CRLF = "\r\n";
constexpr const char* MSG = "+OK\r\n";
constexpr const char* MSG_ERR = "-ERROR\r\n";

constexpr const char MSG_CR_TAG = '\r';
constexpr const char MSG_NULL_TAG = '\0';
constexpr const char MSG_SIGLE_TAG = '*';
constexpr const char MSG_BATCH_TAG = '$';

inline std::string get_errno_str(int errnum = errno) {
  char err_str[BUF_SIZE] = {};
  sprintf(err_str, "%s", strerror(errnum));
  return std::string(err_str);
}

#endif  // MEDIS_BASE_BASE_H_
