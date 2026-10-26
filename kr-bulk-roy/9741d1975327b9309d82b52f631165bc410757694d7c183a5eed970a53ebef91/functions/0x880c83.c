
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall std::_Mpunct<unsigned short>::_Makpat(struct std::money_base::pattern
   &,unsigned int,unsigned int,unsigned int)
    private: void __thiscall std::_Mpunct<wchar_t>::_Makpat(struct std::money_base::pattern
   &,unsigned int,unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

void Makpat(void *param_1,uint param_2,uint param_3,uint param_4)

{
  char *_Src;
  int in_ECX;
  
  if ((((*(char *)(in_ECX + 0x28) == '\0') && (param_2 < 3)) && (param_3 < 2)) && (param_4 < 5)) {
    _Src = "+v$x+v$xv$+xv+$xv$+x+$vx+$vx$v+x+$vx$+vx+v $+v $v $+v +$v $++$ v+$ v$ v++$ v$+ v+xv$+ v$v$ +v+ $v$ ++x$v+ $v$v ++ $v$ +v"
           + ((param_3 + param_2 * 2) * 5 + param_4) * 4;
  }
  else {
    _Src = "$+xv";
  }
  _memcpy_s(param_1,4,_Src,4);
  return;
}

