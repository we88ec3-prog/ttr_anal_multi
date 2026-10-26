
void FUN_006fdba0(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_58;
  undefined1 local_54 [64];
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = 0;
  local_58 = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 **)(param_1 + 0x70) = &local_58;
  iVar1 = __setjmp3(local_54,0);
  if (iVar1 == 0) {
    (*param_2)(param_1,param_3);
    *(undefined4 *)(param_1 + 0x70) = local_58;
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(param_1 + 0x70) = local_58;
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

