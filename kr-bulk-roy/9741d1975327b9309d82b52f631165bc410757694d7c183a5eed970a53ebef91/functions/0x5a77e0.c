
void FUN_005a77e0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4332:
    iVar1 = FUN_005a3810();
    iVar2 = **(int **)(in_ECX + 0x144);
    if (*(char *)(iVar1 + 0x14) == '\0') {
      (**(code **)(iVar2 + 0xd4))();
      return;
    }
    goto LAB_005a783a;
  default:
    goto switchD_005a77f7_caseD_f4333;
  case 0xf4338:
    piVar3 = *(int **)(in_ECX + 0x154);
    break;
  case 0xf4339:
    if (((uint)(*(int **)(in_ECX + 0x158))[10] >> 8 & 1) != 0) {
      return;
    }
    iVar2 = **(int **)(in_ECX + 0x158);
LAB_005a783a:
    (**(code **)(iVar2 + 0xd0))();
    return;
  case 0xf433a:
    piVar3 = *(int **)(in_ECX + 0x160);
  }
  if (((uint)piVar3[10] >> 8 & 1) == 0) {
    (**(code **)(*piVar3 + 0xd0))();
  }
switchD_005a77f7_caseD_f4333:
  return;
}

