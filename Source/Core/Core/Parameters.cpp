#include "Parameters.h"
#include "Common/MsgHandler.h"

int ImmediateXFBenable;

void Parameters::Set::ImmediateXFB(int value)
{
  if (value == 1)
  {
    ImmediateXFBenable = 1;
  }
  
  else
  {
    ImmediateXFBenable = 0;
  }
}

bool Parameters::Get::ImmediateXFB()
{
  if (ImmediateXFBenable == 1)
  {
    return true;
  }
  
  else
  {
    return false;
  }
}
