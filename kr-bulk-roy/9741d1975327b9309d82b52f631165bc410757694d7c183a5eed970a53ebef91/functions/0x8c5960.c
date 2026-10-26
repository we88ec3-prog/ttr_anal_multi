
void FUN_008c5960(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  if (*(int *)(param_1 + 0x1c) != -1) {
    uVar4 = *(uint *)(param_1 + 0x24);
    local_8 = *(int *)(param_1 + 0x1c) + 1;
    if (uVar4 < *(uint *)(param_1 + 0x28)) {
      puVar1 = (undefined1 *)(*(int *)(param_1 + 0x10) + 0x15 + uVar4 * 0xc);
      do {
        uVar2 = CONCAT31(CONCAT21(CONCAT11(puVar1[-5],puVar1[-4]),puVar1[-3]),puVar1[-2]);
        iVar3 = CONCAT31(CONCAT21(CONCAT11(puVar1[3],puVar1[4]),puVar1[5]),puVar1[6]);
        if (local_8 < uVar2) {
          local_8 = uVar2;
        }
        if ((local_8 <= CONCAT31(CONCAT21(CONCAT11(puVar1[-1],*puVar1),puVar1[1]),puVar1[2])) &&
           (iVar3 != 0)) {
          *(uint *)(param_1 + 0x24) = uVar4;
          *(uint *)(param_1 + 0x1c) = local_8;
          *(int *)(param_1 + 0x20) = iVar3;
          return;
        }
        uVar4 = uVar4 + 1;
        puVar1 = puVar1 + 0xc;
      } while (uVar4 < *(uint *)(param_1 + 0x28));
    }
  }
  *(undefined1 *)(param_1 + 0x18) = 0;
  return;
}

