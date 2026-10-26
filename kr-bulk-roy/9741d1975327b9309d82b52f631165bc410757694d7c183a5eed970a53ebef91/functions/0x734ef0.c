
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00734ef0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *unaff_FS_OFFSET;
  undefined **local_88 [3];
  undefined **local_7c [3];
  undefined1 local_70 [4];
  char *local_6c;
  char *local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920c00;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  _DAT_00fb7b70 = 0;
  DAT_00fb7b74 = 0;
  _DAT_00fb7b84 = 0;
  local_14 = uVar1;
  iVar2 = FUN_00891268(100,uVar1);
  if (iVar2 == 0) {
    local_68 = (char *)0x0;
    std::exception::exception((exception *)local_7c,&local_68);
    local_7c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_7c,&DAT_00c857a8);
  }
  DAT_00fb7b80 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fb7b80 + 4) = DAT_00fb7b80;
  *(int *)(DAT_00fb7b80 + 8) = DAT_00fb7b80;
  *(undefined1 *)(DAT_00fb7b80 + 0x60) = 1;
  *(undefined1 *)(DAT_00fb7b80 + 0x61) = 1;
  local_8 = 0;
  DAT_00fb7b8c = 0xffffffff;
  DAT_00fb7b90 = 0xffffffff;
  _DAT_00fb7b9c = 0;
  iVar2 = FUN_00891268(0x14,uVar1);
  if (iVar2 != 0) {
    DAT_00fb7b98 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fb7b98 + 4) = DAT_00fb7b98;
    *(int *)(DAT_00fb7b98 + 8) = DAT_00fb7b98;
    *(undefined1 *)(DAT_00fb7b98 + 0x10) = 1;
    *(undefined1 *)(DAT_00fb7b98 + 0x11) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fb7bac = 0;
    _DAT_00fb7bb0 = 1;
    _DAT_00fb7bc4 = 1;
    _DAT_00fb7bb4 = 0;
    iVar2 = FUN_00891268(0x918,uVar1);
    if (iVar2 == 0) {
      DAT_00fb7ba8 = (undefined4 *)0x0;
    }
    else {
      DAT_00fb7ba8 = (undefined4 *)FUN_007349b0();
    }
    DAT_00fb7b78 = FUN_0073cf50();
    puVar3 = DAT_00fb7ba8;
    _DAT_00fb7bb8 = 3;
    _DAT_00fb7bbc = 0x3c;
    DAT_00fb7bc0 = 0xe10;
    DAT_00fb7ba8[4] = 0x800;
    puVar3[5] = 0x400;
    puVar3[2] = 0x20;
    puVar3[3] = 0x33;
    *puVar3 = 0x40;
    puVar3[1] = 0x14;
    FUN_00734a00();
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0xc;
    local_1c = 4;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,L"굴림");
    puVar3 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_70);
    DAT_00fb7b8c = *puVar3;
    *unaff_FS_OFFSET = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_6c = (char *)0x0;
  std::exception::exception((exception *)local_88,&local_6c);
  local_88[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_88,&DAT_00c857a8);
}

