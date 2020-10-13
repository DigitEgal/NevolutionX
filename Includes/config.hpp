#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "../3rdparty/json.hpp"
#include <string>

class ftpConfig {
  bool enable;
  std::string username;
  std::string password;
  int port;
public:
  ftpConfig();

  bool getEnabled() const { return enable; }
  const std::string& getUser() const { return username; }
  const std::string& getPassword() const { return password; }
  int getPort() const { return port; }

  void setEnabled(bool val);
  void setUser(std::string const& username);
  void setPassword(std::string const& password);
  void setPort(int port);
};
void to_json(nlohmann::json& j, ftpConfig const& f);
void from_json(nlohmann::json const& j, ftpConfig& f);

/*============================================================================*/
/*                                      SNTP                                  */
/*============================================================================*/
class sntpConfig {
  bool enable;
  std::string address;
  int port;
public:
  sntpConfig();

  bool getEnabled() const {return enable; }
  const std::string& getAddress() const { return address; }
  int getPort() const { return port; }

  void setEnabled(bool val);
  void setAddress(std::string const& addr);
  void setPort(int p);
};
void to_json(nlohmann::json& j, sntpConfig const& s);
void from_json(nlohmann::json const& j, sntpConfig& s);


/*============================================================================*/
/*                                Settings                                    */
/*============================================================================*/
class Settings {
public:
  Settings() = default;
  ftpConfig ftp;
  sntpConfig sntp;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings, ftp, sntp)

class Config {
  bool changed = false;
public:
  Config();

  void setChanged();
  void storeToDisk();
  Settings settings;
  nlohmann::json menu;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Config, menu, settings)

#endif
