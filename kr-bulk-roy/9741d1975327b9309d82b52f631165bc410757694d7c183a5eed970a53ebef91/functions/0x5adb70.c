
void FUN_005adb70(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar1 = *(int **)unaff_EDI[0x93];
  if (piVar1 != (int *)unaff_EDI[0x93]) {
    do {
      piVar2 = (int *)piVar1[2];
      if ((~(byte)((uint)piVar2[10] >> 8) & 1) == 0) {
        piVar2 = (int *)*piVar1;
      }
      else {
        (**(code **)(*unaff_EDI + 0x74))(piVar2);
        (**(code **)(*piVar2 + 0x1c))(1);
        piVar2 = (int *)*piVar1;
        if (piVar1 != (int *)unaff_EDI[0x93]) {
          *(int **)piVar1[1] = piVar2;
          *(int *)(*piVar1 + 4) = piVar1[1];
          FUN_0089120c(piVar1);
          unaff_EDI[0x94] = unaff_EDI[0x94] + -1;
        }
      }
      piVar1 = piVar2;
    } while (piVar2 != (int *)unaff_EDI[0x93]);
  }
  return;
}

