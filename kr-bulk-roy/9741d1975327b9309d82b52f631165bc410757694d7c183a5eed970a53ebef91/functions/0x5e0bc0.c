
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e0bc0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  FUN_005d6fb0(param_1);
  if ((*(int *)(iVar1 + 0x10) == 0x7c) && (*(int *)(in_ECX + 0x25c) != 0)) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    param_1 = CONCAT13(*(undefined1 *)(in_ECX + 0x29c),
                       CONCAT12(*(undefined1 *)(in_ECX + 0x298),0x29));
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
    }
  }
  return;
}

