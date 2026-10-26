
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00830e90(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined **local_44 [3];
  undefined **local_38 [3];
  undefined **local_2c [3];
  undefined4 *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009093c6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = &DAT_00fe30c8;
  pcVar2 = (char *)FUN_00891268(0x10,uVar1);
  local_8 = 0;
  local_1c = pcVar2;
  if (pcVar2 == (char *)0x0) {
    DAT_00fe30c8 = (char *)0x0;
  }
  else {
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    iVar3 = FUN_00891268(0x28,uVar1);
    if (iVar3 == 0) goto LAB_00830f0a;
    *(int *)(pcVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(pcVar2 + 4) + 4) = *(int *)(pcVar2 + 4);
    *(int *)(*(int *)(pcVar2 + 4) + 8) = *(int *)(pcVar2 + 4);
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x24) = 1;
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x25) = 1;
    DAT_00fe30c8 = pcVar2;
  }
  local_8 = 0xffffffff;
  pcVar2 = (char *)FUN_00891268(0x10,uVar1);
  local_8 = 1;
  local_1c = pcVar2;
  if (pcVar2 == (char *)0x0) {
    DAT_00fe30cc = (char *)0x0;
  }
  else {
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    iVar3 = FUN_00891268(0x54,uVar1);
    if (iVar3 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    *(int *)(pcVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(pcVar2 + 4) + 4) = *(int *)(pcVar2 + 4);
    *(int *)(*(int *)(pcVar2 + 4) + 8) = *(int *)(pcVar2 + 4);
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x50) = 1;
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x51) = 1;
    DAT_00fe30cc = pcVar2;
  }
  local_8 = 0xffffffff;
  pcVar2 = (char *)FUN_00891268(0x10,uVar1);
  local_8 = 2;
  local_1c = pcVar2;
  if (pcVar2 == (char *)0x0) {
    DAT_00fe30d0 = (char *)0x0;
  }
  else {
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    iVar3 = FUN_00891268(0x24);
    if (iVar3 == 0) goto LAB_00831000;
    *(int *)(pcVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(pcVar2 + 4) + 4) = *(int *)(pcVar2 + 4);
    *(int *)(*(int *)(pcVar2 + 4) + 8) = *(int *)(pcVar2 + 4);
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x20) = 1;
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x21) = 1;
    DAT_00fe30d0 = pcVar2;
  }
  local_8 = 0xffffffff;
  pcVar2 = (char *)FUN_00891268(0x10);
  local_8 = 3;
  local_1c = pcVar2;
  if (pcVar2 == (char *)0x0) {
    DAT_00fe30d4 = (char *)0x0;
  }
  else {
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    iVar3 = FUN_00891268(0x24);
    if (iVar3 == 0) {
LAB_00830f0a:
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    *(int *)(pcVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(pcVar2 + 4) + 4) = *(int *)(pcVar2 + 4);
    *(int *)(*(int *)(pcVar2 + 4) + 8) = *(int *)(pcVar2 + 4);
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x20) = 1;
    *(undefined1 *)(*(int *)(pcVar2 + 4) + 0x21) = 1;
    DAT_00fe30d4 = pcVar2;
  }
  local_8 = 0xffffffff;
  _DAT_00fe30e0 = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_44,&local_1c);
    local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_44,&DAT_00c857a8);
  }
  DAT_00fe30dc = iVar3;
  *(int *)iVar3 = iVar3;
  *(int *)(DAT_00fe30dc + 4) = DAT_00fe30dc;
  *(int *)(DAT_00fe30dc + 8) = DAT_00fe30dc;
  *(undefined1 *)(DAT_00fe30dc + 0x14) = 1;
  *(undefined1 *)(DAT_00fe30dc + 0x15) = 1;
  local_8 = 4;
  _DAT_00fe30f0 = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_38,&local_18);
    local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_38,&DAT_00c857a8);
  }
  DAT_00fe30ec = iVar3;
  *(int *)iVar3 = iVar3;
  *(int *)(DAT_00fe30ec + 4) = DAT_00fe30ec;
  *(int *)(DAT_00fe30ec + 8) = DAT_00fe30ec;
  *(undefined1 *)(DAT_00fe30ec + 0x14) = 1;
  *(undefined1 *)(DAT_00fe30ec + 0x15) = 1;
  local_8 = CONCAT31(local_8._1_3_,5);
  _DAT_00fe3100 = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 != 0) {
    DAT_00fe30fc = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(DAT_00fe30fc + 4) = DAT_00fe30fc;
    *(int *)(DAT_00fe30fc + 8) = DAT_00fe30fc;
    *(undefined1 *)(DAT_00fe30fc + 0x14) = 1;
    *(undefined1 *)(DAT_00fe30fc + 0x15) = 1;
    ExceptionList = local_10;
    return &DAT_00fe30c8;
  }
LAB_00831000:
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&local_14);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

