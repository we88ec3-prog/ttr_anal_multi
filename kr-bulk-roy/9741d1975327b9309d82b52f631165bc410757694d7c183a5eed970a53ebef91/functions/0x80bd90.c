
void FUN_0080bd90(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 unaff_EDI;
  int local_8;
  
  iVar1 = param_1;
  param_1 = FUN_0080c1c0(unaff_EDI);
  if (param_1 != *(int *)(iVar1 + 0x4c)) {
    cVar2 = FUN_005436a0();
    if (cVar2 == '\0') {
      piVar3 = &param_1;
      goto LAB_0080bdc6;
    }
  }
  local_8 = *(int *)(iVar1 + 0x4c);
  piVar3 = &local_8;
LAB_0080bdc6:
  if (*piVar3 != *(int *)(iVar1 + 0x4c)) {
    piVar3 = (int *)(*piVar3 + 0x28);
    *piVar3 = *piVar3 + 1;
  }
  return;
}

