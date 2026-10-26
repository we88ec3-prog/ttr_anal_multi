
void FUN_008e8560(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    iVar1 = FUN_008e8520();
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}

