
void FUN_00750290(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x1490) - *(int *)(unaff_ESI + 0x148c) >> 2;
  iVar2 = 0;
  if (0 < iVar1) {
    piVar3 = *(int **)(unaff_ESI + 0x148c);
    do {
      if (*piVar3 == param_1) {
        piVar3 = *(int **)(unaff_ESI + 0x148c) + iVar2;
        FID_conflict__memcpy
                  (piVar3,piVar3 + 1,(*(int *)(unaff_ESI + 0x1490) - (int)(piVar3 + 1) >> 2) * 4);
        *(int *)(unaff_ESI + 0x1490) = *(int *)(unaff_ESI + 0x1490) + -4;
        break;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar1);
  }
  iVar2 = 0;
  iVar1 = *(int *)(unaff_ESI + 0x14a0) - *(int *)(unaff_ESI + 0x149c) >> 2;
  if (0 < iVar1) {
    piVar3 = *(int **)(unaff_ESI + 0x149c);
    while (*piVar3 != param_1) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (iVar1 <= iVar2) {
        return;
      }
    }
    piVar3 = *(int **)(unaff_ESI + 0x149c) + iVar2;
    FID_conflict__memcpy
              (piVar3,piVar3 + 1,(*(int *)(unaff_ESI + 0x14a0) - (int)(piVar3 + 1) >> 2) * 4);
    *(int *)(unaff_ESI + 0x14a0) = *(int *)(unaff_ESI + 0x14a0) + -4;
  }
  return;
}

