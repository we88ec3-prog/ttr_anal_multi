
void FUN_006b1820(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0x70a) {
    if (iVar1 == 0x709) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
        iVar1 = *(int *)(in_ECX[0x3f] + 0xcc);
        if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) {
          FUN_006b2540(in_ECX,*(undefined4 *)(iVar1 + 0x20));
          FUN_006b2160(in_ECX);
          return;
        }
        FUN_006b2540(in_ECX,0xffffffff);
      }
      FUN_006b2160(in_ECX);
      return;
    }
    if (iVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x47] + 0x20)) goto LAB_006b189b;
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x48] + 0x20)) {
        (**(code **)(*in_ECX + 0xd4))();
      }
    }
    return;
  }
LAB_006b189b:
  FUN_006b18d0(in_ECX);
  (**(code **)(*in_ECX + 0xd4))();
  return;
}

