
void FUN_0069c430(void)

{
  int *piVar1;
  int *in_ECX;
  
  FUN_007459c0();
  piVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 10) & 0x10) == 0) {
    if (in_ECX[0x18] == 0) goto LAB_0069c46c;
    piVar1 = (int *)FUN_00745c20();
  }
  if (((piVar1 != (int *)0x0) && (piVar1[0x18] != 0)) && (((uint)piVar1[10] >> 0xc & 1) == 0)) {
    FUN_0074a010(piVar1);
  }
LAB_0069c46c:
  in_ECX[0x51] = 0;
  FUN_0069c130(in_ECX);
  (**(code **)(*in_ECX + 0x90))(1);
  return;
}

