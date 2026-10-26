
undefined4 FUN_00679cf0(int param_1)

{
  int *in_ECX;
  
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x45] + 0x28) >> 7 & 1) != 0) {
      FUN_0067a010();
    }
    return 1;
  }
  if ((param_1 != 0xe) && (param_1 != 0x2af9)) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

