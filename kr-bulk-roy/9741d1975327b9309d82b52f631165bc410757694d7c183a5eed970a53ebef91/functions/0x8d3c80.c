
int FUN_008d3c80(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint local_c;
  int local_8;
  
  iVar6 = param_2;
  uVar1 = *(undefined4 *)(param_2 + 100);
  local_8 = FUN_008b97e0(param_1,0);
  if ((local_8 != 0) ||
     (local_8 = FUN_008bacd0(param_1,&DAT_00be7ee8,(int *)(param_2 + 0xb8)), local_8 != 0)) {
    return 1;
  }
  if (((*(int *)(param_2 + 0xb8) == 0x70636601) &&
      (uVar10 = *(uint *)(param_2 + 0xbc), uVar10 < 0x8000000)) && (uVar10 != 0)) {
    iVar7 = FUN_008bc7d0(uVar1,0x10,0,uVar10,0,&local_8);
    *(int *)(param_2 + 0xc0) = iVar7;
    if (local_8 != 0) {
      return 0x40;
    }
    uVar10 = 0;
    if (*(int *)(param_2 + 0xbc) != 0) {
      do {
        local_8 = FUN_008bacd0(param_1,&DAT_00be7ef8,iVar7);
        if (local_8 != 0) {
          FUN_008b9f80(uVar1,*(undefined4 *)(param_2 + 0xc0));
          *(undefined4 *)(param_2 + 0xc0) = 0;
          return local_8;
        }
        uVar10 = uVar10 + 1;
        iVar7 = iVar7 + 0x10;
        local_8 = 0;
      } while (uVar10 < *(uint *)(param_2 + 0xbc));
    }
    iVar7 = *(int *)(param_2 + 0xc0);
    iVar8 = *(int *)(param_2 + 0xbc);
    local_c = 0;
    if (iVar8 != 1) {
      do {
        bVar5 = false;
        param_2 = 0;
        if (iVar8 - local_c == 1) {
          return 0;
        }
        puVar9 = (uint *)(iVar7 + 0x1c);
        do {
          if (*puVar9 < puVar9[-4]) {
            uVar10 = puVar9[-6];
            uVar2 = puVar9[-4];
            uVar3 = puVar9[-7];
            uVar4 = puVar9[-5];
            puVar9[-7] = puVar9[-3];
            puVar9[-6] = puVar9[-2];
            puVar9[-5] = puVar9[-1];
            puVar9[-3] = uVar3;
            puVar9[-2] = uVar10;
            puVar9[-1] = uVar4;
            puVar9[-4] = *puVar9;
            *puVar9 = uVar2;
            bVar5 = true;
          }
          if ((*puVar9 < puVar9[-5]) || (*puVar9 - puVar9[-5] < puVar9[-4])) {
            return 9;
          }
          param_2 = param_2 + 1;
          puVar9 = puVar9 + 4;
        } while (param_2 < (*(int *)(iVar6 + 0xbc) - local_c) - 1);
        if (!bVar5) {
          return 0;
        }
        iVar8 = *(int *)(iVar6 + 0xbc);
        local_c = local_c + 1;
      } while (local_c < iVar8 - 1U);
    }
    return 0;
  }
  return 3;
}

