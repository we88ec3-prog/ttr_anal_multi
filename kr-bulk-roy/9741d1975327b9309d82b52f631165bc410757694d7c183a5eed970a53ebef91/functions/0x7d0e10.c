
void FUN_007d0e10(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  uint uVar4;
  char *pcVar5;
  int in_ECX;
  char *in_EDX;
  undefined *local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914b40;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = &DAT_00fbab64;
  local_14 = uVar4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fbab64);
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar5 = in_EDX;
  do {
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar5 - (int)(in_EDX + 1));
  local_8._0_1_ = 1;
  FUN_007b86f0(&local_34,local_30);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar4);
  }
  if (local_34 == *(int *)(in_ECX + 4)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fbab64);
  }
  else {
    puVar3 = *(undefined4 **)(local_34 + 0x24);
    piVar1 = puVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *puVar3 = 2;
      if ((undefined4 *)puVar3[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar3[2])(1);
        puVar3[2] = 0;
      }
      FUN_0089120c(puVar3);
      FUN_007b8680(&local_38,local_34);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fbab64);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

