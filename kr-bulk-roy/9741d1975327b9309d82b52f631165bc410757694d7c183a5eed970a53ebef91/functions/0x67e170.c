
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0067e170(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_24;
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0x578) {
    if (iVar1 == 0xf43a9) {
      local_18 = in_ECX[0x5c];
      local_14 = in_ECX[0x72];
      local_10 = in_ECX[0x88];
      local_24 = in_ECX[0x5d];
      local_20 = in_ECX[0x73];
      local_1c = in_ECX[0x89];
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      FUN_004a3c50(in_ECX[0x46],in_ECX[0x47],&local_24);
      __security_check_cookie(local_c ^ (uint)&local_24);
      return;
    }
    if (iVar1 == 0xf43aa) {
      FUN_0067e8d0();
      (**(code **)(*in_ECX + 0x16c))(1);
      __security_check_cookie(local_10 ^ (uint)&stack0xffffffd8);
      return;
    }
    goto LAB_0067e2e1;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == *(int *)(in_ECX[0x44] + 0x20)) {
    FUN_0067e530();
    __security_check_cookie(local_c ^ (uint)&local_24);
    return;
  }
  if (iVar1 == *(int *)(in_ECX[0x3e] + 0x20)) {
    FUN_0067e8d0();
    __security_check_cookie(local_c ^ (uint)&local_24);
    return;
  }
  if (iVar1 == *(int *)(in_ECX[0x40] + 0x20)) {
    FUN_0067f1f0(0);
    FUN_0067f1f0(1);
LAB_0067e2d8:
    uVar2 = 2;
  }
  else {
    if (iVar1 != *(int *)(in_ECX[0x41] + 0x20)) {
      if (iVar1 != *(int *)(in_ECX[0x42] + 0x20)) goto LAB_0067e2e1;
      goto LAB_0067e2d8;
    }
    uVar2 = 1;
  }
  FUN_0067f1f0(uVar2);
LAB_0067e2e1:
  __security_check_cookie(local_c ^ (uint)&local_24);
  return;
}

