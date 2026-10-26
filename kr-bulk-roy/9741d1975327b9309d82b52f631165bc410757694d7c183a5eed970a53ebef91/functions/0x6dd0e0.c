
undefined4 FUN_006dd0e0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_EAX;
  int *unaff_EDI;
  
  if (*(int *)(in_EAX + 0x10) != 0) {
    piVar1 = *(int **)(*(int *)(in_EAX + 0x10) + 0x60);
    piVar2 = (int *)*piVar1;
    while (piVar2 != piVar1) {
      if (piVar2[4] == 8) {
        uVar3 = piVar2[6];
        *unaff_EDI = (int)(short)uVar3;
        unaff_EDI[1] = uVar3 >> 0x10 & 0xff;
        unaff_EDI[2] = 8;
        return 1;
      }
      FUN_0085e240();
    }
  }
  return 0;
}

