
undefined4 FUN_004fe610(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 2);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    FUN_006edb60(&DAT_00c0d9e0,cVar1);
  }
  return 0x80004005;
}

