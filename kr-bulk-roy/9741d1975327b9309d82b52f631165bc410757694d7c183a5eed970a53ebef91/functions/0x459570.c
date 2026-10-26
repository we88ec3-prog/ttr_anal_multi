
void FUN_00459570(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  int local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_2c;
  void *pvStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093181c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_40;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_3c = param_1;
  FUN_008438c0();
  if ((local_40 == DAT_00f8d91c) || (iVar1 = *(int *)(local_40 + 0x10), iVar1 == 0)) {
    (**(code **)(*(int *)unaff_EDI[0x3c] + 0x19c))();
    FUN_00757710();
  }
  else {
    (**(code **)(*(int *)unaff_EDI[0x3c] + 0x19c))();
    FUN_004026e0(iVar1,0,0xffffffff);
    local_1c = 1;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_1c._0_1_ = 2;
      local_1c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_1c = CONCAT31(local_1c._1_3_,1);
    }
    FUN_005740f0(&stack0xffffffb0);
    if (uVar3 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar4 = (undefined4 *)(uVar3 + 0x10);
    if (7 < *(uint *)(uVar3 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    local_1c = 0xffffffff;
    FUN_00424c80(puVar4);
    local_1c = 3;
    FUN_00757800();
    local_1c = 0xffffffff;
    if (7 < uStack_34) {
      FUN_0089120c();
    }
    uStack_34 = 7;
    uStack_38 = 0;
  }
  (**(code **)(*(int *)unaff_EDI[0x3c] + 200))();
  (**(code **)(*(int *)unaff_EDI[0x3e] + 200))();
  (**(code **)(*unaff_EDI + 0xd0))();
  ExceptionList = pvStack_24;
  __security_check_cookie(uStack_2c ^ (uint)&stack0xffffffb0);
  return;
}

