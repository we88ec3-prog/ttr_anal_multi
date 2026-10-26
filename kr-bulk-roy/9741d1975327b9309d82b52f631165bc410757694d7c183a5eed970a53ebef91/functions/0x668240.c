
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00668240(int param_1)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  undefined2 local_84 [8];
  undefined4 local_74;
  undefined2 *local_70;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined ***pppuStack_4c;
  char *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d2d0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    pppuStack_4c = (undefined ***)0x668291;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar8 = (uint)(*(int *)(*(int *)(param_1 + 0x118) + 0x25c) != 0);
  if (*(int *)(*(int *)(param_1 + 0x11c) + 0x25c) != 0) {
    uVar8 = uVar8 + 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x120) + 0x25c) != 0) {
    uVar8 = uVar8 + 1;
  }
  iVar6 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iVar7 = *(int *)(DAT_00f94300 + 0x2398);
    iVar6 = 0;
    if (0 < iVar7) {
      piVar3 = (int *)(DAT_00f94300 + 0x1720);
      do {
        if ((piVar3[1] == 0) && (*piVar3 == 0)) {
          iVar6 = iVar6 + 1;
        }
        piVar3 = piVar3 + 8;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  if ((int)uVar8 <= iVar6) {
    if ((DAT_00fe18a0 & 1) == 0) {
      DAT_00fe18a0 = DAT_00fe18a0 | 1;
      local_c = 1;
      DAT_00fe18a4 = (undefined4 *)0x0;
      pppuStack_4c = (undefined ***)0x668335;
      puVar4 = (undefined4 *)FUN_00891268();
      if (puVar4 == (undefined4 *)0x0) {
        local_30 = (char *)0x0;
        pppuStack_4c = (undefined ***)0x6683dc;
        std::exception::exception((exception *)local_24,&local_30);
        pppuStack_4c = local_24;
        local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        uStack_50 = 0x6683f3;
        __CxxThrowException_8();
      }
      DAT_00fe18a4 = puVar4;
      puVar4[1] = 0;
      *puVar4 = 0;
      *DAT_00fe18a4 = &DAT_00fe18a4;
      _DAT_00fe18a8 = 0;
      _DAT_00fe18ac = 0;
      _DAT_00fe18b0 = 0;
      _DAT_00fe18b4 = 0;
      _DAT_00fe18bc = 1;
      DAT_00fe18be = 0;
      _DAT_00fe18c0 = 0;
      pppuStack_4c = (undefined ***)0x668391;
      _atexit((_func_4879 *)&LAB_00bce8c0);
    }
    local_c = 0xffffffff;
    DAT_00fe18be = 1;
    pppuStack_4c = (undefined ***)0x6683b5;
    _DAT_00fe18c0 = uVar8;
    _DAT_00fe18c4 = uVar8;
    FUN_00667200();
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 2;
    FUN_00587480();
    pppuStack_4c = (undefined ***)0x66841a;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  pppuStack_4c = (undefined ***)0x0;
  local_28 = (undefined1 *)local_68;
  local_54 = 7;
  local_58 = 0;
  local_70 = &DAT_00bed1fc;
  local_68[0] = 0;
  local_74 = 0x66844b;
  FUN_00402160();
  local_c = 3;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 4;
    local_c._1_3_ = 0;
    local_70 = (undefined2 *)0x668472;
    FUN_00584c40();
    local_70 = (undefined2 *)0x66847c;
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,3);
  }
  local_30 = (char *)0xd;
  local_70 = (undefined2 *)0x66849f;
  FUN_005740f0();
  if (local_2c != (undefined1 *)DAT_00fe5b10) {
    psVar9 = (short *)((int)local_2c + 0x10);
    if (7 < *(uint *)((int)local_2c + 0x24)) {
      psVar9 = *(short **)psVar9;
    }
    local_2c = (undefined1 *)local_84;
    local_70 = (undefined2 *)0x7;
    local_74 = 0;
    local_84[0] = 0;
    psVar5 = psVar9;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar9,(int)psVar5 - (int)(psVar9 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    *(undefined1 *)(param_1 + 0x130) = 0;
    ExceptionList = local_14;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

