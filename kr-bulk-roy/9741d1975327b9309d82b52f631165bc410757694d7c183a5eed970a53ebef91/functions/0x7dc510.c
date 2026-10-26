
void FUN_007dc510(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  LPCSTR **lpText;
  int in_ECX;
  char *in_EDX;
  int local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  LPCSTR *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009149b0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffffff00;
  pcVar4 = in_EDX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
  local_8 = 0;
  FUN_007b86f0(&local_50,local_4c);
  local_8 = 0xffffffff;
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0],uVar3);
  }
  if (local_50 == *(int *)(in_ECX + 4)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (LPCSTR *)((uint)local_30[0] & 0xffffff00);
    pcVar4 = in_EDX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
    local_8 = 1;
    FUN_00401fc0(&DAT_00c50378,0x43);
    lpText = (LPCSTR **)local_30[0];
    if (local_1c < 0x10) {
      lpText = local_30;
    }
    MessageBoxA((HWND)0x0,(LPCSTR)lpText,"Error",0);
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    piVar2 = *(int **)(local_50 + 0x24);
    iVar5 = (**(code **)(*piVar2 + 0xc))();
    if (iVar5 == 0) {
      (**(code **)*piVar2)(1);
      FUN_007b8680(&local_50,local_50);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

