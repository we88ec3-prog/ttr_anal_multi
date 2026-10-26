
undefined4 FUN_006a87f0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (param_1 == 0xd) {
    FUN_006a84a0();
    return 1;
  }
  if (param_1 == 0xe) {
    iVar1 = FUN_00671e60();
    *(undefined4 *)(iVar1 + 4) = 0;
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  if (param_1 == 0x2af9) {
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  return 0;
}

