
void FUN_00738100(void)

{
  int in_EAX;
  int in_ECX;
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    if ((in_ECX == -1) || (in_EAX == -1)) {
      unaff_ESI[3] = unaff_ESI[1];
      unaff_ESI[4] = unaff_ESI[2];
    }
    else {
      unaff_ESI[3] = in_ECX;
      unaff_ESI[4] = in_EAX;
    }
    if ((int *)unaff_ESI[0x46] != (int *)0x0) {
      (**(code **)(*(int *)unaff_ESI[0x46] + 8))();
      unaff_ESI[0x46] = 0;
    }
    unaff_ESI[0x47] = 0;
    unaff_ESI[5] = 1;
    unaff_ESI[0x4c] = 1;
  }
  return;
}

