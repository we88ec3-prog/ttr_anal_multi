
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00667ee0(void)

{
  short sVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  int *in_ECX;
  int *piVar7;
  short *psVar8;
  char local_84 [16];
  undefined4 local_74;
  undefined2 *local_70;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined *puStack_50;
  undefined ***pppuStack_4c;
  undefined **local_34 [3];
  undefined2 local_26;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  char *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009330e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar3 = false;
  iVar4 = 1;
  piVar7 = (int *)(in_ECX[0x45] + 0x80);
  do {
    if (*piVar7 != 0) {
      bVar3 = true;
      break;
    }
    iVar4 = iVar4 + 1;
    piVar7 = piVar7 + 6;
  } while (iVar4 < 4);
  if ((*(int *)(in_ECX[0x45] + 100) == 0) && (!bVar3)) {
    if ((DAT_00fe18a0 & 1) == 0) {
      DAT_00fe18a0 = DAT_00fe18a0 | 1;
      local_8 = 3;
      DAT_00fe18a4 = (undefined4 *)0x0;
      pppuStack_4c = (undefined ***)0x6680a4;
      puVar6 = (undefined4 *)FUN_00891268();
      if (puVar6 == (undefined4 *)0x0) {
        local_18 = (char *)0x0;
        pppuStack_4c = (undefined ***)0x66816c;
        std::exception::exception((exception *)local_34,&local_18);
        pppuStack_4c = local_34;
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        puStack_50 = &UNK_00668181;
        __CxxThrowException_8();
      }
      DAT_00fe18a4 = puVar6;
      *puVar6 = 0;
      puVar6[1] = 0;
      *DAT_00fe18a4 = &DAT_00fe18a4;
      _DAT_00fe18a8 = 0;
      _DAT_00fe18ac = 0;
      _DAT_00fe18b0 = 0;
      _DAT_00fe18b4 = 0;
      _DAT_00fe18bc = 1;
      DAT_00fe18be = 0;
      _DAT_00fe18c0 = 0;
      pppuStack_4c = (undefined ***)0x6680ff;
      _atexit((_func_4879 *)&LAB_00bce8c0);
    }
    local_8 = 0xffffffff;
    local_26 = 0x9d;
    local_24 = *(undefined4 *)in_ECX[0x45];
    local_20 = ((undefined4 *)in_ECX[0x45])[1];
    if (DAT_00fba798 == 0) {
      pppuStack_4c = (undefined ***)&local_26;
      puStack_50 = (undefined *)0x0;
      local_54 = 0x66813f;
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
    (**(code **)(*in_ECX + 0xd4))();
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    pppuStack_4c = (undefined ***)0x667f60;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  pppuStack_4c = (undefined ***)0x667f75;
  pppuStack_4c = (undefined ***)FUN_00891268();
  if (pppuStack_4c == (undefined ***)0x0) {
    pppuStack_4c = (undefined ***)0x0;
  }
  else {
    *pppuStack_4c = FoxUI::FXUIEvent::vftable;
    pppuStack_4c[1] = (undefined **)0xffffffff;
    pppuStack_4c[2] = (undefined **)0xffffffff;
    pppuStack_4c[3] = (undefined **)0x0;
    pppuStack_4c[4] = (undefined **)0xf43de;
  }
  local_1c = (undefined1 *)local_68;
  local_54 = 7;
  local_58 = 0;
  local_70 = &DAT_00bed1fc;
  local_68[0] = 0;
  local_74 = 0x667fbb;
  FUN_00402160();
  local_8 = 1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    local_70 = (undefined2 *)0x667fdf;
    FUN_00584c40();
    local_70 = (undefined2 *)0x667fe9;
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_14 = 0xb4;
  local_70 = (undefined2 *)0x668008;
  FUN_005740f0();
  if (local_18 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar8 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  local_18 = local_84;
  local_70 = (undefined2 *)0x7;
  local_74 = 0;
  local_84[0] = '\0';
  local_84[1] = '\0';
  psVar5 = psVar8;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_10;
  return;
}

