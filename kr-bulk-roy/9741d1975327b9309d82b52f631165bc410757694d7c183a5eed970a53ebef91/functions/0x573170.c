
void FUN_00573170(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  undefined4 unaff_EDI;
  int local_8;
  
  piVar2 = param_1;
  iVar1 = *param_1;
  param_1 = (int *)FUN_006cf160(unaff_EDI);
  if (param_1 != (int *)*(int *)(iVar1 + 4)) {
    cVar3 = FUN_005436a0();
    if (cVar3 == '\0') {
      piVar4 = (int *)&param_1;
      goto LAB_005731a7;
    }
  }
  local_8 = *(int *)(iVar1 + 4);
  piVar4 = &local_8;
LAB_005731a7:
  if (*piVar4 != *(int *)(*piVar2 + 4)) {
    *(undefined4 *)(*(int *)(*piVar4 + 0x28) + 0x1c) = param_2;
  }
  return;
}

