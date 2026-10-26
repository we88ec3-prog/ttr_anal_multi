
void FUN_0040b310(int *param_1)

{
  uint uVar1;
  char cVar2;
  size_t in_EAX;
  int *piVar3;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    uVar1 = in_ECX[5];
    piVar3 = in_ECX;
    if (0xf < uVar1) {
      piVar3 = (int *)*in_ECX;
    }
    if (piVar3 <= param_1) {
      piVar3 = in_ECX;
      if (0xf < uVar1) {
        piVar3 = (int *)*in_ECX;
      }
      if (param_1 < (int *)(in_ECX[4] + (int)piVar3)) {
        if (uVar1 < 0x10) {
          FUN_0040b0b0(in_ECX,(int)param_1 - (int)in_ECX);
          return;
        }
        FUN_0040b0b0(in_ECX,(int)param_1 - *in_ECX);
        return;
      }
    }
  }
  cVar2 = FUN_0040b2c0();
  if (cVar2 != '\0') {
    piVar3 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      piVar3 = (int *)*in_ECX;
    }
    FID_conflict__memcpy(piVar3,param_1,in_EAX);
    in_ECX[4] = in_EAX;
    if (0xf < (uint)in_ECX[5]) {
      *(undefined1 *)(*in_ECX + in_EAX) = 0;
      return;
    }
    *(undefined1 *)((int)in_ECX + in_EAX) = 0;
  }
  return;
}

