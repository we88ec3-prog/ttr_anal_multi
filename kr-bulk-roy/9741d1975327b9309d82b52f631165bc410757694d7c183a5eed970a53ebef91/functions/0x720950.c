
int * FUN_00720950(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 in_EAX;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)FUN_00720570(param_1,in_EAX);
  do {
    iVar2 = param_1[5];
    if ((iVar2 != 0x10) && (iVar2 != 0x11)) {
      return piVar4;
    }
    FUN_0071d0d0();
    piVar5 = piVar4;
    if (iVar2 == 0x11) {
      piVar3 = (int *)*param_1;
      iVar2 = piVar3[1];
      uVar1 = iVar2 + 0x18;
      if (uVar1 < 0x1001) {
        piVar3[1] = uVar1;
        piVar5 = (int *)(*piVar3 + 4 + iVar2);
      }
      else {
        piVar5 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
        if (piVar5 == (int *)0x0) goto LAB_007209f3;
        *piVar5 = *piVar3;
        *piVar3 = (int)piVar5;
        piVar3[1] = 0x18;
        piVar5 = piVar5 + 1;
      }
      if (piVar5 == (int *)0x0) {
LAB_007209f3:
                    /* WARNING: Subroutine does not return */
        FUN_0071f670();
      }
      piVar5[1] = (int)piVar4;
      *piVar5 = 0x2050138;
      piVar5[2] = 0;
      piVar5[3] = 0;
      piVar5[4] = 0;
    }
    piVar4 = (int *)FUN_00720570(param_1,piVar5);
  } while( true );
}

