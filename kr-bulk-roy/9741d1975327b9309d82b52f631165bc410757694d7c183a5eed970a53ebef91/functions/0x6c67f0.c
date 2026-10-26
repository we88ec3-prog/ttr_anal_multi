
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c67f0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_007459c0();
  if ((_DAT_00fc0d5c & 1) == 0) {
    _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
    DAT_00fc0d60 = 0;
    DAT_00fc0d64 = 0;
    _DAT_00fc0d68 = 0;
    _atexit((_func_4879 *)&LAB_00bcd8c0);
  }
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  if (*(int *)(in_ECX + 0xb8) != *(int *)(in_ECX + 0xbc)) {
    uVar1 = FUN_006c8b30(*(int *)(in_ECX + 0xbc),in_ECX);
    FUN_006c8b80(in_ECX);
    *(undefined4 *)(in_ECX + 0xbc) = uVar1;
  }
  if ((DAT_00fc0d64 - DAT_00fc0d60 & 0xfffffffcU) == 4) {
    FUN_006c16d0(in_ECX);
    return;
  }
  FUN_006c14e0(in_ECX,&DAT_00fc0d60);
  return;
}

