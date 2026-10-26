
void FUN_004029e0(int param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = param_1;
  if (7 < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  *(undefined2 *)((int)in_ECX + param_1 * 2) = 0;
  return;
}

