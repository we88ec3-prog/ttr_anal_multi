
void FUN_007fe540(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_1c;
  
  _memset(local_3c,0,0x34);
  local_1c = 0x3f800000;
  local_2c = 0x3f800000;
  local_3c[0] = 0x3f800000;
  FUN_00790dc0(*param_1);
  FUN_00790e90(param_1[1]);
  FUN_00790f60(param_1[2]);
  FUN_00780890();
  FUN_0077efc0();
  FUN_0077efc0();
  *(undefined4 *)(in_ECX + 0x78) = 1;
  *(undefined4 *)(in_ECX + 0x44) = 1;
  *(undefined4 *)(in_ECX + 0x8c) = 1;
  return;
}

