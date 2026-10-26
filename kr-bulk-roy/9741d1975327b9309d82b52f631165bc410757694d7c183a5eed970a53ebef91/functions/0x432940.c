
int FUN_00432940(int *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *extraout_ECX;
  undefined4 *local_c;
  int local_8;
  
  if (0xf < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  local_8 = 0;
  iVar1 = __Stolx(in_EAX,&local_c);
  if (in_EAX == local_c) {
    FUN_0087dae3("invalid stoi argument");
    local_c = extraout_ECX;
  }
  if ((local_8 == 0) && (-0x80000000 <= iVar1)) {
    if (param_1 != (int *)0x0) {
      *param_1 = (int)local_c - (int)in_EAX;
    }
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("stoi argument out of range");
}

