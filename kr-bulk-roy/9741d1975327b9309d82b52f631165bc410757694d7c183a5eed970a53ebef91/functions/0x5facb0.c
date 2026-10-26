
void FUN_005facb0(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  
  FUN_005f50c0();
  in_EAX[0x4a] = 0;
  in_EAX[0x4b] = 0;
  in_EAX[0x4c] = 0;
  in_EAX[0x4d] = 0;
  in_EAX[0x4e] = 0;
  in_EAX[0x4f] = 0;
  in_EAX[0x50] = 0;
  *in_EAX = FUI::CInventoryDialog::vftable;
  in_EAX[0x56] = 0;
  in_EAX[0x57] = 7;
  *(undefined2 *)(in_EAX + 0x52) = 0;
  in_EAX[0x59] = 0;
  in_EAX[0x5a] = 0;
  in_EAX[0x5c] = 0;
  in_EAX[0x5d] = 0;
  in_EAX[100] = 0;
  in_EAX[0x65] = 0;
  in_EAX[0x5e] = 0;
  in_EAX[0x66] = 0;
  in_EAX[0x67] = 0;
  in_EAX[0x5f] = 0;
  in_EAX[0x68] = 0;
  in_EAX[0x69] = 0;
  in_EAX[0x60] = 0;
  in_EAX[0x6a] = 0;
  in_EAX[0x6b] = 0;
  uVar1 = in_EAX[0x65];
  in_EAX[100] = in_EAX[100] | 2;
  in_EAX[100] = in_EAX[100] | 4;
  in_EAX[100] = in_EAX[100] | 8;
  in_EAX[0x68] = in_EAX[0x68] | 0x20000;
  in_EAX[0x68] = in_EAX[0x68] | 0x40000;
  in_EAX[0x68] = in_EAX[0x68] | 0x80000;
  in_EAX[0x62] = 0xffffffff;
  in_EAX[99] = 0xffffffff;
  in_EAX[0x65] = uVar1;
  in_EAX[0x65] = uVar1;
  in_EAX[0x65] = in_EAX[0x65] | 0x100;
  in_EAX[0x65] = in_EAX[0x65] | 0x200;
  in_EAX[0x65] = in_EAX[0x65] | 0x400;
  in_EAX[0x65] = in_EAX[0x65] | 0x800;
  in_EAX[100] = in_EAX[100] | 0x10;
  in_EAX[100] = in_EAX[100] | 0x8000000;
  in_EAX[100] = in_EAX[100];
  in_EAX[100] = in_EAX[100] | 0x10000;
  in_EAX[0x65] = in_EAX[0x65];
  in_EAX[0x66] = in_EAX[0x66] | 0x20;
  in_EAX[0x66] = in_EAX[0x66] | 0x2000;
  in_EAX[0x66] = in_EAX[0x66] | 0x200000;
  in_EAX[0x66] = in_EAX[0x66] | 0x800000;
  in_EAX[0x66] = in_EAX[0x66] | 0x4000000;
  in_EAX[0x67] = in_EAX[0x67];
  in_EAX[0x67] = in_EAX[0x67] | 0x40;
  in_EAX[0x67] = in_EAX[0x67] | 0x80;
  in_EAX[0x66] = in_EAX[0x66];
  in_EAX[0x69] = in_EAX[0x69];
  in_EAX[0x69] = in_EAX[0x69] | 1;
  in_EAX[0x69] = in_EAX[0x69] | 0x10;
  in_EAX[0x69] = in_EAX[0x69] | 0x20;
  in_EAX[0x6a] = in_EAX[0x6a] | in_EAX[100];
  in_EAX[0x68] = in_EAX[0x68];
  in_EAX[0x6b] = in_EAX[0x6b] | in_EAX[0x65];
  in_EAX[0x6a] = in_EAX[0x6a] | in_EAX[0x66];
  in_EAX[0x6b] = in_EAX[0x6b] | in_EAX[0x67];
  in_EAX[0x6a] = in_EAX[0x6a] | in_EAX[0x68];
  in_EAX[0x6b] = in_EAX[0x6b] | in_EAX[0x69];
  in_EAX[0x6b] = ~in_EAX[0x6b];
  in_EAX[0x6a] = ~in_EAX[0x6a];
  return;
}

