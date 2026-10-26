
void FUN_007b67e0(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *in_EDX;
  uint local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ebd0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = local_2c[0] & 0xffffff00;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_006df250(local_2c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  if (0xf < local_18) {
    FUN_0089120c(local_2c[0],uVar2);
  }
  ExceptionList = local_10;
  return;
}

