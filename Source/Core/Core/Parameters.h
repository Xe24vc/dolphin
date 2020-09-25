#pragma once

#include <string>
#include <vector>

namespace Parameters
{

namespace Set
  {
    void GameIni(std::vector<std::string> game);
  }
  
class Get
  {
    public:
    bool DeferEFB();
    bool ImmediateXFB();
  };
}
