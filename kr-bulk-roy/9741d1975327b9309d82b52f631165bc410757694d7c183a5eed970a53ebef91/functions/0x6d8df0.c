
void FUN_006d8df0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = AlarmedThread::vftable;
  in_ECX[2] = 0;
  SetEvent((HANDLE)in_ECX[3]);
  if (in_ECX[1] != 0) {
    FUN_004fb7d0();
    in_ECX[1] = 0;
  }
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
    in_ECX[5] = 0;
  }
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

