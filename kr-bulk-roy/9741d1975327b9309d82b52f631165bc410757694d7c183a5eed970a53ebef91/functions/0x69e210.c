
void FUN_0069e210(int param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  undefined4 uVar3;
  int local_54;
  uint local_38;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932ad6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    FUN_008438c0();
    if (((local_54 != DAT_00f8d91c) && (*(int *)(local_54 + 0x10) != 0)) &&
       (iVar1 = *(int *)(*(int *)(local_54 + 0x10) + 0x54), iVar1 != 0)) {
      if ((*(int *)(iVar1 + 0x78) == 0) && (*(int *)(iVar1 + 0x60) != 0)) {
        FUN_004034e0();
        FUN_00523230();
      }
      if (*(int *)(iVar1 + 0x7c) == 0) {
        FUN_00585620();
        FUN_00585330();
        FUN_004068f0();
        local_8 = 1;
      }
      else {
        FUN_00585620();
        FUN_00585330();
        FUN_0040e460();
        local_8 = 2;
      }
      FUN_00757800();
      local_8 = 0xffffffff;
      FUN_004fa440();
      FUN_00585620();
      FUN_00585330();
      FUN_004068f0();
      local_8 = 3;
      FUN_00757800();
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c();
      }
      FUN_00425330();
      FUN_004f6a30();
      FUN_00757710();
      FUN_00412df0();
      uVar3 = 0x1a;
      local_8 = 4;
      FUN_00585620(0x1a);
      uVar3 = FUN_00585330(uVar3);
      local_8 = 0xffffffff;
      FUN_00424c80(uVar3);
      local_8 = 5;
      FUN_00757800();
      local_8 = 0xffffffff;
      if (7 < local_38) {
        FUN_0089120c();
      }
      (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x1ac))();
      FUN_0069df10();
      goto LAB_0069e537;
    }
  }
  (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x1ac))();
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
LAB_0069e537:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

