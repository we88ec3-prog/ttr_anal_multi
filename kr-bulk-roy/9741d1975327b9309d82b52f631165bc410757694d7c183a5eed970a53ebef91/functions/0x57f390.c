
void FUN_0057f390(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  bool bVar7;
  int iStack_fc;
  int local_f8;
  int local_f4;
  uint local_f0;
  uint auStack_ec [24];
  uint local_8c;
  undefined4 local_7c;
  uint local_78 [2];
  wchar_t local_70 [32];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00921a6e;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)&iStack_fc);
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffef8;
  ExceptionList = &local_14;
  local_f4 = param_1;
  local_f0 = 0;
  local_f8 = FUN_00891268(0xa0,uVar1);
  local_c = 0;
  bVar7 = local_f8 == 0;
  if (bVar7) {
    uVar2 = 0;
  }
  else {
    local_8c = local_8c & 0xffff0000;
    local_78[0] = 7;
    local_7c = 0;
    FUN_00402160(L"NoKey",5);
    local_c = CONCAT31(local_c._1_3_,1);
    local_f0 = 1;
    uVar2 = FUN_0073a110(0x400,1,2);
  }
  bVar7 = !bVar7;
  uVar4 = (uint)bVar7;
  *(undefined4 *)(local_f4 + 8) = uVar2;
  local_c = 0xffffffff;
  if ((bVar7) && (uVar4 = 0, 7 < local_78[0])) {
    FUN_0089120c(local_8c);
  }
  local_f8 = FUN_00891268(0xa0,uVar1);
  local_c = 3;
  if (local_f8 == 0) {
    uVar2 = 0;
  }
  else {
    local_8c = local_8c & 0xffff0000;
    local_78[0] = 7;
    local_7c = 0;
    FUN_00402160(L"NoKey",5);
    local_c = CONCAT31(local_c._1_3_,4);
    uVar4 = uVar4 | 2;
    local_f0 = uVar4;
    uVar2 = FUN_0073a110(0x400,1,2);
  }
  *(undefined4 *)(local_f4 + 0xc) = uVar2;
  local_c = 0xffffffff;
  if ((uVar4 & 2) != 0) {
    if (7 < local_78[0]) {
      FUN_0089120c(local_8c);
    }
    local_78[0] = 7;
    local_7c = 0;
    local_8c = local_8c & 0xffff0000;
  }
  local_30 = 0;
  _memset(local_70,0,0x40);
  local_2c = 0x2a;
  local_28 = 7;
  local_24 = 1;
  _wcscpy_s(local_70,0x20,(wchar_t *)PTR_DAT_00d6a23c);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 6;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = 0xffffffff;
  }
  (**(code **)(*DAT_00fb7b78 + 0x28))(&local_f8,local_70);
  puVar5 = local_78;
  puVar6 = auStack_ec;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar2 = FUN_00736800();
  FUN_00736560(&DAT_00fb7b7c,uVar2);
  *(undefined4 *)(iStack_fc + 0x18) = unaff_EBX;
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffefc);
  return;
}

