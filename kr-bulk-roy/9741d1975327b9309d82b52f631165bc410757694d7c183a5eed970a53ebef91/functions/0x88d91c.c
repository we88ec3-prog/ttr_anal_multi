
/* Library Function - Single Match
    protected: virtual long __thiscall std::collate<char>::do_hash(char const *,char const *)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long __thiscall std::collate<char>::do_hash(collate<char> *this,char *param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = (uVar1 << 8 | uVar1 >> 0x18) + (int)*param_1;
  }
  return uVar1;
}

