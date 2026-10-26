
void FUN_006940c0(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  short *psVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  undefined4 uVar10;
  int unaff_EDI;
  bool bVar11;
  uint local_58;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00942afc;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if ((DAT_00fb7258 == 0) || (iVar5 = FUN_00539aa0(), iVar5 == 0)) goto LAB_0069472a;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  psVar6 = (short *)FUN_004f6a30();
  local_30 = (ushort *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  do {
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  FUN_00402160();
  puVar7 = (ushort *)(unaff_EDI + 0xb8);
  local_8 = 2;
  if (7 < *(uint *)(unaff_EDI + 0xcc)) {
    puVar7 = *(ushort **)puVar7;
  }
  puVar8 = local_30;
  if (local_1c < 8) {
    puVar8 = (ushort *)&local_30;
  }
  do {
    uVar3 = *puVar8;
    bVar11 = uVar3 < *puVar7;
    if (uVar3 != *puVar7) {
LAB_006941f9:
      iVar9 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_006941fe;
    }
    if (uVar3 == 0) break;
    uVar3 = puVar8[1];
    bVar11 = uVar3 < puVar7[1];
    if (uVar3 != puVar7[1]) goto LAB_006941f9;
    puVar7 = puVar7 + 2;
    puVar8 = puVar8 + 2;
  } while (uVar3 != 0);
  iVar9 = 0;
LAB_006941fe:
  if (iVar9 != 0) {
    FUN_00757710();
    (**(code **)(**(int **)(unaff_EDI + 0x88) + 200))();
    FUN_004026e0();
  }
  local_58 = (uint)*(byte *)(iVar5 + 5);
  (**(code **)(**(int **)(unaff_EDI + 0x90) + 0x94))();
  (**(code **)(**(int **)(unaff_EDI + 0x8c) + 0x94))();
  (**(code **)(**(int **)(unaff_EDI + 0x98) + 0x94))();
  FUN_0040f060();
  iVar9 = FUN_004dfb60();
  if ((iVar9 == 0) || (*(char *)(unaff_EDI + 0xf4) == '\0')) {
    bVar1 = *(byte *)(iVar5 + 4);
    if ((uint)bVar1 != *(uint *)(unaff_EDI + 0xd4)) {
      FUN_00403470();
      FUN_00745100();
      (**(code **)(**(int **)(unaff_EDI + 0x84) + 200))();
      *(uint *)(unaff_EDI + 0xd4) = (uint)bVar1;
    }
    uVar10 = 100;
    if ((*(int *)(unaff_EDI + 0xdc) != 100) || (*(int *)(unaff_EDI + 0xe0) != 100)) {
      pcVar4 = *(code **)(**(int **)(unaff_EDI + 0x9c) + 0x128);
      (*(int **)(unaff_EDI + 0x9c))[0x34] = 0x3f800000;
      (*pcVar4)();
      if (*(int *)(*(int *)(unaff_EDI + 0x9c) + 0xcc) != 0) {
        FUN_00757710();
      }
      (**(code **)(**(int **)(unaff_EDI + 0x9c) + 200))();
      *(undefined4 *)(unaff_EDI + 0xdc) = 100;
      *(undefined4 *)(unaff_EDI + 0xe0) = 100;
    }
    if ((*(int *)(unaff_EDI + 0xe4) != 100) || (*(int *)(unaff_EDI + 0xe8) != 100)) {
      pcVar4 = *(code **)(**(int **)(unaff_EDI + 0xa0) + 0x128);
      (*(int **)(unaff_EDI + 0xa0))[0x34] = 0x3f800000;
      (*pcVar4)();
      if (*(int *)(*(int *)(unaff_EDI + 0xa0) + 0xcc) != 0) {
        FUN_00757710();
      }
      (**(code **)(**(int **)(unaff_EDI + 0xa0) + 200))();
      *(undefined4 *)(unaff_EDI + 0xe4) = 100;
      *(undefined4 *)(unaff_EDI + 0xe8) = 100;
    }
    if ((*(int *)(unaff_EDI + 0xec) != 100) || (*(int *)(unaff_EDI + 0xf0) != 100)) {
      pcVar4 = *(code **)(**(int **)(unaff_EDI + 0xa4) + 0x128);
      (*(int **)(unaff_EDI + 0xa4))[0x34] = 0x3f800000;
      (*pcVar4)();
      if (*(int *)(*(int *)(unaff_EDI + 0xa4) + 0xcc) != 0) {
        FUN_00757710();
      }
      (**(code **)(**(int **)(unaff_EDI + 0xa4) + 200))();
      *(undefined4 *)(unaff_EDI + 0xec) = 100;
      goto LAB_006946a6;
    }
  }
  else {
    uVar3 = *(ushort *)(iVar9 + 0x88);
    if ((uint)uVar3 != *(uint *)(unaff_EDI + 0xd4)) {
      FUN_00403470();
      FUN_00745100();
      (**(code **)(**(int **)(unaff_EDI + 0x84) + 200))();
      *(uint *)(unaff_EDI + 0xd4) = (uint)uVar3;
    }
    local_58 = *(uint *)(iVar9 + 0x3d4);
    if ((*(int *)(unaff_EDI + 0xdc) != *(int *)(iVar9 + 0x3c8)) ||
       (*(int *)(unaff_EDI + 0xe0) != *(int *)(iVar9 + 0x3bc))) {
      if (*(int *)(iVar9 + 0x3bc) < 1) {
        pcVar4 = *(code **)(**(int **)(unaff_EDI + 0x9c) + 0x128);
        (*(int **)(unaff_EDI + 0x9c))[0x34] = 0;
        (*pcVar4)();
      }
      else {
        FUN_0075bd40();
      }
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0x9c));
      (**(code **)(**(int **)(unaff_EDI + 0x9c) + 200))();
      *(undefined4 *)(unaff_EDI + 0xdc) = *(undefined4 *)(iVar9 + 0x3c8);
      *(undefined4 *)(unaff_EDI + 0xe0) = *(undefined4 *)(iVar9 + 0x3bc);
    }
    if ((*(int *)(unaff_EDI + 0xe4) != *(int *)(iVar9 + 0x3cc)) ||
       (*(int *)(unaff_EDI + 0xe8) != *(int *)(iVar9 + 0x3c0))) {
      if (*(int *)(iVar9 + 0x3c0) < 1) {
        pcVar4 = *(code **)(**(int **)(unaff_EDI + 0xa0) + 0x128);
        (*(int **)(unaff_EDI + 0xa0))[0x34] = 0;
        (*pcVar4)();
      }
      else {
        FUN_0075bd40();
      }
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa0));
      (**(code **)(**(int **)(unaff_EDI + 0xa0) + 200))();
      *(undefined4 *)(unaff_EDI + 0xe4) = *(undefined4 *)(iVar9 + 0x3cc);
      *(undefined4 *)(unaff_EDI + 0xe8) = *(undefined4 *)(iVar9 + 0x3c0);
    }
    if ((*(int *)(unaff_EDI + 0xec) != *(int *)(iVar9 + 0x3d0)) ||
       (*(int *)(unaff_EDI + 0xf0) != *(int *)(iVar9 + 0x3c4))) {
      if (*(int *)(iVar9 + 0x3c4) < 1) {
        pcVar4 = *(code **)(**(int **)(unaff_EDI + 0xa4) + 0x128);
        (*(int **)(unaff_EDI + 0xa4))[0x34] = 0;
        (*pcVar4)();
      }
      else {
        FUN_0075bd40();
      }
      FUN_0040e460(&DAT_00bf2bf8);
      FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa4));
      (**(code **)(**(int **)(unaff_EDI + 0xa4) + 200))();
      *(undefined4 *)(unaff_EDI + 0xec) = *(undefined4 *)(iVar9 + 0x3d0);
      uVar10 = *(undefined4 *)(iVar9 + 0x3c4);
LAB_006946a6:
      *(undefined4 *)(unaff_EDI + 0xf0) = uVar10;
    }
  }
  if (local_58 != *(uint *)(unaff_EDI + 0xd8)) {
    FUN_0040ef80();
    local_8._0_1_ = 3;
    FUN_00757710();
    local_8 = CONCAT31(local_8._1_3_,2);
    if (7 < local_38) {
      FUN_0089120c();
    }
    (**(code **)(**(int **)(unaff_EDI + 0x94) + 200))();
    *(uint *)(unaff_EDI + 0xd8) = local_58;
  }
  if (7 < local_1c) {
    FUN_0089120c();
  }
LAB_0069472a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

