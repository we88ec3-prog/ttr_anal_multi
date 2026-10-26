
undefined4 * FUN_00807470(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *unaff_EDI;
  undefined4 *local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)unaff_EDI[10]);
  if (unaff_EDI[7] == 0) {
    iVar6 = 0;
    do {
      puVar2 = (undefined4 *)FUN_00891268(0x100c);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[0x402] = 0;
        _memset(puVar2 + 2,0,0x1000);
      }
      iVar1 = unaff_EDI[0xb];
      unaff_EDI[0xb] = iVar1 + 1;
      puVar2[0x402] = iVar1;
      local_8 = puVar2;
      FUN_00804260(&local_8);
      iVar1 = *unaff_EDI;
      iVar3 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_8);
      if (unaff_EDI[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      unaff_EDI[1] = unaff_EDI[1] + 1;
      *(int *)(iVar1 + 4) = iVar3;
      iVar6 = iVar6 + 1;
      **(int **)(iVar3 + 4) = iVar3;
    } while (iVar6 < 0x32);
  }
  piVar4 = (int *)FUN_00542210();
  if ((int *)*piVar4 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)*piVar4;
  }
  uVar5 = (uint)piVar4[2] >> 2;
  if (*(uint *)(iVar6 + 8) <= uVar5) {
    uVar5 = uVar5 - *(uint *)(iVar6 + 8);
  }
  puVar2 = *(undefined4 **)(*(int *)(*(int *)(iVar6 + 4) + uVar5 * 4) + (piVar4[2] & 3U) * 4);
  if (unaff_EDI[7] != 0) {
    unaff_EDI[6] = unaff_EDI[6] + 1;
    if ((uint)(unaff_EDI[5] * 4) <= (uint)unaff_EDI[6]) {
      unaff_EDI[6] = 0;
    }
    iVar6 = unaff_EDI[7] + -1;
    unaff_EDI[7] = iVar6;
    if (iVar6 == 0) {
      unaff_EDI[6] = 0;
    }
  }
  unaff_EDI[9] = unaff_EDI[9] + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)unaff_EDI[10]);
  *puVar2 = 0;
  puVar2[1] = 0;
  return puVar2;
}

