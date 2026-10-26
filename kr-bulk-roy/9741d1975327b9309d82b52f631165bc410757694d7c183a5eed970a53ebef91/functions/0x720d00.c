
int * FUN_00720d00(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  
  if (param_1[5] == 8) {
    FUN_0071d0d0();
    iVar4 = FUN_00720cb0();
    piVar5 = (int *)FUN_0071bdb0();
    if (piVar5 == (int *)0x0) {
LAB_00720d35:
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    *piVar5 = 0x20d;
    piVar5[1] = iVar4;
    piVar5[2] = 0;
    piVar5[3] = 0;
  }
  else {
    piVar5 = (int *)FUN_00720bf0();
  }
  do {
    if (param_1[5] == 9) {
      cVar3 = '\n';
    }
    else {
      if (param_1[5] != 0x14) {
        return piVar5;
      }
      pcVar1 = (char *)param_1[3];
      uVar6 = param_1[4] - (int)pcVar1;
      uVar9 = 0;
      if (uVar6 != 0) {
        do {
          if ((&DAT_00c43168)[uVar9] != pcVar1[uVar9]) goto LAB_00720d9e;
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar6);
      }
      if ((&DAT_00c43168)[uVar6] != '\0') {
LAB_00720d9e:
        uVar9 = 0;
        if (uVar6 != 0) {
          do {
            if ((&DAT_00c44988)[uVar9] != pcVar1[uVar9]) {
              return piVar5;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar6);
        }
        if ((&DAT_00c44988)[uVar6] != '\0') {
          return piVar5;
        }
      }
      cVar3 = (*pcVar1 != 'd') + '\v';
    }
    FUN_0071d0d0();
    if (param_1[5] == 8) {
      FUN_0071d0d0();
      iVar4 = FUN_00720cb0();
      piVar2 = (int *)*param_1;
      uVar6 = piVar2[1] + 0x18;
      if (uVar6 < 0x1001) {
        piVar7 = (int *)(piVar2[1] + 4 + *piVar2);
        piVar2[1] = uVar6;
      }
      else {
        piVar7 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
        if (piVar7 == (int *)0x0) goto LAB_00720d35;
        *piVar7 = *piVar2;
        *piVar2 = (int)piVar7;
        piVar2[1] = 0x18;
        piVar7 = piVar7 + 1;
      }
      if (piVar7 == (int *)0x0) goto LAB_00720d35;
      *piVar7 = 0x20d;
      piVar7[1] = iVar4;
      piVar7[2] = 0;
      piVar7[3] = 0;
    }
    else {
      piVar7 = (int *)FUN_00720bf0();
    }
    piVar2 = (int *)*param_1;
    uVar6 = piVar2[1] + 0x18;
    if (uVar6 < 0x1001) {
      piVar8 = (int *)(piVar2[1] + 4 + *piVar2);
      piVar2[1] = uVar6;
    }
    else {
      piVar8 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar8 == (int *)0x0) goto LAB_00720d35;
      *piVar8 = *piVar2;
      *piVar2 = (int)piVar8;
      piVar2[1] = 0x18;
      piVar8 = piVar8 + 1;
    }
    if (piVar8 == (int *)0x0) goto LAB_00720d35;
    *(char *)piVar8 = cVar3;
    *(undefined2 *)((int)piVar8 + 1) = 2;
    *(undefined1 *)((int)piVar8 + 3) = 0;
    piVar8[1] = (int)piVar5;
    piVar8[2] = (int)piVar7;
    piVar8[3] = 0;
    piVar5 = piVar8;
  } while( true );
}

