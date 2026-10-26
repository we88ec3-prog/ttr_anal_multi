
/* WARNING: Removing unreachable block (ram,0x005f6f19) */

void FUN_005f6cb0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *in_ECX;
  int iVar9;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e066;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = in_ECX + 0x41;
  uVar6 = (**(code **)(*in_ECX + 0x1ac))(uVar5);
  FUN_005f7e40(uVar6);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  iVar9 = *piVar2;
  FUN_005f7fb0();
  FUN_005a9f40(iVar9);
  iVar9 = *piVar2;
  FUN_005f8090();
  FUN_005a9f40(iVar9 + 4);
  iVar9 = *piVar2;
  FUN_005f8170();
  FUN_005a9f40(iVar9 + 8);
  iVar9 = *piVar2;
  FUN_005f8250();
  FUN_005a9f40(iVar9 + 0xc);
  iVar9 = *piVar2;
  FUN_005f8330();
  FUN_005a9f40(iVar9 + 0x10);
  iVar9 = *piVar2;
  FUN_005f8410();
  FUN_005a9f40(iVar9 + 0x14);
  FUN_0040b670(in_ECX);
  iVar9 = 0;
  iVar7 = (**(code **)(*in_ECX + 0x1ac))();
  if (0 < iVar7) {
    do {
      iVar7 = iVar9 + 1;
      FUN_005f5ca0(iVar7);
      piVar1 = *(int **)(*piVar2 + iVar9 * 4);
      (**(code **)(*piVar1 + 0x1a4))();
      (**(code **)(*piVar1 + 0x1a0))();
      uVar6 = FUN_0040e460(&DAT_00bf2bf8);
      local_8._0_1_ = 2;
      FUN_00757800(uVar6);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      if (*(int *)(in_ECX[0x3e] + 0xd8) != 0) {
        FUN_0040acb0(*(int *)(in_ECX[0x3e] + 0xd8),iVar9,*(undefined4 *)(*piVar2 + iVar9 * 4));
      }
      iVar8 = (**(code **)(*in_ECX + 0x1ac))();
      iVar9 = iVar7;
    } while (iVar7 < iVar8);
  }
  piVar2 = (int *)in_ECX[0x3e];
  puVar3 = (undefined4 *)piVar2[0x19];
  for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    iVar9 = puVar4[2];
    if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
    }
  }
  (**(code **)(*piVar2 + 0x128))();
  FUN_0040b5b0(0);
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8._0_1_ = 3;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  (**(code **)(*(int *)in_ECX[0x40] + 0x94))((DAT_00fab104 & 0x20) != 0 || DAT_00fab128 != '\0');
  ExceptionList = local_10;
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}

