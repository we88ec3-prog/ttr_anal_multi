
void FUN_006ea2b0(void)

{
  int *piVar1;
  float fVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  float10 fVar10;
  float local_18;
  int local_8;
  
  fVar10 = (float10)FUN_006dffa0();
  iVar9 = 0;
  if (DAT_00fba7cc == 0) {
    iVar7 = FUN_00891268(0x1380);
    if (iVar7 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar7 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  piVar1 = *(int **)(iVar7 + 0x4c8);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if ((piVar1 != (int *)0x0) && (local_8 = 0, 0 < piVar1[1])) {
    do {
      iVar7 = *piVar1;
      fVar2 = *(float *)(iVar7 + 8 + iVar9);
      uVar3 = *(undefined4 *)(iVar7 + 4 + iVar9);
      pcVar4 = *(code **)(iVar7 + iVar9);
      iVar7 = iVar7 + iVar9;
      uVar5 = *(undefined4 *)(iVar7 + 0x10);
      uVar6 = *(undefined4 *)(iVar7 + 0x14);
      if ((char)uVar5 != '\0') {
        local_18 = *(float *)(iVar7 + 0xc) - (float)fVar10;
        if (local_18 < 0.0) {
          (*pcVar4)(local_8,uVar3);
          local_18 = fVar2;
        }
        if ((-1 < local_8) && (local_8 < piVar1[1])) {
          puVar8 = (undefined4 *)(*piVar1 + iVar9);
          *puVar8 = pcVar4;
          puVar8[1] = uVar3;
          puVar8[2] = fVar2;
          puVar8[3] = local_18;
          puVar8[4] = uVar5;
          puVar8[5] = uVar6;
        }
      }
      local_8 = local_8 + 1;
      iVar9 = iVar9 + 0x18;
    } while (local_8 < piVar1[1]);
  }
  return;
}

