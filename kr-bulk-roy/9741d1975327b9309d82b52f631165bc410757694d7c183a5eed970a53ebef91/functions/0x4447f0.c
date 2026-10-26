
undefined4 FUN_004447f0(void)

{
  int iVar1;
  int in_ECX;
  bool bVar2;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009258ee;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  bVar2 = false;
  local_14 = CONCAT13((char)((uint)in_ECX >> 0x18),7);
  ExceptionList = &local_10;
  if (DAT_00fba80c == 0) {
    iVar1 = FUN_00891268(0x57c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if (*(int *)(DAT_00fba80c + 0x20) != 0) {
    bVar2 = *(char *)(DAT_00fba80c + 0x17d) == '\x01';
    if (bVar2) {
      local_14 = local_14 | 0x80000;
    }
    if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x198) == '\x01')) {
      local_14 = local_14 | 0x100000;
      bVar2 = true;
    }
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb901b == '\x01') {
    local_14 = local_14 | 0x800000;
  }
  else if (!bVar2) {
    ExceptionList = local_10;
    return 0;
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,3);
  }
  ExceptionList = local_10;
  return 1;
}

