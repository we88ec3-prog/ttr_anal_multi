
int * FUN_008666e0(int *param_1,int *param_2)

{
  int *in_EAX;
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int local_c;
  
  if (in_EAX != param_1) {
    piVar1 = in_EAX + 0x44;
    do {
      if (param_2 != piVar1 + -0x44) {
        FUN_00843650(param_2);
        FUN_005540c0(*(undefined4 *)param_2[1],(undefined4 *)param_2[1]);
        FUN_005c7580(piVar1 + -0x44);
        piVar2 = piVar1 + -0x20;
        piVar3 = param_2 + 0x25;
        local_c = 8;
        do {
          if (piVar3 + -0x21 != piVar2 + -0x20) {
            FUN_005540c0(*(undefined4 *)piVar3[-0x20],(undefined4 *)piVar3[-0x20]);
            FUN_005c7580(piVar2 + -0x20);
          }
          if (piVar3 + -1 != piVar2) {
            FUN_005540c0(*(undefined4 *)*piVar3,(undefined4 *)*piVar3);
            FUN_005c7580(piVar2);
          }
          piVar2 = piVar2 + 4;
          piVar3 = piVar3 + 4;
          local_c = local_c + -1;
        } while (local_c != 0);
        piVar2 = (int *)*piVar1;
        param_2[0x44] = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
        param_2[0x45] = piVar1[1];
        param_2[0x46] = piVar1[2];
      }
      param_2 = param_2 + 0x47;
      piVar2 = piVar1 + 3;
      piVar1 = piVar1 + 0x47;
    } while (piVar2 != param_1);
    return param_2;
  }
  return param_2;
}

