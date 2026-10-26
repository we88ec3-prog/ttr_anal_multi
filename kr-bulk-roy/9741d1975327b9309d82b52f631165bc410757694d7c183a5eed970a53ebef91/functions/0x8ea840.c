
uint FUN_008ea840(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(param_1 + 0x2b8);
  uVar4 = 0;
  uVar5 = 0;
  if (param_2 < uVar2) {
    iVar3 = *(int *)(param_1 + 700);
    if (*(short *)(param_1 + 0xd2) == 0) {
      uVar1 = iVar3 + 4 + param_2 * 2;
      uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar3 + param_2 * 2),
                             *(undefined1 *)(iVar3 + 1 + param_2 * 2));
      uVar5 = uVar4;
      if (uVar1 <= iVar3 + uVar2 * 2) {
        uVar5 = (uint)CONCAT11(*(undefined1 *)(uVar1 - 2),*(undefined1 *)(uVar1 - 1));
      }
      uVar4 = uVar4 * 2;
      uVar5 = uVar5 * 2;
    }
    else {
      uVar1 = iVar3 + 8 + param_2 * 4;
      uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + param_2 * 4),
                                         *(undefined1 *)(iVar3 + 1 + param_2 * 4)),
                                *(undefined1 *)(iVar3 + 2 + param_2 * 4)),
                       *(undefined1 *)(iVar3 + 3 + param_2 * 4));
      uVar5 = uVar4;
      if (uVar1 <= iVar3 + uVar2 * 4) {
        uVar5 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar1 - 4),*(undefined1 *)(uVar1 - 3)),
                                  *(undefined1 *)(uVar1 - 2)),*(undefined1 *)(uVar1 - 1));
      }
    }
  }
  uVar2 = *(uint *)(param_1 + 0x29c);
  if (uVar4 <= uVar2) {
    if (uVar2 < uVar5) {
      uVar5 = uVar2;
    }
    if (uVar5 < uVar4) {
      *param_3 = uVar2 - uVar4;
      return uVar4;
    }
    *param_3 = uVar5 - uVar4;
    return uVar4;
  }
  *param_3 = 0;
  return 0;
}

