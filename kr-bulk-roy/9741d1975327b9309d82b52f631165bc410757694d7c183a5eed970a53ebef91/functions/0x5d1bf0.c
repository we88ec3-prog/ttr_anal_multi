
void FUN_005d1bf0(void)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  undefined1 *puStack_40;
  int iStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009437f6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_40;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_54 = 0x5d1c4d;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) && (iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar4 != 0)) {
    if ((*(int *)(iVar4 + 0x158) == 0) || (*(int *)(*(int *)(iVar4 + 0x158) + 0x34) != 0)) {
      if (*(char *)(unaff_EDI + 0x80) == '\0') {
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa4));
        pcVar1 = *(code **)(**(int **)(unaff_EDI + 0xa4) + 0x128);
        (*(int **)(unaff_EDI + 0xa4))[0x34] = 0;
        (*pcVar1)();
        (**(code **)(**(int **)(unaff_EDI + 0xa4) + 200))();
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa8));
        pcVar1 = *(code **)(**(int **)(unaff_EDI + 0xa8) + 0x128);
        (*(int **)(unaff_EDI + 0xa8))[0x34] = 0;
        (*pcVar1)();
        (**(code **)(**(int **)(unaff_EDI + 0xa8) + 200))();
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xac));
        pcVar1 = *(code **)(**(int **)(unaff_EDI + 0xac) + 0x128);
        (*(int **)(unaff_EDI + 0xac))[0x34] = 0;
        (*pcVar1)();
        (**(code **)(**(int **)(unaff_EDI + 0xac) + 200))();
        *(undefined1 *)(unaff_EDI + 0x80) = 1;
        *(undefined4 *)(unaff_EDI + 0x8c) = 0;
        *(undefined4 *)(unaff_EDI + 0x90) = 0;
        *(undefined4 *)(unaff_EDI + 0x94) = 0;
        *(undefined4 *)(unaff_EDI + 0x98) = *(undefined4 *)(iVar4 + 0x3bc);
        *(undefined4 *)(unaff_EDI + 0x9c) = *(undefined4 *)(iVar4 + 0x3c0);
        *(undefined4 *)(unaff_EDI + 0xa0) = *(undefined4 *)(iVar4 + 0x3c4);
      }
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x3c8);
      if ((*(int *)(unaff_EDI + 0x8c) != iVar2) ||
         (*(int *)(unaff_EDI + 0x98) != *(int *)(iVar4 + 0x3bc))) {
        puVar3 = *(undefined1 **)(iVar4 + 0x3bc);
        if ((int)puVar3 < 1) {
          piVar5 = *(int **)(unaff_EDI + 0xa4);
          piVar5[0x34] = 0;
        }
        else {
          piVar5 = *(int **)(unaff_EDI + 0xa4);
          piVar5[0x34] = (int)((float)iVar2 / (float)(int)puVar3);
          puStack_40 = puVar3;
          iStack_3c = iVar2;
        }
        (**(code **)(*piVar5 + 0x128))();
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa4));
        (**(code **)(**(int **)(unaff_EDI + 0xa4) + 200))();
        *(undefined4 *)(unaff_EDI + 0x8c) = *(undefined4 *)(iVar4 + 0x3c8);
        *(undefined4 *)(unaff_EDI + 0x98) = *(undefined4 *)(iVar4 + 0x3bc);
      }
      puVar3 = *(undefined1 **)(iVar4 + 0x3cc);
      if ((*(undefined1 **)(unaff_EDI + 0x90) != puVar3) ||
         (*(int *)(unaff_EDI + 0x9c) != *(int *)(iVar4 + 0x3c0))) {
        iVar2 = *(int *)(iVar4 + 0x3c0);
        if (iVar2 < 1) {
          piVar5 = *(int **)(unaff_EDI + 0xa8);
          piVar5[0x34] = 0;
        }
        else {
          piVar5 = *(int **)(unaff_EDI + 0xa8);
          piVar5[0x34] = (int)((float)(int)puVar3 / (float)iVar2);
          puStack_40 = puVar3;
          iStack_3c = iVar2;
        }
        (**(code **)(*piVar5 + 0x128))();
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xa8));
        (**(code **)(**(int **)(unaff_EDI + 0xa8) + 200))();
        *(undefined4 *)(unaff_EDI + 0x90) = *(undefined4 *)(iVar4 + 0x3cc);
        *(undefined4 *)(unaff_EDI + 0x9c) = *(undefined4 *)(iVar4 + 0x3c0);
      }
      puVar3 = *(undefined1 **)(iVar4 + 0x3d0);
      if ((*(undefined1 **)(unaff_EDI + 0x94) != puVar3) ||
         (*(int *)(unaff_EDI + 0xa0) != *(int *)(iVar4 + 0x3c4))) {
        iVar2 = *(int *)(iVar4 + 0x3c4);
        if (iVar2 < 1) {
          piVar5 = *(int **)(unaff_EDI + 0xac);
          piVar5[0x34] = 0;
        }
        else {
          piVar5 = *(int **)(unaff_EDI + 0xac);
          piVar5[0x34] = (int)((float)(int)puVar3 / (float)iVar2);
          puStack_40 = puVar3;
          iStack_3c = iVar2;
        }
        (**(code **)(*piVar5 + 0x128))();
        puStack_40 = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0xac));
        (**(code **)(**(int **)(unaff_EDI + 0xac) + 200))();
        *(undefined4 *)(unaff_EDI + 0x94) = *(undefined4 *)(iVar4 + 0x3d0);
        *(undefined4 *)(unaff_EDI + 0xa0) = *(undefined4 *)(iVar4 + 0x3c4);
      }
      *(undefined1 *)(unaff_EDI + 0x80) = 0;
    }
    puStack_40 = (undefined1 *)(uint)*(ushort *)(iVar4 + 0x88);
    if (*(undefined1 **)(unaff_EDI + 0x84) != puStack_40) {
      FUN_00403470();
      FUN_00745100();
      (**(code **)(**(int **)(unaff_EDI + 0xb8) + 200))();
      *(undefined1 **)(unaff_EDI + 0x84) = puStack_40;
    }
    iVar4 = *(int *)(iVar4 + 0x3d4);
    if (*(int *)(unaff_EDI + 0x88) != iVar4) {
      FUN_0040ef80();
      local_c = 1;
      uStack_54 = 0x5d2081;
      FUN_00757800();
      local_c = 0xffffffff;
      if (7 < uStack_24) {
        uStack_54 = 0x5d209a;
        FUN_0089120c();
      }
      uStack_38 = uStack_38 & 0xffff0000;
      uStack_24 = 7;
      uStack_28 = 0;
      (**(code **)(**(int **)(unaff_EDI + 0xb0) + 200))();
      *(int *)(unaff_EDI + 0x88) = iVar4;
    }
    FUN_0040f060();
    uStack_54 = 0x5d20f6;
    (**(code **)(**(int **)(unaff_EDI + 0xb4) + 0x94))();
    uStack_54 = 0x5d20fc;
    FUN_005d1ad0();
    FUN_005d2210();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_40);
  return;
}

