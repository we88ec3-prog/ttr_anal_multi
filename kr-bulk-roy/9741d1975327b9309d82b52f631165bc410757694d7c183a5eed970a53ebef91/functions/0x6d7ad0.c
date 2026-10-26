
void FUN_006d7ad0(wchar_t *param_1,int param_2,char param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 unaff_ESI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 local_d4 [8];
  undefined4 auStack_cc [21];
  undefined4 auStack_78 [2];
  wchar_t local_70 [32];
  undefined4 local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092173e;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)local_d4);
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff20;
  ExceptionList = &local_14;
  *(int *)(in_ECX + 4) = param_2;
  *(char *)(in_ECX + 8) = param_3;
  *(undefined4 *)(in_ECX + 0x10) = param_4;
  local_30 = 0;
  _memset(local_70,0,0x40);
  local_2c = -param_2;
  local_28 = (-(uint)(param_3 != '\0') & 3) + 4;
  local_24 = 1;
  _wcscpy_s(local_70,0x20,param_1);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 0;
    FUN_00734ef0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = 0xffffffff;
  }
  (**(code **)(*DAT_00fb7b78 + 0x28))(local_d4,local_70);
  puVar4 = auStack_78;
  puVar5 = auStack_cc;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar2 = FUN_00736800();
  FUN_00736560(&DAT_00fb7b7c,uVar2);
  *(undefined4 *)(in_ECX + 0xc) = unaff_ESI;
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xffffff24);
  return;
}

