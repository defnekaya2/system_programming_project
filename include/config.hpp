#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

class Config {
public:
    static std::string getEnv(const std::string& key);
};

#endif
