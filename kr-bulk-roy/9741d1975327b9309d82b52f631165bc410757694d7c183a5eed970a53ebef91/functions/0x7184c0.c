
undefined4 * FUN_007184c0(undefined4 *param_1)

{
  uint uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009059cb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSection(lpCriticalSection);
  }
  *param_1 = lpCriticalSection;
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  local_8 = 0;
  param_1[8] = 0;
  puVar2 = (undefined4 *)FUN_00891268(0x214,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = ReadStream::vftable;
    puVar2[2] = WriteStream::vftable;
    *puVar2 = BinFile::vftable;
    puVar2[1] = BinFile::vftable;
    puVar2[2] = BinFile::vftable;
    puVar2[3] = 0;
    *(undefined1 *)(puVar2 + 0x84) = 0;
    *(undefined1 *)(puVar2 + 4) = 0;
  }
  param_1[9] = puVar2;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 1;
  ExceptionList = local_10;
  return param_1;
}

