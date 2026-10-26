
int FUN_008c5520(int param_1,uint *param_2,char param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar6 = 0;
  uVar8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 0xd)),
                            *(undefined1 *)(iVar2 + 0xe)),*(undefined1 *)(iVar2 + 0xf));
  local_8 = *param_2;
  if (uVar8 == 0) {
    return 0;
  }
  uVar5 = 0xffffffff;
  if (param_3 != '\0') {
    local_8 = local_8 + 1;
  }
  local_c = 0;
  uVar7 = 0;
  local_10 = uVar8;
  if (uVar8 != 0) {
    do {
      uVar7 = local_10 + local_c >> 1;
      puVar1 = (undefined1 *)(iVar2 + 0x14 + uVar7 * 0xc);
      uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar2 + 0x10 + uVar7 * 0xc),puVar1[-3]),
                                puVar1[-2]),puVar1[-1]);
      uVar5 = CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
      uVar3 = uVar7;
      if (uVar4 <= local_8) {
        if (local_8 <= uVar5) {
          iVar6 = (CONCAT31(CONCAT21(CONCAT11(puVar1[4],puVar1[5]),puVar1[6]),puVar1[7]) - uVar4) +
                  local_8;
          goto LAB_008c562b;
        }
        local_c = uVar7 + 1;
        uVar3 = local_10;
      }
      local_10 = uVar3;
    } while (local_c < local_10);
    iVar6 = 0;
  }
LAB_008c562b:
  if (param_3 != '\0') {
    if ((uVar5 < local_8) && (uVar7 = uVar7 + 1, uVar7 == uVar8)) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x18) = 1;
    *(uint *)(param_1 + 0x1c) = local_8;
    *(uint *)(param_1 + 0x24) = uVar7;
    if (iVar6 == 0) {
      FUN_008c5440(param_1);
      if (*(char *)(param_1 + 0x18) == '\0') {
        return 0;
      }
      iVar6 = *(int *)(param_1 + 0x20);
    }
    else {
      *(int *)(param_1 + 0x20) = iVar6;
    }
    if (iVar6 != 0) {
      *param_2 = *(uint *)(param_1 + 0x1c);
    }
  }
  return iVar6;
}

