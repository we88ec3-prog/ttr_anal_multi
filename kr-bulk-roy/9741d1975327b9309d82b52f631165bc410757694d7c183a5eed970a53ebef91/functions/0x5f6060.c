
void FUN_005f6060(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = 0;
  iVar3 = (**(code **)(*unaff_EDI + 0x198))();
  if (0 < iVar3) {
    do {
      piVar1 = *(int **)(unaff_EDI[0x3d] + iVar4 * 4);
      if ((char)piVar1[0xb3] != '\0') {
        pcVar2 = *(code **)(*piVar1 + 0x90);
        *(undefined1 *)(piVar1 + 0xb3) = 0;
        (*pcVar2)(1);
        if ((piVar1[0x97] == 0) || (*(char *)((int)piVar1 + 0x2a1) != '\0')) {
          if ((piVar1[10] & 8U) != 0) {
            piVar1[10] = piVar1[10] ^ 8;
          }
        }
        else {
          piVar1[10] = piVar1[10] | 8;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = (**(code **)(*unaff_EDI + 0x198))();
    } while (iVar4 < iVar3);
  }
  return;
}

