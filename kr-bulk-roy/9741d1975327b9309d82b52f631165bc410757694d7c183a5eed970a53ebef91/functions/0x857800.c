
undefined4 FUN_00857800(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint local_8;
  
  piVar2 = param_1;
  piVar1 = (int *)param_2[1];
  piVar8 = (int *)*param_2;
  if ((((int)piVar1 - (int)piVar8 & 0xfffffff8U) == 0) || (param_3 == (undefined4 *)0x0)) {
    return 0;
  }
  if (piVar8 != piVar1) {
    puVar4 = (undefined4 *)param_1[5];
    do {
      puVar3 = (undefined4 *)piVar2[4];
      param_1 = (int *)0x0;
      if (puVar3 != puVar4) {
        do {
          piVar5 = (int *)*puVar3;
          if (piVar5 != (int *)puVar3[1]) {
            do {
              if ((*piVar8 == *piVar5) && (piVar8[1] == piVar5[1])) {
                FUN_004fcdc0(param_2);
                iVar7 = *piVar2;
                iVar6 = piVar2[1] - iVar7 >> 0x1f;
                uVar9 = 0;
                if ((piVar2[1] - iVar7) / 0x14 + iVar6 == iVar6) {
                  return 1;
                }
                iVar6 = 0;
                do {
                  puVar4 = (undefined4 *)(*(int *)(iVar6 + iVar7) + (int)param_1 * 0xc);
                  *puVar4 = *param_3;
                  puVar4[1] = param_3[1];
                  iVar6 = iVar6 + 0x14;
                  puVar4[2] = param_3[2];
                  iVar7 = *piVar2;
                  uVar9 = uVar9 + 1;
                  param_3 = param_3 + 3;
                } while (uVar9 < (uint)((piVar2[1] - iVar7) / 0x14));
                return 1;
              }
              piVar5 = piVar5 + 2;
            } while (piVar5 != (int *)puVar3[1]);
          }
          puVar4 = (undefined4 *)piVar2[5];
          param_1 = (int *)((int)param_1 + 1);
          puVar3 = puVar3 + 4;
        } while (puVar3 != puVar4);
      }
      piVar8 = piVar8 + 2;
    } while (piVar8 != piVar1);
  }
  FUN_00847ee0();
  iVar7 = piVar2[1] - *piVar2 >> 0x1f;
  local_8 = 0;
  if ((piVar2[1] - *piVar2) / 0x14 + iVar7 != iVar7) {
    do {
      FUN_00857f00();
      local_8 = local_8 + 1;
    } while (local_8 < (uint)((piVar2[1] - *piVar2) / 0x14));
  }
  return 1;
}

