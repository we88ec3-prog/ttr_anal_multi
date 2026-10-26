
void FUN_00834200(int param_1)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  FUN_008346c0(unaff_ESI + 1,param_1);
  unaff_ESI[5] = *(undefined4 *)(param_1 + 0x10);
  return;
}

