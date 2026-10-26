
void FUN_008dbf10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (param_1 != 0) {
    uVar2 = *(undefined4 *)(param_1 + 100);
    if (*(int *)(param_1 + 0x13c) != 0) {
      param_1 = 0;
      if (0 < *(int *)(iVar3 + 300)) {
        do {
          iVar1 = *(int *)(iVar3 + 0x13c) + param_1 * 8;
          if (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0) {
            FUN_008b9f80(uVar2,**(undefined4 **)(iVar1 + 4));
            **(undefined4 **)(iVar1 + 4) = 0;
            FUN_008b9f80(uVar2,*(undefined4 *)(iVar1 + 4));
            *(undefined4 *)(iVar1 + 4) = 0;
          }
          param_1 = param_1 + 1;
        } while (param_1 < *(int *)(iVar3 + 300));
      }
      FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x13c));
      *(undefined4 *)(iVar3 + 0x13c) = 0;
    }
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0xa4));
    *(undefined4 *)(iVar3 + 0xa4) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0xa8));
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0xac));
    *(undefined4 *)(iVar3 + 0xac) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0xb0));
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0xb4));
    *(undefined4 *)(iVar3 + 0xb4) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x130));
    *(undefined4 *)(iVar3 + 0x130) = 0;
    *(undefined4 *)(iVar3 + 300) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x8c));
    *(undefined4 *)(iVar3 + 0x8c) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x98));
    *(undefined4 *)(iVar3 + 0x98) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x9c));
    *(undefined4 *)(iVar3 + 0x9c) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x144));
    *(undefined4 *)(iVar3 + 0x144) = 0;
    FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x148));
    *(undefined4 *)(iVar3 + 0x148) = 0;
  }
  return;
}

