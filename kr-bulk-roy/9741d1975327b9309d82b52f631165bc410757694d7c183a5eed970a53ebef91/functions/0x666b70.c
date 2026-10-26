
undefined4 FUN_00666b70(void)

{
  uint uVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  int *unaff_ESI;
  
  piVar2 = (int *)unaff_ESI[0x2a];
  while( true ) {
    if (piVar2 == (int *)unaff_ESI[0x2b]) {
      return 0;
    }
    if (*piVar2 == in_ECX) break;
    piVar2 = piVar2 + 1;
  }
  if (unaff_ESI[0x37] == *piVar2) {
    unaff_ESI[0x37] = 0;
  }
  iVar3 = unaff_ESI[0x39];
  uVar1 = *(uint *)(*piVar2 + 0x20);
  (**(code **)(*unaff_ESI + 0x74))(*piVar2);
  FUN_00443d10();
  FID_conflict__memcpy(piVar2,piVar2 + 1,(unaff_ESI[0x2b] - (int)(piVar2 + 1) >> 2) * 4);
  unaff_ESI[0x2b] = unaff_ESI[0x2b] + -4;
  if (iVar3 - 1U <= uVar1) {
    uVar1 = 0;
    unaff_ESI[0x39] = 0;
    iVar3 = unaff_ESI[0x2b] - unaff_ESI[0x2a] >> 2;
    if (0 < iVar3) {
      piVar2 = (int *)unaff_ESI[0x2a];
      do {
        uVar1 = uVar1 + 1;
        if (uVar1 <= *(uint *)(*piVar2 + 0x20)) {
          uVar1 = *(uint *)(*piVar2 + 0x20);
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
        unaff_ESI[0x39] = uVar1;
      } while (iVar3 != 0);
    }
  }
  return 1;
}

