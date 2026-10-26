
undefined4 FUN_00875e90(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_00f7b1c8;
  bVar1 = 0;
  if (param_1 != (int *)0x0) {
    for (iVar2 = (**(code **)(*param_1 + 4))(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
      if (*(int *)(iVar2 + 4) == iVar3) {
        bVar1 = 1;
        goto LAB_00875ec9;
      }
    }
    bVar1 = 0;
  }
LAB_00875ec9:
  uVar4 = -(uint)bVar1 & (uint)param_1;
  if (uVar4 == 0) {
    return 0;
  }
  iVar3 = FUN_00876040(param_2);
  if (iVar3 != 0) {
    *(int **)(uVar4 + 0x74) = param_1;
  }
  iVar3 = FUN_008760c0(param_2);
  if (iVar3 != 0) {
    *(int **)(uVar4 + 0x78) = param_1;
  }
  iVar3 = FUN_00875700(param_2);
  if (iVar3 != 0) {
    *(int **)(uVar4 + 0x7c) = param_1;
  }
  iVar3 = FUN_00876140(param_2);
  if (iVar3 != 0) {
    *(int **)(uVar4 + 0x80) = param_1;
  }
  iVar3 = FUN_008761c0(param_2);
  if (iVar3 != 0) {
    *(int **)(uVar4 + 0x84) = param_1;
  }
  iVar3 = FUN_00876240(param_2);
  if (iVar3 != 0) {
    *(undefined4 *)(uVar4 + 0x8c) = 0;
    *(undefined4 *)(uVar4 + 0x90) = 0;
    *(undefined4 *)(uVar4 + 0x94) = 0;
  }
  return 1;
}

