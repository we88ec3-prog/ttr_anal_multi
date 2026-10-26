
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * FUN_00822000(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined2 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925fda;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb936c;
  DAT_00fb936c = 0;
  _DAT_00fb9378 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fb9374 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb9374 + 4) = DAT_00fb9374;
    *(int *)(DAT_00fb9374 + 8) = DAT_00fb9374;
    *(undefined1 *)(DAT_00fb9374 + 0x14) = 1;
    *(undefined1 *)(DAT_00fb9374 + 0x15) = 1;
    local_8 = 0;
    _DAT_00fb9388 = 0;
    DAT_00fb9384 = FUN_00820120();
    *(int *)DAT_00fb9384 = DAT_00fb9384;
    *(int *)(DAT_00fb9384 + 4) = DAT_00fb9384;
    *(int *)(DAT_00fb9384 + 8) = DAT_00fb9384;
    *(undefined1 *)(DAT_00fb9384 + 0x18) = 1;
    *(undefined1 *)(DAT_00fb9384 + 0x19) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_008221b0();
    ExceptionList = local_10;
    return &DAT_00fb936c;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

