
void FUN_005f2840(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  undefined2 *unaff_EDI;
  
  uVar1 = FUN_004481f0(0,in_EAX,0);
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  FUN_00402800(uVar1);
  return;
}

