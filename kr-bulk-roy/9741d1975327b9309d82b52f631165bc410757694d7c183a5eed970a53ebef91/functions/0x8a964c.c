
/* Library Function - Single Match
    __hextodec
   
   Library: Visual Studio 2010 Release */

uint __hextodec(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0xff00) == 0) {
    iVar1 = _isdigit(param_1 & 0xff);
    if (iVar1 != 0) {
      return param_1 & 0xffff;
    }
  }
  return (param_1 & 0xffdf) - 7;
}

