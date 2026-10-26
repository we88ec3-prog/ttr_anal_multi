
void FUN_00782550(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x60) != 0) {
    do {
      FUN_00721910();
      FUN_00721910();
      FUN_00721910();
      FUN_00721910();
      FUN_00721910();
      FUN_00721910();
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x60));
  }
  return;
}

