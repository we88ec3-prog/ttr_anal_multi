
void FUN_00460810(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  undefined2 *unaff_ESI;
  
  uVar1 = FUN_004041f0(in_EAX,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_00402800(uVar1);
  return;
}

