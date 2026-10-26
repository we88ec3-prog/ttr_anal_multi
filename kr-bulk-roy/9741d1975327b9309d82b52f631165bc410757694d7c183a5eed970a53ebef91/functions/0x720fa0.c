
int * FUN_00720fa0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *in_EAX;
  int *piVar4;
  int iVar5;
  int *piVar6;
  char cVar7;
  
  piVar4 = (int *)FUN_00720ef0();
  do {
    iVar2 = in_EAX[5];
    if ((((iVar2 != 3) && (iVar2 != 5)) && (iVar2 != 4)) && (iVar2 != 6)) {
      return piVar4;
    }
    FUN_0071d0d0();
    iVar5 = FUN_00720ef0();
    piVar3 = (int *)*in_EAX;
    uVar1 = piVar3[1] + 0x18;
    if (uVar1 < 0x1001) {
      piVar6 = (int *)(*piVar3 + 4 + piVar3[1]);
      piVar3[1] = uVar1;
    }
    else {
      piVar6 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar6 == (int *)0x0) {
LAB_0072106c:
                    /* WARNING: Subroutine does not return */
        FUN_0071f670();
      }
      *piVar6 = *piVar3;
      *piVar3 = (int)piVar6;
      piVar3[1] = 0x18;
      piVar6 = piVar6 + 1;
    }
    if (piVar6 == (int *)0x0) goto LAB_0072106c;
    if (iVar2 == 3) {
      cVar7 = '\x04';
    }
    else if (iVar2 == 4) {
      cVar7 = '\x05';
    }
    else {
      cVar7 = (iVar2 != 5) + '\x06';
    }
    *(char *)piVar6 = cVar7;
    *(undefined2 *)((int)piVar6 + 1) = 4;
    *(undefined1 *)((int)piVar6 + 3) = 0;
    piVar6[1] = (int)piVar4;
    piVar6[2] = iVar5;
    piVar6[3] = 0;
    piVar4 = piVar6;
  } while( true );
}

