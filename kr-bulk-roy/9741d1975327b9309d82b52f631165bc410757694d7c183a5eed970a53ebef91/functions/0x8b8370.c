
void FUN_008b8370(int param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    sVar2 = *(short *)(param_1 + 0x16);
    sVar3 = *(short *)(param_1 + 0x38);
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x3a) + sVar2;
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + *(short *)(param_1 + 0x38);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x54);
    uVar4 = 0;
    if ((int)sVar3 != 0) {
      do {
        psVar1 = (short *)(*(int *)(param_1 + 0x44) + uVar4 * 2);
        *psVar1 = *psVar1 + sVar2;
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(int)sVar3);
    }
    FUN_008b8350(param_1);
  }
  return;
}

