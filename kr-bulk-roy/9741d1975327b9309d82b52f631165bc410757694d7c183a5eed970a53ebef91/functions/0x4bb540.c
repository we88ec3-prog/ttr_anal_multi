
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bb540(void)

{
  short sVar1;
  void *_Dst;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009449ff;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00562250();
  (**(code **)(*DAT_00fba7a4 + 0x14))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  DAT_00fab228 = 0;
  FUN_004e1070(&DAT_00fab148);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 4;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  iVar4 = DAT_00fab130;
  FUN_00797a00();
  _Dst = *(void **)(iVar4 + 0x5ee8);
  if (_Dst != *(void **)(iVar4 + 0x5eec)) {
    FID_conflict__memcpy(_Dst,*(void **)(iVar4 + 0x5eec),0);
    *(void **)(iVar4 + 0x5eec) = _Dst;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 2) {
      FUN_00544f50();
      goto LAB_004bb764;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iStack_3c = FUN_00891268(0xc0);
  local_c = 6;
  if (iStack_3c == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00548540(iStack_3c);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bb764:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xc;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 3) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 3;
  }
  uVar2 = *(undefined4 *)(DAT_00fe1aa0 + 0x18);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  uStack_40 = CONCAT13(10,CONCAT12((char)uVar2,0x43));
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_40,4);
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 0xd;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  DAT_00fb8830 = DAT_00fb8830 & 0xfffffffe;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0xe;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (2 < DAT_00f94328) {
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_c = 0xf;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_c = 0xffffffff;
    }
    uStack_40 = 0x10;
    FUN_005740f0(&uStack_40);
    if (iStack_3c == DAT_00fe5aec) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar7 = (short *)(iStack_3c + 0x10);
    if (7 < *(uint *)(iStack_3c + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    uStack_38 = (uint)uStack_38._2_2_ << 0x10;
    uStack_24 = 7;
    uStack_28 = 0;
    psVar6 = psVar7;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
    local_c = 0x10;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 0x11;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = CONCAT31(local_c._1_3_,0x10);
    }
    FUN_004d6b30(&uStack_38);
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

