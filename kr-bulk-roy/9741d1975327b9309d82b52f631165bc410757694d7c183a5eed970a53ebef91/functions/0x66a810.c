
void FUN_0066a810(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  
  iVar1 = 0;
  piVar2 = (int *)(in_EDX + 0x118);
  while ((*piVar2 != 0 && (piVar2[1] != 0))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 6;
    if (2 < iVar1) {
      return;
    }
  }
  if (iVar1 != -1) {
    FUN_0066a850(in_EDX,param_1,param_2,iVar1);
  }
  return;
}

