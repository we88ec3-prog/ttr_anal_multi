
void FUN_00651dc0(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      FUN_006513e0();
      return;
    }
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0xf8);
    while (*(int *)(param_1 + 8) != *(int *)(*piVar2 + 0x20)) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (3 < iVar1) {
        return;
      }
    }
    FUN_00651e20();
  }
  return;
}

