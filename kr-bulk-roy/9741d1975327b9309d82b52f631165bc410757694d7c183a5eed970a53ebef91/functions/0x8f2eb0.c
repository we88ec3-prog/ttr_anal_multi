
void FUN_008f2eb0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x68);
    uVar2 = *(undefined4 *)(param_1 + 100);
    iVar3 = *(int *)(param_1 + 0x214);
    if (*(code **)(param_1 + 0x294) != (code *)0x0) {
      (**(code **)(param_1 + 0x294))(*(undefined4 *)(param_1 + 0x290));
    }
    if (iVar3 != 0) {
      (**(code **)(iVar3 + 0xc))(param_1);
    }
    FUN_008ea930();
    FUN_008eab90();
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x288));
    *(undefined4 *)(param_1 + 0x288) = 0;
    *(undefined4 *)(param_1 + 0x284) = 0;
    FUN_008bab90(uVar1,param_1 + 0x278);
    FUN_008bab90(uVar1,param_1 + 0x280);
    *(undefined4 *)(param_1 + 0x274) = 0;
    *(undefined4 *)(param_1 + 0x27c) = 0;
    FUN_008f1840();
    *(undefined4 *)(param_1 + 0x2a4) = 0;
  }
  return;
}

