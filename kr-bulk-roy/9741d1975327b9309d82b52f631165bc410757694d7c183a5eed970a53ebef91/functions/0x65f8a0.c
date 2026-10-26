
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f8a0(int param_1)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  uint in_ECX;
  uint uVar8;
  byte *pbVar9;
  bool bVar10;
  float10 extraout_ST0;
  undefined1 auStack_134 [52];
  float fStack_100;
  int iStack_fc;
  uint local_f8;
  uint uStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_dc;
  uint uStack_d8;
  ushort ***apppuStack_d0 [5];
  uint uStack_bc;
  uint uStack_a0;
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  local_44._0_1_ = 0xff;
  local_44._1_3_ = 0xffffff;
  puStack_48 = &LAB_0093d4aa;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_134;
  ExceptionList = &local_4c;
  local_f8 = in_ECX;
  if (*(uint *)(param_1 + 0x1b0) != in_ECX) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_44 = 0;
      FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffec0);
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_44._0_1_ = 0xff;
    local_44._1_3_ = 0xffffff;
    iVar3 = *(int *)(param_1 + 0x160);
    if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(**(int **)(param_1 + 0x160) + 200))();
    *(uint *)(param_1 + 0x1b0) = local_f8;
  }
  uVar7 = local_f8;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_44 = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_44._0_1_ = 0xff;
    local_44._1_3_ = 0xffffff;
  }
  if (((uVar7 < 10) &&
      (iVar3 = uVar7 * 0x210, iStack_f0 = iVar3 + DAT_00f94304,
      *(int *)(iVar3 + 0x5c + DAT_00f94304) != 0)) && (iStack_f0 != 0)) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_44 = 2;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_44._0_1_ = 0xff;
      local_44._1_3_ = 0xffffff;
    }
    FUN_00483f00();
    local_44 = 3;
    if (uStack_bc < 8) {
      apppuStack_d0[0] = (ushort ***)apppuStack_d0;
    }
    puVar4 = (ushort *)(*(int *)(param_1 + 0xf4) + 0xe8);
    if (7 < *(uint *)(*(int *)(param_1 + 0xf4) + 0xfc)) {
      puVar4 = *(ushort **)puVar4;
    }
    do {
      uVar1 = *puVar4;
      bVar10 = uVar1 < *(ushort *)apppuStack_d0[0];
      if (uVar1 != *(ushort *)apppuStack_d0[0]) {
LAB_0065fa9e:
        iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_0065faa3;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar4[1];
      bVar10 = uVar1 < *(ushort *)((int)apppuStack_d0[0] + 2);
      if (uVar1 != *(ushort *)((int)apppuStack_d0[0] + 2)) goto LAB_0065fa9e;
      puVar4 = puVar4 + 2;
      apppuStack_d0[0] = apppuStack_d0[0] + 1;
    } while (uVar1 != 0);
    iVar3 = 0;
LAB_0065faa3:
    if (iVar3 != 0) {
      FUN_00757800();
      (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
    }
    uStack_ec = (ushort *)((uint)uStack_ec._2_2_ << 0x10);
    uStack_d8 = 7;
    uStack_dc = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    local_44._0_1_ = 4;
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_44._0_1_ = 5;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_44._0_1_ = 4;
    }
    local_44._0_1_ = 4;
    if (DAT_00fc0bd8 != 0) {
      if ((DAT_00fbad10 & 1) == 0) {
        DAT_00fbad10 = DAT_00fbad10 | 1;
        local_44._0_1_ = 6;
        FUN_004e8010();
        _atexit((_func_4879 *)&LAB_00bcd6b0);
      }
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_44._0_1_ = 7;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
      local_44._0_1_ = 4;
      FUN_004f7370();
      FUN_004ed610();
      local_44._0_1_ = 8;
      FUN_00402800();
      local_44._0_1_ = 4;
      if (7 < uStack_a0) {
        FUN_0089120c();
      }
    }
    puVar4 = (ushort *)(*(int *)(param_1 + 0xf8) + 0xe8);
    if (7 < *(uint *)(*(int *)(param_1 + 0xf8) + 0xfc)) {
      puVar4 = *(ushort **)puVar4;
    }
    puVar5 = uStack_ec;
    if (uStack_d8 < 8) {
      puVar5 = (ushort *)&uStack_ec;
    }
    do {
      uVar1 = *puVar5;
      bVar10 = uVar1 < *puVar4;
      if (uVar1 != *puVar4) {
LAB_0065fc46:
        iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_0065fc4b;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar5[1];
      bVar10 = uVar1 < puVar4[1];
      if (uVar1 != puVar4[1]) goto LAB_0065fc46;
      puVar4 = puVar4 + 2;
      puVar5 = puVar5 + 2;
    } while (uVar1 != 0);
    iVar3 = 0;
LAB_0065fc4b:
    if (iVar3 != 0) {
      FUN_00757800();
      (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    }
    puVar4 = (ushort *)(*(int *)(param_1 + 0xfc) + 0xe8);
    if (7 < *(uint *)(*(int *)(param_1 + 0xfc) + 0xfc)) {
      puVar4 = *(ushort **)puVar4;
    }
    puVar5 = (ushort *)(&PTR_DAT_00d6a1c4)[local_f8];
    do {
      uVar1 = *puVar5;
      bVar10 = uVar1 < *puVar4;
      if (uVar1 != *puVar4) {
LAB_0065fcbb:
        iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_0065fcc0;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar5[1];
      bVar10 = uVar1 < puVar4[1];
      if (uVar1 != puVar4[1]) goto LAB_0065fcbb;
      puVar5 = puVar5 + 2;
      puVar4 = puVar4 + 2;
    } while (uVar1 != 0);
    iVar3 = 0;
LAB_0065fcc0:
    if (iVar3 != 0) {
      FUN_00757710();
      (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_44._0_1_ = 9;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_44._0_1_ = 4;
    }
    iStack_fc = DAT_00f942ac;
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_44._0_1_ = 10;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_44._0_1_ = 4;
    }
    if (iStack_fc != 0) {
      uStack_f4 = (iStack_fc - 1U) / 6;
      FUN_0082ef00();
    }
    iVar3 = *(int *)(param_1 + 0x104);
    if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      FUN_0077b200();
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_44._0_1_ = 0xb;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_44._0_1_ = 4;
    }
    if ((iStack_fc != 0x25) && (iStack_fc != 0)) {
      fStack_100 = (float)(0xc - (iStack_fc - 1U) % 6);
      FUN_0082ef00();
    }
    iVar3 = *(int *)(param_1 + 0x108);
    if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      FUN_0077b200();
    }
    if ((_DAT_00fc1ca8 & 1) == 0) {
      _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
      DAT_00fc1cac = 0;
      DAT_00fc1cb0 = 0;
      _DAT_00fc1cb4 = 0;
      _atexit((_func_4879 *)&LAB_00bce5a0);
    }
    FUN_0082b710();
    FUN_00757710();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_44._0_1_ = 0xc;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_44._0_1_ = 4;
    }
    iVar3 = DAT_00f942b0;
    if ((_DAT_00fc1ca8 & 1) == 0) {
      _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
      DAT_00fc1cac = 0;
      DAT_00fc1cb0 = 0;
      _DAT_00fc1cb4 = 0;
      _atexit((_func_4879 *)&LAB_00bce5a0);
    }
    iVar6 = FUN_0082b6a0();
    if ((_DAT_00fc1ca8 & 1) == 0) {
      _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
      DAT_00fc1cac = 0;
      DAT_00fc1cb0 = 0;
      _DAT_00fc1cb4 = 0;
      _atexit((_func_4879 *)&LAB_00bce5a0);
    }
    fStack_100 = (float)(iVar3 - iVar6);
    iVar3 = FUN_0082b6a0();
    fStack_100 = (float)((extraout_ST0 / (float10)(iVar3 - iVar6)) * (float10)100.0);
    FUN_006614f0(L"%0.2f%%",(double)fStack_100);
    FUN_00757710();
    iVar3 = *(int *)(iStack_f0 + 0x40);
    if (*(int *)(param_1 + 0x1b4) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x110) + 200))();
      *(int *)(param_1 + 0x1b4) = iVar3;
    }
    iVar6 = iStack_f0;
    iVar3 = *(int *)(iStack_f0 + 0x44);
    if (*(int *)(param_1 + 0x1b8) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x114) + 200))();
      *(int *)(param_1 + 0x1b8) = iVar3;
    }
    iVar3 = *(int *)(iVar6 + 0x48);
    if (*(int *)(param_1 + 0x1bc) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x118) + 200))();
      *(int *)(param_1 + 0x1bc) = iVar3;
    }
    iVar3 = *(int *)(iVar6 + 0xb0);
    if (*(int *)(param_1 + 0x1c0) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x11c) + 200))();
      *(int *)(param_1 + 0x1c0) = iVar3;
    }
    iVar3 = *(int *)(iVar6 + 0xb4);
    if (*(int *)(param_1 + 0x1c4) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x120) + 200))();
      *(int *)(param_1 + 0x1c4) = iVar3;
    }
    iVar3 = *(int *)(iVar6 + 0xb8);
    if (*(int *)(param_1 + 0x1c8) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x124) + 200))();
      *(int *)(param_1 + 0x1c8) = iVar3;
    }
    iVar3 = *(int *)(iVar6 + 0xbc);
    if (*(int *)(param_1 + 0x1cc) != iVar3) {
      FUN_007597b0();
      (**(code **)(**(int **)(param_1 + 0x128) + 200))();
      *(int *)(param_1 + 0x1cc) = iVar3;
    }
    uVar7 = *(int *)(DAT_00fe1df4 + 0xc) - *(int *)(DAT_00fe1df4 + 8) >> 3;
    uVar8 = 0;
    if (uVar7 != 0) {
      pbVar9 = *(byte **)(DAT_00fe1df4 + 8);
      do {
        if ((*pbVar9 == local_f8) && (*(int *)(iVar6 + 8) < (int)(uint)pbVar9[1])) {
          bVar2 = 1;
          goto LAB_006601b1;
        }
        uVar8 = uVar8 + 1;
        pbVar9 = pbVar9 + 8;
      } while (uVar8 < uVar7);
    }
    bVar2 = 0;
LAB_006601b1:
    fStack_100 = (float)CONCAT31((int3)((uint)*(int *)(iVar6 + 8) >> 8),bVar2);
    if (((byte)((uint)(*(int **)(param_1 + 0x164))[10] >> 7) & 1) != bVar2) {
      (**(code **)(**(int **)(param_1 + 0x164) + 0x90))();
    }
    if (7 < uStack_d8) {
      FUN_0089120c();
    }
    uStack_d8 = 7;
    uStack_dc = 0;
    uStack_ec = (ushort *)((uint)uStack_ec & 0xffff0000);
    if (7 < uStack_bc) {
      FUN_0089120c();
    }
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_134);
  return;
}

