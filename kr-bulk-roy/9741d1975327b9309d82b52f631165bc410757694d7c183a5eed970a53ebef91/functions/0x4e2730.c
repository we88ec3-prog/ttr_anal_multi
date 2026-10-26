
undefined4 FUN_004e2730(int param_1,uint param_2)

{
  int in_ECX;
  uint uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = (param_2 - 2) / 0x35;
  }
  if (uVar1 != 0) {
    param_1 = param_1 + 2;
    do {
      if ((*(byte *)(param_1 + 0x2e) < 10) &&
         ((uint)*(byte *)(param_1 + 0x2e) * 0x210 + *(int *)(in_ECX + 0x6924) != 0)) {
        FUN_004d4150();
      }
      param_1 = param_1 + 0x35;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  FUN_004e5fb0();
  return 0;
}

