
void FUN_007cd220(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  undefined4 *unaff_EDI;
  
  in_EAX[0xc] = 7;
  _memset(in_EAX,0,0x34);
  _memset(in_EAX,0,0x34);
  in_EAX[8] = 0x3f800000;
  in_EAX[4] = 0x3f800000;
  *in_EAX = 0x3f800000;
  FUN_00780a00();
  FUN_00791100();
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  in_EAX[9] = *unaff_EDI;
  in_EAX[10] = uVar1;
  in_EAX[0xb] = uVar2;
  return;
}

