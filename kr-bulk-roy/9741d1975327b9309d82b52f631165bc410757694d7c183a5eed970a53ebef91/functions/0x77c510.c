
void FUN_0077c510(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_28;
  local_24 = param_3;
  local_20 = CONCAT31(local_20._1_3_,param_2);
  if ((((in_ECX[2] != 0) && (0.0 < (float)in_ECX[0x11])) && (0 < in_ECX[0xe])) && (0 < in_ECX[0xf]))
  {
    uVar1 = (**(code **)(*in_ECX + 0x2c))(local_1c,param_3,local_20,param_4,param_5,param_6);
    FUN_007521a0(uVar1,param_4,param_5,param_6);
  }
  __security_check_cookie(local_c ^ (uint)auStack_28);
  return;
}

