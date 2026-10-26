
undefined4 FUN_00753440(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = *(int **)(in_EAX + 0x1420);
  uVar4 = 0;
  piVar3 = (int *)*piVar1;
joined_r0x00753457:
  do {
    if (piVar3 == piVar1) {
      return uVar4;
    }
    iVar5 = *(int *)(piVar3[2] + 0x80);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xd4) != 0)) {
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0xd4);
      }
      if (*(int *)(iVar5 + 0x10) == param_1) {
        FUN_00750350();
        if (*(int *)(in_EAX + 0x13c4) != 0) {
          (**(code **)(*(int *)piVar3[2] + 0xd4))();
          (**(code **)(**(int **)(in_EAX + 0x13c4) + 0x74))(piVar3[2]);
        }
        if ((int *)piVar3[2] != (int *)0x0) {
          (**(code **)(*(int *)piVar3[2] + 0x1c))(1);
          piVar3[2] = 0;
        }
        piVar2 = (int *)*piVar3;
        if (piVar3 != *(int **)(in_EAX + 0x1420)) {
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          FUN_0089120c(piVar3);
          *(int *)(in_EAX + 0x1424) = *(int *)(in_EAX + 0x1424) + -1;
        }
        uVar4 = 1;
        piVar3 = piVar2;
        goto joined_r0x00753457;
      }
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}

