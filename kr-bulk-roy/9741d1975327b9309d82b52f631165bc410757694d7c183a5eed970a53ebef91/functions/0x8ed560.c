
void FUN_008ed560(int *param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int in_EDX;
  int extraout_EDX;
  uint uVar4;
  
  bVar1 = *(byte *)(*(int *)(in_EDX + 0x164) + 1 + *(int *)(in_EDX + 0x168));
  uVar3 = (uint)bVar1;
  if (uVar3 < (*(int *)(in_EDX + 0x14) - *(int *)(in_EDX + 0x10)) + 1U) {
    *(int *)(in_EDX + 0x168) = *(int *)(in_EDX + 0x168) + 2;
    uVar4 = uVar3;
    if (bVar1 != 0) {
      do {
        sVar2 = FUN_008ec660();
        *param_1 = (int)sVar2;
        param_1 = param_1 + 1;
        uVar4 = uVar4 - 1;
        in_EDX = extraout_EDX;
      } while (uVar4 != 0);
    }
    *(int *)(in_EDX + 0x20) = *(int *)(in_EDX + 0x20) + uVar3;
    *(undefined1 *)(in_EDX + 0x178) = 0;
    return;
  }
  *(undefined4 *)(in_EDX + 0xc) = 0x82;
  return;
}

