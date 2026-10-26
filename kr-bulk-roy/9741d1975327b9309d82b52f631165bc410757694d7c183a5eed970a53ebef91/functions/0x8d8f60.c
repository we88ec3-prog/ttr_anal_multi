
int FUN_008d8f60(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    uVar4 = *(uint *)(param_1 + 0x10);
    do {
      uVar2 = (uVar4 - uVar3 >> 1) + uVar3;
      uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + uVar2 * 0x10);
      if (uVar1 == param_2) {
        return uVar2 + 1;
      }
      if (uVar1 < param_2) {
        uVar3 = uVar2 + 1;
        uVar2 = uVar4;
      }
      uVar4 = uVar2;
    } while (uVar3 < uVar2);
  }
  return 0;
}

