
void FUN_0087b9e0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) &&
     (param_1 < (*(int *)(param_4 + 8) - *(int *)(param_4 + 4)) / 0x38)) {
    iVar1 = FUN_00849ef0();
    if (iVar1 != 0) {
      local_38 = *(undefined4 *)(iVar1 + 4);
      local_34 = *(undefined4 *)(iVar1 + 8);
      local_30 = *(undefined4 *)(iVar1 + 0xc);
      local_2c = *(undefined4 *)(iVar1 + 0x1c);
      local_28 = *(undefined4 *)(iVar1 + 0x20);
      local_24 = *(undefined4 *)(iVar1 + 0x24);
      local_20 = *(undefined4 *)(iVar1 + 0x10);
      local_1c = *(undefined4 *)(iVar1 + 0x14);
      local_18 = *(undefined4 *)(iVar1 + 0x18);
      local_14 = *(undefined4 *)(iVar1 + 0x2c);
      local_10 = *(undefined4 *)(iVar1 + 0x30);
      local_c = *(undefined4 *)(iVar1 + 0x28);
      (**(code **)(*param_2 + 0x50))(param_2,param_3,&local_38,0x30);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

