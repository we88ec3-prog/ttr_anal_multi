
int * FUN_00720bf0(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  
  piVar3 = (int *)FUN_00720b00(in_ECX);
  iVar4 = in_ECX[5];
  while( true ) {
    if (iVar4 != 10) {
      return piVar3;
    }
    FUN_0071d0d0();
    iVar4 = FUN_00720bf0();
    if ((*(char *)((int)piVar3 + 1) != '\x01') || (*(char *)(iVar4 + 1) != '\x01')) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    piVar2 = (int *)*in_ECX;
    uVar1 = piVar2[1] + 0x18;
    if (uVar1 < 0x1001) {
      piVar5 = (int *)(*piVar2 + 4 + piVar2[1]);
      piVar2[1] = uVar1;
    }
    else {
      piVar5 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar5 == (int *)0x0) break;
      *piVar5 = *piVar2;
      *piVar2 = (int)piVar5;
      piVar2[1] = 0x18;
      piVar5 = piVar5 + 1;
    }
    if (piVar5 == (int *)0x0) break;
    *piVar5 = 0x10e;
    piVar5[1] = (int)piVar3;
    piVar5[2] = iVar4;
    piVar5[3] = 0;
    iVar4 = in_ECX[5];
    piVar3 = piVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0071f670();
}

