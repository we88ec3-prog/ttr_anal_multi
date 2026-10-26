
void FUN_007a2eb0(undefined4 *param_1,char param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_EAX;
  int in_ECX;
  int iVar4;
  int *piVar5;
  
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
    piVar5 = (int *)param_3[5];
    if (piVar5 != (int *)0x0) {
      LOCK();
      iVar4 = piVar5[1] + -1;
      piVar5[1] = iVar4;
      UNLOCK();
      if (iVar4 == 0) {
        (**(code **)*piVar5)();
        LOCK();
        iVar4 = piVar5[2] + -1;
        piVar5[2] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)(*piVar5 + 4))();
        }
      }
    }
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
    if (param_2 != '\0') {
      *in_EAX = param_3;
      if (in_EAX == (undefined4 *)**(int **)(in_ECX + 4)) {
        **(int **)(in_ECX + 4) = (int)param_3;
      }
      goto LAB_007a2f48;
    }
    in_EAX[2] = param_3;
    iVar4 = *(int *)(in_ECX + 4);
    if (in_EAX != *(undefined4 **)(iVar4 + 8)) goto LAB_007a2f48;
  }
  *(int **)(iVar4 + 8) = param_3;
LAB_007a2f48:
  cVar1 = *(char *)(param_3[1] + 0x18);
  piVar5 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x18) = 1;
      *param_1 = param_3;
      return;
    }
    piVar2 = (int *)piVar5[1];
    piVar3 = (int *)piVar2[1];
    if (piVar2 == (int *)*piVar3) {
      iVar4 = piVar3[2];
      if (*(char *)(iVar4 + 0x18) == '\0') {
LAB_007a2fa8:
        *(undefined1 *)(piVar2 + 6) = 1;
        *(undefined1 *)(iVar4 + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x18) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar2[2]) {
          FUN_00407e10(in_ECX);
          piVar5 = piVar2;
        }
        *(undefined1 *)(piVar5[1] + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x18) = 0;
        FUN_00852420(in_ECX);
      }
    }
    else {
      iVar4 = *piVar3;
      if (*(char *)(iVar4 + 0x18) == '\0') goto LAB_007a2fa8;
      if (piVar5 == (int *)*piVar2) {
        FUN_00852420(in_ECX);
        piVar5 = piVar2;
      }
      *(undefined1 *)(piVar5[1] + 0x18) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x18) = 0;
      iVar4 = *(int *)(piVar5[1] + 4);
      piVar2 = *(int **)(iVar4 + 8);
      *(int *)(iVar4 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x19) == '\0') {
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
    cVar1 = *(char *)(piVar5[1] + 0x18);
  } while( true );
}

