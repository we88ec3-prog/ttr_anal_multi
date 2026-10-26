
undefined4 FUN_0080c040(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 unaff_EDI;
  int local_8;
  
  iVar1 = param_1;
  param_1 = FUN_0080c1c0(unaff_EDI);
  if (param_1 != *(int *)(iVar1 + 0x2c)) {
    cVar2 = FUN_005436a0();
    if (cVar2 == '\0') {
      piVar3 = &param_1;
      goto LAB_0080c076;
    }
  }
  local_8 = *(int *)(iVar1 + 0x2c);
  piVar3 = &local_8;
LAB_0080c076:
  if (*piVar3 != *(int *)(iVar1 + 0x2c)) {
    return *(undefined4 *)(*piVar3 + 0x28);
  }
  return *(undefined4 *)(iVar1 + 0x24);
}

