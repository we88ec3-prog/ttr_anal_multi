
int FUN_00783970(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907b98;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_ESI + 0x54) == 0) {
    iVar3 = FUN_008808cb();
    if (iVar3 != 0) {
      *(undefined1 *)(unaff_ESI + 0x50) = 1;
      *(undefined1 *)(unaff_ESI + 0x49) = 0;
      FUN_00730d00(uVar2);
      uVar4 = DAT_00fe31e4;
      *(int *)(unaff_ESI + 0x10) = iVar3 + 8;
      *(int *)(unaff_ESI + 0x14) = iVar3 + 8;
      *(int *)(unaff_ESI + 0x20) = iVar3;
      *(int *)(unaff_ESI + 0x24) = iVar3;
      *(int *)(unaff_ESI + 0x54) = iVar3;
      *(int *)(unaff_ESI + 0x30) = iVar3 + 4;
      *(int *)(unaff_ESI + 0x34) = iVar3 + 4;
      *(undefined4 *)(unaff_ESI + 0x4c) = uVar4;
      *(undefined4 *)(unaff_ESI + 0x44) = 0;
      uVar4 = FUN_007838b0();
      local_8 = 0;
      piVar5 = (int *)FUN_007841f0(uVar4);
      cVar1 = (**(code **)(*piVar5 + 4))();
      if (cVar1 != '\0') {
        *(undefined4 *)(unaff_ESI + 0x44) = 0;
        FUN_004327c0();
        ExceptionList = local_10;
        return unaff_ESI;
      }
      *(int **)(unaff_ESI + 0x44) = piVar5;
      FUN_00730d00();
      FUN_004327c0();
      ExceptionList = local_10;
      return unaff_ESI;
    }
  }
  ExceptionList = local_10;
  return 0;
}

