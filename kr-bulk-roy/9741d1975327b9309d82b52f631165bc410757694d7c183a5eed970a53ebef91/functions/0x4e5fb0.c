
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5fb0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e344;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_004d4590(uVar1);
  if (uVar2 != 0) {
    if ((_DAT_00fc1ca8 & 1) == 0) {
      _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
      DAT_00fc1cac = 0;
      DAT_00fc1cb0 = 0;
      _DAT_00fc1cb4 = 0;
      _atexit((_func_4879 *)&LAB_00bce5a0);
    }
    iVar3 = (DAT_00fc1cb0 - DAT_00fc1cac) / 0x24 + -1;
    for (puVar6 = (uint *)(DAT_00fc1cac + 4 + iVar3 * 0x24); uVar2 < *puVar6; puVar6 = puVar6 + -9)
    {
      iVar3 = iVar3 + -1;
    }
    uVar7 = (uint)*(byte *)(DAT_00fc1cac + iVar3 * 0x24);
    if ((*(uint *)(in_ECX + 0x68cc) != uVar7) &&
       (iVar3 = FUN_00404ba0(), *(int *)(iVar3 + 0x5f4c) != 0)) {
      puVar4 = (undefined4 *)FUN_00891268(0x6c);
      local_8 = 0;
      if (puVar4 != (undefined4 *)0x0) {
        FUN_004cd030();
        FUN_0047f540(L"UI/ImageSets/TeamRankIcon_64.dds");
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00553e90(puVar4,100,0x19,0);
        *puVar4 = `public:_void___thiscall_CGlobalStatus::UpdateTeamRank(void)'::__l10::
                  CTeamRankUpEffect::vftable;
        puVar4[0x1a] = uVar7;
      }
      uVar8 = 0;
      local_8 = 2;
      uVar5 = FUN_00422ed0(0);
      FUN_005536e0(uVar5,uVar8);
      if (puVar4 != (undefined4 *)0x0) {
        FUN_00402c50();
      }
    }
    *(uint *)(in_ECX + 0x68d0) = uVar2;
    *(uint *)(in_ECX + 0x68cc) = uVar7;
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

