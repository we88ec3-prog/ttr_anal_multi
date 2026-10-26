
void FUN_007ef3a0(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int in_ECX;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  undefined4 ****ppppuVar9;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_00937746;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  if (*(int *)(in_ECX + 0x38) != 0) {
    pcVar6 = (char *)(in_ECX + 0xb4);
    if (0xf < *(uint *)(in_ECX + 200)) {
      pcVar6 = *(char **)pcVar6;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
    pcVar4 = pcVar6;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
    local_8 = 0;
    FUN_00401fc0("Texture/",8);
    piVar8 = (int *)(in_ECX + 0x60);
    piVar7 = piVar8;
    if (0xf < *(uint *)(in_ECX + 0x74)) {
      piVar7 = (int *)*piVar8;
    }
    piVar5 = piVar7;
    do {
      iVar2 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 1);
    } while ((char)iVar2 != '\0');
    FUN_00401fc0(piVar7,(int)piVar5 - ((int)piVar7 + 1));
    ppppuVar9 = (undefined4 ****)local_30[0];
    if (local_1c < 0x10) {
      ppppuVar9 = local_30;
    }
    if (0xf < *(uint *)(in_ECX + 0x74)) {
      piVar8 = (int *)*piVar8;
    }
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      local_8._0_1_ = 1;
      FUN_007bb970(uVar3);
      _atexit((_func_4879 *)&LAB_00bceac0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    (*DAT_00fe1ae0)(piVar8,ppppuVar9);
    SetEvent(DAT_00fe1b2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    FUN_007efec0();
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

