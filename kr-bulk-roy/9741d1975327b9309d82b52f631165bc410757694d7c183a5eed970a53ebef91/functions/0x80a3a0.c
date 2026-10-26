
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080a3a0(void)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined **local_54 [3];
  undefined **local_48 [3];
  char *local_3c;
  char *local_38;
  uint local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091440d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0;
  DAT_00fab028 = 0;
  DAT_00fab040 = 0xf;
  _DAT_00fab03c = 0;
  DAT_00fab02c = 0;
  local_8 = 0;
  _DAT_00fab058 = 0;
  local_14 = uVar1;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_38 = (char *)0x0;
    std::exception::exception((exception *)local_54,&local_38);
    local_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_54,&DAT_00c857a8);
  }
  DAT_00fab054 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab054 + 4) = DAT_00fab054;
  *(int *)(DAT_00fab054 + 8) = DAT_00fab054;
  *(undefined1 *)(DAT_00fab054 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fab054 + 0x2d) = 1;
  local_8._0_1_ = 1;
  _DAT_00fab068 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_3c = (char *)0x0;
    std::exception::exception((exception *)local_48,&local_3c);
    local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_48,&DAT_00c857a8);
  }
  DAT_00fab064 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab064 + 4) = DAT_00fab064;
  *(int *)(DAT_00fab064 + 8) = DAT_00fab064;
  *(undefined1 *)(DAT_00fab064 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fab064 + 0x2d) = 1;
  local_8._0_1_ = 2;
  _DAT_00fab078 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_38 = (char *)0x0;
    std::exception::exception((exception *)local_54,&local_38);
    local_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_54,&DAT_00c857a8);
  }
  DAT_00fab074 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab074 + 4) = DAT_00fab074;
  *(int *)(DAT_00fab074 + 8) = DAT_00fab074;
  *(undefined1 *)(DAT_00fab074 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fab074 + 0x2d) = 1;
  local_8._0_1_ = 3;
  _DAT_00fab080 = 0x3f000000;
  _DAT_00fab088 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    DAT_00fab084 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fab084 + 4) = DAT_00fab084;
    DAT_00fab090 = 0;
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fab09c,4000);
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fab0b4,4000);
    local_8._0_1_ = 6;
    _DAT_00fab0cc = 0;
    _DAT_00fab0d0 = 0;
    pcVar3 = (char *)FUN_00891268(0x78);
    local_8._0_1_ = 7;
    local_38 = pcVar3;
    if (pcVar3 == (char *)0x0) {
      DAT_00fab048 = (char *)0x0;
    }
    else {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      FUN_00402a70("Default",7);
      local_8 = CONCAT31(local_8._1_3_,8);
      local_34 = 1;
      _memset(pcVar3,0,0x5c);
      pcVar3[0x70] = '\x0f';
      pcVar3[0x71] = '\0';
      pcVar3[0x72] = '\0';
      pcVar3[0x73] = '\0';
      pcVar3[0x6c] = '\0';
      pcVar3[0x6d] = '\0';
      pcVar3[0x6e] = '\0';
      pcVar3[0x6f] = '\0';
      pcVar3[0x5c] = '\0';
      FUN_00403040(local_30,0,0xffffffff);
      DAT_00fab048 = pcVar3;
    }
    local_8 = 6;
    if (((local_34 & 1) != 0) && (local_34 = local_34 & 0xfffffffe, 0xf < local_1c)) {
      FUN_0089120c(local_30[0]);
    }
    pcVar3 = (char *)FUN_00891268(0x78);
    local_8._0_1_ = 10;
    local_38 = pcVar3;
    if (pcVar3 == (char *)0x0) {
      DAT_00fab04c = (char *)0x0;
    }
    else {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      FUN_00402a70("Dummy",5);
      local_8._0_1_ = 0xb;
      local_34 = local_34 | 2;
      _memset(pcVar3,0,0x5c);
      pcVar3[0x70] = '\x0f';
      pcVar3[0x71] = '\0';
      pcVar3[0x72] = '\0';
      pcVar3[0x73] = '\0';
      pcVar3[0x6c] = '\0';
      pcVar3[0x6d] = '\0';
      pcVar3[0x6e] = '\0';
      pcVar3[0x6f] = '\0';
      pcVar3[0x5c] = '\0';
      FUN_00403040(local_30,0,0xffffffff);
      DAT_00fab04c = pcVar3;
    }
    if (((local_34 & 2) != 0) && (0xf < local_1c)) {
      FUN_0089120c(local_30[0]);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_3c = (char *)0x0;
  std::exception::exception((exception *)local_48,&local_3c);
  local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_48,&DAT_00c857a8);
}

