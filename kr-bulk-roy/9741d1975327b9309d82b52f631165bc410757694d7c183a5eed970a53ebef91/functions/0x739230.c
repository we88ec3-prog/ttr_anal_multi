
void FUN_00739230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  int *unaff_ESI;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  SetRect(&local_18,-1,-1,-1,-1);
  (**(code **)(*unaff_ESI + 0xc))
            (param_1,param_2,param_3,0x3f800000,0x3f800000,param_4,local_18.left,local_18.top,
             local_18.right,local_18.bottom,param_5,param_6,param_7,param_8,param_9,param_10);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

