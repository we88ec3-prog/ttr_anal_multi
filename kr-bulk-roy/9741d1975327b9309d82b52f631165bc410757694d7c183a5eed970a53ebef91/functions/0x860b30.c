
/* WARNING: Type propagation algorithm not settling */

undefined4 * FUN_00860b30(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint local_18;
  undefined1 *local_14 [4];
  
  local_14[2] = &LAB_0091800b;
  local_14[1] = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = local_14 + 1;
  param_1[1] = 0;
  local_14[3] = (undefined1 *)0x0;
  *param_1 = gbBase::vftable;
  param_1[6] = 0;
  param_1[7] = 0xf;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(param_2 + 8,0,0xffffffff);
  param_1[9] = 1;
  puVar1 = param_1 + 0xc;
  *param_1 = gbTexImageController::vftable;
  *puVar1 = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  local_14[3] = (undefined1 *)0x2;
  param_1[10] = 0xa1400000;
  param_1[0xb] = 1;
  param_1[0x10] = *(undefined4 *)(param_2 + 0x40);
  local_18 = 0;
  param_1[0x12] = *(undefined4 *)(param_2 + 0x48);
  if (*(int *)(param_2 + 0x34) - *(int *)(param_2 + 0x30) >> 2 != 0) {
    do {
      puVar5 = (undefined4 *)FUN_00891268(8,uVar4);
      puVar8 = (undefined4 *)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar8 = puVar5;
      }
      puVar5 = *(undefined4 **)(*(int *)(param_2 + 0x30) + local_18 * 4);
      *puVar8 = *puVar5;
      puVar8[1] = puVar5[1];
      ppuVar2 = (undefined4 **)param_1[0xd];
      local_14[0] = (undefined1 *)puVar8;
      if ((local_14 < ppuVar2) && (ppuVar3 = (undefined4 **)*puVar1, ppuVar3 <= local_14)) {
        if (ppuVar2 == (undefined4 **)param_1[0xe]) {
          uVar6 = (int)ppuVar2 - (int)ppuVar3 >> 2;
          if (0x3ffffffe < uVar6) {
LAB_00860d10:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar7 = (int)param_1[0xe] - (int)ppuVar3 >> 2;
          if (uVar7 < uVar6) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_00797980(uVar7);
          }
        }
        if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[0xd] =
               *(undefined4 *)(*puVar1 + ((int)local_14 - (int)ppuVar3 >> 2) * 4);
        }
      }
      else {
        if (ppuVar2 == (undefined4 **)param_1[0xe]) {
          uVar6 = (int)((int)ppuVar2 - *puVar1) >> 2;
          if (0x3ffffffe < uVar6) goto LAB_00860d10;
          uVar6 = uVar6 + 1;
          uVar7 = (int)((int)param_1[0xe] - *puVar1) >> 2;
          if (uVar7 < uVar6) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_00797980(uVar7);
          }
        }
        if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[0xd] = puVar8;
        }
      }
      param_1[0xd] = param_1[0xd] + 4;
      FUN_008613c0(*puVar1,param_1[0xd],(int)(param_1[0xd] - *puVar1) >> 2,FUN_008613a0);
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(*(int *)(param_2 + 0x34) - *(int *)(param_2 + 0x30) >> 2));
  }
  ExceptionList = local_14[1];
  return param_1;
}

