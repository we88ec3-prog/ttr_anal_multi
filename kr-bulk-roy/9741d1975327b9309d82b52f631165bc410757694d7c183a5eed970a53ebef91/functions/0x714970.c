
void FUN_00714970(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *unaff_ESI;
  char local_1bc [4];
  char local_1b8 [260];
  char local_b4 [128];
  char local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915d22;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  __splitpath_s(param_1,local_1bc,2,local_1b8,0x104,local_b4,0x80,local_34,0x20);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar2 = local_1bc;
  local_8 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_1bc,(int)pcVar2 - (int)(local_1bc + 1));
  pcVar2 = local_1b8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_1b8,(int)pcVar2 - (int)(local_1b8 + 1));
  pcVar2 = local_b4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_b4,(int)pcVar2 - (int)(local_b4 + 1));
  FUN_00401fc0(&DAT_00c10108,4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

