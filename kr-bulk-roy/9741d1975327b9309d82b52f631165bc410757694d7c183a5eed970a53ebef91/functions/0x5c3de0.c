
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_005c3de0(void)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_0091ad91;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00f94398;
  _DAT_00f94398 = FUI::CFXUITextureMgr::vftable;
  _DAT_00f943a4 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    DAT_00f943a0 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00f943a0 + 4) = DAT_00f943a0;
    *(int *)(DAT_00f943a0 + 8) = DAT_00f943a0;
    *(undefined1 *)(DAT_00f943a0 + 0x2c) = 1;
    *(undefined1 *)(DAT_00f943a0 + 0x2d) = 1;
    local_8 = 0;
    FUN_005c8010(&DAT_00f943b0);
    local_8._0_1_ = 1;
    DAT_00f943e0 = 0;
    DAT_00f943e4 = 0;
    DAT_00f943e8 = 0;
    DAT_00f943ec = 0;
    DAT_00f943f0 = 0;
    DAT_00f943f4 = 0;
    _DAT_00f943f8 = 0;
    _DAT_00f943fc = 0;
    _DAT_00f94400 = 0;
    _DAT_00f94404 = 0;
    _DAT_00f94408 = 0;
    _DAT_00f9440c = 0;
    _DAT_00f94410 = 0;
    _DAT_00f94414 = 0;
    _DAT_00f94418 = 0;
    _DAT_00f9441c = 0;
    _DAT_00f94420 = 0;
    _DAT_00f94424 = 0;
    _DAT_00f94428 = 0;
    _DAT_00f9442c = 0;
    _DAT_00f94430 = 0;
    _DAT_00f94434 = 0;
    _DAT_00f94438 = 0;
    _DAT_00f9443c = 0;
    _DAT_00f94440 = 0;
    _DAT_00f94444 = 0;
    _memset(&DAT_00f94448,0,0x68);
    _DAT_00f944b0 = 0;
    _DAT_00f944b4 = 0;
    _DAT_00f944b8 = 0;
    _DAT_00f944bc = 0;
    _eh_vector_constructor_iterator_(&DAT_00f944c0,0x18,4,FUN_00763ba0,FUN_00763c90);
    local_8._0_1_ = 2;
    DAT_00f94520 = 0;
    _DAT_00f94524 = 0;
    _DAT_00f94528 = 0;
    DAT_00f9452c = 0;
    DAT_00f94530 = 0;
    DAT_00f94534 = 0;
    _DAT_00f94538 = 0;
    _DAT_00f9453c = 0;
    DAT_00f94540 = 0;
    DAT_00f94544 = 0;
    _DAT_00f94548 = 0;
    _DAT_00f9454c = 0;
    _DAT_00f94550 = 0;
    _DAT_00f94554 = 0;
    DAT_00f94558 = 0;
    DAT_00f9455c = 0;
    _DAT_00f94560 = 0;
    _DAT_00f94564 = 0;
    DAT_00f94568 = 0;
    DAT_00f9456c = 0;
    _DAT_00f94578 = 0;
    iVar2 = FUN_00891268(0x18,uVar1);
    if (iVar2 != 0) {
      DAT_00f94574 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f94574 + 4) = DAT_00f94574;
      *(int *)(DAT_00f94574 + 8) = DAT_00f94574;
      *(undefined1 *)(DAT_00f94574 + 0x14) = 1;
      *(undefined1 *)(DAT_00f94574 + 0x15) = 1;
      local_8._0_1_ = 3;
      _DAT_00f94588 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 == 0) {
LAB_005c4361:
        local_18 = (char *)0x0;
        std::exception::exception((exception *)local_34,&local_18);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      DAT_00f94584 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f94584 + 4) = DAT_00f94584;
      *(int *)(DAT_00f94584 + 8) = DAT_00f94584;
      *(undefined1 *)(DAT_00f94584 + 0x14) = 1;
      *(undefined1 *)(DAT_00f94584 + 0x15) = 1;
      local_8._0_1_ = 4;
      _DAT_00f94598 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 == 0) {
LAB_005c433d:
        local_14 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_14);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      DAT_00f94594 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f94594 + 4) = DAT_00f94594;
      *(int *)(DAT_00f94594 + 8) = DAT_00f94594;
      *(undefined1 *)(DAT_00f94594 + 0x14) = 1;
      *(undefined1 *)(DAT_00f94594 + 0x15) = 1;
      local_8._0_1_ = 5;
      _DAT_00f945a8 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 == 0) {
        local_18 = (char *)0x0;
        std::exception::exception((exception *)local_34,&local_18);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      DAT_00f945a4 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f945a4 + 4) = DAT_00f945a4;
      *(int *)(DAT_00f945a4 + 8) = DAT_00f945a4;
      *(undefined1 *)(DAT_00f945a4 + 0x14) = 1;
      *(undefined1 *)(DAT_00f945a4 + 0x15) = 1;
      local_8._0_1_ = 6;
      _DAT_00f945b8 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 == 0) {
        local_14 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_14);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      DAT_00f945b4 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f945b4 + 4) = DAT_00f945b4;
      *(int *)(DAT_00f945b4 + 8) = DAT_00f945b4;
      *(undefined1 *)(DAT_00f945b4 + 0x14) = 1;
      *(undefined1 *)(DAT_00f945b4 + 0x15) = 1;
      local_8._0_1_ = 7;
      _DAT_00f945c8 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 == 0) goto LAB_005c4385;
      DAT_00f945c4 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00f945c4 + 4) = DAT_00f945c4;
      *(int *)(DAT_00f945c4 + 8) = DAT_00f945c4;
      *(undefined1 *)(DAT_00f945c4 + 0x14) = 1;
      *(undefined1 *)(DAT_00f945c4 + 0x15) = 1;
      local_8._0_1_ = 8;
      _DAT_00f945d8 = 0;
      iVar2 = FUN_00891268(0x18);
      if (iVar2 != 0) {
        DAT_00f945d4 = iVar2;
        *(int *)iVar2 = iVar2;
        *(int *)(DAT_00f945d4 + 4) = DAT_00f945d4;
        *(int *)(DAT_00f945d4 + 8) = DAT_00f945d4;
        *(undefined1 *)(DAT_00f945d4 + 0x14) = 1;
        *(undefined1 *)(DAT_00f945d4 + 0x15) = 1;
        local_8._0_1_ = 9;
        _DAT_00f945e8 = 0;
        iVar2 = FUN_00891268(0x18);
        if (iVar2 == 0) goto LAB_005c4361;
        DAT_00f945e4 = iVar2;
        *(int *)iVar2 = iVar2;
        *(int *)(DAT_00f945e4 + 4) = DAT_00f945e4;
        *(int *)(DAT_00f945e4 + 8) = DAT_00f945e4;
        *(undefined1 *)(DAT_00f945e4 + 0x14) = 1;
        *(undefined1 *)(DAT_00f945e4 + 0x15) = 1;
        local_8._0_1_ = 10;
        _DAT_00f945f8 = 0;
        iVar2 = FUN_00891268(0x18);
        if (iVar2 == 0) goto LAB_005c433d;
        DAT_00f945f4 = iVar2;
        *(int *)iVar2 = iVar2;
        *(int *)(DAT_00f945f4 + 4) = DAT_00f945f4;
        *(int *)(DAT_00f945f4 + 8) = DAT_00f945f4;
        *(undefined1 *)(DAT_00f945f4 + 0x14) = 1;
        *(undefined1 *)(DAT_00f945f4 + 0x15) = 1;
        local_8._0_1_ = 0xb;
        DAT_00f94600 = (char *)0x0;
        FUN_00763060(&DAT_00f94604,&DAT_00bed1fc);
        local_8._0_1_ = 0xc;
        FUN_00763060(&DAT_00f946a4,&DAT_00bed1fc);
        local_8._0_1_ = 0xd;
        FUN_00763060(&DAT_00f94744,&DAT_00bed1fc);
        DAT_00f947e4 = 0;
        DAT_00f947e8 = 0;
        _DAT_00f947ec = 0;
        _DAT_00f947f0 = 0;
        _DAT_00f947f4 = 0;
        local_8._0_1_ = 0xf;
        DAT_00f947fc = 0;
        _DAT_00f94808 = 0;
        iVar2 = FUN_00891268(0x18);
        if (iVar2 != 0) {
          DAT_00f94804 = iVar2;
          *(int *)iVar2 = iVar2;
          *(int *)(DAT_00f94804 + 4) = DAT_00f94804;
          *(int *)(DAT_00f94804 + 8) = DAT_00f94804;
          *(undefined1 *)(DAT_00f94804 + 0x14) = 1;
          *(undefined1 *)(DAT_00f94804 + 0x15) = 1;
          local_8._0_1_ = 0x10;
          local_18 = (char *)FUN_00891268(0x14);
          local_8._0_1_ = 0x11;
          if (local_18 == (char *)0x0) {
            DAT_00f943ac = 0;
          }
          else {
            DAT_00f943ac = FUN_007748b0(local_18);
          }
          pcVar3 = _malloc(0x1c);
          local_8 = CONCAT31(local_8._1_3_,0x12);
          pcVar4 = (char *)0x0;
          if (pcVar3 != (char *)0x0) {
            local_18 = pcVar3;
            FUN_00763ba0();
            pcVar3[0x18] = '\0';
            pcVar3[0x19] = '\0';
            pcVar3[0x1a] = '\0';
            pcVar3[0x1b] = '\0';
            *(undefined ***)pcVar3 = FUI::CFXUIImageSetGroupAutoDestory::vftable;
            pcVar4 = pcVar3;
          }
          DAT_00f94600 = pcVar4;
          ExceptionList = local_10;
          return &DAT_00f94398;
        }
      }
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
LAB_005c4385:
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_18);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

