#pragma once

#include <string>
#include <vector>

namespace Parameters
{

namespace Set
  {
    void ImmediateXFB(int value);
  }
  
class Get
  {
    public:
    bool ImmediateXFB();
  };
}
