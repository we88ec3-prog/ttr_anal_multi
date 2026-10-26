
void FUN_008ca690(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x214);
    uVar2 = *(undefined4 *)(param_1 + 100);
    if (iVar1 != 0) {
      if (*(code **)(iVar1 + 0x50) != (code *)0x0) {
        (**(code **)(iVar1 + 0x50))(param_1);
      }
      if (*(code **)(iVar1 + 100) != (code *)0x0) {
        (**(code **)(iVar1 + 100))(param_1);
      }
    }
    FUN_008ca250();
    FUN_008c6e70();
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x8c) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x9c));
    *(undefined4 *)(param_1 + 0x9c) = 0;
    *(undefined2 *)(param_1 + 0x98) = 0;
    FUN_008bab90(*(undefined4 *)(param_1 + 0x68),param_1 + 500);
    uVar3 = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    FUN_008bab90(uVar3,param_1 + 0x2a8);
    FUN_008bab90(uVar3,param_1 + 0x2b0);
    *(undefined4 *)(param_1 + 0x2ac) = 0;
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    if (*(char *)(param_1 + 0x124) != '\0') {
      FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x14c));
      *(undefined4 *)(param_1 + 0x14c) = 0;
      FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x150));
      *(undefined4 *)(param_1 + 0x150) = 0;
      *(undefined1 *)(param_1 + 0x124) = 0;
    }
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x220));
    *(undefined4 *)(param_1 + 0x220) = 0;
    *(undefined2 *)(param_1 + 0x21e) = 0;
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 0x34))(param_1);
    }
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(param_1 + 0x298));
    *(undefined4 *)(param_1 + 0x298) = 0;
    *(undefined4 *)(param_1 + 0x214) = 0;
  }
  return;
}

