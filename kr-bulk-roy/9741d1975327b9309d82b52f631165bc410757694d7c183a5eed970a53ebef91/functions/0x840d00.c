
void FUN_00840d00(int *param_1)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  
  if (in_EAX != param_1) {
    piVar2 = in_EAX + 0x14;
    do {
      piVar1 = (int *)*piVar2;
      piVar2[-0xffffffff00000004] = 0;
      piVar2[-0xffffffff00000003] = 0;
      piVar2[-1] = 4;
      piVar2[-0x14] = 0;
      piVar2[-5] = 0;
      piVar2[-2] = 0;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar2 = 0;
      }
      piVar1 = (int *)piVar2[1];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        piVar2[1] = 0;
      }
      piVar1 = (int *)piVar2[2];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        piVar2[2] = 0;
      }
      piVar2[3] = 0;
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[6] = 0;
      piVar2[8] = 0;
      piVar2[7] = 0;
      piVar2[-6] = 0;
      piVar1 = piVar2 + 10;
      piVar2 = piVar2 + 0x1e;
    } while (piVar1 != param_1);
  }
  return;
}

