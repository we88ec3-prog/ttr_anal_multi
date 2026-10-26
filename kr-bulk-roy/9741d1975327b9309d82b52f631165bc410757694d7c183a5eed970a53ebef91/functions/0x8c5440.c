
void FUN_008c5440(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  if (*(int *)(param_1 + 0x1c) != -1) {
    local_8 = *(uint *)(param_1 + 0x24);
    uVar5 = *(int *)(param_1 + 0x1c) + 1;
    if (local_8 < *(uint *)(param_1 + 0x28)) {
      puVar2 = (undefined1 *)(*(int *)(param_1 + 0x10) + 0x15 + local_8 * 0xc);
      do {
        uVar3 = CONCAT31(CONCAT21(CONCAT11(puVar2[-5],puVar2[-4]),puVar2[-3]),puVar2[-2]);
        uVar4 = CONCAT31(CONCAT21(CONCAT11(puVar2[-1],*puVar2),puVar2[1]),puVar2[2]);
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        if (uVar5 <= uVar4) {
          do {
            iVar1 = (CONCAT31(CONCAT21(CONCAT11(puVar2[3],puVar2[4]),puVar2[5]),puVar2[6]) - uVar3)
                    + uVar5;
            if (iVar1 != 0) {
              *(uint *)(param_1 + 0x1c) = uVar5;
              *(int *)(param_1 + 0x20) = iVar1;
              *(uint *)(param_1 + 0x24) = local_8;
              return;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 <= uVar4);
        }
        local_8 = local_8 + 1;
        puVar2 = puVar2 + 0xc;
      } while (local_8 < *(uint *)(param_1 + 0x28));
    }
  }
  *(undefined1 *)(param_1 + 0x18) = 0;
  return;
}

