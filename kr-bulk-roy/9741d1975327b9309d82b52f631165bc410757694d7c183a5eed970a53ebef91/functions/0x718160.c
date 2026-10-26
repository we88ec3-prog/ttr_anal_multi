
uint FUN_00718160(void)

{
  uint uVar1;
  uint uVar2;
  int *in_ECX;
  
  if ((int *)in_ECX[3] == (int *)0x0) {
    uVar1 = FID_conflict__wprintf("File is not opened!\n");
    return uVar1 & 0xffffff00;
  }
  uVar1 = (**(code **)(*(int *)in_ECX[3] + 0x30))();
  uVar2 = (**(code **)(*in_ECX + 0xc))();
  return (uint)(uVar2 <= uVar1);
}

