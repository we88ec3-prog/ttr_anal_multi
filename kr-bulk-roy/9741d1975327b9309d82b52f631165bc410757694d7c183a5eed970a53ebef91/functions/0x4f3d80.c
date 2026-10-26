
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004f3d80(void)

{
  int iVar1;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009275a2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00fb7470;
  DAT_00fb7478 = 0;
  DAT_00fb7474 = FUN_008404d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fb7474 = DAT_00fb7474;
  *(int *)(DAT_00fb7474 + 4) = DAT_00fb7474;
  *(int *)(DAT_00fb7474 + 8) = DAT_00fb7474;
  *(undefined1 *)(DAT_00fb7474 + 0x74) = 1;
  *(undefined1 *)(DAT_00fb7474 + 0x75) = 1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  _DAT_00fb7488 = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fb7484 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb7484 + 4) = DAT_00fb7484;
    *(int *)(DAT_00fb7484 + 8) = DAT_00fb7484;
    *(undefined1 *)(DAT_00fb7484 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fb7484 + 0x2d) = 1;
    local_8._0_1_ = 1;
    _DAT_00fb7498 = 0;
    iVar1 = FUN_00891268(0x30);
    if (iVar1 != 0) {
      DAT_00fb7494 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb7494 + 4) = DAT_00fb7494;
      *(int *)(DAT_00fb7494 + 8) = DAT_00fb7494;
      *(undefined1 *)(DAT_00fb7494 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb7494 + 0x2d) = 1;
      local_8._0_1_ = 2;
      _DAT_00fb74a8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) {
LAB_004f42f9:
        local_18 = (char *)0x0;
        std::exception::exception((exception *)local_34,&local_18);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      DAT_00fb74a4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb74a4 + 4) = DAT_00fb74a4;
      *(int *)(DAT_00fb74a4 + 8) = DAT_00fb74a4;
      *(undefined1 *)(DAT_00fb74a4 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb74a4 + 0x2d) = 1;
      local_8._0_1_ = 3;
      _DAT_00fb74b8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) {
LAB_004f42d5:
        local_14 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_14);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      DAT_00fb74b4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb74b4 + 4) = DAT_00fb74b4;
      *(int *)(DAT_00fb74b4 + 8) = DAT_00fb74b4;
      *(undefined1 *)(DAT_00fb74b4 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb74b4 + 0x2d) = 1;
      local_8._0_1_ = 4;
      _DAT_00fb74c8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) {
LAB_004f4365:
        local_18 = (char *)0x0;
        std::exception::exception((exception *)local_34,&local_18);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      DAT_00fb74c4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb74c4 + 4) = DAT_00fb74c4;
      *(int *)(DAT_00fb74c4 + 8) = DAT_00fb74c4;
      *(undefined1 *)(DAT_00fb74c4 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb74c4 + 0x2d) = 1;
      local_8._0_1_ = 5;
      _DAT_00fb74d8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) {
LAB_004f4341:
        local_14 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_14);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      DAT_00fb74d4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb74d4 + 4) = DAT_00fb74d4;
      *(int *)(DAT_00fb74d4 + 8) = DAT_00fb74d4;
      *(undefined1 *)(DAT_00fb74d4 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb74d4 + 0x2d) = 1;
      local_8._0_1_ = 6;
      _DAT_00fb74e8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) goto LAB_004f431d;
      DAT_00fb74e4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fb74e4 + 4) = DAT_00fb74e4;
      *(int *)(DAT_00fb74e4 + 8) = DAT_00fb74e4;
      *(undefined1 *)(DAT_00fb74e4 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fb74e4 + 0x2d) = 1;
      local_8._0_1_ = 7;
      _DAT_00fb74f8 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 != 0) {
        DAT_00fb74f4 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb74f4 + 4) = DAT_00fb74f4;
        *(int *)(DAT_00fb74f4 + 8) = DAT_00fb74f4;
        *(undefined1 *)(DAT_00fb74f4 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fb74f4 + 0x2d) = 1;
        local_8._0_1_ = 8;
        _DAT_00fb7508 = 0;
        iVar1 = FUN_00891268(0x30);
        if (iVar1 == 0) goto LAB_004f42f9;
        DAT_00fb7504 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb7504 + 4) = DAT_00fb7504;
        *(int *)(DAT_00fb7504 + 8) = DAT_00fb7504;
        *(undefined1 *)(DAT_00fb7504 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fb7504 + 0x2d) = 1;
        local_8._0_1_ = 9;
        _DAT_00fb7518 = 0;
        iVar1 = FUN_00891268(0x30);
        if (iVar1 == 0) goto LAB_004f42d5;
        DAT_00fb7514 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb7514 + 4) = DAT_00fb7514;
        *(int *)(DAT_00fb7514 + 8) = DAT_00fb7514;
        *(undefined1 *)(DAT_00fb7514 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fb7514 + 0x2d) = 1;
        local_8._0_1_ = 10;
        _DAT_00fb7528 = 0;
        iVar1 = FUN_00891268(0x30);
        if (iVar1 == 0) goto LAB_004f4365;
        DAT_00fb7524 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb7524 + 4) = DAT_00fb7524;
        *(int *)(DAT_00fb7524 + 8) = DAT_00fb7524;
        *(undefined1 *)(DAT_00fb7524 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fb7524 + 0x2d) = 1;
        local_8._0_1_ = 0xb;
        _DAT_00fb7538 = 0;
        iVar1 = FUN_00891268(0x30);
        if (iVar1 == 0) goto LAB_004f4341;
        DAT_00fb7534 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb7534 + 4) = DAT_00fb7534;
        *(int *)(DAT_00fb7534 + 8) = DAT_00fb7534;
        *(undefined1 *)(DAT_00fb7534 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fb7534 + 0x2d) = 1;
        local_8._0_1_ = 0xc;
        _DAT_00fb7548 = 0;
        iVar1 = FUN_00891268(0x48);
        if (iVar1 == 0) goto LAB_004f431d;
        DAT_00fb7544 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fb7544 + 4) = DAT_00fb7544;
        *(int *)(DAT_00fb7544 + 8) = DAT_00fb7544;
        *(undefined1 *)(DAT_00fb7544 + 0x44) = 1;
        *(undefined1 *)(DAT_00fb7544 + 0x45) = 1;
        local_8._0_1_ = 0xd;
        _DAT_00fb7558 = 0;
        iVar1 = FUN_00891268(0x48);
        if (iVar1 != 0) {
          DAT_00fb7554 = iVar1;
          *(int *)iVar1 = iVar1;
          *(int *)(DAT_00fb7554 + 4) = DAT_00fb7554;
          *(int *)(DAT_00fb7554 + 8) = DAT_00fb7554;
          *(undefined1 *)(DAT_00fb7554 + 0x44) = 1;
          *(undefined1 *)(DAT_00fb7554 + 0x45) = 1;
          local_8._0_1_ = 0xe;
          _DAT_00fb7568 = 0;
          iVar1 = FUN_00891268(0x48);
          if (iVar1 == 0) goto LAB_004f42f9;
          DAT_00fb7564 = iVar1;
          *(int *)iVar1 = iVar1;
          *(int *)(DAT_00fb7564 + 4) = DAT_00fb7564;
          *(int *)(DAT_00fb7564 + 8) = DAT_00fb7564;
          *(undefined1 *)(DAT_00fb7564 + 0x44) = 1;
          *(undefined1 *)(DAT_00fb7564 + 0x45) = 1;
          local_8._0_1_ = 0xf;
          _DAT_00fb7578 = 0;
          iVar1 = FUN_00891268(0x18);
          if (iVar1 == 0) goto LAB_004f42d5;
          DAT_00fb7574 = iVar1;
          *(int *)iVar1 = iVar1;
          *(int *)(DAT_00fb7574 + 4) = DAT_00fb7574;
          *(int *)(DAT_00fb7574 + 8) = DAT_00fb7574;
          *(undefined1 *)(DAT_00fb7574 + 0x14) = 1;
          *(undefined1 *)(DAT_00fb7574 + 0x15) = 1;
          DAT_00fb7580 = 0;
          _DAT_00fb7584 = 0;
          _DAT_00fb7588 = 0;
          local_8._0_1_ = 0x11;
          _DAT_00fb7598 = 0;
          iVar1 = FUN_00891268(0x18);
          if (iVar1 != 0) {
            DAT_00fb7594 = iVar1;
            *(int *)iVar1 = iVar1;
            *(int *)(DAT_00fb7594 + 4) = DAT_00fb7594;
            *(int *)(DAT_00fb7594 + 8) = DAT_00fb7594;
            *(undefined1 *)(DAT_00fb7594 + 0x14) = 1;
            *(undefined1 *)(DAT_00fb7594 + 0x15) = 1;
            DAT_00fb75a0 = 0;
            _DAT_00fb75a4 = 0;
            _DAT_00fb75a8 = 0;
            local_8 = CONCAT31(local_8._1_3_,0x13);
            FUN_004f4960();
            ExceptionList = local_10;
            return &DAT_00fb7470;
          }
        }
      }
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
LAB_004f431d:
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_18);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

