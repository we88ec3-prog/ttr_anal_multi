
int * FUN_00721080(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *unaff_EDI;
  
  piVar4 = (int *)FUN_00720fa0();
  do {
    iVar2 = unaff_EDI[5];
    if ((iVar2 != 1) && (iVar2 != 2)) {
      return piVar4;
    }
    FUN_0071d0d0();
    iVar5 = FUN_00720fa0();
    piVar3 = (int *)*unaff_EDI;
    uVar1 = piVar3[1] + 0x18;
    if (uVar1 < 0x1001) {
      piVar6 = (int *)(*piVar3 + 4 + piVar3[1]);
      piVar3[1] = uVar1;
    }
    else {
      piVar6 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar6 == (int *)0x0) {
LAB_00721128:
                    /* WARNING: Subroutine does not return */
        FUN_0071f670();
      }
      *piVar6 = *piVar3;
      *piVar3 = (int)piVar6;
      piVar3[1] = 0x18;
      piVar6 = piVar6 + 1;
    }
    if (piVar6 == (int *)0x0) goto LAB_00721128;
    *(char *)piVar6 = (iVar2 != 1) + '\x02';
    *(undefined2 *)((int)piVar6 + 1) = 4;
    *(undefined1 *)((int)piVar6 + 3) = 0;
    piVar6[1] = (int)piVar4;
    piVar6[2] = iVar5;
    piVar6[3] = 0;
    piVar4 = piVar6;
  } while( true );
}

