
void FUN_006ed120(void)

{
  undefined4 *unaff_ESI;
  
  if ((void *)*unaff_ESI != (void *)0x0) {
    _free((void *)*unaff_ESI);
    *unaff_ESI = 0;
  }
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

