
void FUN_008e1a00(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2c = *(undefined4 *)(in_ECX + 0x2dd0);
  local_28 = *(undefined4 *)(in_ECX + 0x2dd4);
  local_c = 1;
  cVar1 = FUN_008e0f70();
  if (cVar1 == '\0') {
    FUN_008e3940();
  }
  FUN_008e1420(in_ECX + 8,param_1,param_2);
  (*(code *)**(undefined4 **)(in_ECX + 4))(*(undefined4 **)(in_ECX + 4),&local_2c);
  *(undefined4 *)(in_ECX + 0x2dd0) = local_24;
  *(undefined4 *)(in_ECX + 0x2dd4) = local_20;
  *(undefined4 *)(in_ECX + 0x2db8) = param_1;
  *(undefined4 *)(in_ECX + 0x2dbc) = param_2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

