
void FUN_007754b0(undefined4 param_1)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FoxUI::FXUIManagedLine::vftable;
  _eh_vector_constructor_iterator_
            (unaff_ESI + 1,0x1c,4,(_func_void_void_ptr *)&LAB_0074d970,FUN_005f5d10);
  unaff_ESI[0x21] = 0x41100000;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x22] = 0x3f800000;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = param_1;
  return;
}

