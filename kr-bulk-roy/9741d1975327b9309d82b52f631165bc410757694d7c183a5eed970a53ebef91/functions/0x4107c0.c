
void FUN_004107c0(void)

{
  int in_ECX;
  
  FUN_004067f0();
  FUN_00411030();
  if (((uint)(*(int **)(in_ECX + 0x110))[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x004107e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x110) + 0xd4))();
    return;
  }
  return;
}

