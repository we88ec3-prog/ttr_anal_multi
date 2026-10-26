
void FUN_00680430(void)

{
  int *piVar1;
  float fVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(in_EAX + 0x278);
  iVar4 = 2;
  do {
    piVar1 = (int *)*piVar3;
    if (((uint)piVar1[10] >> 8 & 1) != 0) {
      if ((float)piVar1[0x20] <= 0.0) {
        (**(code **)(*piVar1 + 0x94))(0);
      }
      else {
        fVar2 = (float)piVar1[0x20] - 0.011666667;
        if (fVar2 <= 0.0) {
          fVar2 = 0.0;
        }
        (**(code **)(*piVar1 + 0xd8))(fVar2);
        (**(code **)(*(int *)*piVar3 + 200))();
      }
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

