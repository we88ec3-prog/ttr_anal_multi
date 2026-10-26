
undefined4 FUN_0054a2d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  cVar1 = *(char *)(unaff_ESI + 0x84 + *(int *)(unaff_ESI + 0x10c) * 0x10);
  iVar2 = *(int *)(unaff_ESI + 0x6c);
  if (iVar2 == 0) {
    if (cVar1 != '\0') {
      if (cVar1 != '\x01') {
        if (cVar1 != '\x02') {
          return 0;
        }
LAB_0054a36a:
        piVar3 = *(int **)(unaff_ESI + 0x58);
        goto LAB_0054a306;
      }
      goto LAB_0054a36f;
    }
  }
  else if (iVar2 == 1) {
    if (cVar1 == '\0') goto LAB_0054a36f;
    if (cVar1 != '\x01') {
      if (cVar1 != '\x02') {
        return 0;
      }
      piVar3 = *(int **)(unaff_ESI + 0x58);
      goto LAB_0054a306;
    }
  }
  else {
    if (iVar2 != 2) {
      return 0;
    }
    if (cVar1 == '\0') {
LAB_0054a36f:
      piVar3 = *(int **)(unaff_ESI + 0x50);
      goto LAB_0054a306;
    }
    if (cVar1 == '\x01') goto LAB_0054a36a;
    if (cVar1 != '\x02') {
      return 0;
    }
  }
  piVar3 = *(int **)(unaff_ESI + 0x54);
LAB_0054a306:
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x70))();
    if (iVar2 <= (int)(uint)*(byte *)(unaff_ESI + 0x83 + *(int *)(unaff_ESI + 0x10c) * 0x10)) {
      FUN_0054a790();
      *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 5;
      return 0;
    }
    if (*(int *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) == 5) {
      *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 1;
    }
  }
  return 0;
}

