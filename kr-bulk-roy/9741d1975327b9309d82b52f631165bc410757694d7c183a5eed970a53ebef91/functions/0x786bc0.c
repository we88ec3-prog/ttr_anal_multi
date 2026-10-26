
undefined4 FUN_00786bc0(int param_1)

{
  int in_ECX;
  int iVar1;
  int local_c [2];
  
  if (in_ECX + 8 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 8,0xc,0);
  }
  local_c[0] = (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x18;
  iVar1 = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_c,4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 0x18) != 0) && (iVar1 * 0x18 != 0)) {
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),*(int *)(in_ECX + 0x18),iVar1 * 0x18,0);
    }
  }
  return 1;
}

