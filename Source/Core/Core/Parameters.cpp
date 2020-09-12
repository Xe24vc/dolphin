#include "Parameters.h"
#include "Core/BootManager.h"
#include "Core/ConfigManager.h"
#include "Common/IniFile.h"
#include <iostream>
#include <fstream>

int ImmediateXFBenable;
bool ImmediateXFB = false;

using std::ifstream;

void Parameters::Set::GameIni(std::vector<std::string> game)
{
  SConfig& StartUp = SConfig::GetInstance();
  
  std::string game_id;
  std::optional<u16> revision;
  
  const char *file = (game.front().c_str());
  ifstream infile(file, ifstream::in);
  infile >> std::hex >> game_id;
  revision = 0;
  
  IniFile game_ini = StartUp.LoadGameIni(game_id.c_str(), revision);
  
  IniFile::Section* core_section = game_ini.GetOrCreateSection("Core");
  IniFile::Section* dsp_section = game_ini.GetOrCreateSection("DSP");
  IniFile::Section* controls_section = game_ini.GetOrCreateSection("Controls");
  IniFile::Section* video_hacks_section = game_ini.GetOrCreateSection("Video_Hacks");
  
  core_section->Get("Overclock", &StartUp.m_OCFactor, StartUp.m_OCFactor);
  core_section->Get("OverclockEnable", &StartUp.m_OCEnable, StartUp.m_OCEnable);
  video_hacks_section->Get("ImmediateXFBenable", &ImmediateXFB, ImmediateXFB);
  
  if (ImmediateXFB == true)
  {
    ImmediateXFBenable = 1;
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
