
/* Library Function - Single Match
    public: char const * __thiscall std::_Locinfo::_Getmonths(void)const 
   
   Library: Visual Studio 2010 Release */

char * __thiscall std::_Locinfo::_Getmonths(_Locinfo *this)

{
  void *_Memory;
  char *pcVar1;
  
  _Memory = (void *)FUN_0089a7b5();
  if (_Memory != (void *)0x0) {
    FUN_00433ba0(_Memory);
    _free(_Memory);
  }
  pcVar1 = *(char **)(this + 0xc);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = 
    ":Jan:January:Feb:February:Mar:March:Apr:April:May:May:Jun:June:Jul:July:Aug:August:Sep:September:Oct:October:Nov:November:Dec:December"
    ;
  }
  return pcVar1;
}

