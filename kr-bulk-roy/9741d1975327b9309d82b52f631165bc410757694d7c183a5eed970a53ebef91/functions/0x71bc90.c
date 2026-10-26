
void FUN_0071bc90(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1[1] != 0) {
    (*(code *)PTR_FUN_00d63d4c)(param_1[1]);
    param_1[1] = 0;
  }
  if ((uint *)*param_1 != (uint *)0x0) {
    piVar2 = (int *)(*(uint *)*param_1 & 0xffffffe0);
    iVar1 = piVar2[3];
    while (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 0xc);
      (*(code *)PTR_FUN_00d63d4c)(*(undefined4 *)(iVar1 + 4));
      iVar1 = iVar3;
    }
    *piVar2 = iVar3;
    piVar2[3] = iVar3;
    piVar2[5] = iVar3;
    piVar2[4] = iVar3;
    *param_1 = iVar3;
  }
  return;
}

