
int FUN_008d4f20(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(uint *)(param_1 + 0x10);
  iVar2 = 0;
  uVar5 = 0;
  if (uVar4 != 0) {
    while( true ) {
      uVar3 = uVar4 + uVar5 >> 1;
      uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + uVar3 * 8);
      if (param_2 == uVar1) break;
      if (uVar1 <= param_2) {
        uVar5 = uVar3 + 1;
        uVar3 = uVar4;
      }
      uVar4 = uVar3;
      if (uVar3 <= uVar5) {
        return 0;
      }
    }
    iVar2 = *(ushort *)(*(int *)(param_1 + 0x14) + 4 + uVar3 * 8) + 1;
  }
  return iVar2;
}

