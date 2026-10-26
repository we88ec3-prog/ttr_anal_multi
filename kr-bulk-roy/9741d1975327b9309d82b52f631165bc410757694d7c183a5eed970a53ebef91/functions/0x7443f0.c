
void FUN_007443f0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_007456f0(param_1);
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  piVar3 = (int *)(param_1 + 0x94);
  iVar2 = 4;
  do {
    if (*piVar3 != 0) {
      iVar1 = (**(code **)(*(int *)*piVar3 + 0x28))();
      *(int *)((in_ECX - param_1) + (int)piVar3) = iVar1;
      *(int *)(iVar1 + 8) = in_ECX;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

