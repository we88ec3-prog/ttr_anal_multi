
void FUN_00466b20(undefined4 *param_1,char param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_EAX;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  
  if (0x3fffffd < *(uint *)(unaff_EDI + 8)) {
    if (7 < (uint)param_3[0xc]) {
      FUN_0089120c(param_3[7]);
    }
    param_3[0xc] = 7;
    param_3[0xb] = 0;
    *(undefined2 *)(param_3 + 7) = 0;
    FUN_0089120c(param_3);
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) + 1;
  param_3[1] = (int)in_EAX;
  if (in_EAX == *(undefined4 **)(unaff_EDI + 4)) {
    (*(undefined4 **)(unaff_EDI + 4))[1] = param_3;
    **(undefined4 **)(unaff_EDI + 4) = param_3;
    iVar4 = *(int *)(unaff_EDI + 4);
  }
  else {
    if (param_2 != '\0') {
      *in_EAX = param_3;
      if (in_EAX == (undefined4 *)**(int **)(unaff_EDI + 4)) {
        **(int **)(unaff_EDI + 4) = (int)param_3;
      }
      goto LAB_00466bab;
    }
    in_EAX[2] = param_3;
    iVar4 = *(int *)(unaff_EDI + 4);
    if (in_EAX != *(undefined4 **)(iVar4 + 8)) goto LAB_00466bab;
  }
  *(int **)(iVar4 + 8) = param_3;
LAB_00466bab:
  cVar1 = *(char *)(param_3[1] + 0x4c);
  piVar5 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(unaff_EDI + 4) + 4) + 0x4c) = 1;
      *param_1 = param_3;
      return;
    }
    piVar2 = (int *)piVar5[1];
    piVar3 = (int *)piVar2[1];
    if (piVar2 == (int *)*piVar3) {
      iVar4 = piVar3[2];
      if (*(char *)(iVar4 + 0x4c) == '\0') {
LAB_00466c08:
        *(undefined1 *)(piVar2 + 0x13) = 1;
        *(undefined1 *)(iVar4 + 0x4c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x4c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar2[2]) {
          FUN_00529790(unaff_EDI);
          piVar5 = piVar2;
        }
        *(undefined1 *)(piVar5[1] + 0x4c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x4c) = 0;
        FUN_005297f0(unaff_EDI);
      }
    }
    else {
      iVar4 = *piVar3;
      if (*(char *)(iVar4 + 0x4c) == '\0') goto LAB_00466c08;
      if (piVar5 == (int *)*piVar2) {
        FUN_005297f0(unaff_EDI);
        piVar5 = piVar2;
      }
      *(undefined1 *)(piVar5[1] + 0x4c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x4c) = 0;
      iVar4 = *(int *)(piVar5[1] + 4);
      piVar2 = *(int **)(iVar4 + 8);
      *(int *)(iVar4 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x4d) == '\0') {
        *(int *)(*piVar2 + 4) = iVar4;
      }
      piVar2[1] = *(int *)(iVar4 + 4);
      if (iVar4 == *(int *)(*(int *)(unaff_EDI + 4) + 4)) {
        *(int **)(*(int *)(unaff_EDI + 4) + 4) = piVar2;
      }
      else {
        piVar3 = *(int **)(iVar4 + 4);
        if (iVar4 == *piVar3) {
          *piVar3 = (int)piVar2;
        }
        else {
          piVar3[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar4;
      *(int **)(iVar4 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar5[1] + 0x4c);
  } while( true );
}

