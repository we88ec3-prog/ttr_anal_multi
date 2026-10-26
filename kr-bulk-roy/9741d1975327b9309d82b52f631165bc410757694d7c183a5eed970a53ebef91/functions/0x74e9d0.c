
void FUN_0074e9d0(void)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  
  FUN_00750350();
  pvVar1 = *(void **)(unaff_EDI + 0x148c);
  if (pvVar1 != *(void **)(unaff_EDI + 0x1490)) {
    FID_conflict__memcpy(pvVar1,*(void **)(unaff_EDI + 0x1490),0);
    *(void **)(unaff_EDI + 0x1490) = pvVar1;
  }
  pvVar1 = *(void **)(unaff_EDI + 0x149c);
  if (pvVar1 != *(void **)(unaff_EDI + 0x14a0)) {
    FID_conflict__memcpy(pvVar1,*(void **)(unaff_EDI + 0x14a0),0);
    *(void **)(unaff_EDI + 0x14a0) = pvVar1;
  }
  FUN_00753830();
  FUN_00753830();
  piVar3 = *(int **)(unaff_EDI + 0x1474);
  piVar2 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(unaff_EDI + 0x1474) + 4) = *(int *)(unaff_EDI + 0x1474);
  *(undefined4 *)(unaff_EDI + 0x1478) = 0;
  if (piVar2 != *(int **)(unaff_EDI + 0x1474)) {
    do {
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
    } while (piVar3 != (int *)*(int *)(unaff_EDI + 0x1474));
  }
  piVar3 = *(int **)(unaff_EDI + 0x1480);
  piVar2 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(unaff_EDI + 0x1480) + 4) = *(int *)(unaff_EDI + 0x1480);
  *(undefined4 *)(unaff_EDI + 0x1484) = 0;
  if (piVar2 != *(int **)(unaff_EDI + 0x1480)) {
    do {
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
    } while (piVar3 != (int *)*(int *)(unaff_EDI + 0x1480));
  }
  iVar5 = *(int *)(unaff_EDI + 0x1454);
  while (iVar5 != 0) {
    piVar3 = (int *)FUN_00542210();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)*piVar3;
    }
    uVar4 = (uint)piVar3[2] >> 1;
    if (*(uint *)(iVar5 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar5 + 8);
    }
    piVar3 = *(int **)(*(int *)(*(int *)(iVar5 + 4) + uVar4 * 4) + (piVar3[2] & 1U) * 8 + 4);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x10))(1);
    }
    if (*(int *)(unaff_EDI + 0x1454) != 0) {
      *(int *)(unaff_EDI + 0x1450) = *(int *)(unaff_EDI + 0x1450) + 1;
      if ((uint)(*(int *)(unaff_EDI + 0x144c) * 2) <= *(uint *)(unaff_EDI + 0x1450)) {
        *(undefined4 *)(unaff_EDI + 0x1450) = 0;
      }
      iVar5 = *(int *)(unaff_EDI + 0x1454) + -1;
      *(int *)(unaff_EDI + 0x1454) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(unaff_EDI + 0x1450) = 0;
      }
    }
    iVar5 = *(int *)(unaff_EDI + 0x1454);
  }
  FUN_00753520();
  return;
}

