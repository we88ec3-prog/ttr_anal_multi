
/* WARNING: Removing unreachable block (ram,0x005416cf) */
/* WARNING: Removing unreachable block (ram,0x005416d8) */
/* WARNING: Removing unreachable block (ram,0x00541796) */
/* WARNING: Removing unreachable block (ram,0x005417a2) */
/* WARNING: Removing unreachable block (ram,0x005417b6) */

void FUN_00541610(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  HANDLE hHandle;
  int *piVar4;
  int *unaff_FS_OFFSET;
  int local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009393dc;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_14;
  if ((((9 < param_1) && (9999 < param_1)) && (10999 < param_1)) && (20999 < param_1)) {
    FUN_006edb60();
  }
  puVar3 = (undefined4 *)FUN_00891268();
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    *(undefined1 *)(puVar3 + 2) = 1;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
  }
  FUN_0047c0d0();
  local_c = 0;
  uRam00000008 = 0;
  uRam00000004 = 0xff;
  FUN_004a8680();
  uVar1 = local_c >> 8;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_c._0_1_ = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar1 = (uint)local_c._1_3_;
  }
  local_c = uVar1 << 8;
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_c._0_1_ = 3;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_c = (uint)local_c._1_3_ << 8;
  }
  iVar2 = DAT_00fe173c;
  piVar4 = (int *)**(int **)(DAT_00fe173c + 4);
  if (piVar4 != *(int **)(DAT_00fe173c + 4)) {
    do {
      if (((int *)piVar4[9])[1] == 0) {
        (**(code **)(*(int *)piVar4[9] + 4))();
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(iVar2 + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

