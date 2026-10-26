
void FUN_0069f540(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined4 ***pppuVar3;
  undefined4 uVar4;
  int local_70;
  undefined4 ***local_6c;
  undefined4 local_68;
  uint local_54;
  undefined4 ***local_4c [5];
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932a1e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
    *(uint *)(unaff_EDI + 0x28) = *(uint *)(unaff_EDI + 0x28) | 4;
  }
  else {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(local_14);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    local_6c = *(undefined4 ****)(param_1 + 0x18);
    FUN_008438c0(&local_6c);
    if (((local_70 != DAT_00f8d91c) && (iVar1 = *(int *)(local_70 + 0x10), iVar1 != 0)) &&
       (local_6c = *(undefined4 ****)(iVar1 + 0x54),
       (undefined4 ****)local_6c != (undefined4 ****)0x0)) {
      if (((undefined4 ***)local_6c[0x1e] == (undefined4 ***)0x0) &&
         (pppuVar3 = (undefined4 ***)local_6c[0x18], pppuVar3 != (undefined4 ***)0x0)) {
        FUN_004034e0(pppuVar3);
        FUN_00523230(pppuVar3);
      }
      local_6c = (undefined4 ***)local_6c[0x1f];
      if (local_6c == (undefined4 ***)0x0) {
        uVar4 = 0x154;
        FUN_00585620(0x154);
        FUN_00585330(uVar4);
        uVar4 = FUN_004068f0();
        local_8 = 1;
      }
      else {
        uVar4 = 0x152;
        FUN_00585620(0x152);
        uVar4 = FUN_00585330(uVar4);
        uVar4 = FUN_0040e460(uVar4);
        local_8 = 2;
      }
      FUN_00757800(uVar4);
      local_8 = 0xffffffff;
      FUN_004fa440();
      local_6c = (undefined4 ***)((uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0x1e))
      ;
      uVar4 = 0x35;
      FUN_00585620(0x35);
      FUN_00585330(uVar4);
      uVar4 = FUN_004068f0();
      local_8 = 3;
      FUN_00757800(uVar4);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      FUN_00425330(uVar4,uVar4);
      FUN_004f6a30(uVar4);
      FUN_00757710();
      puVar2 = (undefined4 *)FUN_00412df0();
      local_8 = 4;
      if (7 < (uint)puVar2[5]) {
        puVar2 = (undefined4 *)*puVar2;
      }
      FUN_00402250(puVar2);
      local_8._0_1_ = 6;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      if (local_38 < 8) {
        local_6c = local_4c;
      }
      else {
        local_6c = local_4c[0];
      }
      uVar4 = 0x1a;
      FUN_00585620(0x1a);
      FUN_00585330(uVar4);
      uVar4 = FUN_004ed610();
      local_8._0_1_ = 7;
      FUN_00757800(uVar4);
      local_8 = CONCAT31(local_8._1_3_,6);
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
      (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x1ac))
                (*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                 *(undefined1 *)(param_1 + 0x1c));
      FUN_0069f210(param_1,iVar1);
      if ((*(uint *)(unaff_EDI + 0x28) & 4) != 0) {
        *(uint *)(unaff_EDI + 0x28) = *(uint *)(unaff_EDI + 0x28) ^ 4;
      }
      if (7 < local_38) {
        FUN_0089120c(local_4c[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

