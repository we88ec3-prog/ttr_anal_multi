
void FUN_0078f270(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  int iVar2;
  undefined1 local_44 [60];
  int local_8;
  
  iVar1 = (in_EAX - in_ECX) / 0x3c;
  iVar2 = iVar1 / 2;
  if (0 < iVar2) {
    local_8 = in_ECX + iVar2 * 0x3c;
    do {
      local_8 = local_8 + -0x3c;
      iVar2 = iVar2 + -1;
      FUN_007866a0();
      FUN_00790010(iVar1,local_44,param_1);
    } while (0 < iVar2);
  }
  return;
}

