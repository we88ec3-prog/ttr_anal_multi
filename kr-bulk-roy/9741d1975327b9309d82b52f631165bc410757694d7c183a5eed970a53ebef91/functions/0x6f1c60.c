
int * FUN_006f1c60(uint param_1)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  
  iVar1 = in_EAX + param_1 * 0xc;
  piVar2 = (int *)(in_EAX + (param_1 * 3 + 0xc) * 4);
  *piVar2 = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  if (*(int *)(in_EAX + 0x20) != 0) {
    local_8 = 4;
    piVar5 = (int *)(in_EAX + 0x18);
    do {
      if ((((*piVar5 != 0) && (iVar3 = (**(code **)(*(int *)*piVar5 + 0x2c))(), iVar3 != 0)) &&
          (iVar3 = (**(code **)(*(int *)*piVar5 + 0x30))(), iVar3 != 0)) &&
         (piVar4 = (int *)(**(code **)(*(int *)*piVar5 + 0x20))(), piVar4 != (int *)0x0)) {
        iVar3 = (int)param_1 / 2;
        if (iVar3 == 1) {
          piVar4 = piVar4 + 0x2c;
        }
        else if (iVar3 == 2) {
          piVar4 = piVar4 + 0x34;
        }
        else if (iVar3 == 3) {
          piVar4 = piVar4 + 0x3c;
        }
        if ((param_1 & 1) == 0) {
          *piVar2 = *piVar2 + *piVar4 + -0x7fff;
          *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + piVar4[1] + -0x7fff;
          iVar3 = piVar4[2];
        }
        else {
          *piVar2 = *piVar2 + piVar4[3] + -0x7fff;
          *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + piVar4[4] + -0x7fff;
          iVar3 = piVar4[5];
        }
        *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + iVar3 + -0x7fff;
      }
      local_8 = local_8 + -1;
      piVar5 = piVar5 + -1;
    } while (-1 < local_8);
  }
  return piVar2;
}

