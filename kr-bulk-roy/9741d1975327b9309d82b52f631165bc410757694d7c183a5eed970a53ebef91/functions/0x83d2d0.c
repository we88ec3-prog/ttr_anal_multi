
void FUN_0083d2d0(void)

{
  int *piVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))();
  piVar1 = (int *)in_ECX[0x112];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x112] = 0;
  }
  piVar1 = (int *)in_ECX[0x113];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x113] = 0;
  }
  FUN_008391a0(in_ECX + 0xd4);
  FUN_008642e0(in_ECX + 0x5e);
  FUN_00863df0(in_ECX + 0x4d);
  FUN_00863710(in_ECX + 0x3c);
  piVar1 = (int *)in_ECX[0x10b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x10b] = 0;
  }
  piVar1 = (int *)in_ECX[0x10c];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x10c] = 0;
  }
  if (DAT_00fba944 != (int *)0x0) {
    (**(code **)(*DAT_00fba944 + 8))(DAT_00fba944);
    DAT_00fba944 = (int *)0x0;
  }
  piVar1 = (int *)in_ECX[0x115];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x115] = 0;
  }
  return;
}

