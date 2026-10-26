
void FUN_0050f440(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *unaff_ESI;
  
  bVar2 = true;
  piVar5 = DAT_00fe17c4;
  if (*(char *)(DAT_00fe17c4[1] + 0x49) == '\0') {
    piVar3 = (int *)DAT_00fe17c4[1];
    do {
      piVar5 = piVar3;
      bVar2 = *(int *)(param_1 + 0xc) < piVar5[3];
      if (bVar2) {
        piVar3 = (int *)*piVar5;
      }
      else {
        piVar3 = (int *)piVar5[2];
      }
    } while (*(char *)((int)piVar3 + 0x49) == '\0');
  }
  if (bVar2) {
    if (piVar5 == (int *)*DAT_00fe17c4) {
      puVar4 = (undefined4 *)FUN_0050f520(&param_1,1);
      uVar1 = *puVar4;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      *unaff_ESI = uVar1;
      return;
    }
    FUN_0050fbf0();
  }
  if (*(int *)(param_1 + 0xc) <= piVar5[3]) {
    FUN_0050dd90();
    FUN_0089120c(param_1);
    *(undefined1 *)(unaff_ESI + 1) = 0;
    *unaff_ESI = piVar5;
    return;
  }
  puVar4 = (undefined4 *)FUN_0050f520(&param_1,bVar2);
  *unaff_ESI = *puVar4;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}

