
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_006d7840(undefined4 param_1)

{
  undefined4 in_ECX;
  int *in_EDX;
  undefined4 local_4ea4;
  int *local_4ea0;
  int *local_4e9c;
  undefined1 local_4e98 [4];
  undefined4 local_4e94;
  int local_4e90;
  undefined4 local_4e8c;
  int local_4e88;
  undefined4 local_4e84;
  undefined4 local_4e80;
  undefined4 local_4e78;
  int local_4e6c;
  undefined4 local_4e68;
  undefined4 local_4e64;
  undefined4 local_4e60;
  undefined4 local_4e5c;
  undefined4 local_4e48;
  int local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x6d784d;
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(*in_EDX + 0x30))();
  D3DXCreateTexture(in_ECX,local_14,local_10,1,0,0x14,1,&local_4ea0);
  (**(code **)(*local_4ea0 + 0x48))(local_4ea0,0,&local_4e9c);
  D3DXLoadSurfaceFromSurface(local_4e9c,0,0,in_EDX,0,0,0xffffffff,0);
  FUN_006d79b0(&local_4ea4,local_4e9c);
  (**(code **)(*local_4e9c + 8))(local_4e9c);
  (**(code **)(*local_4ea0 + 8))(local_4ea0);
  Ordinal_2(local_4e98);
  local_4e88 = (local_14 * 3 + 3U & 0xfffffffc) + local_14 * -3;
  local_4e90 = local_14;
  local_4e8c = local_10;
  local_4e94 = local_4ea4;
  local_4e84 = 3;
  local_4e80 = 2;
  local_4e78 = param_1;
  local_4e6c = local_14;
  local_4e68 = local_10;
  local_4e64 = 3;
  local_4e60 = 3;
  local_4e5c = 2;
  local_4e48 = 0x62;
  Ordinal_5(local_4e98,8);
  Ordinal_3(local_4e98);
  FUN_0089120c(local_4ea4);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

