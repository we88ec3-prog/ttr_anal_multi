
undefined4 FUN_008eb830(void)

{
  char *pcVar1;
  char *_SubStr;
  char *unaff_EDI;
  
  _SubStr = "DFKaiSho-SB";
  do {
    pcVar1 = _strstr(unaff_EDI,_SubStr);
    if (pcVar1 != (char *)0x0) {
      return 1;
    }
    _SubStr = _SubStr + 0x14;
  } while ((int)_SubStr < 0xbeab84);
  return 0;
}

