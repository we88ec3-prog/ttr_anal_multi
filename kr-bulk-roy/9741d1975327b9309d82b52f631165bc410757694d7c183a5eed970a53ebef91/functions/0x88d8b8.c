
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall std::_Mpunct<char>::_Tidy(void)
    private: void __thiscall std::_Mpunct<unsigned short>::_Tidy(void)
    private: void __thiscall std::_Mpunct<wchar_t>::_Tidy(void)
   
   Library: Visual Studio */

void Tidy(void)

{
  int in_ECX;
  
  FUN_00891d3d(*(undefined4 *)(in_ECX + 8));
  FUN_00891d3d(*(undefined4 *)(in_ECX + 0x10));
  FUN_00891d3d(*(undefined4 *)(in_ECX + 0x14));
  FUN_00891d3d(*(undefined4 *)(in_ECX + 0x18));
  return;
}

