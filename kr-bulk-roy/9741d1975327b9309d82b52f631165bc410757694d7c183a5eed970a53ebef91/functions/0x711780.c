
void FUN_00711780(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_40 [52];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) == 0x11f) {
    uVar1 = FUN_006ffec0(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x10) = uVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
  }
  FUN_007116f0();
  FUN_0070ef60();
  FUN_00712880(local_40);
  *(undefined4 *)
   (*(int *)(**(int **)(in_ECX + 0x30) + 0x14) + -4 + (*(int **)(in_ECX + 0x30))[6] * 4) = param_1;
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

