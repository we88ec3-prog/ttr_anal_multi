
void FUN_008ca020(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 100);
  if (*(char *)(param_1 + 0x264) != '\0') {
    if (*(int *)(param_1 + 0x1d4) == 0x20000) {
      FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x26c));
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x26c) = 0;
      *(undefined2 *)(param_1 + 0x268) = 0;
      if (*(short *)(param_1 + 0x26a) != 0) {
        do {
          uVar3 = (uint)uVar2;
          FUN_008b9f80(uVar1,*(undefined4 *)(*(int *)(param_1 + 0x270) + uVar3 * 4));
          uVar2 = uVar2 + 1;
          *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x270)) = 0;
        } while (uVar2 < *(ushort *)(param_1 + 0x26a));
      }
      FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x270));
      *(undefined4 *)(param_1 + 0x270) = 0;
      *(undefined2 *)(param_1 + 0x26a) = 0;
      *(undefined1 *)(param_1 + 0x264) = 0;
      return;
    }
    if (*(int *)(param_1 + 0x1d4) == 0x28000) {
      FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x26c));
      *(undefined4 *)(param_1 + 0x26c) = 0;
      *(undefined2 *)(param_1 + 0x268) = 0;
      *(undefined1 *)(param_1 + 0x264) = 0;
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x264) = 0;
  return;
}

