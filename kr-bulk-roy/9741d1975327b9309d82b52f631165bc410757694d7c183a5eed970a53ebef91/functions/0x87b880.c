
void FUN_0087b880(uint param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((((param_4 != 0) && (param_2 != (int *)0x0)) &&
      (uVar2 = *(int *)(param_4 + 0x38) - *(int *)(param_4 + 0x34) >> 5, (int)param_1 < (int)uVar2))
     && ((param_1 < uVar2 && (iVar1 = param_1 * 0x20 + *(int *)(param_4 + 0x34), iVar1 != 0)))) {
    local_20 = *(undefined4 *)(iVar1 + 4);
    local_1c = *(undefined4 *)(iVar1 + 8);
    local_18 = *(undefined4 *)(iVar1 + 0xc);
    local_14 = *(undefined4 *)(iVar1 + 0x10);
    local_10 = *(undefined4 *)(iVar1 + 0x14);
    local_c = *(undefined4 *)(iVar1 + 0x18);
    (**(code **)(*param_2 + 0x50))(param_2,param_3,&local_20,0x18);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

