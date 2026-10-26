
void FUN_00739180(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int *unaff_ESI;
  tagRECT local_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  SetRect(&local_1c,-1,-1,-1,-1);
  (**(code **)(*unaff_ESI + 0xc))
            (param_1,param_2,param_3,0x3f800000,0x3f800000,0,local_1c.left,local_1c.top,
             local_1c.right,local_1c.bottom,param_4,param_5,param_6,param_7,param_8,param_9);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

