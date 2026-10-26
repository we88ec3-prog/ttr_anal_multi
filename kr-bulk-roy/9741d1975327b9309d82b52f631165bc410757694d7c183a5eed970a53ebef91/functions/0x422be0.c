
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422be0(int *param_1)

{
  short sVar1;
  code *pcVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined2 local_74 [8];
  undefined4 local_64;
  undefined2 *local_60;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941c40;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_3c = (undefined4 *)0x422c37;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9424c < 0x32) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      puStack_3c = (undefined4 *)0x422cbf;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    puStack_3c = (undefined4 *)0x422ccd;
    puVar3 = (undefined4 *)FUN_00891268();
    puVar5 = (undefined4 *)0x0;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[3] = 0;
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[4] = 0xf4441;
      puVar5 = puVar3;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 2;
      FUN_0074d990();
      puStack_3c = (undefined4 *)0x422d14;
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_1c = (undefined1 *)local_58;
    local_44 = 7;
    local_48 = 0;
    local_60 = &DAT_00bed1fc;
    local_58[0] = 0;
    local_64 = 0x422d4a;
    puStack_3c = puVar5;
    FUN_00402160();
    local_c = 3;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      local_60 = (undefined2 *)0x422d72;
      FUN_00584c40();
      local_60 = (undefined2 *)0x422d7c;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    local_24 = 0x16;
    local_60 = (undefined2 *)0x422d9e;
    FUN_005740f0();
    if (local_20 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_20 + 0x10);
    if (7 < *(uint *)(local_20 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_20 = (undefined1 *)local_74;
    local_60 = (undefined2 *)0x7;
    local_64 = 0;
    local_74[0] = 0;
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xcf);
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      puStack_3c = (undefined4 *)0x422c68;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_24 = CONCAT22(local_24._2_2_,0x8f);
    if (DAT_00fba798 == 0) {
      puStack_3c = &local_24;
      uStack_40 = 0;
      local_44 = 0x422c98;
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
  }
  (**(code **)(*param_1 + 0xd4))();
  ExceptionList = local_14;
  return;
}

