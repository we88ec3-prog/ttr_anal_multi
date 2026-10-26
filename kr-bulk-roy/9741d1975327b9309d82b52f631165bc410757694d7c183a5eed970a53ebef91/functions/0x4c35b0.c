
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c35b0(void)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  short *psVar8;
  int in_ECX;
  short *psVar9;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009306f6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((_DAT_00fe6fe0 & 1) == 0) {
    _DAT_00fe6fe0 = _DAT_00fe6fe0 | 1;
    _DAT_00fe6fdc = timeGetTime();
  }
  DVar4 = timeGetTime();
  piVar3 = DAT_00fba854;
  if (*(int *)(in_ECX + 0xbd54) != 0) {
    if (300000 < DVar4 - *(int *)(in_ECX + 0xbd58)) {
      *(DWORD *)(in_ECX + 0xbd58) = DVar4;
      (**(code **)(*piVar3 + 0x20))();
      puVar5 = (undefined4 *)FUN_00891268();
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = FoxUI::FXUIEvent::vftable;
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf4400;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      FUN_00402160();
      local_8 = 1;
      iVar6 = FUN_005854b0();
      FUN_005740f0();
      if (local_18 == *(int *)(iVar6 + 4)) {
        pcVar2 = (code *)swi(3);
        uVar7 = (*pcVar2)();
        return uVar7;
      }
      psVar9 = (short *)(local_18 + 0x10);
      if (7 < *(uint *)(local_18 + 0x24)) {
        psVar9 = *(short **)psVar9;
      }
      psVar8 = psVar9;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar8 - (int)(psVar9 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      *(undefined4 *)(in_ECX + 0xbd54) = 0;
      ExceptionList = local_10;
      return 0;
    }
    if (5000 < DVar4 - _DAT_00fe6fdc) {
      _DAT_00fe6fdc = DVar4;
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
  }
  ExceptionList = local_10;
  return 0;
}

