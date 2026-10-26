
void FUN_008711c0(undefined4 *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_EAX;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *unaff_EDI;
  
  if (0x7fffffd < DAT_00fe351c) {
    if (0xf < (uint)unaff_EDI[8]) {
      FUN_0089120c(unaff_EDI[3]);
    }
    unaff_EDI[8] = 0xf;
    unaff_EDI[7] = 0;
    *(undefined1 *)(unaff_EDI + 3) = 0;
    FUN_0089120c();
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  DAT_00fe351c = DAT_00fe351c + 1;
  unaff_EDI[1] = (int)in_EAX;
  if (in_EAX == DAT_00fe3518) {
    DAT_00fe3518[1] = (int)unaff_EDI;
    *DAT_00fe3518 = (int)unaff_EDI;
    DAT_00fe3518[2] = (int)unaff_EDI;
  }
  else if (param_2 == '\0') {
    in_EAX[2] = (int)unaff_EDI;
    if (in_EAX == (int *)DAT_00fe3518[2]) {
      DAT_00fe3518[2] = (int)unaff_EDI;
    }
  }
  else {
    *in_EAX = (int)unaff_EDI;
    if (in_EAX == (int *)*DAT_00fe3518) {
      *DAT_00fe3518 = (int)unaff_EDI;
    }
  }
  cVar1 = *(char *)(unaff_EDI[1] + 0x2c);
  piVar6 = unaff_EDI;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(DAT_00fe3518[1] + 0x2c) = 1;
      *param_1 = unaff_EDI;
      return;
    }
    piVar4 = (int *)piVar6[1];
    piVar5 = (int *)piVar4[1];
    if (piVar4 == (int *)*piVar5) {
      iVar2 = piVar5[2];
      if (*(char *)(iVar2 + 0x2c) == '\0') {
        *(undefined1 *)(piVar4 + 0xb) = 1;
        *(undefined1 *)(iVar2 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
      else {
        if (piVar6 == (int *)piVar4[2]) {
          FUN_0085f4f0();
          piVar6 = piVar4;
        }
        *(undefined1 *)(piVar6[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;
        piVar4 = *(int **)(piVar6[1] + 4);
        piVar5 = (int *)*piVar4;
        *piVar4 = piVar5[2];
        if (*(char *)(piVar5[2] + 0x2d) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar4;
        }
        piVar5[1] = piVar4[1];
        if (piVar4 == (int *)DAT_00fe3518[1]) {
          DAT_00fe3518[1] = (int)piVar5;
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
LAB_0087137f:
        piVar4[1] = (int)piVar5;
      }
    }
    else {
      iVar2 = *piVar5;
      if (*(char *)(iVar2 + 0x2c) != '\0') {
        if (piVar6 == (int *)*piVar4) {
          FUN_0085f540();
          piVar6 = piVar4;
        }
        *(undefined1 *)(piVar6[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;
        piVar4 = *(int **)(piVar6[1] + 4);
        piVar5 = (int *)piVar4[2];
        piVar4[2] = *piVar5;
        if (*(char *)(*piVar5 + 0x2d) == '\0') {
          *(int **)(*piVar5 + 4) = piVar4;
        }
        piVar5[1] = piVar4[1];
        if (piVar4 == (int *)DAT_00fe3518[1]) {
          DAT_00fe3518[1] = (int)piVar5;
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
        goto LAB_0087137f;
      }
      *(undefined1 *)(piVar4 + 0xb) = 1;
      *(undefined1 *)(iVar2 + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;
      piVar6 = *(int **)(piVar6[1] + 4);
    }
    cVar1 = *(char *)(piVar6[1] + 0x2c);
  } while( true );
}

