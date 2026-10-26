
void FUN_008454f0(undefined4 *param_1,char param_2,int *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *in_EAX;
  int iVar5;
  int *piVar6;
  int unaff_EDI;
  
  if (0x1ffffffd < *(uint *)(unaff_EDI + 8)) {
    puVar2 = (undefined4 *)param_3[4];
    if (puVar2 != (undefined4 *)0x0) {
      piVar6 = puVar2 + 1;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    FUN_0089120c(param_3);
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) + 1;
  param_3[1] = (int)in_EAX;
  if (in_EAX == *(undefined4 **)(unaff_EDI + 4)) {
    (*(undefined4 **)(unaff_EDI + 4))[1] = param_3;
    **(undefined4 **)(unaff_EDI + 4) = param_3;
    iVar5 = *(int *)(unaff_EDI + 4);
  }
  else {
    if (param_2 != '\0') {
      *in_EAX = param_3;
      if (in_EAX == (undefined4 *)**(int **)(unaff_EDI + 4)) {
        **(int **)(unaff_EDI + 4) = (int)param_3;
      }
      goto LAB_00845569;
    }
    in_EAX[2] = param_3;
    iVar5 = *(int *)(unaff_EDI + 4);
    if (in_EAX != *(undefined4 **)(iVar5 + 8)) goto LAB_00845569;
  }
  *(int **)(iVar5 + 8) = param_3;
LAB_00845569:
  cVar1 = *(char *)(param_3[1] + 0x14);
  piVar6 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(unaff_EDI + 4) + 4) + 0x14) = 1;
      *param_1 = param_3;
      return;
    }
    piVar3 = (int *)piVar6[1];
    piVar4 = (int *)piVar3[1];
    if (piVar3 == (int *)*piVar4) {
      iVar5 = piVar4[2];
      if (*(char *)(iVar5 + 0x14) == '\0') {
LAB_008455c8:
        *(undefined1 *)(piVar3 + 5) = 1;
        *(undefined1 *)(iVar5 + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
      else {
        if (piVar6 == (int *)piVar3[2]) {
          FUN_00763f60(unaff_EDI);
          piVar6 = piVar3;
        }
        *(undefined1 *)(piVar6[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
        FUN_0043e670(unaff_EDI);
      }
    }
    else {
      iVar5 = *piVar4;
      if (*(char *)(iVar5 + 0x14) == '\0') goto LAB_008455c8;
      if (piVar6 == (int *)*piVar3) {
        FUN_0043e670(unaff_EDI);
        piVar6 = piVar3;
      }
      *(undefined1 *)(piVar6[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
      iVar5 = *(int *)(piVar6[1] + 4);
      piVar3 = *(int **)(iVar5 + 8);
      *(int *)(iVar5 + 8) = *piVar3;
      if (*(char *)(*piVar3 + 0x15) == '\0') {
        *(int *)(*piVar3 + 4) = iVar5;
      }
      piVar3[1] = *(int *)(iVar5 + 4);
      if (iVar5 == *(int *)(*(int *)(unaff_EDI + 4) + 4)) {
        *(int **)(*(int *)(unaff_EDI + 4) + 4) = piVar3;
      }
      else {
        piVar4 = *(int **)(iVar5 + 4);
        if (iVar5 == *piVar4) {
          *piVar4 = (int)piVar3;
        }
        else {
          piVar4[2] = (int)piVar3;
        }
      }
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
    }
    cVar1 = *(char *)(piVar6[1] + 0x14);
  } while( true );
}

