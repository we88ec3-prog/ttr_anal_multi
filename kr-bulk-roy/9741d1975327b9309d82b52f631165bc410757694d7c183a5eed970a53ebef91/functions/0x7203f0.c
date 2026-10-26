
int * FUN_007203f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  undefined1 *puVar6;
  int *piVar7;
  
  piVar5 = (int *)FUN_007201a0(param_1);
  iVar2 = param_1[5];
  do {
    if (iVar2 != 0x12) {
      return piVar5;
    }
    FUN_0071d0d0();
    puVar6 = (undefined1 *)FUN_00721210();
    if (*(char *)((int)piVar5 + 1) != '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    if (puVar6[1] == '\x02') {
switchD_0072044a_caseD_16:
      cVar4 = '\0';
    }
    else {
      switch(*puVar6) {
      default:
        if ((*(int *)(puVar6 + 4) != 0) && (cVar4 = FUN_0071f590(), cVar4 == '\0'))
        goto switchD_0072044a_caseD_16;
        for (iVar2 = *(int *)(puVar6 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
          cVar4 = FUN_0071f590();
          if (cVar4 == '\0') goto switchD_0072044a_caseD_16;
        }
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x38:
      case 0x39:
        cVar4 = '\x01';
        break;
      case 0x16:
        goto switchD_0072044a_caseD_16;
      }
    }
    piVar3 = (int *)*param_1;
    uVar1 = piVar3[1] + 0x18;
    if (uVar1 < 0x1001) {
      piVar7 = (int *)(*piVar3 + 4 + piVar3[1]);
      piVar3[1] = uVar1;
    }
    else {
      piVar7 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar7 == (int *)0x0) goto LAB_00720524;
      *piVar7 = *piVar3;
      *piVar3 = (int)piVar7;
      piVar3[1] = 0x18;
      piVar7 = piVar7 + 1;
    }
    if (piVar7 == (int *)0x0) {
LAB_00720524:
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    *(char *)piVar7 = cVar4 + '\x10';
    *(undefined2 *)((int)piVar7 + 1) = 1;
    *(undefined1 *)((int)piVar7 + 3) = 0;
    piVar7[1] = (int)piVar5;
    piVar7[2] = (int)puVar6;
    piVar7[3] = 0;
    if (param_1[5] != 0x13) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    FUN_0071d0d0();
    iVar2 = param_1[5];
    piVar5 = piVar7;
  } while( true );
}

