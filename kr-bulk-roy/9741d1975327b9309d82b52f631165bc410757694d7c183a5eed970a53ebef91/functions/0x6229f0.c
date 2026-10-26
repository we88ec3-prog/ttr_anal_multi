
void FUN_006229f0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_EDX;
  int unaff_EDI;
  uint uVar5;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d6a0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(in_EDX + 8);
  if (iVar1 == *(int *)(*(int *)(unaff_EDI + 0xec) + 0x20)) {
    uVar5 = uVar2;
    FUN_00622fa0(unaff_EDI);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 2;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 3;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    FUN_008fed10();
    uVar3 = FUN_0040ef80();
    local_8 = 4;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    piVar4 = *(int **)(unaff_EDI + 0xf0);
  }
  else {
    if (iVar1 == *(int *)(*(int *)(unaff_EDI + 0xf8) + 0x20)) {
      FUN_00622fa0(unaff_EDI);
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8 = 5;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8 = 0xffffffff;
      }
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8 = 6;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8 = 0xffffffff;
      }
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8 = 7;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8 = 0xffffffff;
      }
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8 = 8;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8 = 0xffffffff;
      }
      FUN_008fed10();
      uVar3 = FUN_0040ef80();
      local_8 = 9;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      (**(code **)(**(int **)(unaff_EDI + 0x10c) + 200))();
      goto LAB_00622f83;
    }
    if (iVar1 == *(int *)(*(int *)(unaff_EDI + 0xfc) + 0x20)) {
      FUN_00622fa0(unaff_EDI);
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_008fed10();
      uVar3 = FUN_0040ef80();
      local_8 = 10;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      (**(code **)(**(int **)(unaff_EDI + 0x110) + 200))();
      goto LAB_00622f83;
    }
    if (iVar1 == *(int *)(*(int *)(unaff_EDI + 0x100) + 0x20)) {
      FUN_00622fa0(unaff_EDI);
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_008fed10();
      uVar3 = FUN_0040ef80();
      local_8 = 0xb;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      FUN_004fa440();
      piVar4 = *(int **)(unaff_EDI + 0x114);
    }
    else if (iVar1 == *(int *)(*(int *)(unaff_EDI + 0x104) + 0x20)) {
      FUN_00622fa0(unaff_EDI);
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_008fed10();
      uVar3 = FUN_0040ef80();
      local_8 = 0xc;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      FUN_004fa440();
      piVar4 = *(int **)(unaff_EDI + 0x118);
    }
    else {
      if (iVar1 != *(int *)(*(int *)(unaff_EDI + 0x108) + 0x20)) goto LAB_00622f83;
      FUN_00622fa0(unaff_EDI);
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_00444ad0();
      FUN_008fed10();
      uVar3 = FUN_0040ef80();
      local_8 = 0xd;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      FUN_004fa440();
      piVar4 = *(int **)(unaff_EDI + 0x11c);
    }
  }
  (**(code **)(*piVar4 + 200))();
LAB_00622f83:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

