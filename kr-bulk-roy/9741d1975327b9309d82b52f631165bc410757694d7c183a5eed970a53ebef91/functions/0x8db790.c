
int FUN_008db790(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint *local_14;
  int local_8;
  
  uVar2 = *(undefined4 *)(param_1 + 0x148);
  iVar13 = *(int *)(param_1 + 0x88);
  uVar3 = *(undefined4 *)(param_1 + 100);
  piVar12 = (int *)0x0;
  local_20 = 0;
  local_14 = (uint *)FUN_008bc7d0(uVar3,8,0,*(undefined4 *)(param_1 + 300),0,&local_8);
  *(uint **)(param_1 + 0x13c) = local_14;
  if ((local_8 == 0) && (local_28 = 0, 0 < *(int *)(param_1 + 300))) {
    local_1c = 0;
    do {
      iVar9 = *(int *)(param_1 + 0x130) + local_1c;
      uVar4 = *(uint *)(iVar9 + 0xf0);
      iVar5 = *(int *)(iVar9 + 4);
      if (uVar4 == 0xffffffff) {
LAB_008dba34:
        local_8 = 0xa0;
LAB_008dba40:
        if (*(int *)(param_1 + 0x13c) != 0) {
          iVar13 = 0;
          if (0 < *(int *)(param_1 + 300)) {
            do {
              puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x13c) + 4 + iVar13 * 8);
              if (puVar7 != (undefined4 *)0x0) {
                FUN_008b9f80(uVar3,*puVar7);
                **(undefined4 **)(*(int *)(param_1 + 0x13c) + 4 + iVar13 * 8) = 0;
              }
              FUN_008b9f80(uVar3,*(undefined4 *)(*(int *)(param_1 + 0x13c) + 4 + iVar13 * 8));
              *(undefined4 *)(*(int *)(param_1 + 0x13c) + 4 + iVar13 * 8) = 0;
              iVar13 = iVar13 + 1;
            } while (iVar13 < *(int *)(param_1 + 300));
          }
          FUN_008b9f80(uVar3,*(undefined4 *)(param_1 + 0x13c));
          *(undefined4 *)(param_1 + 0x13c) = 0;
        }
        break;
      }
      if (local_20 < uVar4 + 1) {
        uVar10 = uVar4 + 4 & 0xfffffffc;
        if (uVar10 <= local_20) goto LAB_008dba34;
        piVar12 = (int *)FUN_008bc7d0(uVar3,4,local_20,uVar10,piVar12,&local_8);
        local_20 = uVar10;
        if (local_8 == 0) goto LAB_008db868;
        goto LAB_008dba40;
      }
LAB_008db868:
      local_8 = FUN_008b97e0(uVar2,*(int *)(iVar9 + 0xf4) + *(int *)(param_1 + 0x134));
      if ((local_8 != 0) ||
         (local_8 = FUN_008babe0(uVar2,*(int *)(iVar9 + 0xf8) * (uVar4 + 1)), local_8 != 0))
      goto LAB_008dba40;
      local_24 = 0;
      do {
        iVar9 = FUN_008db320();
        piVar12[local_24] = iVar9;
        local_24 = local_24 + 1;
      } while (local_24 <= uVar4);
      FUN_008baca0(uVar2);
      uVar10 = 1;
      if (uVar4 != 0) {
        do {
          if ((uint)piVar12[uVar10] < (uint)piVar12[uVar10 - 1]) goto LAB_008dba40;
          uVar10 = uVar10 + 1;
        } while (uVar10 <= uVar4);
      }
      iVar9 = piVar12[uVar4];
      iVar6 = *piVar12;
      uVar10 = FUN_008bc7d0(uVar3,4,0,uVar4 + 1,0,&local_8);
      local_14[1] = uVar10;
      if (local_8 != 0) goto LAB_008dba40;
      uVar11 = FUN_008baee0(uVar3,iVar9 - iVar6,&local_8);
      *(undefined4 *)local_14[1] = uVar11;
      if (((local_8 != 0) ||
          (local_8 = FUN_008b97e0(uVar2,*piVar12 + *(int *)(param_1 + 0x134)), local_8 != 0)) ||
         (local_8 = FUN_008bab70(uVar2,*(undefined4 *)local_14[1],iVar9 - iVar6), local_8 != 0))
      goto LAB_008dba40;
      uVar10 = 1;
      if (uVar4 != 0) {
        do {
          iVar6 = uVar10 * 4;
          iVar8 = uVar10 - 1;
          iVar9 = uVar10 * 4;
          piVar1 = piVar12 + uVar10;
          uVar10 = uVar10 + 1;
          *(int *)(local_14[1] + iVar9) =
               (*(int *)((local_14[1] - 4) + iVar6) - piVar12[iVar8]) + *piVar1;
        } while (uVar10 <= uVar4);
      }
      if ((-1 < iVar5) && (uVar10 = 0, uVar4 != 0)) {
        do {
          (**(code **)(iVar13 + 0x10))
                    (*(undefined4 *)(local_14[1] + uVar10 * 4),piVar12[uVar10 + 1] - piVar12[uVar10]
                     ,0x10ea);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar4);
      }
      local_1c = local_1c + 0xfc;
      *local_14 = uVar4;
      local_28 = local_28 + 1;
      local_14 = local_14 + 2;
    } while (local_28 < *(int *)(param_1 + 300));
  }
  FUN_008b9f80(uVar3,piVar12);
  return local_8;
}

