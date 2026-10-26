
undefined4 FUN_007a7800(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int local_c;
  int local_8;
  
  FUN_0082ef00(&param_1);
  if (local_8 != *(int *)(in_EAX + 0x80)) {
    param_1 = *(undefined4 *)(local_8 + 0x10);
  }
  local_8 = *(int *)(in_EAX + 0x18);
  iVar1 = FUN_0047c290();
  FUN_00515790(&local_8);
  if ((local_c != *(int *)(iVar1 + 4)) &&
     (iVar1 = *(int *)(*(int *)(local_c + 0x10) + 0x54), iVar1 != 0)) {
    FUN_0082ef00(&param_1);
    if (local_c != *(int *)(iVar1 + 0xd8)) {
      return *(undefined4 *)(local_c + 0x10);
    }
  }
  return 0;
}

