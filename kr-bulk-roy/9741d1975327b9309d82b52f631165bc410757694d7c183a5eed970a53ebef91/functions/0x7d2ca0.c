
void FUN_007d2ca0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x18) + local_8 * 4);
      piVar2 = *(int **)(iVar1 + 0x2c);
      if ((piVar2 != (int *)0x0) &&
         (iVar3 = piVar2[1] - *piVar2 >> 0x1f, uVar4 = 0,
         (piVar2[1] - *piVar2) / 0x1c + iVar3 != iVar3)) {
        do {
          FUN_00440c60();
          piVar2 = *(int **)(iVar1 + 0x2c);
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)((piVar2[1] - *piVar2) / 0x1c));
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2));
  }
  return;
}

