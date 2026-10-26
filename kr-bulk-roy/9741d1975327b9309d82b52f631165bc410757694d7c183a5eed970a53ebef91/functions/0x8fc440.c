
int FUN_008fc440(void)

{
  int iVar1;
  undefined2 in_CX;
  
  iVar1 = FUN_008b97e0();
  if (iVar1 == 0) {
    iVar1 = FUN_008bab70();
    if ((iVar1 == 0) && (((char)in_CX != '\x1f' || ((char)((ushort)in_CX >> 8) != -99)))) {
      iVar1 = 3;
    }
  }
  return iVar1;
}

