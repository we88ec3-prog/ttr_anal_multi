
void FUN_007135b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 local_214;
  undefined1 local_213 [511];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ce3e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  for (piVar1 = (int *)(**(code **)(*param_1 + 0x14))(local_14); piVar1 != (int *)0x0;
      piVar1 = (int *)piVar1[2]) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 1) {
      uVar3 = (**(code **)(*piVar1 + 0x10))();
      iVar2 = FUN_00714d50(uVar3);
      piVar4 = (int *)(**(code **)(*piVar1 + 0x38))("AttachedPackage");
      if (piVar4 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar4 + 0x20))();
        uVar6 = -(uint)(iVar5 != 0) & (uint)piVar4;
        if (uVar6 != 0) {
          iVar5 = *(int *)(uVar6 + 0x118);
          local_214 = 0;
          _memset(local_213,0,0x1ff);
          FID_conflict__memcpy(&local_214,*(void **)(iVar5 + 0x48),*(size_t *)(iVar5 + 0x4c));
          iVar5 = FUN_00891268(0x178);
          puVar7 = (undefined4 *)0x0;
          local_8 = 0;
          if (iVar5 != 0) {
            puVar7 = (undefined4 *)FUN_00715270(iVar5);
          }
          local_8 = 0xffffffff;
          iVar5 = FUN_00715620(1);
          if (iVar5 == 0) {
            *(undefined4 **)(iVar2 + 0x100) = puVar7;
          }
          else {
            if (iVar5 != -1) {
              *param_4 = 1;
            }
            if (puVar7 != (undefined4 *)0x0) {
              (**(code **)*puVar7)(1);
            }
          }
        }
      }
      FUN_007135b0(piVar1,iVar2,param_3,param_4);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

