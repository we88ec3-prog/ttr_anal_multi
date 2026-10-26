
void FUN_007e2bb0(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *unaff_ESI;
  int *piVar5;
  undefined1 local_44 [8];
  undefined1 *local_3c;
  int *local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined1 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937966;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined1 *)FUN_007e30c0(local_14);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)FUN_00891268(0x20);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(puVar2 + 0x14) = 0xf;
      *(undefined4 *)(puVar2 + 0x10) = 0;
      *puVar2 = 0;
    }
    pcVar3 = unaff_ESI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    local_3c = puVar2;
    FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
    *(undefined4 *)(puVar2 + 0x1c) = 0;
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    pcVar3 = unaff_ESI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
    piVar5 = local_38 + 1;
    local_8 = 0;
    local_18 = puVar2;
    uVar4 = FUN_00552de0(local_34);
    FUN_007e2910(piVar5,local_44,uVar4);
    local_8 = 0xffffffff;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    puVar2 = local_3c;
  }
  *(int *)(puVar2 + 0x1c) = *(int *)(puVar2 + 0x1c) + 1;
  if ((*(int *)(puVar2 + 0x1c) == 1) && (*local_38 == 1)) {
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      local_8 = 1;
      FUN_007bb970();
      _atexit((_func_4879 *)&LAB_00bceac0);
      local_8 = 0xffffffff;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    (*DAT_00fe1adc)();
    SetEvent(DAT_00fe1b2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

