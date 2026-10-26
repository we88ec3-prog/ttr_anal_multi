
undefined4 FUN_004e4100(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00412440();
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 2 >> 1;
  }
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    param_1 = param_1 + 2;
    uVar2 = FUN_0055e5b0(param_1);
    FUN_00412b40(in_ECX + 0x690c,uVar2);
  }
  return 0;
}

