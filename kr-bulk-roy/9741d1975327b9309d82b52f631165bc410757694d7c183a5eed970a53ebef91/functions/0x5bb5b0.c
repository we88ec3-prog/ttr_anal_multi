
void FUN_005bb5b0(void)

{
  int unaff_ESI;
  undefined2 local_a;
  undefined4 local_8;
  
  if (((uint)(*(int **)(unaff_ESI + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x224) + 0xd4))();
  }
  local_8 = *(undefined4 *)(*(int *)(unaff_ESI + 0x2b8) + 0x154);
  local_a = 0xf4;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
  }
  return;
}

