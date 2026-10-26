
undefined4 FUN_004ed560(void)

{
  int unaff_ESI;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 local_a;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(unaff_ESI + 0x5ec4);
  local_a = 0xec;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
  }
  local_e = *(undefined4 *)(unaff_ESI + 0x5ec4);
  local_10 = 0xed;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,6);
  }
  return 1;
}

