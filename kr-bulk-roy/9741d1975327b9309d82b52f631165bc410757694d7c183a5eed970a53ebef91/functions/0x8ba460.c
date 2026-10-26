
void FUN_008ba460(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x54);
    uVar2 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 8);
    iVar4 = 0;
    if (iVar1 != 0) {
      while (iVar3 = iVar1, iVar3 != param_1) {
        iVar1 = *(int *)(iVar3 + 8);
        iVar4 = iVar3;
        if (*(int *)(iVar3 + 8) == 0) {
          return;
        }
      }
      if (iVar4 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x54) = *(undefined4 *)(iVar3 + 8);
      }
      else {
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + 8);
      }
      if (*(code **)(param_1 + 0x14) != (code *)0x0) {
        (**(code **)(param_1 + 0x14))(param_1);
      }
      FUN_008ba3f0();
      FUN_008b9f80(uVar2,param_1);
    }
  }
  return;
}

