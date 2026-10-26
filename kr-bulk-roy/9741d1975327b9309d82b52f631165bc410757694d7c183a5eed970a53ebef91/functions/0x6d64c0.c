
void FUN_006d64c0(int *param_1)

{
  int iVar1;
  undefined1 local_44 [44];
  undefined4 uStack_18;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)local_44;
  if ((*param_1 != 0) && (iVar1 = FUN_00495610(DAT_00fb1318), iVar1 != 0)) {
    FUN_006d6b70();
    iVar1 = FUN_00404ba0();
    uStack_18._0_3_ = CONCAT12(*(undefined1 *)(iVar1 + 0x6898),(undefined2)uStack_18);
    iVar1 = FUN_00404ba0();
    _strcpy_s((char *)((int)&uStack_18 + 3),5,(char *)(iVar1 + 0x6899));
    iVar1 = FUN_00404ba0();
    local_10 = *(undefined4 *)(iVar1 + 0x68a0);
    (**(code **)(*DAT_00fba854 + 0x10))(1);
    __security_check_cookie(uStack_18 ^ (uint)&stack0xffffffb0);
    return;
  }
  __security_check_cookie(local_c ^ (uint)local_44);
  return;
}

