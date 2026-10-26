
undefined4 FUN_008ccc20(undefined4 param_1)

{
  int *in_EAX;
  undefined4 uVar1;
  int *unaff_ESI;
  int local_8;
  
  if (*in_EAX == 0) {
    uVar1 = FUN_008ccbd0(param_1,&local_8);
    *unaff_ESI = local_8;
    return uVar1;
  }
  *unaff_ESI = in_EAX[2] + -0x10 + *in_EAX * 0x10;
  return 0;
}

