
undefined4 * FUN_00544c40(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  int *unaff_FS_OFFSET;
  undefined **local_20 [3];
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092f055;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  *param_1 = CController::vftable;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 1;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 1;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  local_8 = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x14] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0x13] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x13] + 4) = param_1[0x13];
    *(undefined4 *)(param_1[0x13] + 8) = param_1[0x13];
    *(undefined1 *)(param_1[0x13] + 0x14) = 1;
    *(undefined1 *)(param_1[0x13] + 0x15) = 1;
    local_8._0_1_ = 1;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    DVar3 = timeGetTime();
    param_1[0x19] = DVar3;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0xbf800000;
    FUN_0049c480();
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar1 = DAT_00fb79e8 & 1;
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined1 *)(param_1 + 5) = 1;
    param_1[6] = 0;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 8) = 1;
    param_1[9] = 0;
    param_1[10] = 0;
    *(undefined1 *)(param_1 + 0xb) = 1;
    DAT_00fbab34 = 0;
    DAT_00fbab38 = 0;
    if (uVar1 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar2 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xd8) = *(undefined4 *)(DAT_00fb76e8 + 0xd4);
    *(undefined4 *)(iVar2 + 0xb0) = 1;
    param_1[0x1a] = 0;
    *(undefined1 *)(param_1 + 0x1b) = 0;
    DAT_00d6a62c = GetPrivateProfileIntW(L"LATENCY",L"LOW_LATENCY",100,L"./latency.ini");
    DAT_00d6a630 = GetPrivateProfileIntW(L"LATENCY",L"AVG_LATENCY",0x78,L"./latency.ini");
    DAT_00d6a634 = GetPrivateProfileIntW(L"LATENCY",L"SLOW_LATENCY",0xb4,L"./latency.ini");
    DAT_00d6a638 = GetPrivateProfileIntW(L"LATENCY",L"CATASTROPHIC_LATENCY",300,L"./latency.ini");
    *unaff_FS_OFFSET = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

