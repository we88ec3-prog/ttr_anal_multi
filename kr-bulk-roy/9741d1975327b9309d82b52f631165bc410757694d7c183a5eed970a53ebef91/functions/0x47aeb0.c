
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0047aeb0(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b6da;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fc0f84;
  _DAT_00fc0f90 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fc0f8c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc0f8c + 4) = DAT_00fc0f8c;
  *(int *)(DAT_00fc0f8c + 8) = DAT_00fc0f8c;
  *(undefined1 *)(DAT_00fc0f8c + 0x14) = 1;
  *(undefined1 *)(DAT_00fc0f8c + 0x15) = 1;
  local_8 = 0;
  _DAT_00fc0fa0 = 0;
  iVar2 = FUN_00891268(0x14,uVar1);
  if (iVar2 != 0) {
    DAT_00fc0f9c = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0f9c + 4) = DAT_00fc0f9c;
    *(int *)(DAT_00fc0f9c + 8) = DAT_00fc0f9c;
    *(undefined1 *)(DAT_00fc0f9c + 0x10) = 1;
    *(undefined1 *)(DAT_00fc0f9c + 0x11) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fc0fb0 = 0;
    DAT_00fc0fac = FUN_00570a10();
    *(int *)DAT_00fc0fac = DAT_00fc0fac;
    *(int *)(DAT_00fc0fac + 4) = DAT_00fc0fac;
    *(int *)(DAT_00fc0fac + 8) = DAT_00fc0fac;
    *(undefined1 *)(DAT_00fc0fac + 0x40) = 1;
    *(undefined1 *)(DAT_00fc0fac + 0x41) = 1;
    DAT_00fc0fb8 = 0;
    _DAT_00fc0fbc = 0;
    ExceptionList = local_10;
    return &DAT_00fc0f84;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

