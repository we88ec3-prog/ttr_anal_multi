
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063e710(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0x7c) {
    uVar1 = *(undefined4 *)(in_ECX + 0x20);
    if ((_DAT_00fc0d5c & 1) == 0) {
      _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
      DAT_00fc0d60 = 0;
      DAT_00fc0d64 = 0;
      _DAT_00fc0d68 = 0;
      _atexit((_func_4879 *)&LAB_00bcd8c0);
    }
    FUN_006c8c80(uVar1,4);
  }
  return;
}

