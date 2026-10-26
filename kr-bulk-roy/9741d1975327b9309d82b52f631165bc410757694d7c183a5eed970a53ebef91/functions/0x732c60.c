
void FUN_00732c60(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
    while (iVar1 = FUN_00733980(param_1), 0 < iVar1) {
      FUN_00429630(1,iVar1);
      if (iVar1 == 0x3e) {
        return;
      }
      if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
        return;
      }
    }
    if (in_ECX != (int *)0x0) {
      while (iVar1 = (**(code **)(*in_ECX + 0x10))(), iVar1 == 0) {
        in_ECX = (int *)in_ECX[4];
        if (in_ECX == (int *)0x0) {
          return;
        }
      }
      iVar1 = (**(code **)(*in_ECX + 0x10))();
      if (iVar1 != 0) {
        FUN_00732010(0xe,0,0,0);
      }
    }
  }
  return;
}

