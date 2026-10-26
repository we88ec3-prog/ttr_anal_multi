
int FUN_004dc850(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int unaff_EDI;
  undefined **local_30 [3];
  char *local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910763;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = 0;
  if (*(int *)(unaff_EDI + 0x48) - *(int *)(unaff_EDI + 0x44) >> 3 != 0) {
    do {
      iVar2 = *(int *)(unaff_EDI + 0x44);
      iVar1 = local_14 * 8;
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 0;
        DAT_00f8d9b4 = 0;
        iVar4 = FUN_00891268(0x18,uVar3);
        if (iVar4 == 0) {
          local_24 = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_24);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        DAT_00f8d9b0 = iVar4;
        *(int *)iVar4 = iVar4;
        *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
        *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
        *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      local_1c = *(undefined4 *)(iVar2 + iVar1 + 4);
      FUN_008438c0(&local_1c);
      if ((local_20 != DAT_00f8d9b0) && (*(int *)(local_20 + 0x10) != 0)) {
        local_18 = local_18 + *(int *)(*(int *)(local_20 + 0x10) + 0x5c);
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(*(int *)(unaff_EDI + 0x48) - *(int *)(unaff_EDI + 0x44) >> 3));
  }
  ExceptionList = local_10;
  return local_18;
}

