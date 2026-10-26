
void FUN_006edd50(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 *unaff_ESI;
  char *unaff_EDI;
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915eab;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  local_8 = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  GetCurrentDirectoryA(0x104,local_118);
  pcVar2 = local_118;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_118,(int)pcVar2 - (int)(local_118 + 1));
  FUN_00401fc0(&DAT_00c420d4,1);
  pcVar2 = unaff_EDI;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(unaff_EDI,(int)pcVar2 - (int)(unaff_EDI + 1));
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

