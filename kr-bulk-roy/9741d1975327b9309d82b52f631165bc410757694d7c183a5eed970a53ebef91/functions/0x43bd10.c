
void FUN_0043bd10(int param_1)

{
  uint uVar1;
  int iVar2;
  byte *in_ECX;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931b88;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX != (byte *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x24c) + 0x19c))
              (0xffffffff,*(undefined4 *)(in_ECX + 4),0,0,uVar1);
    (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
    if (*in_ECX < 4) {
      (**(code **)(**(int **)(param_1 + 0x248) + 0x94))(1);
      iVar2 = *(int *)(param_1 + 0x248);
      if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
         (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
        FUN_0077b200();
      }
      (**(code **)(**(int **)(param_1 + 0x248) + 200))();
    }
    (**(code **)(**(int **)(param_1 + 0x250) + 0x94))
              (~(byte)((uint)*(undefined4 *)(*(int *)(param_1 + 0x248) + 0x28) >> 8) & 1);
    if ((*(uint *)(*(int *)(param_1 + 0x250) + 0x28) >> 8 & 1) != 0) {
      FUN_00757800(in_ECX + 0xc);
      (**(code **)(**(int **)(param_1 + 0x250) + 200))();
    }
    FUN_00426ec0();
    local_8 = 0;
    FUN_00757710();
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

