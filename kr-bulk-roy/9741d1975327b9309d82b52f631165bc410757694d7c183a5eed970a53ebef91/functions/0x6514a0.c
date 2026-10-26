
void FUN_006514a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x3c] + 0x20)) {
      FUN_006513e0();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3d] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    iVar2 = 0;
    piVar3 = in_ECX + 0x3e;
    while (iVar1 != *(int *)(*piVar3 + 0x20)) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (3 < iVar2) {
        return;
      }
    }
    FUN_00651e20();
  }
  return;
}

