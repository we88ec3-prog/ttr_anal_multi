
void FUN_00536cb0(undefined4 *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_EAX;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *unaff_EDI;
  
  if (0x71c71c5 < DAT_00fe36f8) {
    if (7 < (uint)unaff_EDI[9]) {
      FUN_0089120c(unaff_EDI[4]);
    }
    unaff_EDI[9] = 7;
    unaff_EDI[8] = 0;
    *(undefined2 *)(unaff_EDI + 4) = 0;
    FUN_0089120c();
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  DAT_00fe36f8 = DAT_00fe36f8 + 1;
  unaff_EDI[1] = (int)in_EAX;
  if (in_EAX == DAT_00fe36f4) {
    DAT_00fe36f4[1] = (int)unaff_EDI;
    *DAT_00fe36f4 = (int)unaff_EDI;
    DAT_00fe36f4[2] = (int)unaff_EDI;
  }
  else if (param_2 == '\0') {
    in_EAX[2] = (int)unaff_EDI;
    if (in_EAX == (int *)DAT_00fe36f4[2]) {
      DAT_00fe36f4[2] = (int)unaff_EDI;
    }
  }
  else {
    *in_EAX = (int)unaff_EDI;
    if (in_EAX == (int *)*DAT_00fe36f4) {
      *DAT_00fe36f4 = (int)unaff_EDI;
    }
  }
  cVar1 = *(char *)(unaff_EDI[1] + 0x30);
  piVar6 = unaff_EDI;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(DAT_00fe36f4[1] + 0x30) = 1;
      *param_1 = unaff_EDI;
      return;
    }
    piVar4 = (int *)piVar6[1];
    piVar5 = (int *)piVar4[1];
    if (piVar4 == (int *)*piVar5) {
      iVar2 = piVar5[2];
      if (*(char *)(iVar2 + 0x30) == '\0') {
        *(undefined1 *)(piVar4 + 0xc) = 1;
        *(undefined1 *)(iVar2 + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x30) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
      else {
        if (piVar6 == (int *)piVar4[2]) {
          FUN_00536b20();
          piVar6 = piVar4;
        }
        *(undefined1 *)(piVar6[1] + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x30) = 0;
        piVar4 = *(int **)(piVar6[1] + 4);
        piVar5 = (int *)*piVar4;
        *piVar4 = piVar5[2];
        if (*(char *)(piVar5[2] + 0x31) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar4;
        }
        piVar5[1] = piVar4[1];
        if (piVar4 == (int *)DAT_00fe36f4[1]) {
          DAT_00fe36f4[1] = (int)piVar5;
          piVar5[2] = (int)piVar4;
        }
        else {
          piVar3 = (int *)piVar4[1];
          if (piVar4 == (int *)piVar3[2]) {
            piVar3[2] = (int)piVar5;
            piVar5[2] = (int)piVar4;
          }
          else {
            *piVar3 = (int)piVar5;
            piVar5[2] = (int)piVar4;
          }
        }
LAB_00536e73:
        piVar4[1] = (int)piVar5;
      }
    }
    else {
      iVar2 = *piVar5;
      if (*(char *)(iVar2 + 0x30) != '\0') {
        if (piVar6 == (int *)*piVar4) {
          FUN_00536b70();
          piVar6 = piVar4;
        }
        *(undefined1 *)(piVar6[1] + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x30) = 0;
        piVar4 = *(int **)(piVar6[1] + 4);
        piVar5 = (int *)piVar4[2];
        piVar4[2] = *piVar5;
        if (*(char *)(*piVar5 + 0x31) == '\0') {
          *(int **)(*piVar5 + 4) = piVar4;
        }
        piVar5[1] = piVar4[1];
        if (piVar4 == (int *)DAT_00fe36f4[1]) {
          DAT_00fe36f4[1] = (int)piVar5;
        }
        else {
          piVar3 = (int *)piVar4[1];
          if (piVar4 == (int *)*piVar3) {
            *piVar3 = (int)piVar5;
          }
          else {
            piVar3[2] = (int)piVar5;
          }
        }
        *piVar5 = (int)piVar4;
        goto LAB_00536e73;
      }
      *(undefined1 *)(piVar4 + 0xc) = 1;
      *(undefined1 *)(iVar2 + 0x30) = 1;
      *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x30) = 0;
      piVar6 = *(int **)(piVar6[1] + 4);
    }
    cVar1 = *(char *)(piVar6[1] + 0x30);
  } while( true );
}

