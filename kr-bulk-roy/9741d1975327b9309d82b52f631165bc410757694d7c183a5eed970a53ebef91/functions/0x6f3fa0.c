
void FUN_006f3fa0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(**(int **)(in_ECX + 4) + 100))(*(int **)(in_ECX + 4));
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))(*(int **)(in_ECX + 4),0x14,&local_1c);
  if (iVar1 < 0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(*(int **)(in_ECX + 4));
    iVar1 = 100;
    while ((iVar2 == -0x7ff8ffe2 && (iVar1 = iVar1 + -1, iVar1 != 0))) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(*(int **)(in_ECX + 4));
    }
    if (-1 < iVar2) {
      (**(code **)(**(int **)(in_ECX + 4) + 100))(*(int **)(in_ECX + 4));
      iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))(*(int **)(in_ECX + 4),0x14,&local_1c);
      if (-1 < iVar1) goto LAB_006f403e;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_006f403e:
  *(undefined4 *)(in_ECX + 8) = local_1c;
  *(undefined4 *)(in_ECX + 0xc) = local_18;
  *(undefined4 *)(in_ECX + 0x10) = local_14;
  *(undefined4 *)(in_ECX + 0x14) = local_10;
  *(undefined4 *)(in_ECX + 0x18) = local_c;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

