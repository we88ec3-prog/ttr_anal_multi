
void FUN_0073b4c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *in_ECX;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 *puStack_64;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
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
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_58;
  local_58 = param_1;
  local_54 = param_2;
  local_18 = 0;
  puStack_64 = &local_58;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  puStack_7c = &local_50;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  local_14 = 0x3f800000;
  local_28 = 0x3f800000;
  local_3c = 0x3f800000;
  local_50 = 0x3f800000;
  local_68 = 0;
  uStack_6c = 0;
  uStack_70 = param_4;
  local_74 = 0;
  uStack_78 = 0;
  uStack_80 = 0x73b54c;
  D3DXMatrixTransformation2D();
  uStack_80 = param_5;
  uStack_84 = 0;
  uStack_88 = 0;
  (**(code **)(*in_ECX + 0x40))(&uStack_6c,param_3);
  __security_check_cookie(local_3c ^ (uint)&uStack_88);
  return;
}

