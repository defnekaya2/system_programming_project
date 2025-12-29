#include "config.hpp"
#include <cstdlib>

std::string Config::getEnv(const std::string& key) {
    const char* value = std::getenv(key.c_str());
    if (value == nullptr) {
        return "";
    }
    return std::string(value);
}
