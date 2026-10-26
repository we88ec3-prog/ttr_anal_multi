
void FUN_004ef3e0(void)

{
  int unaff_ESI;
  undefined2 local_8;
  undefined2 local_6;
  
  if (*(char *)(unaff_ESI + 0x18) != '\0') {
    local_6 = 0x9e;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_6,2);
    }
    _local_8 = CONCAT22(local_6,0x95);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,2);
    }
    *(undefined1 *)(unaff_ESI + 0x18) = 0;
  }
  return;
}

