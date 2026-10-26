
void FUN_0084e870(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_00857010(1);
    FUN_00857010(2);
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_008579a0(*(int *)(param_1 + 0x44));
    FUN_008579a0(*(undefined4 *)(param_1 + 0x44));
  }
  FUN_0084bd30();
  if (*(int *)(param_1 + 0xc0) != *(int *)(param_1 + 0xc4)) {
    uVar1 = FUN_008539a0(param_1);
    *(undefined4 *)(param_1 + 0xc4) = uVar1;
  }
  return;
}

