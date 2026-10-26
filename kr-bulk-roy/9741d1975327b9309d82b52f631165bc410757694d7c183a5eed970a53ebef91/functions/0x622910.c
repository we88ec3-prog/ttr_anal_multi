
void FUN_00622910(int param_1)

{
  undefined4 in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    FUN_00624150(in_ECX);
    FUN_006241f0();
  }
  else if (*(int *)(param_1 + 0x10) == 0x5e6) {
    FUN_006229f0();
    FUN_006241f0();
    return;
  }
  return;
}

