
void FUN_0043fb90(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_EAX;
  int in_ECX;
  int iVar4;
  int *piVar5;
  
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
    if (param_3[4] != 0) {
      FUN_006ab960(param_2);
      FUN_0089120c(param_3[4]);
    }
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    FUN_0089120c(param_3);
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("map/set<T> too long");
  }
  *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) + 1;
  param_3[1] = (int)in_EAX;
  if (in_EAX == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = param_3;
    **(undefined4 **)(in_ECX + 4) = param_3;
    iVar4 = *(int *)(in_ECX + 4);
  }
  else {
    if ((char)param_2 != '\0') {
      *in_EAX = param_3;
      if (in_EAX == (undefined4 *)**(int **)(in_ECX + 4)) {
        **(int **)(in_ECX + 4) = (int)param_3;
      }
      goto LAB_0043fc1f;
    }
    in_EAX[2] = param_3;
    iVar4 = *(int *)(in_ECX + 4);
    if (in_EAX != *(undefined4 **)(iVar4 + 8)) goto LAB_0043fc1f;
  }
  *(int **)(iVar4 + 8) = param_3;
LAB_0043fc1f:
  cVar1 = *(char *)(param_3[1] + 0x20);
  piVar5 = param_3;
  while (cVar1 == '\0') {
    piVar2 = (int *)piVar5[1];
    piVar3 = (int *)piVar2[1];
    if (piVar2 == (int *)*piVar3) {
      iVar4 = piVar3[2];
      if (*(char *)(iVar4 + 0x20) == '\0') {
        *(undefined1 *)(piVar2 + 8) = 1;
        *(undefined1 *)(iVar4 + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x20) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar2[2]) {
          FUN_00405150(in_ECX);
          piVar5 = piVar2;
        }
        *(undefined1 *)(piVar5[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x20) = 0;
        FUN_00819bd0(in_ECX);
      }
    }
    else {
      iVar4 = *piVar3;
      if (*(char *)(iVar4 + 0x20) == '\0') {
        *(undefined1 *)(piVar2 + 8) = 1;
        *(undefined1 *)(iVar4 + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x20) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)*piVar2) {
          FUN_00819bd0(in_ECX);
          piVar5 = piVar2;
        }
        *(undefined1 *)(piVar5[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x20) = 0;
        iVar4 = *(int *)(piVar5[1] + 4);
        piVar2 = *(int **)(iVar4 + 8);
        *(int *)(iVar4 + 8) = *piVar2;
        if (*(char *)(*piVar2 + 0x21) == '\0') {
          *(int *)(*piVar2 + 4) = iVar4;
        }
        piVar2[1] = *(int *)(iVar4 + 4);
        if (iVar4 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
          *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
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
    }
    cVar1 = *(char *)(piVar5[1] + 0x20);
  }
  iVar4 = *(int *)(*(int *)(in_ECX + 4) + 4);
  *param_1 = param_3;
  *(undefined1 *)(iVar4 + 0x20) = 1;
  return;
}

