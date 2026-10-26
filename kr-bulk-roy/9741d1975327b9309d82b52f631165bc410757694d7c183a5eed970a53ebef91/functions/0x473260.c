
void FUN_00473260(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e238;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)(in_ECX + 0x250);
  (**(code **)(**(int **)(in_ECX + 0x24c) + 0x19c))
            (*puVar1,*(char *)((int)puVar1 + 6) + *(char *)(puVar1 + 1) + -1,2,uVar2);
  (**(code **)(**(int **)(in_ECX + 0x24c) + 200))();
  if (*(char *)(*(int *)(in_ECX + 0x250) + 6) == '\0') {
    *(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x154) = 0xffffffff;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x154) = 0xff5aff78;
  }
  FUN_00473ba0();
  local_8 = 0;
  FUN_00757710();
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  (**(code **)(**(int **)(in_ECX + 0x248) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

