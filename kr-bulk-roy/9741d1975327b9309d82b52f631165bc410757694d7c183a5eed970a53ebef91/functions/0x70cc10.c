
void FUN_0070cc10(void)

{
  code *pcVar1;
  undefined4 *unaff_ESI;
  
  FUN_006f7c30(*unaff_ESI,"%s: %s in precompiled chunk",unaff_ESI[3]);
  FUN_006fdb40(*unaff_ESI,3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

