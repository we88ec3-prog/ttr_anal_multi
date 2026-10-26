
undefined4 FUN_0055d560(int param_1)

{
  int iVar1;
  undefined4 *local_10;
  undefined4 local_c;
  
  local_10 = (undefined4 *)(*(int *)(param_1 + 8) + -0x10);
  if ((local_10 != &DAT_00c0bfc8) && (*(int *)(*(int *)(param_1 + 8) + -8) == 6)) {
    local_c = 0;
    iVar1 = FUN_006fe770(FUN_006f5a50,&local_10,(int)local_10 - *(int *)(param_1 + 0x20));
    if (iVar1 != 0) {
      if (*(int *)(*(int *)(param_1 + 8) + -8) != 4) {
        iVar1 = FUN_006fb5d0();
        if ((iVar1 != 0) &&
           (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           )) {
          FUN_006fb3a0();
        }
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    }
  }
  return 0;
}

