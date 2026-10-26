
void FUN_0040b4f0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FoxUI::FXUIBinderBase::vftable;
  if (unaff_ESI[1] != 0) {
    FUN_0089120c(unaff_ESI[1]);
  }
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  return;
}

