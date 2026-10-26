
undefined4 FUN_004b3710(ushort *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_2 - 2 >> 1;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    param_1 = param_1 + 1;
    uVar1 = *param_1 | 0x6000000;
    FUN_0040f060(uVar1);
    FUN_004dfc90(uVar1);
  }
  return 0;
}

