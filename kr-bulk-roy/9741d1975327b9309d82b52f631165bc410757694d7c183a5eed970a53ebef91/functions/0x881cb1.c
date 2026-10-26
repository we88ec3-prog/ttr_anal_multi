
/* Library Function - Single Match
    public: char const * __thiscall std::_Locinfo::_Getdays(void)const 
   
   Library: Visual Studio 2010 Release */

char * __thiscall std::_Locinfo::_Getdays(_Locinfo *this)

{
  void *_Memory;
  char *pcVar1;
  
  _Memory = (void *)FUN_0089a6bc();
  if (_Memory != (void *)0x0) {
    FUN_00433ba0(_Memory);
    _free(_Memory);
  }
  pcVar1 = *(char **)(this + 4);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = ":Sun:Sunday:Mon:Monday:Tue:Tuesday:Wed:Wednesday:Thu:Thursday:Fri:Friday:Sat:Saturday"
    ;
  }
  return pcVar1;
}

