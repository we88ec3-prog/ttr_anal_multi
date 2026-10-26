
void FUN_006d6590(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  wchar_t *in_ECX;
  undefined1 auStack_84 [4];
  int local_80;
  undefined4 local_7c;
  undefined2 local_78;
  wchar_t local_76 [47];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_84;
  if (*param_1 != 0) {
    iVar2 = FUN_00495610(DAT_00fb1318);
    if (iVar2 != 0) {
      local_78 = 0xe1;
      _memset(local_76,0,0x66);
      _wcscpy_s(local_76,0x33,in_ECX);
      (**(code **)(*DAT_00fba854 + 0x10))(1);
      __security_check_cookie(uStack_18 ^ (uint)&stack0xffffff70);
      return;
    }
    FUN_006ded00();
    local_7c = 0x181;
    iVar2 = FUN_005854b0();
    FUN_005740f0();
    if (local_80 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar3 = (undefined4 *)(local_80 + 0x10);
    if (7 < *(uint *)(local_80 + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_00404b10(0xca,puVar3,&DAT_00bed1fc);
  }
  __security_check_cookie(local_c ^ (uint)auStack_84);
  return;
}

