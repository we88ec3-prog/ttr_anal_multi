
undefined4 FUN_006f71a0(int param_1)

{
  int iVar1;
  char *_Format;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(iVar1 + -8) != 4) {
    iVar1 = FUN_006fb5d0();
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_006f71df;
    }
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar1 = *(int *)(iVar1 + -0x10) + 0x10;
LAB_006f71df:
  _Format = "PANIC: unprotected error in call to Lua API (%s)\n";
  iVar1 = FUN_00894fab("PANIC: unprotected error in call to Lua API (%s)\n",iVar1);
  _fprintf((FILE *)(iVar1 + 0x40),_Format);
  return 0;
}

