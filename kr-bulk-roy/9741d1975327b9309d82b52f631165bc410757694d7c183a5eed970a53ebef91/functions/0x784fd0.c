
/* WARNING: Removing unreachable block (ram,0x00785012) */

undefined4 FUN_00784fd0(int param_1)

{
  int in_ECX;
  undefined4 local_c [2];
  
  local_c[0] = *(undefined4 *)(in_ECX + 0x18);
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_c,4);
  if (in_ECX + 0x2c != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x2c,4,0);
  }
  if (in_ECX + 0x28 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x28,4,0);
  }
  return 1;
}

