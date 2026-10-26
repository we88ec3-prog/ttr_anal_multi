
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005087d0(int param_1)

{
  short sVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  DWORD DVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092be9e;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 0x20) != '\0') {
    if ((_DAT_00fe69a8 & 1) == 0) {
      _DAT_00fe69a8 = _DAT_00fe69a8 | 1;
      _DAT_00fe69a4 = timeGetTime();
    }
    DVar5 = timeGetTime();
    if (5000 < DVar5 - _DAT_00fe69a4) {
      _DAT_00fe69a4 = DVar5;
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_20 = 0x43;
      local_1e = (undefined1)*(undefined4 *)(param_1 + 0x18);
      local_1d = 10;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_20,4);
      }
    }
  }
  local_1c = (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8)) / 0x28;
  bVar3 = false;
  if (local_1c != 0) {
    iVar8 = 0;
    do {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(iVar8 + 0x1c + iVar2) == 0) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          uStack_c = 0;
          FUN_004f3d80(uVar4);
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          uStack_c = 0xffffffff;
        }
        psVar6 = (short *)FUN_004f6a30(*(undefined4 *)(iVar8 + iVar2));
        psVar7 = psVar6;
        do {
          sVar1 = *psVar7;
          psVar7 = psVar7 + 1;
        } while (sVar1 != 0);
        FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
        bVar3 = true;
      }
      iVar8 = iVar8 + 0x28;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
    if (bVar3) {
      FUN_0058aad0(0xf4249);
    }
  }
  ExceptionList = local_14;
  return;
}

