
undefined4 FUN_00765770(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    uVar1 = FUN_00764fb0(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = uVar1;
    return 1;
  }
  return 0;
}

