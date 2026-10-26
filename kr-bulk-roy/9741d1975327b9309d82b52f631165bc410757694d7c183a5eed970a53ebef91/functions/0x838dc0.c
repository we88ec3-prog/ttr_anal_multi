
void FUN_00838dc0(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 4) + uVar4 * 4);
      if ((*(int *)(iVar1 + 0x14) != 0) && (piVar2 = *(int **)(iVar1 + 8), piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 0x30))(piVar2);
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + 0x10) = 0;
    } while (uVar4 < uVar3);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_00839060(param_1);
  return;
}

