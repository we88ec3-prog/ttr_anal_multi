
void FUN_007ef760(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  int *piVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 ****ppppuVar10;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009377c6;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  if (*(int *)(in_ECX + 0x38) == 0) {
    pcVar8 = (char *)(in_ECX + 0xb4);
    if (0xf < *(uint *)(in_ECX + 200)) {
      pcVar8 = *(char **)pcVar8;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
    pcVar4 = pcVar8;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
    local_8 = 0;
    FUN_00401fc0("Texture/",8);
    piVar9 = (int *)(in_ECX + 0x60);
    piVar7 = piVar9;
    if (0xf < *(uint *)(in_ECX + 0x74)) {
      piVar7 = (int *)*piVar9;
    }
    piVar5 = piVar7;
    do {
      iVar2 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 1);
    } while ((char)iVar2 != '\0');
    FUN_00401fc0(piVar7,(int)piVar5 - ((int)piVar7 + 1));
    ppppuVar10 = (undefined4 ****)local_30[0];
    if (local_1c < 0x10) {
      ppppuVar10 = local_30;
    }
    if (0xf < *(uint *)(in_ECX + 0x74)) {
      piVar9 = (int *)*piVar9;
    }
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      local_8._0_1_ = 1;
      FUN_007bb970();
      _atexit((_func_4879 *)&LAB_00bceac0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    (*DAT_00fe1ae0)(piVar9,ppppuVar10);
    SetEvent(DAT_00fe1b2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  puVar6 = (undefined4 *)FUN_00891268(0x50,uVar3);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[1] = 0;
    puVar6[6] = 0;
    puVar6[7] = 0xf;
    *(undefined1 *)(puVar6 + 2) = 0;
    puVar6[0x11] = 0;
    puVar6[0x12] = 0;
    puVar6[9] = 0;
    puVar6[10] = 1;
    puVar6[0xb] = 0;
    *puVar6 = IS3D::CItemNodeSimple::vftable;
    puVar6[0xc] = 0xf;
    puVar6[0xd] = 0;
    puVar6[0xe] = 0;
    puVar6[0xf] = 0;
    puVar6[0x10] = 0;
    puVar6[0x13] = 0;
  }
  *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
  if (*(int *)(in_ECX + 0x128) == 0) {
    FUN_006edb10(&DAT_00c50988);
    FUN_007efec0();
  }
  FUN_007f07b0(puVar6);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

