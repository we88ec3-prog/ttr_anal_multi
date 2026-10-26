
void FUN_008dfff0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 100);
    if (*(int *)(param_1 + 0x214) != 0) {
      (**(code **)(*(int *)(param_1 + 0x214) + 0xc))(param_1);
    }
    if (*(int *)(param_1 + 0x290) != 0) {
      FUN_008def20();
      FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x290));
      *(undefined4 *)(param_1 + 0x290) = 0;
    }
  }
  return;
}

