
int * FUN_00721130(void)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  piVar2 = (int *)FUN_00721080();
  iVar4 = in_EAX[5];
  while( true ) {
    if (iVar4 != 0x14) {
      return piVar2;
    }
    uVar6 = in_EAX[4] - in_EAX[3];
    uVar3 = 0;
    if (uVar6 != 0) {
      do {
        if ((&DAT_00c42ce0)[uVar3] != *(char *)(in_EAX[3] + uVar3)) {
          return piVar2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar6);
    }
    if ((&DAT_00c42ce0)[uVar6] != '\0') {
      return piVar2;
    }
    FUN_0071d0d0();
    iVar4 = FUN_00721080();
    piVar1 = (int *)*in_EAX;
    uVar3 = piVar1[1] + 0x18;
    if (uVar3 < 0x1001) {
      piVar5 = (int *)(*piVar1 + 4 + piVar1[1]);
      piVar1[1] = uVar3;
    }
    else {
      piVar5 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar5 == (int *)0x0) break;
      *piVar5 = *piVar1;
      *piVar1 = (int)piVar5;
      piVar1[1] = 0x18;
      piVar5 = piVar5 + 1;
    }
    if (piVar5 == (int *)0x0) break;
    *piVar5 = 0x401;
    piVar5[1] = (int)piVar2;
    piVar5[2] = iVar4;
    piVar5[3] = 0;
    iVar4 = in_EAX[5];
    piVar2 = piVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0071f670();
}

