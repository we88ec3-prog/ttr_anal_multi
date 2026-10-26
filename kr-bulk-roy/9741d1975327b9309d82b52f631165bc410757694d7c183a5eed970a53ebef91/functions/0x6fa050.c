
void FUN_006fa050(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x30);
  if (piVar1 != (int *)0x0) {
    do {
      piVar1 = (int *)*piVar1;
      *(byte *)((int)piVar1 + 5) = *(byte *)((int)piVar1 + 5) & 0xf8;
      switch(*(undefined1 *)(piVar1 + 1)) {
      default:
        goto switchD_006fa07b_caseD_4;
      case 5:
        piVar1[6] = *(undefined4 *)(unaff_EDI + 0x24);
        break;
      case 6:
        piVar1[2] = *(undefined4 *)(unaff_EDI + 0x24);
        break;
      case 7:
        *(byte *)((int)piVar1 + 5) = *(byte *)((int)piVar1 + 5) | 4;
        if ((piVar1[2] != 0) && ((*(byte *)(piVar1[2] + 5) & 3) != 0)) {
          FUN_006f9f70();
        }
        if ((*(byte *)(piVar1[3] + 5) & 3) != 0) {
          FUN_006f9f70();
        }
        goto switchD_006fa07b_caseD_4;
      case 8:
        piVar1[0x1b] = *(undefined4 *)(unaff_EDI + 0x24);
        break;
      case 9:
        piVar1[0x11] = *(undefined4 *)(unaff_EDI + 0x24);
        break;
      case 10:
        if ((3 < ((int *)piVar1[2])[2]) && ((*(byte *)(*(int *)piVar1[2] + 5) & 3) != 0)) {
          FUN_006f9f70();
        }
        if ((int *)piVar1[2] == piVar1 + 4) {
          *(byte *)((int)piVar1 + 5) = *(byte *)((int)piVar1 + 5) | 4;
        }
        goto switchD_006fa07b_caseD_4;
      }
      *(int **)(unaff_EDI + 0x24) = piVar1;
switchD_006fa07b_caseD_4:
    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x30));
  }
  return;
}

