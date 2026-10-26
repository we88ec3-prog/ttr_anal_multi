
void FUN_0055ecc0(void)

{
  int *unaff_ESI;
  float local_c [2];
  
  if (((int *)*unaff_ESI != (int *)0x0) && (unaff_ESI[3] != 0)) {
    local_c[1] = 1.0;
    local_c[0] = (float)unaff_ESI[1] * 0.0625 + 2.0;
    (**(code **)(*(int *)*unaff_ESI + 0x24))(0xfffffff0,0xffffffe4,0,local_c,0,0,0xffffffff);
    local_c[0] = (float)unaff_ESI[1] * 0.0625 + 2.0;
    local_c[1] = 1.0;
    (**(code **)(*(int *)*unaff_ESI + 0x24))
              (0xfffffff0,unaff_ESI[2] + -100,0,local_c,0,0,0xffffffff);
  }
  return;
}

