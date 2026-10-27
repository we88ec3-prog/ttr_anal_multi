
void FUN_005c32d0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  FUN_0059b420(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf42db) {
    piVar2 = *(int **)(in_ECX + 0x220);
    if (((uint)piVar2[10] >> 8 & 1) == 0) {
      FUN_00596e00(in_ECX,piVar2);
    }
    else if (((uint)piVar2[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar2 + 0xd4))();
      return;
    }
  }
  else {
    if (iVar1 == 0xf42dd) {
      FUN_005c34b0();
      return;
    }
    if (iVar1 == 0xf431f) {
      FUN_005c36d0();
      return;
    }
  }
  return;
}

