
void FUN_005f7b30(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iVar4;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911bd8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(in_ECX[0x41] + in_ECX[0x46] * 4) + 0x19c))(local_14);
  (**(code **)(*(int *)in_ECX[0x3e] + 200))();
  iVar4 = 0;
  iVar2 = (**(code **)(*in_ECX + 0x1ac))();
  if (0 < iVar2) {
    do {
      piVar1 = *(int **)(in_ECX[0x41] + iVar4 * 4);
      local_34 = (**(code **)(*piVar1 + 0x1a4))();
      (**(code **)(*piVar1 + 0x1a0))();
      uVar3 = FUN_0040e460(&DAT_00bf2bf8);
      local_8 = 0;
      local_34 = iVar4;
      FUN_0082ef00(&local_34);
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_30 = local_30 & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      iVar4 = iVar4 + 1;
      iVar2 = (**(code **)(*in_ECX + 0x1ac))();
    } while (iVar4 < iVar2);
  }
  (**(code **)(**(int **)(in_ECX[0x3e] + 0xd8) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

