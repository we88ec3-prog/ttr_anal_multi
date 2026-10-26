
void FUN_005d80f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EDI;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e238;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x25c) == 0) {
    FUN_00757710(local_14);
  }
  else {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 0;
    FUN_00757800(*(undefined4 *)(unaff_EDI + 600));
    iVar1 = *(int *)(unaff_EDI + 0x298);
    iVar3 = *(int *)(iVar1 + 0xf8);
    puVar2 = (undefined4 *)(iVar1 + 0xe8);
    if (7 < *(uint *)(iVar1 + 0xfc)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    local_34 = iVar3;
    (**(code **)(**(int **)(iVar1 + 0x150) + 0x38))
              (&local_34,
               *(int *)(*(int *)(unaff_EDI + 0x298) + 0x10) -
               *(int *)(*(int *)(unaff_EDI + 0x298) + 8),puVar2,*(undefined4 *)(iVar1 + 0xf8));
    if (local_34 < iVar3) {
      iVar1 = local_34 + -3;
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          puVar2 = *(undefined4 **)(unaff_EDI + 600);
          if (7 < (uint)puVar2[5]) {
            puVar2 = (undefined4 *)*puVar2;
          }
          FUN_00440010(1,*(undefined2 *)((int)puVar2 + iVar3 * 2));
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      FUN_00404300(&DAT_00c22b44,3);
    }
    else {
      FUN_004026e0(*(int *)(unaff_EDI + 0x298) + 0xe8,0,0xffffffff);
    }
    FUN_00757800(local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

