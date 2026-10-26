
void FUN_008ed630(int *param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int in_EDX;
  int extraout_EDX;
  
  uVar1 = *(byte *)(in_EDX + 0x170) - 0xb7;
  uVar3 = (uint)uVar1;
  if (uVar3 < (*(int *)(in_EDX + 0x14) - *(int *)(in_EDX + 0x10)) + 1U) {
    *(int *)(in_EDX + 0x168) = *(int *)(in_EDX + 0x168) + 1;
    if (uVar1 != 0) {
      do {
        sVar2 = FUN_008ec660();
        *param_1 = (int)sVar2;
        param_1 = param_1 + 1;
        uVar3 = uVar3 - 1;
        in_EDX = extraout_EDX;
      } while (uVar3 != 0);
    }
    *(undefined1 *)(in_EDX + 0x178) = 0;
    return;
  }
  *(undefined4 *)(in_EDX + 0xc) = 0x82;
  return;
}

