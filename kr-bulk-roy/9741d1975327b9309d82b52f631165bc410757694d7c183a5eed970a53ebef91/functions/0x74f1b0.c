
void FUN_0074f1b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  
  iVar1 = (int)param_1;
  iVar3 = 0;
  do {
    iVar2 = *(int *)(iVar1 + 0xfc + *(int *)(iVar1 + 0x1338 + iVar3 * 4) * 4);
    if ((iVar2 == 1) && (unaff_ESI == *(int **)(iVar1 + 0x13cc))) {
      param_1 = (int *)FUN_00891268(0x14);
      if (param_1 == (int *)0x0) {
LAB_0074f27d:
        param_1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x1344 + iVar3 * 0x18);
LAB_0074f238:
        *param_1 = (int)FoxUI::FXUIEvent::vftable;
        param_1[1] = unaff_ESI[8];
        param_1[2] = unaff_ESI[0x12];
        param_1[3] = (int)unaff_ESI;
        param_1[4] = iVar2;
      }
      (**(code **)(*unaff_ESI + 0x140))(param_1);
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 0x10))(1);
      }
    }
    else {
      if (iVar2 == 3) {
        if (iVar3 == 0) {
          if (*(char *)(iVar1 + 0x13d8) != '\0') {
LAB_0074f263:
            param_1 = (int *)FUN_00891268(0x14);
            if (param_1 == (int *)0x0) goto LAB_0074f27d;
            iVar2 = *(int *)(iVar1 + 0x1348 + iVar3 * 0x18);
            goto LAB_0074f238;
          }
        }
        else if ((iVar3 == 1) && (*(char *)(iVar1 + 0x13d8) == '\0')) goto LAB_0074f263;
      }
      if ((iVar2 == 6) && (unaff_ESI == *(int **)(iVar1 + 0x13cc))) {
        param_1 = (int *)FUN_00891268(0x14);
        if (param_1 == (int *)0x0) goto LAB_0074f27d;
        iVar2 = *(int *)(iVar1 + 0x134c + iVar3 * 0x18);
        goto LAB_0074f238;
      }
    }
    iVar2 = *(int *)(iVar1 + 0x108 + *(int *)(iVar1 + 0x1338 + iVar3 * 4) * 4);
    if (iVar2 == 4) {
      if (iVar3 != 0) {
        if ((iVar3 == 1) && (*(char *)(iVar1 + 0x13d8) == '\0')) goto LAB_0074f332;
        goto LAB_0074f2c4;
      }
      if (*(char *)(iVar1 + 0x13d8) == '\0') goto LAB_0074f2c4;
LAB_0074f332:
      param_1 = (int *)FUN_00891268(0x14);
      if (param_1 != (int *)0x0) {
        iVar2 = *(int *)(iVar1 + (iVar3 * 3 + 0x26a) * 8);
        goto LAB_0074f307;
      }
LAB_0074f374:
      param_1 = (int *)0x0;
LAB_0074f37b:
      (**(code **)(*unaff_ESI + 0x140))(param_1);
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 0x10))(1);
      }
    }
    else {
LAB_0074f2c4:
      if (iVar2 == 5) {
        if (iVar3 != 0) {
          if ((iVar3 == 1) && (*(char *)(iVar1 + 0x13d8) == '\0')) goto LAB_0074f35a;
          goto LAB_0074f2da;
        }
        if (*(char *)(iVar1 + 0x13d8) == '\0') goto LAB_0074f2da;
LAB_0074f35a:
        param_1 = (int *)FUN_00891268(0x14);
        if (param_1 == (int *)0x0) goto LAB_0074f374;
        iVar2 = *(int *)(iVar1 + 0x1354 + iVar3 * 0x18);
LAB_0074f307:
        *param_1 = (int)FoxUI::FXUIEvent::vftable;
        param_1[1] = unaff_ESI[8];
        param_1[2] = unaff_ESI[0x12];
        param_1[3] = (int)unaff_ESI;
        param_1[4] = iVar2;
        goto LAB_0074f37b;
      }
LAB_0074f2da:
      if ((iVar2 == 2) && (unaff_ESI == *(int **)(iVar1 + 0x13cc))) {
        param_1 = (int *)FUN_00891268(0x14);
        if (param_1 == (int *)0x0) goto LAB_0074f374;
        iVar2 = *(int *)(iVar1 + 0x1358 + iVar3 * 0x18);
        goto LAB_0074f307;
      }
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return;
    }
  } while( true );
}

