
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ed470(void)

{
  wchar_t *in_EAX;
  errno_t eVar1;
  int _FileHandle;
  long lVar2;
  void *_DstBuf;
  int unaff_ESI;
  undefined2 local_10;
  undefined4 local_e;
  char local_a;
  FILE *local_8;
  
  eVar1 = __wfopen_s(&local_8,in_EAX,L"rb");
  if (eVar1 == 0x16) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0x5f14) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0x5f14));
    *(undefined4 *)(unaff_ESI + 0x5f14) = 0;
  }
  _FileHandle = __fileno(local_8);
  lVar2 = __filelength(_FileHandle);
  *(long *)(unaff_ESI + 0x5f10) = lVar2;
  _DstBuf = (void *)FUN_0087dc3d(lVar2);
  *(void **)(unaff_ESI + 0x5f14) = _DstBuf;
  _fread(_DstBuf,*(size_t *)(unaff_ESI + 0x5f10),1,local_8);
  _fclose(local_8);
  local_a = (char)(*(uint *)(unaff_ESI + 0x5f10) >> 10);
  if ((*(uint *)(unaff_ESI + 0x5f10) & 0x3ff) != 0) {
    local_a = local_a + '\x01';
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_e = *(undefined4 *)(unaff_ESI + 0x5f10);
  local_10 = 0xbc7;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_10,7);
  }
  return 1;
}

