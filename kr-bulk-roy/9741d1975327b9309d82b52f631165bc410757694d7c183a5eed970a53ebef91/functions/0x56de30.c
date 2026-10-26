
/* WARNING: Removing unreachable block (ram,0x0056e041) */

void FUN_0056de30(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **local_a0 [3];
  undefined1 *local_94;
  uint local_90;
  char *local_8c;
  wchar_t local_88 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921e0d;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_90 = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  local_94 = param_1;
  *param_1 = 0;
  local_8c = param_1 + 0x20;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0xf;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *local_8c = '\0';
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  uVar1 = FUN_00570a10(local_18);
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(int *)(*(int *)(param_1 + 0x48) + 4) = *(int *)(param_1 + 0x48);
  *(int *)(*(int *)(param_1 + 0x48) + 8) = *(int *)(param_1 + 0x48);
  *(undefined1 *)(*(int *)(param_1 + 0x48) + 0x40) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x48) + 0x41) = 1;
  local_8._0_1_ = 2;
  *(undefined4 *)(param_1 + 0x58) = 0;
  iVar2 = FUN_00891268(0xc);
  if (iVar2 == 0) {
    local_8c = (char *)0x0;
    std::exception::exception((exception *)local_a0,&local_8c);
    local_a0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_a0,&DAT_00c857a8);
  }
  *(int *)(param_1 + 0x54) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*(int *)(param_1 + 0x54) + 4) = *(int *)(param_1 + 0x54);
  local_8._0_1_ = 3;
  local_8c = (char *)FUN_00891268(0xa0);
  local_8._0_1_ = 4;
  if (local_8c == (char *)0x0) {
    uVar1 = 0;
  }
  else {
    local_20 = 7;
    local_24 = 0;
    local_34 = local_34 & 0xffff0000;
    FUN_00402160(L"MinimapCached",0xd);
    local_8 = CONCAT31(local_8._1_3_,5);
    local_90 = 1;
    uVar1 = FUN_0073a110(0x100,0,1);
  }
  local_8 = 3;
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  if ((local_90 & 1) != 0) {
    if (7 < local_20) {
      FUN_0089120c(local_34);
    }
    local_20 = 7;
    local_24 = 0;
    local_34 = local_34 & 0xffff0000;
  }
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  local_8._0_1_ = 7;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  local_48 = 0;
  _memset(local_88,0,0x40);
  local_44 = 0xc;
  local_40 = 7;
  local_3c = 1;
  _wcscpy_s(local_88,0x20,(wchar_t *)PTR_DAT_00d6a230);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 8;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 7;
  }
  puVar3 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,&local_8c);
  *(undefined4 *)(param_1 + 0x70) = *puVar3;
  if (*(int *)(param_1 + 0x74) != *(int *)(param_1 + 0x78)) {
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x74);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

