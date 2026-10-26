
/* WARNING: Removing unreachable block (ram,0x007c4c51) */

void FUN_007c4b70(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *in_ECX;
  char *in_EDX;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937746;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar4 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_8._0_1_ = 1;
    FUN_007bb970(uVar4);
    _atexit((_func_4879 *)&LAB_00bceac0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
  (*DAT_00fe1ae0)();
  SetEvent(DAT_00fe1b2c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

