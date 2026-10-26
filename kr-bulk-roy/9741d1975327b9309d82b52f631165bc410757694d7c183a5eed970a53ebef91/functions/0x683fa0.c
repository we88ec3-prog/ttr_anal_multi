
void FUN_00683fa0(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    FUN_004067f0();
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&stack0xfffffffa,2,CONCAT22(0x1d,(short)in_ECX));
    }
  }
  return;
}

