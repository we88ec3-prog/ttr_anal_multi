
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00669a00(void)

{
  short sVar1;
  code *pcVar2;
  size_t _Size;
  int iVar3;
  undefined1 *puVar4;
  short *psVar5;
  short *psVar6;
  wchar_t *****_Src;
  undefined4 *_Src_00;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  undefined2 local_1114 [8];
  undefined4 local_1104;
  undefined2 *local_1100;
  undefined2 local_10f8 [8];
  undefined4 local_10e8;
  undefined4 local_10e4;
  short local_10c4 [2];
  undefined4 local_10c0;
  undefined1 *local_10bc;
  undefined1 *local_10b8;
  undefined4 local_10b4;
  uint local_10a4;
  uint local_10a0;
  undefined4 local_1098;
  undefined4 local_1088;
  uint local_1084;
  wchar_t ****local_107c [4];
  uint local_106c;
  uint local_1068;
  undefined4 local_1060;
  undefined4 local_1050;
  uint local_104c;
  undefined4 local_1034;
  undefined1 *local_1030;
  undefined1 local_102c;
  undefined2 local_1028;
  undefined1 auStack_1026 [4094];
  int local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d0c7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_10c4;
  ExceptionList = &local_14;
  local_10c0 = in_ECX;
  puVar4 = (undefined1 *)FUN_0068ace0();
  local_10bc = puVar4;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f94244 < puVar4 + 100) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    local_10b8 = (undefined1 *)local_10f8;
    local_10e4 = 7;
    local_10e8 = 0;
    local_1100 = &DAT_00bed1fc;
    local_10f8[0] = 0;
    local_1104 = 0x669b03;
    FUN_00402160();
    local_c = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 3;
      local_c._1_3_ = 0;
      local_1100 = (undefined2 *)0x669b30;
      FUN_00584c40();
      local_1100 = (undefined2 *)0x669b3a;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    local_10c0 = 0xf;
    local_1100 = (undefined2 *)0x669b60;
    FUN_005740f0();
    if (local_10bc == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_10bc + 0x10);
    if (7 < *(uint *)(local_10bc + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_10bc = (undefined1 *)local_1114;
    local_1100 = (undefined2 *)0x7;
    local_1104 = 0;
    local_1114[0] = 0;
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x100);
    local_28 = 0;
    if (*(char *)(iVar8 + 0x141) != '\0') {
      FUN_006edb10();
    }
    piVar7 = (int *)(iVar8 + 0x108);
    if (7 < *(uint *)(iVar8 + 0x11c)) {
      piVar7 = (int *)*piVar7;
    }
    local_107c[0] = (wchar_t ****)((uint)local_107c[0] & 0xffff0000);
    local_1068 = 7;
    local_106c = 0;
    do {
      sVar1 = *(short *)piVar7;
      piVar7 = (int *)((int)piVar7 + 2);
    } while (sVar1 != 0);
    FUN_00402160();
    local_c = 4;
    local_10c4[0] = 0x2019;
    local_10c4[1] = 0;
    if (0x14 < local_106c) {
      FUN_00402400();
    }
    psVar6 = local_10c4;
    local_1060 = (uint)local_1060._2_2_ << 0x10;
    local_104c = 7;
    local_1050 = 0;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_c._0_1_ = 5;
    local_1098 = (uint)local_1098._2_2_ << 0x10;
    local_1084 = 7;
    local_1088 = 0;
    FUN_00402160();
    local_c = CONCAT31(local_c._1_3_,6);
    FUN_006699b0();
    if (7 < local_1084) {
      FUN_0089120c();
    }
    local_1084 = 7;
    local_1088 = 0;
    local_1098 = local_1098 & 0xffff0000;
    if (7 < local_104c) {
      FUN_0089120c();
    }
    local_10a0 = 7;
    local_10a4 = 0;
    local_10b4 = (undefined4 *)((uint)local_10b4._2_2_ << 0x10);
    local_c = CONCAT31(local_c._1_3_,7);
    FUN_00765c20();
    if (200 < local_10a4) {
      FUN_00402400();
    }
    psVar6 = local_10c4;
    local_1060 = local_1060 & 0xffff0000;
    local_104c = 7;
    local_1050 = 0;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_c._0_1_ = 8;
    local_1098 = local_1098 & 0xffff0000;
    local_1084 = 7;
    local_1088 = 0;
    FUN_00402160();
    local_c = CONCAT31(local_c._1_3_,9);
    FUN_006699b0();
    if (7 < local_1084) {
      FUN_0089120c();
    }
    local_c = CONCAT31(local_c._1_3_,7);
    local_1084 = 7;
    local_1088 = 0;
    local_1098 = local_1098 & 0xffff0000;
    if (7 < local_104c) {
      FUN_0089120c();
    }
    iVar8 = local_10c0;
    _Src = (wchar_t *****)local_107c[0];
    if (local_1068 < 8) {
      _Src = local_107c;
    }
    local_1034 = *(undefined4 *)(local_10c0 + 0x16c);
    local_1060 = CONCAT22(local_1060._2_2_,0x92);
    local_1030 = local_10bc;
    local_102c = (undefined1)local_10a4;
    local_10e4 = 0x669e7d;
    _wcscpy_s((wchar_t *)((int)&local_1060 + 2),0x15,(wchar_t *)_Src);
    if (local_28 + 0x35U < 0x1001) {
      local_10e4 = 0x669ea6;
      FID_conflict__memcpy((void *)((int)&local_1028 + local_28),&local_1060,0x35);
      local_28 = local_28 + 0x35;
    }
    _Src_00 = local_10b4;
    if (local_10a0 < 8) {
      _Src_00 = &local_10b4;
    }
    _Size = local_10a4 * 2;
    if (local_28 + _Size < 0x1001) {
      local_10e4 = 0x669ee8;
      FID_conflict__memcpy((void *)((int)&local_1028 + local_28),_Src_00,_Size);
      local_28 = local_28 + _Size;
    }
    piVar7 = (int *)(iVar8 + 0x118);
    iVar9 = 3;
    iVar8 = local_28;
    do {
      if ((*piVar7 != 0) && (piVar7[1] != 0)) {
        iVar3 = piVar7[3];
        local_10c0._0_2_ = CONCAT11((char)piVar7[1],(char)*piVar7);
        if (iVar8 + 3U < 0x1001) {
          *(undefined2 *)((int)&local_1028 + iVar8) = (undefined2)local_10c0;
          auStack_1026[iVar8] = (char)iVar3;
          iVar8 = local_28 + 3;
          local_28 = iVar8;
        }
      }
      piVar7 = piVar7 + 6;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    local_10e4 = 0x669f6e;
    (**(code **)(*DAT_00fba854 + 0x10))();
    if (7 < local_10a0) {
      FUN_0089120c();
    }
    local_10a0 = 7;
    local_10a4 = 0;
    local_10b4 = (undefined4 *)((uint)local_10b4 & 0xffff0000);
    if (7 < local_1068) {
      FUN_0089120c();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_10c4);
  return;
}

