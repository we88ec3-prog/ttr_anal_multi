
void FUN_007d0f20(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *unaff_ESI;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _sprintf_s(local_10c,0x104,"ObjFileMgr.CurrentEntry : %d\n",*(undefined4 *)(param_1 + 8),0);
  pcVar2 = local_10c;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_10c,(int)pcVar2 - (int)(local_10c + 1));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

