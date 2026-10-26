
void FUN_00440850(undefined1 param_1,undefined1 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 in_CL;
  undefined1 in_DL;
  undefined1 *unaff_ESI;
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  char local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917ad8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00440830("%d.%d.%d.%d",param_1,in_DL,in_CL,param_2,local_14);
  pcVar2 = local_54;
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = local_70[0] & 0xffffff00;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_54,(int)pcVar2 - (int)(local_54 + 1));
  local_8 = 0;
  _memset(local_54,0,0x40);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  FUN_00403040(local_70,0,0xffffffff);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

