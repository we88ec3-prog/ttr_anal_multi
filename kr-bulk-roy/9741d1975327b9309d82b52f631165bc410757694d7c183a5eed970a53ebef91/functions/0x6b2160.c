
void FUN_006b2160(int param_1)

{
  int *piVar1;
  short sVar2;
  undefined4 *puVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  uint uStack_8c;
  uint local_88;
  int local_84;
  int local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093588e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_8c;
  ExceptionList = &local_14;
  local_80 = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff68);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  uVar8 = DAT_00fab1bc;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c = 1;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_c = 0xffffffff;
  local_88 = uVar8;
  FUN_0050db00(&local_88);
  if ((local_84 == DAT_00fe17c4) || (local_84 == -0x10)) {
    FUN_006edb60(&DAT_00c3cf4c);
  }
  else {
    iVar10 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
    if (iVar10 == 0) {
      uVar8 = 0xffffffff;
    }
    else {
      iVar10 = *(int *)(iVar10 + 0xdc);
      if (iVar10 == 0) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = *(uint *)(iVar10 + 0x20);
      }
    }
    local_88 = 0;
    piVar4 = (int *)(param_1 + 0x124);
    do {
      if ((*(uint *)(*piVar4 + 0x28) >> 9 & 1) != 0) goto LAB_006b22a2;
      local_88 = local_88 + 1;
      piVar4 = piVar4 + 1;
    } while (local_88 < 4);
    local_88 = 4;
LAB_006b22a2:
    if (uVar8 < *(uint *)(local_84 + 0x40)) {
      piVar4 = (int *)FUN_005cfc30();
      iVar10 = *piVar4;
      FUN_00757200(local_54);
      local_c = 2;
      if (*(uint *)(iVar10 + 0x3c) < 8) {
        psVar7 = (short *)(iVar10 + 0x28);
      }
      else {
        psVar7 = *(short **)(iVar10 + 0x28);
      }
      local_78 = (uint)local_78._2_2_ << 0x10;
      local_64 = 7;
      local_68 = 0;
      psVar5 = psVar7;
      do {
        sVar2 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
      local_c._0_1_ = 3;
      FUN_007578f0();
      FUN_00759ed0(local_54,&local_78,0x7b,0x7d);
      local_c = CONCAT31(local_c._1_3_,2);
      if (7 < local_64) {
        FUN_0089120c(local_78);
      }
      local_78 = local_78 & 0xffff0000;
      local_64 = 7;
      local_68 = 0;
      FUN_00766030();
      if (local_88 < (uint)(*(int *)(iVar10 + 0x48) - *(int *)(iVar10 + 0x44) >> 2)) {
        puVar3 = *(undefined4 **)(*(int *)(iVar10 + 0x44) + local_88 * 4);
        uVar11 = *puVar3;
        FUN_00403470(uVar11);
        FUN_005c7110(uVar11);
        FUN_00745100();
        uVar8 = (int)(puVar3[3] - puVar3[2]) >> 2;
        local_84 = -0x100 - local_80;
        local_88 = 0;
        puVar9 = (undefined4 *)(local_80 + 0x100);
        local_7c = uVar8;
        do {
          if (local_88 < uVar8) {
            (**(code **)(*(int *)*puVar9 + 0x19c))
                      (0xffffffff,*(undefined4 *)(puVar3[2] + local_84 + (int)puVar9));
            uVar8 = uStack_8c;
          }
          else {
            (**(code **)(*(int *)*puVar9 + 0x19c))(0xffffffff,0xffffffff,0,0);
          }
          (**(code **)(*(int *)*puVar9 + 200))();
          local_88 = local_88 + 1;
          puVar9 = puVar9 + 1;
        } while (local_88 < 7);
      }
      local_c = 0xffffffff;
      FUN_00757640(local_54);
      param_1 = local_80;
    }
    else {
      iVar10 = *(int *)(param_1 + 0xf8);
      if (((*(char *)(iVar10 + 0xa4) != '\0') && (*(int *)(iVar10 + 0x94) != 0)) &&
         (iVar6 = (**(code **)(**(int **)(iVar10 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
        iVar10 = *(int *)(iVar10 + 0x94);
        iVar6 = *(int *)(iVar10 + 0x10);
        if (iVar6 != 0) {
          piVar4 = *(int **)(iVar6 + 8);
          if (piVar4 != (int *)0x0) {
            piVar1 = piVar4 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar4 + 0x28))();
            }
          }
          *(undefined4 *)(iVar10 + 0x10) = 0;
        }
      }
      FUN_00765f70(*(undefined4 *)(param_1 + 0xf4),&DAT_00bed1fc);
      puVar9 = (undefined4 *)(param_1 + 0x100);
      iVar10 = 7;
      do {
        (**(code **)(*(int *)*puVar9 + 0x19c))(0xffffffff,0xffffffff,0,0);
        (**(code **)(*(int *)*puVar9 + 200))();
        puVar9 = puVar9 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_8c);
  return;
}

