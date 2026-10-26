
void FUN_00439f80(void)

{
  int in_ECX;
  undefined2 local_c;
  undefined1 local_a;
  undefined2 local_6;
  
  FUN_007459c0();
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00439fc2;
    in_ECX = FUN_00745c20();
  }
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x60) != 0)) &&
     ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) {
    FUN_0074a010(in_ECX);
  }
LAB_00439fc2:
  FUN_0040b5b0(0);
  local_c = 0xfd;
  local_a = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,3);
  }
  local_6 = 0xfe;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_6,2);
  }
  return;
}

