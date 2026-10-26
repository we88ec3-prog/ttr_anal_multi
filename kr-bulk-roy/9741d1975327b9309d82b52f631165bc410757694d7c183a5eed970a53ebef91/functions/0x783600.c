
undefined4 FUN_00783600(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x15] != 0) {
    iVar1 = (**(code **)(*in_ECX + 0xc))(0xffffffff);
    if (iVar1 != -1) {
      iVar1 = _fflush((FILE *)in_ECX[0x15]);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

