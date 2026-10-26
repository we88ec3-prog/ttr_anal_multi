
/* WARNING: Removing unreachable block (ram,0x00420ff5) */

void FUN_004209e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  undefined2 auStack_ec [6];
  undefined4 uStack_e0;
  undefined4 *puStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined2 local_d0 [4];
  undefined4 uStack_c8;
  int local_a4;
  undefined1 *local_a0;
  undefined1 *local_9c;
  int local_98;
  uint local_94;
  undefined1 uStack_90;
  uint local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941d50;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_a4;
  ExceptionList = &local_14;
  local_9c = (undefined1 *)0x0;
  uVar8 = DAT_00fb7348 + 8;
  local_94 = uVar8;
  if (*(int *)(DAT_00fb7348 + 0x11) == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_a4 = 0x15a;
    FUN_005740f0();
    if (local_a0 == (undefined1 *)DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 0;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_a0 = (undefined1 *)0x159;
    FUN_005740f0();
    if (local_a4 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
  }
  FUN_00757710();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  local_a0 = *(undefined1 **)(DAT_00fab130 + 0x5eac);
  if ((DAT_00fb7324 & 1) == 0) {
    DAT_00fb7324 = DAT_00fb7324 | 1;
    local_c = 3;
    FUN_0081b920();
    _atexit((_func_4879 *)&LAB_00bcd080);
    local_c = 0xffffffff;
  }
  iVar7 = FUN_0081bb60();
  if (iVar7 != 0) {
    local_a4 = iVar7;
    if ((DAT_00fb7324 & 1) == 0) {
      DAT_00fb7324 = DAT_00fb7324 | 1;
      local_c = 4;
      FUN_0081b920();
      _atexit((_func_4879 *)&LAB_00bcd080);
      local_c = 0xffffffff;
    }
    FUN_0081c9e0();
    if (*(uint *)(iVar7 + 0x28) < 2) {
      local_8c = local_8c & 0xffff0000;
      local_78 = 7;
      local_7c = 0;
      FUN_00402160();
      local_c = 6;
      uVar8 = 2;
    }
    else {
      FUN_004ed610();
      local_c = 5;
      uVar8 = 1;
    }
    local_5c = 7;
    local_60 = 0;
    local_70 = (uint)local_70._2_2_ << 0x10;
    local_9c = (undefined1 *)uVar8;
    FUN_00402800();
    local_c = 7;
    if ((uVar8 & 2) != 0) {
      uVar8 = uVar8 & 0xfffffffd;
      if (7 < local_78) {
        FUN_0089120c();
      }
      local_78 = 7;
      local_7c = 0;
      local_8c = local_8c & 0xffff0000;
    }
    local_c._0_1_ = 9;
    if ((uVar8 & 1) != 0) {
      if (7 < local_40) {
        FUN_0089120c();
      }
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
    }
    local_a0 = (undefined1 *)local_d0;
    uStack_d4 = 0xffffffff;
    uStack_d8 = 0;
    puStack_dc = &local_70;
    local_d0[0] = 0;
    uStack_e0 = 0x420d27;
    FUN_004026e0();
    local_9c = (undefined1 *)auStack_ec;
    local_c._0_1_ = 10;
    uStack_d8 = 7;
    puStack_dc = (undefined4 *)0x0;
    auStack_ec[0] = 0;
    FUN_004026e0(local_a4 + 4,0,0xffffffff);
    local_c._0_1_ = 9;
    FUN_004213a0(L"{0}{1}");
    local_c = CONCAT31(local_c._1_3_,0xb);
    FUN_00757800();
    if (7 < uStack_24) {
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    uVar8 = local_94;
    if (7 < local_5c) {
      FUN_0089120c();
      uVar8 = local_94;
    }
  }
  local_a4 = *(int *)(uVar8 + 4);
  FUN_00421170();
  iVar7 = 0;
  local_a4 = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0xc;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  cVar6 = FUN_004d9d20();
  iVar9 = local_98;
  if (cVar6 != '\0') {
    iVar7 = 2;
  }
  local_94 = (uint)*(byte *)(uVar8 + 8);
  local_a4 = iVar7 + 3;
  FUN_004210f0();
  iVar7 = *(int *)(DAT_00fb7348 + 0x1c);
  iVar1 = *(int *)(DAT_00fb7348 + 0x18);
  if (*(int *)(*(int *)(iVar9 + 0x100) + 0xcc) != 0) {
    FUN_00408920();
  }
  iVar9 = 0;
  local_a4 = 5 - (iVar7 - iVar1) / 5;
  local_9c = (undefined1 *)0x0;
  local_a0 = (undefined1 *)0x0;
  do {
    iVar7 = *(int *)(*(int *)(local_98 + 0x100) + 0xcc);
    if ((((iVar7 == 0) || (iVar9 < 0)) ||
        (*(int *)(iVar7 + 0xac) - *(int *)(iVar7 + 0xa8) >> 2 <= iVar9)) ||
       (piVar11 = *(int **)(*(int *)(iVar7 + 0xa8) + iVar9 * 4), piVar11 == (int *)0x0)) {
LAB_00420f02:
      piVar11 = (int *)0x0;
    }
    else {
      iVar7 = (**(code **)(*piVar11 + 4))();
      if (iVar7 != 0x12d) {
        uStack_c8 = 0x420f02;
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00420f02;
      }
    }
    iVar9 = iVar9 + 1;
    if (local_a4 < iVar9) {
      (**(code **)(*(int *)piVar11[0x92] + 0x94))();
      (**(code **)(*(int *)piVar11[0x92] + 200))();
      (**(code **)(*(int *)piVar11[0x93] + 0x94))();
      (**(code **)(*(int *)piVar11[0x93] + 200))();
      if (local_9c < (uint)((*(int *)(DAT_00fb7348 + 0x1c) - *(int *)(DAT_00fb7348 + 0x18)) / 5)) {
        puVar10 = (uint *)(*(int *)(DAT_00fb7348 + 0x18) + (int)local_a0);
      }
      else {
        puVar10 = (uint *)0x0;
      }
      local_94 = *puVar10;
      uStack_90 = (undefined1)puVar10[1];
      local_9c = (undefined1 *)((int)local_9c + 1);
      local_a0 = (undefined1 *)((int)local_a0 + 5);
      FUN_00425e20();
    }
    else {
      (**(code **)(*(int *)piVar11[0x92] + 0x94))();
      (**(code **)(*(int *)piVar11[0x92] + 200))();
      (**(code **)(*(int *)piVar11[0x93] + 0x94))();
      (**(code **)(*(int *)piVar11[0x93] + 200))();
    }
    if (4 < iVar9) {
      if (*(int *)(DAT_00fb7348 + 0x18) != *(int *)(DAT_00fb7348 + 0x1c)) {
        *(int *)(DAT_00fb7348 + 0x1c) = *(int *)(DAT_00fb7348 + 0x18);
      }
      piVar11 = *(int **)(local_98 + 0x100);
      puVar2 = (undefined4 *)piVar11[0x19];
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        if ((*(int *)(puVar3[2] + 0x60) != 0) &&
           (piVar4 = *(int **)(puVar3[2] + 0x1c), piVar4[2] != 6)) {
          (**(code **)(*piVar4 + 0x30))();
        }
      }
      (**(code **)(*piVar11 + 0x128))();
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&local_a4);
      return;
    }
  } while( true );
}

