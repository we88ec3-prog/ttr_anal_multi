
short FUN_008bfb20(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  uVar4 = 0;
  if (uVar3 == 0) {
    return 0;
  }
  do {
    uVar2 = uVar3 + uVar4 >> 1;
    uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + uVar2 * 8);
    if (param_2 == uVar1) {
      return *(short *)(*(int *)(param_1 + 0x14) + 4 + uVar2 * 8) + 1;
    }
    if (uVar1 <= param_2) {
      uVar4 = uVar2 + 1;
      uVar2 = uVar3;
    }
    uVar3 = uVar2;
  } while (uVar4 < uVar2);
  return 0;
}

