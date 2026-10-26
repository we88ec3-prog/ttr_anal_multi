
void FUN_004bcf60(void)

{
  ushort *puVar1;
  short sVar2;
  code *pcVar3;
  void *pvVar4;
  undefined1 *puVar5;
  int *piVar6;
  short *psVar7;
  short *psVar8;
  uint uVar9;
  undefined2 local_94 [8];
  undefined4 local_84;
  undefined2 *local_80;
  undefined4 uStack_7c;
  undefined2 local_78 [8];
  undefined4 local_68;
  undefined4 local_64;
  undefined1 *local_44;
  undefined1 *local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947b56;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  if ((DAT_00fe18c8 & 1) == 0) {
    DAT_00fe18c8 = DAT_00fe18c8 | 1;
    local_c = 0;
    FUN_0053f970();
    _atexit((_func_4879 *)&LAB_00bce810);
  }
  local_c = 0xffffffff;
  FUN_0053ff50();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((int)DAT_00f9431c - (int)DAT_00f94318 & 0xfffffffeU) != 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_40 = (undefined1 *)0x1b8;
    FUN_005740f0();
    if (local_44 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    piVar6 = (int *)(local_44 + 0x10);
    if (7 < *(uint *)(local_44 + 0x24)) {
      piVar6 = (int *)*piVar6;
    }
    uVar9 = 0;
    local_24 = 7;
    local_28 = 0;
    local_38 = (short *)((uint)local_38._2_2_ << 0x10);
    do {
      sVar2 = *(short *)piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while (sVar2 != 0);
    FUN_00402160();
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    FUN_00404300();
    if ((int)DAT_00f9431c - (int)DAT_00f94318 >> 1 != 0) {
      do {
        puVar1 = (ushort *)((int)DAT_00f94318 + uVar9 * 2);
        if ((DAT_00fe17b8 & 1) == 0) {
          DAT_00fe17b8 = DAT_00fe17b8 | 1;
          local_c._0_1_ = 4;
          FUN_0050caf0();
          _atexit((_func_4879 *)&LAB_00bce7e0);
          local_c._0_1_ = 3;
        }
        local_44 = (undefined1 *)(uint)*puVar1;
        FUN_005366c0();
        puVar5 = local_40;
        if (((local_40 != (undefined1 *)DAT_00fe17e4) && (local_40 != (undefined1 *)0xfffffff0)) &&
           (*(int *)((int)local_40 + 0x28) != 0)) {
          local_64 = 0x4bd164;
          FUN_004041f0();
          FUN_00404300();
          psVar7 = (short *)(&PTR_u_Normal_00d6a208)[*(int *)((int)puVar5 + 0x14)];
          do {
            sVar2 = *psVar7;
            psVar7 = psVar7 + 1;
          } while (sVar2 != 0);
          FUN_00404300();
          FUN_00404300();
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < (uint)((int)DAT_00f9431c - (int)DAT_00f94318 >> 1));
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c._0_1_ = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c._0_1_ = 3;
    }
    local_44 = (undefined1 *)local_78;
    uStack_7c = 0;
    local_64 = 7;
    local_68 = 0;
    local_80 = &DAT_00bed1fc;
    local_78[0] = 0;
    local_84 = 0x4bd216;
    FUN_00402160();
    local_c._0_1_ = 6;
    psVar7 = local_38;
    if (local_24 < 8) {
      psVar7 = (short *)&local_38;
    }
    local_40 = (undefined1 *)local_94;
    local_80 = (undefined2 *)0x7;
    local_84 = 0;
    local_94[0] = 0;
    psVar8 = psVar7;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_0058b270(0xca);
    pvVar4 = DAT_00f94318;
    if (DAT_00f94318 != DAT_00f9431c) {
      local_64 = 0x4bd287;
      FID_conflict__memcpy(DAT_00f94318,DAT_00f9431c,0);
      DAT_00f9431c = pvVar4;
    }
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c();
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = (short *)((uint)local_38 & 0xffff0000);
  }
  FUN_004adb10();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

