
int FUN_008dd460(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  if (*(char *)*in_ECX == '\x1e') {
    iVar1 = FUN_008dd160(in_ECX[1],0,0);
    return iVar1 >> 0x10;
  }
  iVar1 = FUN_008dd0c0();
  return iVar1;
}

