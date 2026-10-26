
void FUN_00782370(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint local_8;
  
  iVar3 = param_1;
  local_8 = 0;
  if (*(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x74) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(*(int *)(iVar3 + 0x74) + local_8 * 4) + 4) == 0) {
        param_1 = FUN_00782420(iVar3,local_8);
        puVar1 = *(undefined4 **)(iVar3 + 8);
        if (&param_1 < puVar1) {
          puVar2 = *(undefined4 **)(iVar3 + 4);
          if (&param_1 < puVar2) goto LAB_007823e5;
          if (puVar1 == *(undefined4 **)(iVar3 + 0xc)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(iVar3 + 8) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar3 + 8) =
                 *(undefined4 *)(*(int *)(iVar3 + 4) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
          }
        }
        else {
LAB_007823e5:
          if (puVar1 == *(undefined4 **)(iVar3 + 0xc)) {
            FUN_00797930();
          }
          if (*(int **)(iVar3 + 8) != (int *)0x0) {
            **(int **)(iVar3 + 8) = param_1;
          }
        }
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 4;
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(*(int *)(iVar3 + 0x78) - *(int *)(iVar3 + 0x74) >> 2));
  }
  return;
}

