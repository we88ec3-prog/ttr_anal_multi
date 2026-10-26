
void FUN_007ef500(void)

{
  int in_ECX;
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_1c;
  
  FUN_0077f030(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc)
              );
  _memset(local_3c,0,0x34);
  local_1c = 0x3f800000;
  local_2c = 0x3f800000;
  local_3c[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(in_ECX + 0x10));
  FUN_00790e90(*(undefined4 *)(in_ECX + 0x14));
  FUN_00790f60(*(undefined4 *)(in_ECX + 0x18));
  FUN_00780890();
  FUN_0077efc0();
  FUN_0077ef50(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
               *(undefined4 *)(in_ECX + 0x24));
  return;
}

