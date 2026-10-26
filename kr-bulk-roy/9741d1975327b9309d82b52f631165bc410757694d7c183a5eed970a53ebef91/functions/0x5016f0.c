
void FUN_005016f0(short *param_1,undefined4 param_2)

{
  short sVar1;
  undefined1 uVar2;
  uint uVar3;
  short *psVar4;
  int *piVar5;
  undefined4 *unaff_ESI;
  short *local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009221b9;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  *(undefined1 *)(unaff_ESI + 0xe) = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[5] = 1;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x17] = 0xf;
  unaff_ESI[0x16] = 0;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  local_68 = param_1;
  unaff_ESI[0x19] = 0;
  local_8 = 0;
  *unaff_ESI = CQuestMsgObj::vftable;
  unaff_ESI[0x1f] = 7;
  unaff_ESI[0x1e] = 0;
  *(undefined2 *)(unaff_ESI + 0x1a) = 0;
  psVar4 = param_1;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  local_14 = uVar3;
  FUN_00402160(param_1,(int)psVar4 - (int)(param_1 + 1) >> 1);
  local_8._0_1_ = 1;
  unaff_ESI[0x21] = param_2;
  _eh_vector_constructor_iterator_
            (unaff_ESI + 0x22,0x1c,2,(_func_void_void_ptr *)&LAB_00402140,FUN_004fa440);
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  unaff_ESI[0x30] = 0xffffffff;
  if (DAT_00e312c4 == -1) {
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0x28;
    local_1c = 4;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a240);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8._0_1_ = 3;
      FUN_00734ef0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8._0_1_ = 2;
    }
    piVar5 = (int *)FUN_00735850(&DAT_00fb7b70,&local_68);
    DAT_00e312c4 = *piVar5;
    uVar2 = (undefined1)local_8;
  }
  local_8._0_1_ = uVar2;
  unaff_ESI[7] = 0x14;
  unaff_ESI[10] = 0x14;
  unaff_ESI[8] = 0x28;
  unaff_ESI[0xb] = 0x28;
  unaff_ESI[0xc] = 0x3c;
  unaff_ESI[0xf] = 0;
  FUN_00402a70("QuestMsgBg.png",0xe);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

