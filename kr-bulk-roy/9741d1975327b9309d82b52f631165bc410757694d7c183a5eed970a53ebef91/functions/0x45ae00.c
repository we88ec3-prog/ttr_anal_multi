
uint FUN_0045ae00(int param_1)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int unaff_EDI;
  
  uVar4 = 0;
  uVar5 = *(int *)(unaff_EDI + 0xf4) - *(int *)(unaff_EDI + 0xf0) >> 2;
  if (uVar5 != 0) {
    in_EAX = *(int **)(unaff_EDI + 0xf0);
    do {
      if (*(char *)(*in_EAX + 0x2a4) == '\0') {
        iVar1 = *(int *)(*(int *)(unaff_EDI + 0xec) + 0xcc);
        if (iVar1 != 0) {
          for (piVar2 = *(int **)(iVar1 + 0xa8); piVar2 != *(int **)(iVar1 + 0xac);
              piVar2 = piVar2 + 1) {
            iVar3 = *piVar2;
            if (*(uint *)(iVar3 + 0x20) == uVar4) goto LAB_0045ae70;
          }
        }
        iVar3 = 0;
LAB_0045ae70:
        if (*(int *)(iVar3 + 0x20) == param_1) {
          iVar1 = *(int *)(*(int *)(unaff_EDI + 0xf0) + uVar4 * 4);
          in_EAX = (int *)(iVar1 + 0x2b0);
          if ((*(int *)(iVar1 + 0x2c0) != -1) && (*(int *)(iVar1 + 0x2c4) != -1)) {
            return CONCAT31((int3)((uint)in_EAX >> 8),1);
          }
          break;
        }
      }
      uVar4 = uVar4 + 1;
      in_EAX = in_EAX + 1;
    } while (uVar4 < uVar5);
  }
  return (uint)in_EAX & 0xffffff00;
}

