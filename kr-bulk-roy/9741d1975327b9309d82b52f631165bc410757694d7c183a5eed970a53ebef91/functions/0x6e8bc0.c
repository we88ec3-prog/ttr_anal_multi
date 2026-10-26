
void FUN_006e8bc0(void)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  short *psVar7;
  undefined **ppuVar8;
  int iVar9;
  undefined2 local_264 [100];
  short local_19c [100];
  short local_d4 [102];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar4 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar4 + 0x2fe);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') goto LAB_006e8e6b;
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar4 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  puVar3 = *(undefined4 **)(iVar4 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (((puVar3 == (undefined4 *)0x0) || (iVar4 = FUN_006e3660(0), iVar4 == 0)) ||
     (iVar4 = FUN_006ec8b0(*puVar3,puVar3[2],puVar3[6],puVar3[0xc]), iVar4 == 0)) goto LAB_006e8e6b;
  if (*(int *)(iVar4 + 8) == *(int *)(iVar4 + 0xc)) {
    iVar4 = FUN_006ed2c0();
    iVar9 = 100;
    psVar6 = local_19c;
    do {
      psVar7 = psVar6;
      if ((iVar9 == -0x7fffff9a) ||
         (sVar2 = *(short *)((iVar4 - (int)local_19c) + (int)psVar7), sVar2 == 0)) {
        if (iVar9 == 0) {
          psVar7 = psVar7 + -1;
        }
        *psVar7 = 0;
        goto LAB_006e8d4a;
      }
      *psVar7 = sVar2;
      iVar9 = iVar9 + -1;
      psVar6 = psVar7 + 1;
    } while (iVar9 != 0);
    *psVar7 = 0;
  }
  else {
    uVar5 = FUN_006ed2c0();
    uVar5 = FUN_006ed2c0(uVar5);
    FUN_006ead50(local_19c,L"backbuf %s, adapter %s",uVar5);
  }
LAB_006e8d4a:
  if (puVar3[0xd] == 0) {
    local_264[0] = 0;
  }
  else {
    uVar5 = FUN_006ed2c0();
    FUN_006ead50(local_264,L" (%s)",uVar5);
  }
  iVar4 = puVar3[8];
  if (iVar4 == 0) {
    psVar6 = local_d4;
    iVar4 = 100;
    iVar9 = (int)&DAT_00bed1fc - (int)psVar6;
    do {
      if ((iVar4 == -0x7fffff9a) || (sVar2 = *(short *)(iVar9 + (int)psVar6), sVar2 == 0))
      goto LAB_006e8e10;
      *psVar6 = sVar2;
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
LAB_006e8e14:
    psVar6 = psVar6 + -1;
    goto LAB_006e8e17;
  }
  psVar6 = local_d4;
  if (iVar4 == 1) {
    iVar4 = 100;
    do {
      if ((iVar4 == -0x7fffff9a) ||
         (sVar2 = *(short *)(((int)L" (Nonmaskable Multisample)" - (int)local_d4) + (int)psVar6),
         sVar2 == 0)) goto LAB_006e8e10;
      *psVar6 = sVar2;
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    goto LAB_006e8e14;
  }
  FUN_006ead50(psVar6,L" (%dx Multisample)",iVar4);
LAB_006e8e1c:
  uVar5 = FUN_006df6d0();
  uVar5 = FUN_006e17e0(uVar5);
  ppuVar8 = (undefined **)&DAT_00c41460;
  if (puVar3[0x11] != -0x80000000) {
    ppuVar8 = &PTR___break_00c41468;
  }
  FUN_006ead50(uVar5,L"%%sVsync %s (%dx%d), %s%s%s",ppuVar8,puVar3[4],puVar3[5],local_19c,local_264,
               local_d4);
LAB_006e8e6b:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
LAB_006e8e10:
  if (iVar4 == 0) goto LAB_006e8e14;
LAB_006e8e17:
  *psVar6 = 0;
  goto LAB_006e8e1c;
}

