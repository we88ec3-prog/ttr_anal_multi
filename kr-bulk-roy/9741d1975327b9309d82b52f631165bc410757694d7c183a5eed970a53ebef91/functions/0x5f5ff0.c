
undefined4 FUN_005f5ff0(void)

{
  int *piVar1;
  code *pcVar2;
  int in_EAX;
  int iVar3;
  int *unaff_EDI;
  
  if (0 < in_EAX) {
    iVar3 = (**(code **)(*unaff_EDI + 0x198))();
    if (in_EAX <= iVar3) {
      piVar1 = *(int **)(unaff_EDI[0x3d] + -4 + in_EAX * 4);
      if ((char)piVar1[0xb3] != '\0') {
        pcVar2 = *(code **)(*piVar1 + 0x90);
        *(undefined1 *)(piVar1 + 0xb3) = 0;
        (*pcVar2)(1);
        if ((piVar1[0x97] != 0) && (*(char *)((int)piVar1 + 0x2a1) == '\0')) {
          piVar1[10] = piVar1[10] | 8;
          return 1;
        }
        if ((piVar1[10] & 8U) != 0) {
          piVar1[10] = piVar1[10] ^ 8;
        }
      }
      return 1;
    }
  }
  return 0;
}

