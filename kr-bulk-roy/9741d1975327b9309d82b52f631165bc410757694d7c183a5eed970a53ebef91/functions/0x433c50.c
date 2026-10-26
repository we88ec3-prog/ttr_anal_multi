
undefined4 * FUN_00433c50(undefined4 *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  uint uStack_48;
  _Lockit local_38 [4];
  undefined4 local_34;
  undefined1 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined1 local_20;
  byte *local_1c;
  byte local_18 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b830;
  local_10 = ExceptionList;
  uStack_48 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 1;
    *puVar2 = std::locale::_Locimp::vftable;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    *(undefined1 *)(puVar2 + 5) = 0;
    puVar2[6] = 0;
    *(undefined1 *)(puVar2 + 7) = 0;
    FUN_00433ba0(&DAT_00bf9754);
  }
  *param_1 = puVar2;
  local_8 = 0;
  std::locale::_Init();
  std::_Lockit::_Lockit(local_38,0);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = (byte *)0x0;
  local_18[0] = 0;
  local_8._0_1_ = 5;
  std::_Locinfo::_Locinfo_ctor((_Locinfo *)local_38,0x3f,"");
  local_8._0_1_ = 6;
  pbVar3 = local_1c;
  if (local_1c == (byte *)0x0) {
    pbVar3 = local_18;
  }
  pbVar5 = &DAT_00bf9754;
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_00433d34:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_00433d39;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_00433d34;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00433d39:
  if (iVar4 == 0) {
    FUN_0087dbca("bad locale name");
  }
  std::locale::_Locimp::_Makeloc((_Locinfo *)local_38,0x3f,(_Locimp *)*param_1,(locale *)0x0);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00431620();
  ExceptionList = local_10;
  return param_1;
}

