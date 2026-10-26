
void FUN_007012e0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x28) == -1)) {
    FUN_006f5da0(3);
  }
  FUN_007011f0(0);
  return;
}

