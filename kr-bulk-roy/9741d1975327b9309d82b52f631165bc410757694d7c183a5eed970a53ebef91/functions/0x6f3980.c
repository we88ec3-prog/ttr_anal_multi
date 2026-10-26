
void FUN_006f3980(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = Input::CJoypadDevice::vftable;
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[0x448] = 0;
  unaff_ESI[0x447] = 0;
  unaff_ESI[0x449] = 1;
  unaff_ESI[0x44a] = 0;
  unaff_ESI[1099] = 0;
  _memset(unaff_ESI + 0x47,0,0x800);
  _memset(unaff_ESI + 0x247,0,0x800);
  _memset(unaff_ESI + 3,0,0x110);
  return;
}

